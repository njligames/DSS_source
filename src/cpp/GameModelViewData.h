//
//  GameModelViewData.h
//  SDLSkeleton
//
//  Created by James Folk on 2/21/20.
//

#ifndef GameViewData_h
#define GameViewData_h

#include "MLBJsonModel.h"
#include "PubSub.h"
#include "ThreadPool.h"
#include <mutex>  // std::mutex
#include <thread> // std::thread

#include "Node.h"
#include "Shader.h"
#include "SpriteGeometry.h"

struct FileData;

class GameModelViewData : public Publisher, public Subscriber {
    std::string mHomeName;
    std::string mAwayName;

    std::string mDetailDescription;

    std::string mDetailImageTitle;
    std::string mDetailImageDescription;
    void *mDetailImageData;
    std::string mDetailImageUrl;

    std::string mListItemDescription;
    void *mListItemImageData;
    bool mReceivedListItemData = false;
    std::string mListItemImageUrl;
    std::thread *mListItemImageThread;

    GameModelViewData() = delete;
    GameModelViewData(const GameModelViewData &) = delete;
    const GameModelViewData &operator=(const GameModelViewData &) = delete;

    std::mutex mMutex;

    NJLIC::Node *mImageNode;
    NJLIC::SpriteGeometry *mImageGeometry;

    NJLIC::Shader *mpImageShader;


  public:
    GameModelViewData(const MLBJson::Game &game);
    ~GameModelViewData();

    void load(NJLIC::Shader *imageShader);
    NJLIC::Node *getImageNode() const { return mImageNode; }

    const std::string &getHomeName() const;
    const std::string &getAwayName() const;

    const std::string &getDetailDescription() const;
    const std::string &getDetailImageTitle() const;
    const std::string &getDetailImageDescription() const;
    void *getDetailImageData(int *width, int *height, int *channels_in_file,
                             size_t *fileSize, bool downloadImage = false);
    const std::string &getDetailImageUrl() const;
    void setDetailImageData(void *ptr, size_t size);
    bool receivedDetailImageData() const;

    std::string getListItemTitle() const;
    const std::string &getListItemDescription() const;
    void *getListItemImageData(int *width, int *height, int *channels_in_file,
                               size_t *fileSize, bool downloadImage = false);
    const std::string &getListItemImageUrl() const;
    void setListItemImageData(void *ptr, size_t size);
    bool receivedListItemImageData() const;

    void setImageData(const std::string &url, FileData *fd);

    static void loadGames(const std::vector<MLBJson::Game> &games,
                          std::vector<GameModelViewData *> &gvdVector);

    virtual void update(Publisher *who, void *userdata = 0);

    virtual void render();

  protected:
    bool download_jpeg(const char *url,
                       size_t (*fun_ptr)(void *ptr, size_t size, size_t nmemb,
                                         void *userdata));
    
};

#endif /* GameViewData_h */
