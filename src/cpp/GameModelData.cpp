//
//  GameModelData.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/22/20.
//

#include "GameModelData.h"
#include <string>
#include "curl/curl.h"
#include "SDL.h"
#include "GameModelViewData.h"
#include "UtilDSS.h"

extern int gDone;

struct FileData {
    char *_current_ptr;
    char *_buffer;
    size_t _size;
    
    FileData(int megabytes) {
        _buffer = new char[1024 * 1024 * megabytes];
        _current_ptr = _buffer;
        _size = 0;
    }
    ~FileData() {
        delete [] _buffer;
    }
    void append_data(char *ptr, size_t size, size_t nmemb) {
        int s = (size * nmemb);
        memcpy(_current_ptr, ptr, s);
        _current_ptr += s;
        _size += s;
    }
};

static std::mutex sMutex;

static size_t callbackfunction(char *ptr, size_t size, size_t nmemb, void* userdata)
{
    FileData *fd = (FileData*)userdata;
    fd->append_data(ptr, size, nmemb);
    
    if(gDone)
        return 0;
    return (size * nmemb);
}

static void download_json(GameModelData *gmd)
{
    int megabyteBuffer = 10;
    FileData *fd = new FileData(megabyteBuffer);

    CURL* curlCtx = curl_easy_init();
    curl_easy_setopt(curlCtx, CURLOPT_URL, gmd->getUrl().c_str());
    curl_easy_setopt(curlCtx, CURLOPT_WRITEDATA, fd);
    curl_easy_setopt(curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
    curl_easy_setopt(curlCtx, CURLOPT_FOLLOWLOCATION, 1);

    CURLcode rc = curl_easy_perform(curlCtx);
    if (rc) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "!!! Failed to download: %s\n", gmd->getUrl().c_str());
    }

    long res_code = 0;
    curl_easy_getinfo(curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201) && rc != CURLE_ABORTED_BY_CALLBACK)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "!!! Response code: %ld\n", res_code);
    }

    curl_easy_cleanup(curlCtx);
    
#if !(defined(NDEBUG))
    std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
    n += "_curl.json";
    FILE* fp = fopen(n.c_str(), "wb");
    if (fp) {
        fwrite(fd->_buffer, sizeof(char), fd->_size, fp);
        
        fclose(fp);
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "!!! Failed to create file on the disk\n");
    }
#endif
    
    sMutex.lock();
    gmd->setJson(fd->_buffer);
    sMutex.unlock();
    
    delete fd;
}

const std::string GameModelData::URLBase = "http://statsapi.mlb.com/api/v1/schedule?hydrate=game(content(editorial(recap))),decisions&date=%.4d-%.2d-%.2d&sportId=1";

GameModelData::GameModelData(const std::string url) :
mUrl(url) {
    if(!UtilDSS::validUrl(mUrl)) {
        mUrl = "";
    }
}

GameModelData *GameModelData::generateGameModelData(struct tm time_str) {
    static char buff[4096];

    int month = time_str.tm_mon;
    int day = time_str.tm_mday;
    int year = time_str.tm_year;

    snprintf(buff, sizeof(buff), URLBase.c_str(), year, month, day);
    
    GameModelData *_GameModelData = new GameModelData(buff);
    
    ThreadPool::getInstance()->enqueue(download_json, _GameModelData);
    
    return _GameModelData;
}

void GameModelData::setJson(char *json) {
    
    try {
        mDssData = nlohmann::json::parse(json);
        notify();
    } catch (nlohmann::json::exception& e) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "exception message: %s \nexception id: %d", e.what(), e.id);
    }
}

const std::string &GameModelData::getUrl()const {
    return mUrl;
}

const MLBJson::Dss &GameModelData::getMLBData()const {
    return mDssData;
}

void GameModelData::update(Publisher* who, void* userdata) {
    GameModelData *completed_me = dynamic_cast<GameModelData*>(who);
    
    if(nullptr != completed_me) {
        
        for (std::vector<MLBJson::DateElement>::iterator dateElement_iterator = completed_me->mDssData.getMutableDates().begin();
             dateElement_iterator != completed_me->mDssData.getMutableDates().end();
             ++dateElement_iterator) {

            MLBJson::DateElement _dateElement = *dateElement_iterator;

            //TODO: The Renderer will have to subscribe to this!
            
            std::vector<GameModelViewData*> gvdVector;
            GameModelViewData::loadGames(_dateElement.getMutableGames(), gvdVector);
            
            for(std::vector<GameModelViewData*>::iterator iter = gvdVector.begin();
                iter != gvdVector.end();
                ++iter) {
                GameModelViewData *_GameModelViewData = *iter;
                _GameModelViewData->subscribe(_GameModelViewData);
            }
        }
    }
}
