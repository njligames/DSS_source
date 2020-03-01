#include "TestClass.h"

#include "SDL.h"

#include <string>

#include "MLBJsonModel.h"

#include "GameModelData.h"
#include "GameModelViewData.h"

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#include "BitmapFont.h"

#include "Date.h"
#include "GameCard.h"
#include "UtilDSS.h"

#include "Camera.h"
#include "Geometry.h"

#include "BackgroundRenderer.h"

#include "MeshGeometry.h"
#include "SpriteGeometry.h"

#include "ListItemNode.h"

static void UpdateFrame(void *param) {
    //  njli::NJLIGameEngine::update(1.0f / ((float)gDisplayMode.refresh_rate));

    //        TestClass::getInstance()->update(0.06);
    //    TestClass::get()->render();

    //  Graphics *graphics = (Graphics *)param;
    //  graphics->update();
}

static SDL_Texture *LoadTexture(SDL_Renderer *renderer, char *file,
                                SDL_bool transparent) {
    SDL_Surface *temp;
    SDL_Texture *texture;

    /* Load the sprite image */
    temp = SDL_LoadBMP(file);
    if (temp == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't load %s: %s", file,
                     SDL_GetError());
        return NULL;
    }

    /* Set transparent pixel as the pixel at (0,0) */
    if (transparent) {
        if (temp->format->palette) {
            SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *)temp->pixels);
        } else {
            switch (temp->format->BitsPerPixel) {
            case 15:
                SDL_SetColorKey(temp, SDL_TRUE,
                                (*(Uint16 *)temp->pixels) & 0x00007FFF);
                break;
            case 16:
                SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *)temp->pixels);
                break;
            case 24:
                SDL_SetColorKey(temp, SDL_TRUE,
                                (*(Uint32 *)temp->pixels) & 0x00FFFFFF);
                break;
            case 32:
                SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *)temp->pixels);
                break;
            }
        }
    }

    /* Create textures from the image */
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return NULL;
    }
    SDL_FreeSurface(temp);

    /* We're ready to roll. :) */
    return texture;
}

TestClass *TestClass::sInstance = nullptr;

TestClass::TestClass()
    : mWindow(nullptr), mRenderer(nullptr), mIsDone(true),
      mShader(new NJLIC::Shader()), // mGeometry(new NJLIC::SpriteGeometry()),
      mCamera(new NJLIC::Camera()), mCameraNode(new NJLIC::Node()),
      mScene(new NJLIC::Scene()) {}

// TestClass::TestClass(SDL_Window *window, SDL_Renderer *renderer)
//    : mWindow(window), mRenderer(renderer), mIsDone(true) {}

TestClass::~TestClass() {

    while (!mCubeNodes.empty()) {
        NJLIC::Node *node = mCubeNodes.back();
        mCubeNodes.pop_back();
        delete node;
    }

    delete mScene;
    mScene = nullptr;

    delete mCameraNode;
    mCameraNode = nullptr;

    delete mCamera;
    mCamera = nullptr;

    //    delete mGeometry;
    //    mGeometry = nullptr;

    delete mShader;
    mShader = nullptr;

    NJLIC::BackgroundRenderer::destroyInstance();
    BitmapFont::destroyInstance();
    ThreadPool::destroyInstance();

    unInit();
}

void TestClass::createInstance() {
    if (nullptr == sInstance)
        sInstance = new TestClass();
}

// void TestClass::create(SDL_Window *window, SDL_Renderer *renderer) {
//    if (nullptr != window && nullptr != renderer) {
//        if (nullptr == sInstance)
//            sInstance = new TestClass(window, renderer);
//    }
//}

void TestClass::destroyInstance() {
    if (nullptr != sInstance)
        delete sInstance;
    sInstance = nullptr;
}

TestClass *TestClass::getInstance() { return sInstance; }

bool TestClass::loadfile(SDL_Renderer *renderer) {
    int w, h;

    SDL_Texture *sprite =
        LoadTexture(renderer, (char *)"assets/sample.bmp", SDL_TRUE);
    if (nullptr == sprite) {
        SDL_Log("Could not find the sprite");
        return false;
    } else {
        SDL_QueryTexture(sprite, NULL, NULL, &w, &h);
        SDL_Log("Width: %d, Height: %d", w, h);
    }
    return true;
}

void TestClass::init(const unsigned int numCards) {
    //    mMutex.lock();
    mIsDone = false;
    //    mMutex.unlock();

#define TEST_DL

#ifdef TEST_DL
    int numberOfDaysToGoBack((365 * 4) + 1);
    numberOfDaysToGoBack = 1;
    NJLIC::Date formatted_date(6, 10, 2018);
    NJLIC::Date formatted_date2(6, 9, 2018);
    NJLIC::Date today;

    GameModelData *gmd = GameModelData::generateGameModelData(formatted_date);

    mGameModelDataVector.push_back(gmd);

//    NJLIC::Date date(formatted_date);
//    for (int i = 0; i < numberOfDaysToGoBack; ++i, date--) {
//
//        printf("%s\n", std::string(date).c_str());
//        mGameModelDataVector.push_back(
//            GameModelData::generateGameModelData(date));
//    }
#endif

    //    mShader = new NJLIC::Shader();
    //
    //    size_t vsSize = 0;
    //    char *vsFileBuffer = UtilDSS::loadFile("assets/shaders/shader.vsh",
    //    vsSize); const std::string vertexSource(vsFileBuffer);
    //
    //    size_t fsSize = 0;
    //    char *fsFileBuffer = UtilDSS::loadFile("assets/shaders/shader.fsh",
    //    fsSize); const std::string fragmentSource(fsFileBuffer);

    //    if (mShader->load(vertexSource, fragmentSource)) {
    //        GameCard *pGameCard = new GameCard();
    //        NJLIC::Camera *pCamera = new NJLIC::Camera();
    //        NJLIC::Geometry *pGeometry = new NJLIC::Geometry();
    //    }

    //    mstep = 0;
    //    control = 0;

    UtilDSS::printGLInfo();

    BitmapFont::getInstance()->setCurrentFontName("FranklinGothicMedium");
    //    BitmapFont::getInstance()->printf("%s - %d", "jimbo", 100);

    GLclampf red, green, blue;
    red = green = blue = (254.0 / 255.0);

    glClearColor(red, green, blue, 1.0f);
    //    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);

    NJLIC::BackgroundRenderer::getInstance()->init();

    mCameraNode->addCamera(mCamera);
    mCameraNode->setOrigin(glm::vec3(0.0f, 0.0f, 0.0f));

    mScene->addActiveNode(mCameraNode);
    mScene->addActiveCamera(mCamera);
    mScene->getRootNode()->setOrigin(glm::vec3(0.0f, 0.0f, 10.0f));

    bool loaded = false;

    const char *vertShader =
        UtilDSS::loadFile("assets/shaders/StandardShader2.vert");
    const char *fragShader =
        UtilDSS::loadFile("assets/shaders/StandardShader2.frag");

    if (nullptr != vertShader && nullptr != fragShader) {
        const std::string &vertexSource(vertShader);
        const std::string &fragmentSource(fragShader);

        if (mShader->load(vertexSource, fragmentSource)) {
            const char *objData = UtilDSS::loadFile("assets/models/sprite.obj");
        }
    }
}
void TestClass::unInit() {
    while (!mGameModelDataVector.empty()) {
        GameModelData *gmd = mGameModelDataVector.back();
        delete gmd;
        mGameModelDataVector.pop_back();
    }
}
void TestClass::update(float step) {

    mScene->update(step);
}
void TestClass::render() {
    mMutex.lock();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glDisable(GL_DEPTH_TEST);
    NJLIC::BackgroundRenderer::getInstance()->render(1920, 1080);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, 1920 * 2, 1920 * 2);

    for (int i = 0; i < mGameModelViewVector.size(); i++) {
        GameModelViewData *gmvd = mGameModelViewVector.at(i);
        gmvd->render();
    }
    mScene->render();

    // This has to go on the render function because update is called
    // asynchronously.

    const float tileWidth = 0.888888895f;

    float start_x = -3.0f;
    float x_inc = tileWidth;
    float x_gutter_selected = tileWidth / 2.f;
    float x_gutter = tileWidth / 10.f;

    float x = start_x;
    for (int i = 0; i < mGameModelDataVector.size(); i++) {
        GameModelData *gmd = mGameModelDataVector.at(i);
        if (nullptr != gmd && mGameModelViewVector.size() == 0 &&
            gmd->hasGames()) {
            gmd->getGameModelViewVector(mGameModelViewVector);

            for (int j = 0; j < mGameModelViewVector.size(); j++) {
                GameModelViewData *gmvd = mGameModelViewVector.at(j);

                gmvd->load(mScene, mShader);

                ListItemNode *imageNode = gmvd->getNode();

                imageNode->subscribe(this);

                imageNode->setName(std::to_string(j));

                float prev_x(x - (x_inc + x_gutter_selected));
                float next_x(x + (x_inc + x_gutter_selected));
                imageNode->setOrigin(glm::vec3(x, -1.5, 0));

                imageNode->setPreviousPosition(glm::vec3(prev_x, -1.5, 0));
                imageNode->setNextPosition(glm::vec3(next_x, -1.5, 0));

                if (0 == j) {
                    gmvd->setSelected(true);
                    mpSelectedNode = gmvd;

                    x += x_inc;
                    x += x_gutter_selected;
                } else {
                    x += x_inc;
                    x += x_gutter_selected;
                }
            }
        }
    }
    mMutex.unlock();
}

void TestClass::input() {
    mMutex.lock();

    bool callFinishKeys = false;
    SDL_Event event;
    SDL_PumpEvents();
    while (SDL_PollEvent(&event)) {
        //        njli::NJLIGameEngine::handleEvent(&event);
        //        SDLTest_PrintEvent(&event);
        switch (event.type) {

#if defined(__MACOSX__) || defined(__EMSCRIPTEN__) || defined(__ANDROID__)
        case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:

            //            NJLI_HandleMouse(event.button.button,
            //            event.type, event.button.x,
            //                             event.button.y,
            //                             event.button.clicks);
            break;
#endif

#if (defined(__ANDROID__) && __ANDROID__)
        case SDL_FINGERMOTION:
        case SDL_FINGERDOWN:
        case SDL_FINGERUP:
            //            NJLI_HandleTouch((int)event.tfinger.touchId,
            //                             (int)event.tfinger.fingerId,
            //                             event.type, event.tfinger.x,
            //                             event.tfinger.y,
            //                             event.tfinger.dx,
            //                             event.tfinger.dy,
            //                             event.tfinger.pressure);
            break;
#endif
        case SDL_APP_DIDENTERFOREGROUND:
            SDL_Log("SDL_APP_DIDENTERFOREGROUND");

#if (defined(__IPHONEOS__) && __IPHONEOS__)
            SDL_iPhoneSetAnimationCallback(mWindow, 1, UpdateFrame, nullptr);
#endif
            //            NJLI_HandleResume();
            break;

        case SDL_APP_DIDENTERBACKGROUND:
            SDL_Log("SDL_APP_DIDENTERBACKGROUND");

            //            njli::NJLIGameEngine::didEnterBackground();
            break;

        case SDL_APP_LOWMEMORY:
            SDL_Log("SDL_APP_LOWMEMORY");
            //            NJLI_HandleLowMemory();

            break;

        case SDL_APP_TERMINATING:
            SDL_Log("SDL_APP_TERMINATING");
            //            njli::NJLIGameEngine::willTerminate();
            break;

        case SDL_APP_WILLENTERBACKGROUND:
            SDL_Log("SDL_APP_WILLENTERBACKGROUND");
#if (defined(__IPHONEOS__) && __IPHONEOS__)
            SDL_iPhoneSetAnimationCallback(mWindow, 1, NULL, nullptr);
#endif
            //            NJLI_HandlePause();
            break;

        case SDL_APP_WILLENTERFOREGROUND:
            SDL_Log("SDL_APP_WILLENTERFOREGROUND");

            //            njli::NJLIGameEngine::willEnterForeground();
            break;

        case SDL_WINDOWEVENT:
            switch (event.window.event) {
            case SDL_WINDOWEVENT_RESTORED:
                //                NJLI_HandleResume();
                break;
            case SDL_WINDOWEVENT_MINIMIZED:
                //                NJLI_HandlePause();
                break;
            case SDL_WINDOWEVENT_RESIZED:
            case SDL_WINDOWEVENT_SIZE_CHANGED: {
                int w, h;
#if defined(__MACOSX__)
                SDL_GetWindowSize(mWindow, &w, &h);
#else
                SDL_GL_GetDrawableSize(mWindow, &w, &h);
#endif
                TestClass::getInstance()->resize(w, h);

                //                  NJLI_HandleResize(w, h,
                //                  gDisplayMode.format,
                //                                    gDisplayMode.refresh_rate);
            } break;
            case SDL_WINDOWEVENT_CLOSE: {
                SDL_Window *window = SDL_GetWindowFromID(event.window.windowID);
                if (window) {
                    if (window == mWindow) {
                        SDL_DestroyWindow(mWindow);
                        mWindow = nullptr;
                        break;
                    }
                }
            } break;
            }
            break;
        case SDL_KEYUP: {
            callFinishKeys = true;
            int temp = SDL_GetModState();
            temp = temp & KMOD_CAPS;
            bool withCapsLock = (temp == KMOD_CAPS);

            bool withControl = !!(event.key.keysym.mod & KMOD_CTRL);
            bool withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
            bool withAlt = !!(event.key.keysym.mod & KMOD_ALT);
            bool withGui = !!(event.key.keysym.mod & KMOD_GUI);

            //              NJLI_HandleKeyUp(SDL_GetScancodeName(event.key.keysym.scancode),
            //                               withCapsLock,
            //                               withControl, withShift,
            //                               withAlt, withGui);
        } break;
        case SDL_KEYDOWN: {
            callFinishKeys = true;
            int temp = SDL_GetModState();
            temp = temp & KMOD_CAPS;
            bool withCapsLock = (temp == KMOD_CAPS);

            bool withControl = !!(event.key.keysym.mod & KMOD_CTRL);
            bool withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
            bool withAlt = !!(event.key.keysym.mod & KMOD_ALT);
            bool withGui = !!(event.key.keysym.mod & KMOD_GUI);

            //              NJLI_HandleKeyDown(SDL_GetScancodeName(event.key.keysym.scancode),
            //                                 withCapsLock,
            //                                 withControl,
            //                                 withShift, withAlt,
            //                                 withGui);

            switch (event.key.keysym.sym) {
            /* Add hotkeys here */
            case SDLK_PRINTSCREEN: {
                SDL_Window *window = SDL_GetWindowFromID(event.key.windowID);
                if (window) {
                    if (window == mWindow) {
                        //                            SDLTest_ScreenShot(mRenderer);
                    }
                }
            } break;
            case SDLK_EQUALS:
                if (withControl) {
                    /* Ctrl-+ double the size of the window
                     */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        int w, h;
                        SDL_GetWindowSize(window, &w, &h);
                        SDL_SetWindowSize(window, w * 2, h * 2);
                    }
                }
                break;
            case SDLK_MINUS:
                if (withControl) {
                    /* Ctrl-- half the size of the window */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        int w, h;
                        SDL_GetWindowSize(window, &w, &h);
                        SDL_SetWindowSize(window, w / 2, h / 2);
                    }
                }
                break;
            case SDLK_o:
                if (withControl) {
#if !defined(__LINUX__)
                    /* Ctrl-O (or Ctrl-Shift-O) changes
                     * window opacity. */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        float opacity;
                        if (SDL_GetWindowOpacity(window, &opacity) == 0) {
                            if (withShift) {
                                opacity += 0.20f;
                            } else {
                                opacity -= 0.20f;
                            }
                            SDL_SetWindowOpacity(window, opacity);
                        }
                    }
#endif
                }
                break;

            case SDLK_c:
                if (withControl) {
                    /* Ctrl-C copy awesome text! */
                    SDL_SetClipboardText("SDL rocks!\nYou know it!");
                    printf("Copied text to clipboard\n");
                }
                if (withAlt) {
                    /* Alt-C toggle a render clip rectangle
                     */
                    int w, h;
                    if (mRenderer) {
                        SDL_Rect clip;
                        SDL_GetWindowSize(mWindow, &w, &h);
                        SDL_RenderGetClipRect(mRenderer, &clip);
                        if (SDL_RectEmpty(&clip)) {
                            clip.x = w / 4;
                            clip.y = h / 4;
                            clip.w = w / 2;
                            clip.h = h / 2;
                            SDL_RenderSetClipRect(mRenderer, &clip);
                        } else {
                            SDL_RenderSetClipRect(mRenderer, NULL);
                        }
                    }
                }
                if (withShift) {
                    SDL_Window *current_win = SDL_GetKeyboardFocus();
                    if (current_win) {
                        const bool shouldCapture =
                            (SDL_GetWindowFlags(current_win) &
                             SDL_WINDOW_MOUSE_CAPTURE) == 0;
                        const int rc =
                            SDL_CaptureMouse((SDL_bool)shouldCapture);
                        SDL_Log("%sapturing mouse %s!\n",
                                shouldCapture ? "C" : "Unc",
                                (rc == 0) ? "succeeded" : "failed");
                    }
                }
                break;
            case SDLK_v:
                if (withControl) {
                    /* Ctrl-V paste awesome text! */
                    char *text = SDL_GetClipboardText();
                    if (*text) {
                        printf("Clipboard: %s\n", text);
                    } else {
                        printf("Clipboard is empty\n");
                    }
                    SDL_free(text);
                }
                break;
            case SDLK_g:
                if (withControl) {
                    /* Ctrl-G toggle grab */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        SDL_SetWindowGrab(window, !SDL_GetWindowGrab(window)
                                                      ? SDL_TRUE
                                                      : SDL_FALSE);
                    }
                }
                break;
            case SDLK_m:
                if (withControl) {
                    /* Ctrl-M maximize */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        Uint32 flags = SDL_GetWindowFlags(window);
                        if (flags & SDL_WINDOW_MAXIMIZED) {
                            SDL_RestoreWindow(window);
                        } else {
                            SDL_MaximizeWindow(window);
                        }
                    }
                }
                break;
            case SDLK_r:
                if (withControl) {
                    /* Ctrl-R toggle mouse relative mode */
                    SDL_SetRelativeMouseMode(
                        !SDL_GetRelativeMouseMode() ? SDL_TRUE : SDL_FALSE);
                }
                break;
            case SDLK_z:
                if (withControl) {
                    /* Ctrl-Z minimize */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        SDL_MinimizeWindow(window);
                    }
                }
                break;
            case SDLK_RETURN:
                if (withControl) {
                    /* Ctrl-Enter toggle fullscreen */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        Uint32 flags = SDL_GetWindowFlags(window);
                        if (flags & SDL_WINDOW_FULLSCREEN) {
                            SDL_SetWindowFullscreen(window, SDL_FALSE);
                        } else {
                            SDL_SetWindowFullscreen(window,
                                                    SDL_WINDOW_FULLSCREEN);
                        }
                    }
                } else if (withAlt) {
                    /* Alt-Enter toggle fullscreen desktop
                     */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        Uint32 flags = SDL_GetWindowFlags(window);
                        if (flags & SDL_WINDOW_FULLSCREEN) {
                            SDL_SetWindowFullscreen(window, SDL_FALSE);
                        } else {
                            SDL_SetWindowFullscreen(
                                window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        }
                    }
                } else if (withShift) {
                    /* Shift-Enter toggle fullscreen desktop
                     * / fullscreen */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        Uint32 flags = SDL_GetWindowFlags(window);
                        if ((flags & SDL_WINDOW_FULLSCREEN_DESKTOP) ==
                            SDL_WINDOW_FULLSCREEN_DESKTOP) {
                            SDL_SetWindowFullscreen(window,
                                                    SDL_WINDOW_FULLSCREEN);
                        } else {
                            SDL_SetWindowFullscreen(
                                window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        }
                    }
                }

                break;
            case SDLK_b:
                if (withControl) {
                    /* Ctrl-B toggle window border */
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window) {
                        const Uint32 flags = SDL_GetWindowFlags(window);
                        const SDL_bool b =
                            ((flags & SDL_WINDOW_BORDERLESS) != 0) ? SDL_TRUE
                                                                   : SDL_FALSE;
                        SDL_SetWindowBordered(window, b);
                    }
                }
                break;
            case SDLK_a:
                if (withControl) {
                    /* Ctrl-A reports absolute mouse
                     * position. */
                    int x, y;
                    const Uint32 mask = SDL_GetGlobalMouseState(&x, &y);
                    SDL_Log("ABSOLUTE MOUSE: (%d, "
                            "%d)%s%s%s%s%s\n",
                            x, y, (mask & SDL_BUTTON_LMASK) ? " [LBUTTON]" : "",
                            (mask & SDL_BUTTON_MMASK) ? " [MBUTTON]" : "",
                            (mask & SDL_BUTTON_RMASK) ? " [RBUTTON]" : "",
                            (mask & SDL_BUTTON_X1MASK) ? " [X2BUTTON]" : "",
                            (mask & SDL_BUTTON_X2MASK) ? " [X2BUTTON]" : "");
                }
                break;
            case SDLK_0:
                if (withControl) {
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                             "Test Message", "You're awesome!",
                                             window);
                }
                break;
            case SDLK_1:
                if (withControl) {
                    //                      FullscreenTo(0,
                    //                      event.key.windowID);
                }
                break;
            case SDLK_2:
                if (withControl) {
                    //                      FullscreenTo(1,
                    //                      event.key.windowID);
                }
                break;
            case SDLK_ESCAPE:
                mMutex.lock();
                mIsDone = true;
                mMutex.unlock();
                break;
            case SDLK_SPACE: { /*
                                char message[256];
                                SDL_Window *window =
                                    SDL_GetWindowFromID(event.key.windowID);
                                SDL_snprintf(message,
                                sizeof(message),
                                             "(%i, %i), rel
                                (%i, %i)\n", gLastEvent.x,
                                             gLastEvent.y,
                                gLastEvent.xrel,
                                             gLastEvent.yrel);
                                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                                         "Last
                                mouse position", message,
                                                         window);*/
                break;
            }
            default:
                break;
            }
            break;
        }
        case SDL_QUIT:

            //            NJLI_HandleQuit();

            break;

        case SDL_MOUSEWHEEL:
            SDL_Log("SDL EVENT: Mouse: wheel scrolled %d in x and %d in y "
                    "(reversed: %d) in window %d",
                    event.wheel.x, event.wheel.y, event.wheel.direction,
                    event.wheel.windowID);
            //            gXOffset -= (event.wheel.x * 1);
            //            gYOffset -= (event.wheel.y * 1);
            //            NJLI_HandleResize(gDisplayMode.w,
            //            gDisplayMode.h,
            //                              gDisplayMode.format,
            //                              gDisplayMode.refresh_rate);
            // SDL_MouseWheelEvent wheel = event.wheel;

            break;
        case SDL_DROPFILE: {
            char *dropped_filedir = event.drop.file;
            //              NJLI_HandleDropFile(dropped_filedir);
            SDL_free(dropped_filedir);
        } break;
#if !defined(__LINUX__)
        case SDL_DROPTEXT: {
            char *dropped_filedir = event.drop.file;
            //              NJLI_HandleDropFile(dropped_filedir);
            SDL_free(dropped_filedir);
        } break;
        case SDL_DROPBEGIN: {
            printf("Dropped file begin: %u\n", event.drop.windowID);
        } break;
        case SDL_DROPCOMPLETE: {
            printf("Dropped file begin: %u\n", event.drop.windowID);
        }
#endif
        break;
        default:
            break;
        }
    }

    //    if (callFinishKeys)
    //      NJLI_HandleKeyboardFinish(SDL_GetKeyboardState(NULL),
    //      SDL_NUM_SCANCODES);

#if !(defined(__MACOSX__) && __MACOSX__)
#endif

    mMutex.unlock();
}

void TestClass::resize(int w, int h) {}

bool TestClass::isDone() const { return mIsDone; }

static int randi(int lo, int hi) {
    int n = hi - lo + 1;
    int i = rand() % n;
    if (i < 0)
        i = -i;
    return lo + i;
}
void TestClass::keyDown(const std::string &keycodeName, bool withCapsLock,
                        bool withControl, bool withShift, bool withAlt,
                        bool withGui) {
    bool updated = false;

    if (keycodeName == "Right") {
        if (!mIsScrolling && mSelectedIndex < mGameModelViewVector.size() - 1) {

            mpSelectedNode->setSelected(false);

            mSelectedIndex++;

            mpSelectedNode = mGameModelViewVector.at(mSelectedIndex);
            mpSelectedNode->setSelected(true);

            int algo = randi(0, 30);
            algo = 15;
            printf("chose algo %d\n", algo);
            for (int j = 0; j < mGameModelViewVector.size(); j++) {
                GameModelViewData *gmvd = mGameModelViewVector.at(j);
                ListItemNode *imageNode = gmvd->getNode();
                imageNode->scrollPrevious(1.f, algo);
            }
            mIsScrolling = true;
        }
    } else if (keycodeName == "Left") {
        if (!mIsScrolling && mSelectedIndex > 0) {
            mpSelectedNode->setSelected(false);

            mSelectedIndex--;

            mpSelectedNode = mGameModelViewVector.at(mSelectedIndex);
            mpSelectedNode->setSelected(true);

            int algo = randi(0, 30);
            algo = 5;
            printf("chose algo %d\n", algo);
            for (int j = 0; j < mGameModelViewVector.size(); j++) {
                GameModelViewData *gmvd = mGameModelViewVector.at(j);
                ListItemNode *imageNode = gmvd->getNode();
                imageNode->scrollNext(1.f, algo);
            }
            mIsScrolling = true;
        }
    } else if (keycodeName == "Return") {
        SDL_LogVerbose(SDL_LOG_CATEGORY_TEST, "pressed enter\n");
    }

    if (updated) {
        const float tileWidth = 0.888888895f;

        float start_x = -3.0f;
        float x_inc = tileWidth;
        float x_gutter_selected = tileWidth / 2.f;
        float x_gutter = tileWidth / 10.f;

        float x = start_x;

        for (int i = 0; i < mGameModelViewVector.size(); i++) {
            GameModelViewData *gmvd = mGameModelViewVector.at(i);

            //            NJLIC::Node *imageNode = gmvd->getImageNode();
            NJLIC::Node *imageNode = gmvd->getNode();

            imageNode->setOrigin(glm::vec3(x, -1.5, 0));

            if (mpSelectedNode == gmvd) {
                x += x_inc;
                x += x_gutter_selected;
            } else {
                if (i + 1 < mGameModelViewVector.size()) {
                    GameModelViewData *gmvd_next = mGameModelViewVector.at(i);

                    if (gmvd_next == mpSelectedNode) {
                        x += x_inc;
                        x += x_gutter_selected;
                    }
                } else {
                    x += x_inc;
                    x += x_gutter;
                }
            }
        }
    }
}



void TestClass::keyUp(const std::string &keycodeName, bool withCapsLock,
                      bool withControl, bool withShift, bool withAlt,
                      bool withGui) {

    
}

void TestClass::update(Publisher *who, void *userdata) {
    ListItemNode *lin = dynamic_cast<ListItemNode *>(who);

    if (nullptr != lin) {

        ++mNumItemsReeachDestination;

        if (mNumItemsReeachDestination >= mGameModelViewVector.size()) {
            mNumItemsReeachDestination = 0;
            mIsScrolling = false;

            const float tileWidth = 0.888888895f;

            float x_inc = tileWidth;
            float x_gutter_selected = tileWidth / 2.f;
            float x_gutter = tileWidth / 10.f;

            //            printf("REACHED\n");

            for (int j = 0; j < mGameModelViewVector.size(); j++) {
                GameModelViewData *gmvd = mGameModelViewVector.at(j);

                ListItemNode *imageNode = gmvd->getNode();

                glm::vec3 o(imageNode->getOrigin());

                float prev_x(o.x - (x_inc + x_gutter_selected));
                float next_x(o.x + (x_inc + x_gutter_selected));

                imageNode->setPreviousPosition(glm::vec3(prev_x, -1.5, 0));
                imageNode->setNextPosition(glm::vec3(next_x, -1.5, 0));
            }
        }
    }
}
std::string TestClass::loadStringData(char *path) {
    void *buffer = nullptr;
    long fileSize;

    SDL_RWops *rw = SDL_RWFromFile(path, "rb");
    if (rw) {
        fileSize = SDL_RWsize(rw);

        buffer = (char *)malloc(fileSize + 1);

        Sint64 nb_read_total = 0, nb_read = 1;
        char *buf = (char *)buffer;
        while (nb_read_total < fileSize && nb_read != 0) {
            nb_read = SDL_RWread(rw, buf, 1, (fileSize - nb_read_total));
            nb_read_total += nb_read;
            buf += nb_read;
        }
        SDL_RWclose(rw);
        if (nb_read_total != fileSize) {
            free(buffer);
            return std::string("");
        }

        return std::string((char *)buffer);
    }

    return std::string("");
}
