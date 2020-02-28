class SDL_Renderer;
class SDL_Window;

#include <mutex>
#include <vector>

#include "PubSub.h"

#include "Camera.h"
#include "Geometry.h"
#include "Node.h"
#include "Scene.h"
#include "Shader.h"

#include "curl.h"

class GameModelData;
class BitmapFont;
class GameModelData;

class TestClass {
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
    NJLIC::Geometry *mGeometry;
    NJLIC::Geometry *mFontGeometry;
    NJLIC::Camera *mCamera;
    NJLIC::Node *mCameraNode;
    NJLIC::Scene *mScene;
    std::vector<NJLIC::Node *> mCubeNodes;
    float m_Rotation = 0.0;
};
