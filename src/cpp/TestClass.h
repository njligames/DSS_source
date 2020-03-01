class SDL_Renderer;
class SDL_Window;

#include <mutex>
#include <vector>

#include "PubSub.h"

#include "Camera.h"
#include "Node.h"
#include "Scene.h"
#include "Shader.h"
#include "SpriteGeometry.h"

#include "curl.h"

class GameModelViewData;
class GameModelData;
class BitmapFont;
class GameModelData;

class TestClass : public Subscriber {
    static TestClass *sInstance;
    TestClass();
    virtual ~TestClass();

    TestClass(const TestClass &rhs) = delete;
    TestClass &operator=(const TestClass &rhs) = delete;

  public:
    static void createInstance();
    //    static void create(SDL_Window *window, SDL_Renderer *renderer);
    static void destroyInstance();
    static TestClass *getInstance();

  public:
    bool loadfile(SDL_Renderer *renderer);

    void reset(int n);
    int increment(int n);

    void init(const unsigned int numCards);
    void unInit();
    void update(float step);
    void render();
    void input();

    void resize(int w, int h);

    bool isDone() const;

    void keyDown(const std::string &keycodeName, bool withCapsLock,
                 bool withControl, bool withShift, bool withAlt, bool withGui);
    void keyUp(const std::string &keycodeName, bool withCapsLock,
               bool withControl, bool withShift, bool withAlt, bool withGui);

    virtual void update(Publisher *who, void *userdata = 0) override;

  protected:
    static std::string loadStringData(char *path);

  private:
    //    int mNum;
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    std::mutex mMutex;
    bool mIsDone;

    std::vector<GameModelData *> mGameModelDataVector;

    NJLIC::Shader *mShader;
    //    NJLIC::SpriteGeometry *mGeometry;
    NJLIC::Camera *mCamera;
    NJLIC::Node *mCameraNode;
    NJLIC::Scene *mScene;
    std::vector<NJLIC::Node *> mCubeNodes;
    float m_Rotation = 0.0;

    //        unsigned char *mBufferData0;
    //        int mwidth0, mheight0, mchannels_in_file0;
    //
    //    unsigned char *mBufferData1;
    //    int mwidth1, mheight1, mchannels_in_file1;
    //    float mstep;
    //    int control;

    std::vector<GameModelViewData *> mGameModelViewVector;
    GameModelViewData *mpSelectedNode = nullptr;
    int mSelectedIndex = 0;

    int mNumItemsReeachDestination = 0;
    bool mIsScrolling = false;
};
