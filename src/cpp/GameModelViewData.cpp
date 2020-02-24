//
//  GameModelViewData.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/21/20.
//

#include "GameModelViewData.h"

//#define STB_IMAGE_IMPLEMENTATION
#ifndef njlic_stb_image
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

//#define STB_IMAGE_WRITE_IMPLEMENTATION
#ifndef njlic_stb_image_write
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#endif

#include "SDL.h"
#include "UtilDSS.h"
#include "curl/curl.h"

extern int gDone;

const int MAX_IMAGE_WIDTH = 4096;
const int MAX_IMAGE_HEIGHT = 4096;
const int MAX_IMAGE_COMPONENTS = 4;

struct FileData {
    char *_current_ptr;
    char *_buffer;
    size_t _size;

    CURL *_curlCtx;
    std::string _url;
    GameModelViewData *_gvd_ptr;

    FileData(int width, int height, int num_components) {
        _buffer = new char[width * height * num_components];
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

static FileData *download_jpeg(const char *url) {
    FileData *fd =
        new FileData(MAX_IMAGE_WIDTH, MAX_IMAGE_HEIGHT, MAX_IMAGE_COMPONENTS);

    curl_easy_setopt(fd->_curlCtx, CURLOPT_URL, url);
    curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEDATA, fd);
    curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
    curl_easy_setopt(fd->_curlCtx, CURLOPT_FOLLOWLOCATION, 1);

    CURLcode rc = curl_easy_perform(fd->_curlCtx);
    if (rc) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "!!! Failed to download: %s\n", url);
        return nullptr;
    }

    long res_code = 0;
    curl_easy_getinfo(fd->_curlCtx, CURLINFO_RESPONSE_CODE, &res_code);
    if (!((res_code == 200 || res_code == 201) &&
          rc != CURLE_ABORTED_BY_CALLBACK)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "!!! Response code: %ld\n",
                     res_code);
        return nullptr;
    } else {
        SDL_LogVerbose(SDL_LOG_CATEGORY_TEST,
                       "Transfer completed with Response code: %ld\n",
                       res_code);
    }

#if !(defined(NDEBUG))
    std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
    n += "_curl.jpg";
    FILE *fp = fopen(n.c_str(), "wb");
    if (fp) {
        fwrite(fd->_buffer, sizeof(char), fd->_size, fp);

        fclose(fp);
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "!!! Failed to create file on the disk\n");
    }
#endif

    return fd;
}

static bool download_detailimage(const char *url, GameModelViewData *gvd) {
    FileData *fd = download_jpeg(url);
    if (nullptr != fd) {

        int width, height, channels_in_file;
        void *ptr =
            stbi_load_from_memory((const stbi_uc *)fd->_buffer, fd->_size,
                                  &width, &height, &channels_in_file, 0);

        if (nullptr != ptr) {
            size_t fileSize = ((width) * (height) * (channels_in_file));

            gvd->setDetailImageData(ptr, fileSize);

#if !(defined(NDEBUG))
            std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
            n += "_detail_stbi.jpg";
            stbi_write_jpg(n.c_str(), width, height, channels_in_file, ptr,
                           100);
#endif
        }
        delete fd;

        return true;
    }
    return false;
}

static bool download_listitemimage(const char *url, GameModelViewData *gvd) {
    FileData *fd = download_jpeg(url);
    if (nullptr != fd) {

        int width, height, channels_in_file;
        void *ptr =
            stbi_load_from_memory((const stbi_uc *)fd->_buffer, fd->_size,
                                  &width, &height, &channels_in_file, 0);

        if (nullptr != ptr) {
            size_t fileSize = ((width) * (height) * (channels_in_file));

            gvd->setListItemImageData(ptr, fileSize);
#if !(defined(NDEBUG))
            std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
            n += "_listitem_stbi.jpg";
            stbi_write_jpg(n.c_str(), width, height, channels_in_file, ptr,
                           100);
#endif
        }
        delete fd;

        return true;
    }
    return fd;
}

GameModelViewData::GameModelViewData(const MLBJson::Game &game)
    : mHomeName(game.getTeams().getHome().getTeam().getName()),
      mAwayName(game.getTeams().getAway().getTeam().getName()),
      mDetailDescription(
          game.getContent().getEditorial().getRecap().getMlb().getBlurb()),
      mDetailImageTitle(game.getContent()
                            .getEditorial()
                            .getRecap()
                            .getMlb()
                            .getMedia()
                            .getHeadline()
                            .c_str()),
      mDetailImageDescription(game.getContent()
                                  .getEditorial()
                                  .getRecap()
                                  .getMlb()
                                  .getMedia()
                                  .getDescription()
                                  .c_str()),
      mDetailImageData(nullptr), mDetailImageUrl(""),
      mListItemDescription(game.getContent()
                               .getEditorial()
                               .getRecap()
                               .getMlb()
                               .getPhoto()
                               .getTitle()
                               .c_str()),
      mListItemImageData(nullptr), mListItemImageUrl("") {

    MLBJson::MlbMedia _media =
        game.getContent().getEditorial().getRecap().getMlb().getMedia();

    MLBJson::Cut largest_cut;
    int64_t largestSize = 0;
    for (std::vector<MLBJson::Cut>::const_iterator cut_iterator =
             _media.getImage().getCuts().begin();
         cut_iterator != _media.getImage().getCuts().end(); ++cut_iterator) {
        MLBJson::Cut cut = *cut_iterator;

        int64_t w = cut.getWidth();
        int64_t h = cut.getHeight();
        if ((w * h) > largestSize && UtilDSS::validUrl(cut.getSrc())) {
            largestSize = w * h;
            largest_cut = cut;
        }
    }

    mDetailImageUrl = largest_cut.getSrc().c_str();

    MLBJson::Photo _photo =
        game.getContent().getEditorial().getRecap().getMlb().getPhoto();

    largestSize = 0;
    for (std::map<std::string, MLBJson::Cut>::const_iterator cuts_iterator =
             _photo.getCuts().begin();
         cuts_iterator != _photo.getCuts().end(); ++cuts_iterator) {

        std::string key = cuts_iterator->first;
        MLBJson::Cut value = cuts_iterator->second;

        int64_t w = value.getWidth();
        int64_t h = value.getHeight();
        if ((w * h) > largestSize && UtilDSS::validUrl(value.getSrc())) {
            largestSize = w * h;
            largest_cut = value;
        }
    }

    mListItemImageUrl = largest_cut.getSrc().c_str();
}

GameModelViewData::~GameModelViewData() {

    if (nullptr != mDetailImageData)
        free(mDetailImageData);
    mDetailImageData = nullptr;
}

const std::string &GameModelViewData::getHomeName() const { return mHomeName; }

const std::string &GameModelViewData::getAwayName() const { return mAwayName; }

const std::string &GameModelViewData::getDetailDescription() const {
    return mDetailDescription;
}

const std::string &GameModelViewData::getDetailImageTitle() const {
    return mDetailImageTitle;
}

const std::string &GameModelViewData::getDetailImageDescription() const {
    return mDetailImageDescription;
}

void *GameModelViewData::getDetailImageData(int *width, int *height,
                                            int *channels_in_file,
                                            size_t *fileSize,
                                            bool downloadImage) {

    if (nullptr == mDetailImageData) {

        std::string base_path(SDL_GetBasePath());
        std::string defaultImage("assets/Default.png");
        base_path += defaultImage;

        mDetailImageData = (void *)stbi_load(base_path.c_str(), width, height,
                                             channels_in_file, 0);

        if (nullptr != mDetailImageData) {
            *fileSize = ((*width) * (*height) * (*channels_in_file));
        }

        if (downloadImage) {
            ThreadPool::getInstance()->enqueue(
                download_detailimage, getDetailImageUrl().c_str(), this);
        }
    }

    return mDetailImageData;
}

const std::string &GameModelViewData::getDetailImageUrl() const {
    return mDetailImageUrl;
}

void GameModelViewData::setDetailImageData(void *ptr, size_t size) {
    std::unique_lock<std::mutex> lock(mMutex);

    if (nullptr != mDetailImageData)
        free(mDetailImageData);

    mDetailImageData = ptr;
}

std::string GameModelViewData::getListItemTitle() const {
    std::string ret = getHomeName() + " vs " + getAwayName();
    return ret;
}

const std::string &GameModelViewData::getListItemDescription() const {
    return mListItemDescription;
}

void *GameModelViewData::getListItemImageData(int *width, int *height,
                                              int *channels_in_file,
                                              size_t *fileSize,
                                              bool downloadImage) {

    if (nullptr == mListItemImageData) {

        std::string base_path(SDL_GetBasePath());
        std::string defaultImage("assets/Default.png");
        base_path += defaultImage;

        mListItemImageData = (void *)stbi_load(base_path.c_str(), width, height,
                                               channels_in_file, 0);

        if (nullptr != mListItemImageData) {
            *fileSize = ((*width) * (*height) * (*channels_in_file));
        }

        if (downloadImage) {
            ThreadPool::getInstance()->enqueue(
                download_listitemimage, getListItemImageUrl().c_str(), this);
        }
    }

    return mListItemImageData;
}

const std::string &GameModelViewData::getListItemImageUrl() const {
    return mListItemImageUrl;
}

void GameModelViewData::setListItemImageData(void *ptr, size_t size) {
    std::unique_lock<std::mutex> lock(mMutex);

    if (nullptr != mListItemImageData)
        free(mListItemImageData);

    mListItemImageData = ptr;
}

void GameModelViewData::setImageData(const std::string &url, FileData *fd) {
    std::unique_lock<std::mutex> lock(mMutex);

    if (nullptr != fd) {
        int width, height, channels_in_file;
        void *ptr =
            stbi_load_from_memory((const stbi_uc *)fd->_buffer, fd->_size,
                                  &width, &height, &channels_in_file, 0);

        if (nullptr != ptr) {
            size_t fileSize = ((width) * (height) * (channels_in_file));

#if !(defined(NDEBUG))
            std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
            n += "_stbi.jpg";
            stbi_write_jpg(n.c_str(), width, height, channels_in_file, ptr,
                           100);
#endif
        }

        if (url == mListItemImageUrl) {
            if (nullptr != mListItemImageData)
                free(mListItemImageData);
            mListItemImageData = ptr;
        } else if (url == mDetailImageUrl) {
            if (nullptr != mDetailImageData)
                free(mDetailImageData);
            mDetailImageData = ptr;
        }

        notify(fd);
    }
}

static void multi_image_download(CURLM *multi_handle,
                                 const std::vector<CURL *> &handleList,
                                 std::vector<FileData *> &fileDataVector) {

    int still_running = 0; /* keep number of running handles */

    /* we start some action by calling perform right away */
    curl_multi_perform(multi_handle, &still_running);

    CURLMsg *msg;  /* for picking up messages with the transfer status */
    int msgs_left; /* how many messages are left */
    while (still_running) {
        struct timeval timeout;
        int rc;       /* select() return code */
        CURLMcode mc; /* curl_multi_fdset() return code */

        fd_set fdread;
        fd_set fdwrite;
        fd_set fdexcep;
        int maxfd = -1;

        long curl_timeo = -1;

        FD_ZERO(&fdread);
        FD_ZERO(&fdwrite);
        FD_ZERO(&fdexcep);

        /* set a suitable timeout to play around with */
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        curl_multi_timeout(multi_handle, &curl_timeo);
        if (curl_timeo >= 0) {
            timeout.tv_sec = curl_timeo / 1000;
            if (timeout.tv_sec > 1)
                timeout.tv_sec = 1;
            else
                timeout.tv_usec = (curl_timeo % 1000) * 1000;
        }

        /* get file descriptors from the transfers */
        mc =
            curl_multi_fdset(multi_handle, &fdread, &fdwrite, &fdexcep, &maxfd);

        if (mc != CURLM_OK) {
            fprintf(stderr, "curl_multi_fdset() failed, code %d.\n", mc);
            break;
        }

        /* On success the value of maxfd is guaranteed to be >= -1. We call
           select(maxfd + 1, ...); specially in case of (maxfd == -1) there
           are no fds ready yet so we call select(0, ...) --or Sleep() on
           Windows-- to sleep 100ms, which is the minimum suggested value in
           the curl_multi_fdset() doc. */

        if (maxfd == -1) {
#ifdef _WIN32
            Sleep(100);
            rc = 0;
#else
            /* Portable sleep for platforms other than Windows. */
            struct timeval wait = {0, 100 * 1000}; /* 100ms */
            rc = select(0, NULL, NULL, NULL, &wait);
#endif
        } else {
            /* Note that on some platforms 'timeout' may be modified by
             select(). If you need access to the original value save a
             copy beforehand. */
            rc = select(maxfd + 1, &fdread, &fdwrite, &fdexcep, &timeout);
        }

        switch (rc) {
        case -1:
            /* select error */
            break;
        case 0:  /* timeout */
        default: /* action */
            curl_multi_perform(multi_handle, &still_running);
            break;
        }
    }

    /* See how the transfers went */
    while ((msg = curl_multi_info_read(multi_handle, &msgs_left))) {
        if (msg->msg == CURLMSG_DONE) {
            int idx;

            /* Find out which handle this message is about */
            for (idx = 0; idx < handleList.size(); idx++) {
                int found = (msg->easy_handle == handleList[idx]);
                if (found)
                    break;
            }

            SDL_LogVerbose(SDL_LOG_CATEGORY_TEST,
                           "Transfer completed with status %d\n",
                           msg->data.result);
        }
    }

    while (!fileDataVector.empty()) {
        FileData *fd = fileDataVector.back();
        fd->_gvd_ptr->setImageData(fd->_url, fd);
        fileDataVector.pop_back();
        delete fd;
    }

    curl_multi_cleanup(multi_handle);
}

void GameModelViewData::loadGames(const std::vector<MLBJson::Game> &games,
                                  std::vector<GameModelViewData *> &gvdVector) {

    std::vector<CURL *> handleList;
    CURLM *multi_handle = curl_multi_init();

    std::vector<FileData *> fileDataVector;
    FileData *fd = nullptr;

    for (std::vector<MLBJson::Game>::const_iterator iter = games.begin();
         iter != games.end(); ++iter) {

        GameModelViewData *gvd = new GameModelViewData(*iter);
        gvdVector.push_back(gvd);

        fd = new FileData(MAX_IMAGE_WIDTH, MAX_IMAGE_HEIGHT,
                          MAX_IMAGE_COMPONENTS);
        fd->_url = gvd->getDetailImageUrl();
        fd->_gvd_ptr = gvd;
        curl_easy_setopt(fd->_curlCtx, CURLOPT_URL, fd->_url.c_str());
        curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEDATA, fd);
        curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
        curl_easy_setopt(fd->_curlCtx, CURLOPT_FOLLOWLOCATION, 1);
        curl_multi_add_handle(multi_handle, fd->_curlCtx);
        fileDataVector.push_back(fd);

        fd = new FileData(MAX_IMAGE_WIDTH, MAX_IMAGE_HEIGHT,
                          MAX_IMAGE_COMPONENTS);
        fd->_url = gvd->getListItemImageUrl();
        fd->_gvd_ptr = gvd;
        curl_easy_setopt(fd->_curlCtx, CURLOPT_URL, fd->_url.c_str());
        curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEDATA, fd);
        curl_easy_setopt(fd->_curlCtx, CURLOPT_WRITEFUNCTION, callbackfunction);
        curl_easy_setopt(fd->_curlCtx, CURLOPT_FOLLOWLOCATION, 1);
        curl_multi_add_handle(multi_handle, fd->_curlCtx);
        fileDataVector.push_back(fd);
    }

    ThreadPool::getInstance()->enqueue(multi_image_download, multi_handle,
                                       handleList, fileDataVector);
}

void GameModelViewData::update(Publisher *who, void *userdata) {
    GameModelViewData *completed_me = dynamic_cast<GameModelViewData *>(who);
    FileData *fd = static_cast<FileData *>(userdata);

    if (nullptr != completed_me && nullptr != fd) {
        SDL_LogVerbose(SDL_LOG_CATEGORY_TEST,
                       "This image is now loaded. (%s)\n", fd->_url.c_str());
    }
}
