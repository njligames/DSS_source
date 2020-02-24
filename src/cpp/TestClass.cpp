#include "TestClass.h"

#include "SDL.h"

#include <string>

#include "MLBJsonModel.h"

#include "GameModelViewData.h"
#include "GameModelData.h"

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#include "BitmapFont.h"

#include "Date.h"
#include "UtilDSS.h"

static void UpdateFrame(void *param)
{
//  njli::NJLIGameEngine::update(1.0f / ((float)gDisplayMode.refresh_rate));
    
    TestClass::get()->update();
    TestClass::get()->render();

//  Graphics *graphics = (Graphics *)param;
//  graphics->update();
}

static SDL_Texture *
LoadTexture(SDL_Renderer *renderer, char *file, SDL_bool transparent)
{
    SDL_Surface *temp;
    SDL_Texture *texture;

    /* Load the sprite image */
    temp = SDL_LoadBMP(file);
    if (temp == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't load %s: %s", file, SDL_GetError());
        return NULL;
    }

    /* Set transparent pixel as the pixel at (0,0) */
    if (transparent) {
        if (temp->format->palette) {
            SDL_SetColorKey(temp, SDL_TRUE, *(Uint8 *) temp->pixels);
        } else {
            switch (temp->format->BitsPerPixel) {
            case 15:
                SDL_SetColorKey(temp, SDL_TRUE,
                                (*(Uint16 *) temp->pixels) & 0x00007FFF);
                break;
            case 16:
                SDL_SetColorKey(temp, SDL_TRUE, *(Uint16 *) temp->pixels);
                break;
            case 24:
                SDL_SetColorKey(temp, SDL_TRUE,
                                (*(Uint32 *) temp->pixels) & 0x00FFFFFF);
                break;
            case 32:
                SDL_SetColorKey(temp, SDL_TRUE, *(Uint32 *) temp->pixels);
                break;
            }
        }
    }

    /* Create textures from the image */
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return NULL;
    }
    SDL_FreeSurface(temp);

    /* We're ready to roll. :) */
    return texture;
}

TestClass *TestClass::sInstance = nullptr;

TestClass::TestClass() :
mWindow(nullptr),
mRenderer(nullptr),
mIsDone(true){
}

TestClass::TestClass(SDL_Window *window, SDL_Renderer *renderer) :
mWindow(window),
mRenderer(renderer),
mIsDone(true) {
}

TestClass::~TestClass() {
    BitmapFont::destroy();
    ThreadPool::destroy();
    
    unInit();
}

void TestClass::create() {
    if(nullptr == sInstance)
        sInstance = new TestClass();
}

void TestClass::create(SDL_Window *window, SDL_Renderer *renderer) {
    if(nullptr != window && nullptr != renderer) {
        if(nullptr == sInstance)
            sInstance = new TestClass(window, renderer);
    }
}

void TestClass::destroy() {
    if(nullptr != sInstance)
        delete sInstance;
    sInstance = nullptr;
}

TestClass *TestClass::get() {
    
    return sInstance;
}

bool TestClass::loadfile(SDL_Renderer *renderer) {
    int w,h;
    
    SDL_Texture *sprite = LoadTexture(renderer, (char*)"assets/sample.bmp", SDL_TRUE);
    if(nullptr == sprite) {
        SDL_Log("Could not find the sprite");
        return false;
    } else {
        SDL_QueryTexture(sprite, NULL, NULL, &w, &h);
        SDL_Log("Width: %d, Height: %d", w, h);
    }
    return true;
    
}

void TestClass::init() {
//    mMutex.lock();
    mIsDone = false;
//    mMutex.unlock();
    
    mShader = new NJLIC::Shader();
    
//    size_t vsSize = 0;
//    char *vsFileBuffer = UtilDSS::loadFile("assets/shaders/shader.vsh", vsSize);
//
//    size_t fsSize = 0;
//    char *fsFileBuffer = UtilDSS::loadFile("assets/shaders/shader.fsh", fsSize);
//
//    mShader->load(vsFileBuffer, fsFileBuffer);
    
//    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "ERROR");
    
    
    const std::string fragmentSource = R"(
    //#version 100
                                                                                           
    uniform sampler2D videoFrame;
                                                                                           
    varying vec2 textureCoordinate;
    varying vec4 frag_Color;
                                                                                           
    void main(void) {
        gl_FragColor = texture2D(videoFrame, textureCoordinate) * frag_Color;
    }
                                                                                           
    )";
                                                                                           
    const std::string vertexSource = R"(
    //#version 100
                                                                                           
    attribute vec4 a_Position;
    attribute vec4 a_Color;
    attribute vec4 a_Texture;
                                                                                           
    varying vec2 textureCoordinate;
    varying vec4 frag_Color;
                                                                                           
    void main(void) {
        frag_Color = a_Color;
        gl_Position = a_Position;
        textureCoordinate = a_Texture.xy;
    }
                                                                                           
                                                                                           
    )";
    
    if(mShader->load(vertexSource, fragmentSource)) {
        
    }
    
    
    
    
    
    
    int numberOfDaysToGoBack((365*4) + 1);
    numberOfDaysToGoBack = 1;
    NJLIC::Date formatted_date(6,10,2018);
    
    NJLIC::Date date(formatted_date);
    for(int i = 0;
        i < numberOfDaysToGoBack;
        ++i, date--) {
        
        printf("%s\n", std::string(date).c_str());
        mGameModelDataVector.push_back(GameModelData::generateGameModelData(date));
    }
    
//    BitmapFont::getInstance()->load("FranklinGothicMedium");
//    BitmapFont::getInstance()->load("FranklinGothicMedium");
    
    BitmapFont::getInstance()->setCurrentFontName("FranklinGothicMedium");
    BitmapFont::getInstance()->printf("%s - %d", "jimbo", 100);
    
    
    
//    for (std::vector<MLBJson::DateElement>::iterator dateElement_iterator = data.getMutableDates().begin();
//         dateElement_iterator != data.getMutableDates().end();
//         ++dateElement_iterator) {
//
//        MLBJson::DateElement _dateElement = *dateElement_iterator;
//
//        std::vector<GameModelViewData*> gvdVector;
//        GameModelViewData::loadGames(_dateElement.getMutableGames(), gvdVector);
//
//
////        size_t gameNumber = 0;
////
////        for (std::vector<MLBJson::Game>::iterator game_iterator = _dateElement.getMutableGames().begin();
////        game_iterator != _dateElement.getMutableGames().end();
////        ++game_iterator) {
////            gameNumber++;
////
////            MLBJson::Game _game = *game_iterator;
////
////            GameModelViewData gvd(_game);
////
////            int width, height, channels_in_file;
////            size_t fileSize;
////
////            void *data1 = gvd.getDetailImageData(&width, &height, &channels_in_file, &fileSize);
////            void *data2 = gvd.getListItemImageData(&width, &height, &channels_in_file, &fileSize);
////
////            gvd.getAwayName();
////
////        }
//    }
    
//    SDL_LogVerbose(SDL_LOG_CATEGORY_TEST, "%s", mlbJson.c_str());
}
void TestClass::unInit() {
    while(!mGameModelDataVector.empty()) {
        GameModelData *gmd = mGameModelDataVector.back();
        delete gmd;
        mGameModelDataVector.pop_back();
    }
}
void TestClass::update() {

}
void TestClass::render() {
    GLclampf red, green, blue;
    red = green = blue = (254.0 / 255.0);
    
    glClearColor(red, green, blue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

}

void TestClass::input() {
    mMutex.lock();
    
    bool callFinishKeys = false;
    SDL_Event event;
    SDL_PumpEvents();
    while (SDL_PollEvent(&event))
      {
//        njli::NJLIGameEngine::handleEvent(&event);
//        SDLTest_PrintEvent(&event);
        switch (event.type)
          {

#if defined(__MACOSX__) || defined(__EMSCRIPTEN__) || defined(__ANDROID__)
          case SDL_MOUSEMOTION:
          case SDL_MOUSEBUTTONDOWN:
          case SDL_MOUSEBUTTONUP:

//            NJLI_HandleMouse(event.button.button, event.type, event.button.x,
//                             event.button.y, event.button.clicks);
            break;
#endif

#if (defined(__ANDROID__) && __ANDROID__)
          case SDL_FINGERMOTION:
          case SDL_FINGERDOWN:
          case SDL_FINGERUP:
//            NJLI_HandleTouch((int)event.tfinger.touchId,
//                             (int)event.tfinger.fingerId, event.type,
//                             event.tfinger.x, event.tfinger.y, event.tfinger.dx,
//                             event.tfinger.dy, event.tfinger.pressure);
            break;
#endif
          case SDL_APP_DIDENTERFOREGROUND:
            SDL_Log("SDL_APP_DIDENTERFOREGROUND");

#if (defined(__IPHONEOS__) && __IPHONEOS__)
            SDL_iPhoneSetAnimationCallback(mWindow, 1, UpdateFrame,
                                           nullptr);
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
            switch (event.window.event)
              {
              case SDL_WINDOWEVENT_RESTORED:
//                NJLI_HandleResume();
                break;
              case SDL_WINDOWEVENT_MINIMIZED:
//                NJLI_HandlePause();
                break;
              case SDL_WINDOWEVENT_RESIZED:
              case SDL_WINDOWEVENT_SIZE_CHANGED:
                {
                  int w, h;
#if defined(__MACOSX__)
                  SDL_GetWindowSize(mWindow, &w, &h);
#else
                  SDL_GL_GetDrawableSize(mWindow, &w, &h);
#endif
                    TestClass::get()->resize(w, h);
                    
//                  NJLI_HandleResize(w, h, gDisplayMode.format,
//                                    gDisplayMode.refresh_rate);
                }
                break;
              case SDL_WINDOWEVENT_CLOSE:
                {
                  SDL_Window *window =
                      SDL_GetWindowFromID(event.window.windowID);
                  if (window)
                    {
                      if (window == mWindow)
                        {
                          SDL_DestroyWindow(mWindow);
                          mWindow = nullptr;
                          break;
                        }
                    }
                }
                break;
              }
            break;
          case SDL_KEYUP:
            {
              callFinishKeys = true;
              int temp = SDL_GetModState();
              temp = temp & KMOD_CAPS;
              bool withCapsLock = (temp == KMOD_CAPS);

              bool withControl = !!(event.key.keysym.mod & KMOD_CTRL);
              bool withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
              bool withAlt = !!(event.key.keysym.mod & KMOD_ALT);
              bool withGui = !!(event.key.keysym.mod & KMOD_GUI);

//              NJLI_HandleKeyUp(SDL_GetScancodeName(event.key.keysym.scancode),
//                               withCapsLock, withControl, withShift, withAlt,
//                               withGui);
            }
            break;
          case SDL_KEYDOWN:
            {
              callFinishKeys = true;
              int temp = SDL_GetModState();
              temp = temp & KMOD_CAPS;
              bool withCapsLock = (temp == KMOD_CAPS);

              bool withControl = !!(event.key.keysym.mod & KMOD_CTRL);
              bool withShift = !!(event.key.keysym.mod & KMOD_SHIFT);
              bool withAlt = !!(event.key.keysym.mod & KMOD_ALT);
              bool withGui = !!(event.key.keysym.mod & KMOD_GUI);

//              NJLI_HandleKeyDown(SDL_GetScancodeName(event.key.keysym.scancode),
//                                 withCapsLock, withControl, withShift, withAlt,
//                                 withGui);

              switch (event.key.keysym.sym)
                {
                /* Add hotkeys here */
                case SDLK_PRINTSCREEN:
                  {
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    if (window)
                      {
                        if (window == mWindow)
                          {
//                            SDLTest_ScreenShot(mRenderer);
                          }
                      }
                  }
                  break;
                case SDLK_EQUALS:
                  if (withControl)
                    {
                      /* Ctrl-+ double the size of the window */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          int w, h;
                          SDL_GetWindowSize(window, &w, &h);
                          SDL_SetWindowSize(window, w * 2, h * 2);
                        }
                    }
                  break;
                case SDLK_MINUS:
                  if (withControl)
                    {
                      /* Ctrl-- half the size of the window */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          int w, h;
                          SDL_GetWindowSize(window, &w, &h);
                          SDL_SetWindowSize(window, w / 2, h / 2);
                        }
                    }
                  break;
                case SDLK_o:
                  if (withControl)
                    {
#if !defined(__LINUX__)
                      /* Ctrl-O (or Ctrl-Shift-O) changes window opacity. */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          float opacity;
                          if (SDL_GetWindowOpacity(window, &opacity) == 0)
                            {
                              if (withShift)
                                {
                                  opacity += 0.20f;
                                }
                              else
                                {
                                  opacity -= 0.20f;
                                }
                              SDL_SetWindowOpacity(window, opacity);
                            }
                        }
#endif
                    }
                  break;

                case SDLK_c:
                  if (withControl)
                    {
                      /* Ctrl-C copy awesome text! */
                      SDL_SetClipboardText("SDL rocks!\nYou know it!");
                      printf("Copied text to clipboard\n");
                    }
                  if (withAlt)
                    {
                      /* Alt-C toggle a render clip rectangle */
                      int w, h;
                      if (mRenderer)
                        {
                          SDL_Rect clip;
                          SDL_GetWindowSize(mWindow, &w, &h);
                          SDL_RenderGetClipRect(mRenderer, &clip);
                          if (SDL_RectEmpty(&clip))
                            {
                              clip.x = w / 4;
                              clip.y = h / 4;
                              clip.w = w / 2;
                              clip.h = h / 2;
                              SDL_RenderSetClipRect(mRenderer, &clip);
                            }
                          else
                            {
                              SDL_RenderSetClipRect(mRenderer, NULL);
                            }
                        }
                    }
                  if (withShift)
                    {
                      SDL_Window *current_win = SDL_GetKeyboardFocus();
                      if (current_win)
                        {
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
                  if (withControl)
                    {
                      /* Ctrl-V paste awesome text! */
                      char *text = SDL_GetClipboardText();
                      if (*text)
                        {
                          printf("Clipboard: %s\n", text);
                        }
                      else
                        {
                          printf("Clipboard is empty\n");
                        }
                      SDL_free(text);
                    }
                  break;
                case SDLK_g:
                  if (withControl)
                    {
                      /* Ctrl-G toggle grab */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          SDL_SetWindowGrab(window, !SDL_GetWindowGrab(window)
                                                        ? SDL_TRUE
                                                        : SDL_FALSE);
                        }
                    }
                  break;
                case SDLK_m:
                  if (withControl)
                    {
                      /* Ctrl-M maximize */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          Uint32 flags = SDL_GetWindowFlags(window);
                          if (flags & SDL_WINDOW_MAXIMIZED)
                            {
                              SDL_RestoreWindow(window);
                            }
                          else
                            {
                              SDL_MaximizeWindow(window);
                            }
                        }
                    }
                  break;
                case SDLK_r:
                  if (withControl)
                    {
                      /* Ctrl-R toggle mouse relative mode */
                      SDL_SetRelativeMouseMode(
                          !SDL_GetRelativeMouseMode() ? SDL_TRUE : SDL_FALSE);
                    }
                  break;
                case SDLK_z:
                  if (withControl)
                    {
                      /* Ctrl-Z minimize */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          SDL_MinimizeWindow(window);
                        }
                    }
                  break;
                case SDLK_RETURN:
                  if (withControl)
                    {
                      /* Ctrl-Enter toggle fullscreen */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          Uint32 flags = SDL_GetWindowFlags(window);
                          if (flags & SDL_WINDOW_FULLSCREEN)
                            {
                              SDL_SetWindowFullscreen(window, SDL_FALSE);
                            }
                          else
                            {
                              SDL_SetWindowFullscreen(window,
                                                      SDL_WINDOW_FULLSCREEN);
                            }
                        }
                    }
                  else if (withAlt)
                    {
                      /* Alt-Enter toggle fullscreen desktop */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          Uint32 flags = SDL_GetWindowFlags(window);
                          if (flags & SDL_WINDOW_FULLSCREEN)
                            {
                              SDL_SetWindowFullscreen(window, SDL_FALSE);
                            }
                          else
                            {
                              SDL_SetWindowFullscreen(
                                  window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                            }
                        }
                    }
                  else if (withShift)
                    {
                      /* Shift-Enter toggle fullscreen desktop / fullscreen */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          Uint32 flags = SDL_GetWindowFlags(window);
                          if ((flags & SDL_WINDOW_FULLSCREEN_DESKTOP) ==
                              SDL_WINDOW_FULLSCREEN_DESKTOP)
                            {
                              SDL_SetWindowFullscreen(window,
                                                      SDL_WINDOW_FULLSCREEN);
                            }
                          else
                            {
                              SDL_SetWindowFullscreen(
                                  window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                            }
                        }
                    }

                  break;
                case SDLK_b:
                  if (withControl)
                    {
                      /* Ctrl-B toggle window border */
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      if (window)
                        {
                          const Uint32 flags = SDL_GetWindowFlags(window);
                          const SDL_bool b =
                              ((flags & SDL_WINDOW_BORDERLESS) != 0)
                                  ? SDL_TRUE
                                  : SDL_FALSE;
                          SDL_SetWindowBordered(window, b);
                        }
                    }
                  break;
                case SDLK_a:
                  if (withControl)
                    {
                      /* Ctrl-A reports absolute mouse position. */
                      int x, y;
                      const Uint32 mask = SDL_GetGlobalMouseState(&x, &y);
                      SDL_Log("ABSOLUTE MOUSE: (%d, %d)%s%s%s%s%s\n", x, y,
                              (mask & SDL_BUTTON_LMASK) ? " [LBUTTON]" : "",
                              (mask & SDL_BUTTON_MMASK) ? " [MBUTTON]" : "",
                              (mask & SDL_BUTTON_RMASK) ? " [RBUTTON]" : "",
                              (mask & SDL_BUTTON_X1MASK) ? " [X2BUTTON]" : "",
                              (mask & SDL_BUTTON_X2MASK) ? " [X2BUTTON]" : "");
                    }
                  break;
                case SDLK_0:
                  if (withControl)
                    {
                      SDL_Window *window =
                          SDL_GetWindowFromID(event.key.windowID);
                      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                               "Test Message",
                                               "You're awesome!", window);
                    }
                  break;
                case SDLK_1:
                  if (withControl)
                    {
//                      FullscreenTo(0, event.key.windowID);
                    }
                  break;
                case SDLK_2:
                  if (withControl)
                    {
//                      FullscreenTo(1, event.key.windowID);
                    }
                  break;
                case SDLK_ESCAPE:
                        mMutex.lock();
                        mIsDone = true;
                        mMutex.unlock();
                  break;
                case SDLK_SPACE:
                  {/*
                    char message[256];
                    SDL_Window *window =
                        SDL_GetWindowFromID(event.key.windowID);
                    SDL_snprintf(message, sizeof(message),
                                 "(%i, %i), rel (%i, %i)\n", gLastEvent.x,
                                 gLastEvent.y, gLastEvent.xrel,
                                 gLastEvent.yrel);
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                             "Last mouse position", message,
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
            //            NJLI_HandleResize(gDisplayMode.w, gDisplayMode.h,
            //                              gDisplayMode.format,
            //                              gDisplayMode.refresh_rate);
            // SDL_MouseWheelEvent wheel = event.wheel;

            break;
          case SDL_DROPFILE:
            {
              char *dropped_filedir = event.drop.file;
//              NJLI_HandleDropFile(dropped_filedir);
              SDL_free(dropped_filedir);
            }
            break;
#if !defined(__LINUX__)
          case SDL_DROPTEXT:
            {
              char *dropped_filedir = event.drop.file;
//              NJLI_HandleDropFile(dropped_filedir);
              SDL_free(dropped_filedir);
            }
            break;
          case SDL_DROPBEGIN:
            {
              printf("Dropped file begin: %u\n", event.drop.windowID);
            }
            break;
          case SDL_DROPCOMPLETE:
            {
              printf("Dropped file begin: %u\n", event.drop.windowID);
            }
#endif
            break;
          default:
            break;
          }
      }

//    if (callFinishKeys)
//      NJLI_HandleKeyboardFinish(SDL_GetKeyboardState(NULL), SDL_NUM_SCANCODES);

#if !(defined(__MACOSX__) && __MACOSX__)
#endif
    
    mMutex.unlock();
  }

void TestClass::resize(int w, int h)
{
    
}

bool TestClass::isDone()const
{
    return mIsDone;
}

std::string TestClass::loadStringData(char *path)
{
    void *buffer = nullptr;
    long fileSize;
    
    SDL_RWops *rw = SDL_RWFromFile(path, "rb");
    if (rw)
    {
        fileSize = SDL_RWsize(rw);
        
        buffer = (char *)malloc(fileSize + 1);

        Sint64 nb_read_total = 0, nb_read = 1;
        char *buf = (char *)buffer;
        while (nb_read_total < fileSize && nb_read != 0)
        {
            nb_read = SDL_RWread(rw, buf, 1, (fileSize - nb_read_total));
            nb_read_total += nb_read;
            buf += nb_read;
        }
        SDL_RWclose(rw);
        if (nb_read_total != fileSize)
        {
            free(buffer);
            return std::string("");
        }
        
        return std::string((char *)buffer);
    }

    return std::string("");
}
