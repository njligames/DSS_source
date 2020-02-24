class SDL_Renderer;
class SDL_Window;

#include <mutex>
#include <vector>

#include "PubSub.h"
#include "Shader.h"
#include "curl.h"

class GameModelData;
class BitmapFont;
class GameModelData;

class TestClass {
    static TestClass *sInstance;
    TestClass();
    TestClass(SDL_Window *window, SDL_Renderer *renderer);
    virtual ~TestClass();

    TestClass(const TestClass &rhs) = delete;
    TestClass &operator=(const TestClass &rhs) = delete;

  public:
    static void create();
    static void create(SDL_Window *window, SDL_Renderer *renderer);
    static void destroy();
    static TestClass *get();

  public:
    bool loadfile(SDL_Renderer *renderer);

    void reset(int n);
    int increment(int n);

    void init();
    void unInit();
    void update();
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
};
