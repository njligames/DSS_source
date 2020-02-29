//
//  GameModelData.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/22/20.
//

#include "GameModelData.h"
#include "BackgroundRenderer.h"
#include "GameModelViewData.h"
#include "SDL.h"
#include "UtilDSS.h"
#include "curl/curl.h"
#include <string>

extern int gDone;

static void curlErrorCheck(CURLcode code, const char *stmt, const char *fname,
                           int line) {
    if (CURLE_OK != code) {

        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Curl error %08x, (%s) at %s:%i - for %s", code,
                     curl_easy_strerror(code), fname, line, stmt);
    }
}
#ifndef CURL_CHECK
#if !(defined(NDEBUG))
#define CURL_CHECK(stmt)                                                       \
    do {                                                                       \
        curlErrorCheck(stmt, #stmt, __FILE__, __LINE__);                       \
    } while (0);
#else
#define CURL_CHECK(stmt) stmt
#endif
#endif

struct FileData {
    char *_current_ptr;
    char *_buffer;
    size_t _size;
    CURL *_curlCtx;

    FileData(int megabytes) {
        _buffer = new char[1024 * 1024 * megabytes];
        _current_ptr = _buffer;
        _size = 0;
        _curlCtx = curl_easy_init();
    }
    ~FileData() {
        delete[] _buffer;
        curl_easy_cleanup(_curlCtx);
    }
    void append_data(char *ptr, size_t size, size_t nmemb) {
        int s = (size * nmemb);
        memcpy(_current_ptr, ptr, s);
        _current_ptr += s;
        _size += s;
    }
};

static size_t callbackfunction(char *ptr, size_t size, size_t nmemb,
                               void *userdata) {
    FileData *fd = (FileData *)userdata;
    fd->append_data(ptr, size, nmemb);

    if (gDone)
        return 0;
    return (size * nmemb);
}

static void download_json(GameModelData *gmd) {

    CURLcode _CURLcode(CURLE_OK);

    int megabyteBuffer = 10;
    FileData *fd = new FileData(megabyteBuffer);

    char *buff = new char[1024];

    CURL_CHECK(
        curl_easy_setopt(fd->_curlCtx, CURLOPT_URL, gmd->getUrl().c_str()));
    CURL_CHECK(curl_easy_setopt(fd->_curlCtx, CURLOPT_FOLLOWLOCATION, 1L));
    CURL_CHECK(curl_easy_setopt(fd->_curlCtx, CURLOPT_ERRORBUFFER, buff));
    CURL_CHECK(curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEFUNCTION,
                                callbackfunction));
    CURL_CHECK(curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEDATA, fd));
    //#if !(defined(NDEBUG))
    //    CURL_CHECK(curl_easy_setopt(fd->_curlCtx, CURLOPT_NOPROGRESS, 0L));
    //#endif
    //    CURL_CHECK(curl_easy_setopt(fd->_curlCtx, CURLOPT_CONNECTTIMEOUT,
    //    5L));

    CURLcode rc = curl_easy_perform(fd->_curlCtx);
    if (rc) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "!!! Failed to download: %s\n", gmd->getUrl().c_str());
    }

    long res_code = 0;
    curl_easy_getinfo(fd->_curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201) &&
          rc != CURLE_ABORTED_BY_CALLBACK)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "!!! Response code: %ld\n",
                     res_code);
    }

#if !(defined(NDEBUG))
    std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
    n += "_curl.json";
    FILE *fp = fopen(n.c_str(), "wb");
    if (fp) {
        fwrite(fd->_buffer, sizeof(char), fd->_size, fp);

        fclose(fp);
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "!!! Failed to create file on the disk\n");
    }
#endif

    gmd->setJson(fd->_buffer);

    delete[] buff;

    delete fd;
}

const std::string GameModelData::URLBase =
    "http://statsapi.mlb.com/api/v1/"
    "schedule?hydrate=game(content(editorial(recap))),decisions&date=%.4d-%.2d-"
    "%.2d&sportId=1";

GameModelData::GameModelData(const std::string url) : mUrl(url) {
    if (!UtilDSS::validUrl(mUrl)) {
        mUrl = "";
    }
    ThreadPool::getInstance()->enqueue(download_json, this);
}
GameModelData::~GameModelData() {
    while (!mGameModelViewDataVector.empty()) {
        GameModelViewData *gmvd = mGameModelViewDataVector.back();
        mGameModelViewDataVector.pop_back();

        delete gmvd;
    }
}

void GameModelData::getGameModelViewVector(
    std::vector<GameModelViewData *> &v) {
    v = mGameModelViewDataVector;
}
bool GameModelData::hasGames() const { return mHasGames; }

GameModelData *GameModelData::generateGameModelData(const NJLIC::Date &date) {
    static char buff[4096];

    snprintf(buff, sizeof(buff), URLBase.c_str(), date.getYear(),
             date.getMonth(), date.getDay());

    GameModelData *_GameModelData = new GameModelData(buff);

    _GameModelData->subscribe(_GameModelData);

    return _GameModelData;
}

void GameModelData::setJson(char *json) {
    std::unique_lock<std::mutex> lock(mMutex);

    try {
        mDssData = nlohmann::json::parse(json);
        notify();
    } catch (nlohmann::json::exception &e) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "exception message: %s \nexception id: %d", e.what(),
                     e.id);
    }
}

const std::string &GameModelData::getUrl() const { return mUrl; }

const MLBJson::Dss &GameModelData::getMLBData() const { return mDssData; }

void GameModelData::update(Publisher *who, void *userdata) {
    GameModelData *completed_me = dynamic_cast<GameModelData *>(who);

    if (nullptr != completed_me) {

        NJLIC::BackgroundRenderer::getInstance()->enableLoadedJson();

        for (std::vector<MLBJson::DateElement>::iterator dateElement_iterator =
                 completed_me->mDssData.getMutableDates().begin();
             dateElement_iterator !=
             completed_me->mDssData.getMutableDates().end();
             ++dateElement_iterator) {

            MLBJson::DateElement _dateElement = *dateElement_iterator;

            // TODO: The Renderer will have to subscribe to this!

            GameModelViewData::loadGames(_dateElement.getMutableGames(),
                                         mGameModelViewDataVector);

            mHasGames = true;
            for (std::vector<GameModelViewData *>::iterator iter =
                     mGameModelViewDataVector.begin();
                 iter != mGameModelViewDataVector.end(); ++iter) {
                GameModelViewData *_GameModelViewData = *iter;
                _GameModelViewData->subscribe(*iter);
            }
        }
    }
}
