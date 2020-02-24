
/*
  Copyright (C) 1997-2019 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely.
*/

/* Simple program:  draw as many random objects on the screen as possible */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "TestClass.h"
#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include "curl.h"
#include "nlohmann/json.hpp"

//#include "SDL_test_common.h"
//
//#define NUM_OBJECTS 100
//
//static SDLTest_CommonState *state;
//static int num_objects;
//static SDL_bool cycle_color;
//static SDL_bool cycle_alpha;
//static int cycle_direction = 1;
//static int current_alpha = 255;
//static int current_color = 255;
//static SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
//
//int done;
//
//TestClass testClass;
//
//void
//DrawPoints(SDL_Renderer * renderer)
//{
//    int i;
//    int x, y;
//    SDL_Rect viewport;
//
//    /* Query the sizes */
//    SDL_RenderGetViewport(renderer, &viewport);
//
//    for (i = 0; i < num_objects * 4; ++i) {
//        /* Cycle the color and alpha, if desired */
//        if (cycle_color) {
//            current_color += cycle_direction;
//            if (current_color < 0) {
//                current_color = 0;
//                cycle_direction = -cycle_direction;
//            }
//            if (current_color > 255) {
//                current_color = 255;
//                cycle_direction = -cycle_direction;
//            }
//        }
//        if (cycle_alpha) {
//            current_alpha += cycle_direction;
//            if (current_alpha < 0) {
//                current_alpha = 0;
//                cycle_direction = -cycle_direction;
//            }
//            if (current_alpha > 255) {
//                current_alpha = 255;
//                cycle_direction = -cycle_direction;
//            }
//        }
//        SDL_SetRenderDrawColor(renderer, 255, (Uint8) current_color,
//                               (Uint8) current_color, (Uint8) current_alpha);
//
//        x = rand() % viewport.w;
//        y = rand() % viewport.h;
//        SDL_RenderDrawPoint(renderer, x, y);
//    }
//}
//
//void
//DrawLines(SDL_Renderer * renderer)
//{
//    int i;
//    int x1, y1, x2, y2;
//    SDL_Rect viewport;
//
//    /* Query the sizes */
//    SDL_RenderGetViewport(renderer, &viewport);
//
//    for (i = 0; i < num_objects; ++i) {
//        /* Cycle the color and alpha, if desired */
//        if (cycle_color) {
//            current_color += cycle_direction;
//            if (current_color < 0) {
//                current_color = 0;
//                cycle_direction = -cycle_direction;
//            }
//            if (current_color > 255) {
//                current_color = 255;
//                cycle_direction = -cycle_direction;
//            }
//        }
//        if (cycle_alpha) {
//            current_alpha += cycle_direction;
//            if (current_alpha < 0) {
//                current_alpha = 0;
//                cycle_direction = -cycle_direction;
//            }
//            if (current_alpha > 255) {
//                current_alpha = 255;
//                cycle_direction = -cycle_direction;
//            }
//        }
//        SDL_SetRenderDrawColor(renderer, 255, (Uint8) current_color,
//                               (Uint8) current_color, (Uint8) current_alpha);
//
//        if (i == 0) {
//            SDL_RenderDrawLine(renderer, 0, 0, viewport.w - 1, viewport.h - 1);
//            SDL_RenderDrawLine(renderer, 0, viewport.h - 1, viewport.w - 1, 0);
//            SDL_RenderDrawLine(renderer, 0, viewport.h / 2, viewport.w - 1, viewport.h / 2);
//            SDL_RenderDrawLine(renderer, viewport.w / 2, 0, viewport.w / 2, viewport.h - 1);
//        } else {
//            x1 = (rand() % (viewport.w*2)) - viewport.w;
//            x2 = (rand() % (viewport.w*2)) - viewport.w;
//            y1 = (rand() % (viewport.h*2)) - viewport.h;
//            y2 = (rand() % (viewport.h*2)) - viewport.h;
//            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
//        }
//    }
//}
//
//void
//DrawRects(SDL_Renderer * renderer)
//{
//    int i;
//    SDL_Rect rect;
//    SDL_Rect viewport;
//
//    /* Query the sizes */
//    SDL_RenderGetViewport(renderer, &viewport);
//
//    for (i = 0; i < num_objects / 4; ++i) {
//        /* Cycle the color and alpha, if desired */
//        if (cycle_color) {
//            current_color += cycle_direction;
//            if (current_color < 0) {
//                current_color = 0;
//                cycle_direction = -cycle_direction;
//            }
//            if (current_color > 255) {
//                current_color = 255;
//                cycle_direction = -cycle_direction;
//            }
//        }
//        if (cycle_alpha) {
//            current_alpha += cycle_direction;
//            if (current_alpha < 0) {
//                current_alpha = 0;
//                cycle_direction = -cycle_direction;
//            }
//            if (current_alpha > 255) {
//                current_alpha = 255;
//                cycle_direction = -cycle_direction;
//            }
//        }
//        SDL_SetRenderDrawColor(renderer, 255, (Uint8) current_color,
//                               (Uint8) current_color, (Uint8) current_alpha);
//
//        rect.w = rand() % (viewport.h / 2);
//        rect.h = rand() % (viewport.h / 2);
//        rect.x = (rand() % (viewport.w*2) - viewport.w) - (rect.w / 2);
//        rect.y = (rand() % (viewport.h*2) - viewport.h) - (rect.h / 2);
//        SDL_RenderFillRect(renderer, &rect);
//    }
//}
//
//void
//loop()
//{
//    int i;
//    SDL_Event event;
//
//    /* Check for events */
//    while (SDL_PollEvent(&event)) {
//        SDLTest_CommonEvent(state, &event, &done);
//    }
//    for (i = 0; i < state->num_windows; ++i) {
//        SDL_Renderer *renderer = state->renderers[i];
//        if (state->windows[i] == NULL)
//            continue;
//        SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
//        SDL_RenderClear(renderer);
//
//        DrawRects(renderer);
//        DrawLines(renderer);
//        DrawPoints(renderer);
//
//        testClass.loadfile(renderer);
//
//        SDL_RenderPresent(renderer);
//    }
//#ifdef __EMSCRIPTEN__
//    if (done) {
//        emscripten_cancel_main_loop();
//    }
//#endif
//}

#include "SDL.h"
#include <memory>


class Graphics
{
private:
  SDL_Window *_window;

public:
  Graphics(SDL_Window *window) { _window = window; }

  void update()
  {
      TestClass::get()->render();
//    njli::NJLIGameEngine::render();

    SDL_GL_SwapWindow(_window);
  }
};

std::unique_ptr<Graphics> gGraphics;

SDL_Window *gWindow = nullptr;
SDL_Renderer *gRenderer = nullptr;
SDL_DisplayMode gDisplayMode;
SDL_GLContext gGlContext;
int gDone;




#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
 
std::mutex g_display_mutex;
std::thread *gUpdateThread;
std::mutex g_update_mutex;


#if (defined(__IPHONEOS__) && __IPHONEOS__)

  static int EventFilter(void *userdata, SDL_Event *event)
  {
    //#if ((defined(__IPHONEOS__) && __IPHONEOS__) || (defined(__ANDROID__) &&
    //__ANDROID__))
    //    NJLI_HandleStartTouches();
    //#endif

//    njli::NJLIGameEngine::handleEvent(&event);
    //    SDLTest_PrintEvent(event);

    Uint32 eventType = event->type;

    switch (eventType)
      {
          case SDL_JOYDEVICEMOTION:
          {
//              SDL_Log("Joystick device %d motion. [%f, %f, %f, %f, %f, %f, %f, %f, %f]\n", (int) event->jmotion.which, event->jmotion.m11, event->jmotion.m12, event->jmotion.m13, event->jmotion.m21, event->jmotion.m22, event->jmotion.m23, event->jmotion.m31, event->jmotion.m32, event->jmotion.m33);
//              SDL_Log("Yaw, Pitch, Roll (%f, %f, %f)\n", event->jmotion.yaw, event->jmotion.pitch, event->jmotion.roll);
              
//              float _transform[] = {static_cast<float>(event->jmotion.m11), static_cast<float>(event->jmotion.m12), static_cast<float>(event->jmotion.m13), static_cast<float>(event->jmotion.m21), static_cast<float>(event->jmotion.m22), static_cast<float>(event->jmotion.m23), static_cast<float>(event->jmotion.m31), static_cast<float>(event->jmotion.m32), static_cast<float>(event->jmotion.m33)};
              
              
              
//              glm::mat4 transform = glm::make_mat4(_transform);
//              NJLI_HandleVRCameraRotation(static_cast<float>(event->jmotion.m11), static_cast<float>(event->jmotion.m12), static_cast<float>(event->jmotion.m13), static_cast<float>(event->jmotion.m21), static_cast<float>(event->jmotion.m22), static_cast<float>(event->jmotion.m23), static_cast<float>(event->jmotion.m31), static_cast<float>(event->jmotion.m32), static_cast<float>(event->jmotion.m33));
              
//              NJLI_HandleVRCameraRotationYPR(static_cast<float>(event->jmotion.yaw),
//                                             static_cast<float>(event->jmotion.pitch),
//                                             static_cast<float>(event->jmotion.roll));
              // = glm::mat4(event->jmotion.m11, event->jmotion.m12, event->jmotion.m13, event->jmotion.m21, event->jmotion.m22, event->jmotion.m23, event->jmotion.m31, event->jmotion.m32, event->jmotion.m33);
              
          }
              break;
      //#if ((defined(__MACOSX__) && __MACOSX__) || (defined(__EMSCRIPTEN__) &&
      //__EMSCRIPTEN__))
      case SDL_MOUSEMOTION:
      case SDL_MOUSEBUTTONDOWN:
      case SDL_MOUSEBUTTONUP:

//        NJLI_HandleMouse(event->button.button, event->type, event->button.x,
//                         event->button.y, event->button.clicks);
        break;
      //#endif

      //#if ((defined(__IPHONEOS__) && __IPHONEOS__) || (defined(__ANDROID__) &&
      //__ANDROID__))
      case SDL_FINGERMOTION:
      case SDL_FINGERDOWN:
      case SDL_FINGERUP:
//        NJLI_HandleTouch((int)event->tfinger.touchId,
//                         (int)event->tfinger.fingerId, event->type,
//                         event->tfinger.x, event->tfinger.y, event->tfinger.dx,
//                         event->tfinger.dy, event->tfinger.pressure);
        break;
      //#endif
      default:
        break;
      }

#if ((defined(__IPHONEOS__) && __IPHONEOS__) ||                                \
     (defined(__ANDROID__) && __ANDROID__))
//    NJLI_HandleFinishTouches();
#endif

    return 1;
  }
#endif

static void RenderFrame(void *param)
{
//  njli::NJLIGameEngine::update(1.0f / ((float)gDisplayMode.refresh_rate));
    
//    TestClass::get()->update();

  Graphics *graphics = (Graphics *)param;
  graphics->update();
}

static void handleInput()
  {
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
            SDL_iPhoneSetAnimationCallback(gWindow, 1, RenderFrame, gGraphics.get());
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
            SDL_iPhoneSetAnimationCallback(gWindow, 1, nullptr, nullptr);
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
                  SDL_GetWindowSize(gWindow, &w, &h);
#else
                  SDL_GL_GetDrawableSize(gWindow, &w, &h);
#endif
                    TestClass::get()->resize(w,h);
                    
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
                      if (window == gWindow)
                        {
                          SDL_DestroyWindow(gWindow);
                          gWindow = NULL;
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
                        if (window == gWindow)
                          {
//                            SDLTest_ScreenShot(gRenderer);
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
                      if (gRenderer)
                        {
                          SDL_Rect clip;
                          SDL_GetWindowSize(gWindow, &w, &h);
                          SDL_RenderGetClipRect(gRenderer, &clip);
                          if (SDL_RectEmpty(&clip))
                            {
                              clip.x = w / 4;
                              clip.y = h / 4;
                              clip.w = w / 2;
                              clip.h = h / 2;
                              SDL_RenderSetClipRect(gRenderer, &clip);
                            }
                          else
                            {
                              SDL_RenderSetClipRect(gRenderer, NULL);
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
                        g_display_mutex.lock();
                  gDone = 1;
                        g_display_mutex.unlock();
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
  }

static void Update() {
    while(!gDone) {
        TestClass::get()->update();
        
//        std::thread::id this_id = std::this_thread::get_id();
//        g_display_mutex.lock();
//        std::cout << "thread " << this_id << " sleeping...\n";
//        g_display_mutex.unlock();
    }
}

#if !(defined(__IPHONEOS__) && __IPHONEOS__)
  static void mainloop()
  {
#if !defined(NDEBUG) && 0
      // Declare display mode structure to be filled in.
      SDL_DisplayMode current;
      // Get current display mode of all displays.
      for(int i = 0; i < SDL_GetNumVideoDisplays(); ++i){
          
          int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);
          
          if(should_be_zero != 0)
              // In case of error...
              SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());
          
          else
              // On success, print the current display mode.
              SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", i, current.w, current.h, current.refresh_rate);
          
      }
#endif
      
    handleInput();

      TestClass::get()->update();
      
    RenderFrame(gGraphics.get());

    int w, h;
    SDL_GL_GetDrawableSize(gWindow, &w, &h);

    int w2, h2;
    SDL_GetWindowSize(gWindow, &w2, &h2);
      
#if defined(__EMSCRIPTEN__) || defined(__ANDROID__)

    
      TestClass::get()->resize(gDisplayMode.w, gDisplayMode.h);
      
//    NJLI_HandleResize(gDisplayMode.w, gDisplayMode.h, gDisplayMode.format,
//                      gDisplayMode.refresh_rate);
                      

#endif

#if defined(__EMSCRIPTEN__)

    if (gDone)
      {
        emscripten_cancel_main_loop();

//        njli::NJLIGameEngine::destroy();
          TestClass::destroy();

        SDL_GL_DeleteContext(gGlContext);

        // while (!gGameJoysticks.empty())
        //   {
        //     SDL_Joystick *joystick = gGameJoysticks.back();
        //     gGameJoysticks.pop_back();
        //     SDL_JoystickClose(joystick);
        //   }

        SDL_DestroyWindow(gWindow);
        SDL_Quit();
      }

#endif
  }
#endif

#if defined(__MACOSX__)
static void createRenderer()
{
    int n = SDL_GetNumRenderDrivers();
    SDL_RendererInfo info;
    
    for (int j = 0; j < n; ++j)
    {
        SDL_GetRenderDriverInfo(j, &info);
        //                SDLTest_PrintRenderer(&info);
        SDL_LogInfo(SDL_LOG_CATEGORY_TEST, "%s", info.name);
        if (SDL_strcasecmp(info.name, "opengl") == 0)
        {
            gRenderer = SDL_CreateRenderer(gWindow, j, 0);
            return;
        }
    }
}
#endif

int
main(int argc, char *argv[])
{
      
      
      
      
      
//      std::string working_directory("");
//      bool found_working_dir = false;
//      for(int i = 0; i < argc; ++i)
//      {
//          std::string s(argv[i]);
//
//          if(found_working_dir)
//          {
//              working_directory = std::string(argv[i]);
//              working_directory += "/";
//              found_working_dir = false;
//
//              setAssetPath(working_directory.c_str());
//          }
//          if(s == "-working_dir")
//          {
//              found_working_dir = true;
//          }
//
//      }
      
      
#if (defined(__MACOSX__) && __MACOSX__)
    if (argc > 1)
      {
        //        setRunningPath(argv[1]);
//        setScriptDir(argv[1]);
      }
#endif

      SDL_SetHint(SDL_HINT_ACCELEROMETER_AS_JOYSTICK, "0");
      
    /* initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
      {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
      }

      const char *name, *type;
      int i;
      SDL_Joystick *joystick;

      /* Print information about the joysticks */
      SDL_Log("There are %d joysticks attached\n", SDL_NumJoysticks());
      for ( i = 0; i < SDL_NumJoysticks(); ++i) {
          name = SDL_JoystickNameForIndex(i);
          SDL_Log("Joystick %d: %s\n", i, name ? name : "Unknown Joystick");
          joystick = SDL_JoystickOpen(i);
          if (joystick == NULL) {
              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_JoystickOpen(%d) failed: %s\n", i,
                           SDL_GetError());
          } else {
              char guid[64];
              SDL_assert(SDL_JoystickFromInstanceID(SDL_JoystickInstanceID(joystick)) == joystick);
              SDL_JoystickGetGUIDString(SDL_JoystickGetGUID(joystick),
                                        guid, sizeof (guid));
              switch (SDL_JoystickGetType(joystick)) {
                  case SDL_JOYSTICK_TYPE_GAMECONTROLLER:
                      type = "Game Controller";
                      break;
                  case SDL_JOYSTICK_TYPE_WHEEL:
                      type = "Wheel";
                      break;
                  case SDL_JOYSTICK_TYPE_ARCADE_STICK:
                      type = "Arcade Stick";
                      break;
                  case SDL_JOYSTICK_TYPE_FLIGHT_STICK:
                      type = "Flight Stick";
                      break;
                  case SDL_JOYSTICK_TYPE_DANCE_PAD:
                      type = "Dance Pad";
                      break;
                  case SDL_JOYSTICK_TYPE_GUITAR:
                      type = "Guitar";
                      break;
                  case SDL_JOYSTICK_TYPE_DRUM_KIT:
                      type = "Drum Kit";
                      break;
                  case SDL_JOYSTICK_TYPE_ARCADE_PAD:
                      type = "Arcade Pad";
                      break;
                  case SDL_JOYSTICK_TYPE_THROTTLE:
                      type = "Throttle";
                      break;
                  default:
                      type = "Unknown";
                      break;
              }
              SDL_Log("       type: %s\n", type);
              SDL_Log("       axes: %d\n", SDL_JoystickNumAxes(joystick));
              SDL_Log("      balls: %d\n", SDL_JoystickNumBalls(joystick));
              SDL_Log("       hats: %d\n", SDL_JoystickNumHats(joystick));
              SDL_Log("    buttons: %d\n", SDL_JoystickNumButtons(joystick));
              SDL_Log("instance id: %d\n", SDL_JoystickInstanceID(joystick));
              SDL_Log("       guid: %s\n", guid);
              SDL_Log("    VID/PID: 0x%.4x/0x%.4x\n", SDL_JoystickGetVendor(joystick), SDL_JoystickGetProduct(joystick));
              SDL_JoystickClose(joystick);
          }
      }
      
      
      
#if defined(__ANDROID__) || defined(__IPHONEOS__ )
      if (SDL_NumJoysticks() > 0) {
#else
          if (argv[1]) {
#endif
              SDL_bool reportederror = SDL_FALSE;
              SDL_bool keepGoing = SDL_TRUE;
              SDL_Event event;
              int device;
#if defined(__ANDROID__) || defined(__IPHONEOS__)
              device = 0;
#else
              device = atoi(argv[1]);
#endif
              joystick = SDL_JoystickOpen(device);
              if (joystick != NULL) {
                  SDL_assert(SDL_JoystickFromInstanceID(SDL_JoystickInstanceID(joystick)) == joystick);
              }
              
//              while ( keepGoing ) {
//                  if (joystick == NULL) {
//                      if ( !reportederror ) {
//                          SDL_Log("Couldn't open joystick %d: %s\n", device, SDL_GetError());
//                          keepGoing = SDL_FALSE;
//                          reportederror = SDL_TRUE;
//                      }
//                  } else {
//                      reportederror = SDL_FALSE;
//                      keepGoing = WatchJoystick(joystick);
//                      SDL_JoystickClose(joystick);
//                  }
//
//                  joystick = NULL;
//                  if (keepGoing) {
//                      SDL_Log("Waiting for attach\n");
//                  }
//                  while (keepGoing) {
//                      SDL_WaitEvent(&event);
//                      if ((event.type == SDL_QUIT) || (event.type == SDL_FINGERDOWN)
//                          || (event.type == SDL_MOUSEBUTTONDOWN)) {
//                          keepGoing = SDL_FALSE;
//                      } else if (event.type == SDL_JOYDEVICEADDED) {
//                          device = event.jdevice.which;
//                          joystick = SDL_JoystickOpen(device);
//                          if (joystick != NULL) {
//                              SDL_assert(SDL_JoystickFromInstanceID(SDL_JoystickInstanceID(joystick)) == joystick);
//                          }
//                          break;
//                      }
//                  }
//              }
          }
      
      
      
      

#if !defined(__ANDROID__)
    SDL_GetDesktopDisplayMode(0, &gDisplayMode);
#endif
      
#if defined(__EMSCRIPTEN__)
    gDisplayMode.h = 725.0f;
    float div = gDisplayMode.h / 9.0;
    gDisplayMode.w = div * 16.0f;
//      gDisplayMode.h = 600.0f;
          gDisplayMode.refresh_rate = 60.0f;
#endif

#if defined(__EMSCRIPTEN__) || defined(__ANDROID__) || defined(__IPHONEOS__)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
#endif

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

      
      
//#if defined(__GL_ES2__)
//
//      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
//
//#elif defined(__GL_ES3__)
//
//      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//
//#elif defined(__GL_2__)
      
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
//#if defined(__MACOSX__)
      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
//#endif
      
//#elif defined(__GL_3__)
//
//      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//#if defined(__MACOSX__)
////      SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
////      SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
////      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
////      SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
////
//
////      SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//#endif
      
//#endif
      
#if defined(__MACOSX__) || defined(__WINDOWS32__) || defined(__WINDOWS64__)
    SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
#endif

      Uint32 flags = SDL_WINDOW_OPENGL;
      
      
#if defined(__MACOSX__)
//      flags |= SDL_WINDOW_RESIZABLE;
//      flags |= SDL_WINDOW_MAXIMIZED;
      flags |= SDL_WINDOW_ALWAYS_ON_TOP;
      flags |= SDL_WINDOW_UTILITY;
#endif

#if defined(__ANDROID__) || defined(__IPHONEOS__)
      flags |= SDL_WINDOW_FULLSCREEN;
#endif
      
#if defined(__ANDROID__) || defined(__IPHONEOS__) || defined(__MACOSX__)
      flags |= SDL_WINDOW_ALLOW_HIGHDPI;
#endif
      
    /* create window and renderer */
    gWindow =
        SDL_CreateWindow("JamesFolk_DSSAssignment", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, gDisplayMode.w, gDisplayMode.h,
                         flags);

#if defined(__MACOSX__)
    createRenderer();
#endif

     SDL_SetWindowSize(gWindow, 1920, 1080);

//    int w, h;
//    SDL_GetWindowSize(gWindow, &w, &h);
//    SDL_Log("SDL_GetWindowSize #%d: current display mode is %dx%dpx", 0, w, h);

    //#if defined(__MACOSX__)
    //#if !(defined(NDEBUG))
    //        SDL_SetWindowSize(gWindow, w * 0.25f, h * 0.25f);
    //#endif
    //#endif

//    SDL_GL_GetDrawableSize(gWindow, &w, &h);
//    SDL_Log("SDL_GL_GetDrawableSize #%d: current display mode is %dx%dpx", 0, w, h);

    if (!gWindow)
      {
        printf("Could not initialize Window\n");
        return 1;
      }

#if (defined(__ANDROID__) && (__ANDROID__))
    SDL_SetWindowFullscreen(gWindow, SDL_TRUE);
#endif

    gGlContext = SDL_GL_CreateContext(gWindow);

#if defined(__WINDOWS32__)
    glewExperimental = true;
    GLenum e = GLEW_OK;
    e = glewInit();
    if (e != GLEW_OK) { // never fails
        printf("glewInit initialization failed. GLEW error %s\n", glewGetErrorString(e));
    }
#endif

          TestClass::create();
          TestClass::get()->init();
//    if (!njli::NJLIGameEngine::create(
//            DeviceUtil::hardwareDescription().c_str()))
//      {
//        cerr << "Error initializing OpenGL" << endl;
//        return 1;
//      }

    gGraphics = std::unique_ptr<Graphics>(new Graphics(gWindow));

#if (defined(__IPHONEOS__) && __IPHONEOS__)
    SDL_AddEventWatch(EventFilter, NULL);
#endif

//    int drawableW, drawableH;
    int screen_w, screen_h;
    float pointSizeScale;

    /* The window size and drawable size may be different when highdpi is
     * enabled,
     * due to the increased pixel density of the drawable. */
    SDL_GetWindowSize(gWindow, &screen_w, &screen_h);
      
      
//      SDL_GL_GetDrawableSize(gWindow, &w, &h);
#if !defined(__EMSCRIPTEN__)
        SDL_GL_GetDrawableSize(gWindow, &gDisplayMode.w, &gDisplayMode.h);
#endif
//      gDisplayMode.w = drawableW;
//      gDisplayMode.h = drawableH;

    /* In OpenGL, point sizes are always in pixels. We don't want them looking
     * tiny on a retina screen. */
    pointSizeScale = (float)gDisplayMode.w / (float)screen_h;

    //#if defined(__MACOSX__)
    //    SDL_GetWindowSize(gWindow, &w, &h);
    //#else
    //    SDL_GL_GetDrawableSize(gWindow, &w, &h);
    //#endif
    //#if defined(__EMSCRIPTEN__)
      
    #if defined(__EMSCRIPTEN__)
//           int fullScreen = 0;
//           emscripten_get_canvas_size(&gDisplayMode.w, &gDisplayMode.h, &fullScreen);

//           EMSCRIPTEN_RESULT r = emscripten_get_canvas_element_size("#gameCanvas", &gDisplayMode.w, &gDisplayMode.h);
//           if (r != EMSCRIPTEN_RESULT_SUCCESS) /* handle error */
//               EmscriptenFullscreenChangeEvent e;
//           r = emscripten_get_fullscreen_status(&e);
//           if (r != EMSCRIPTEN_RESULT_SUCCESS) /* handle error */
//               fullScreen = e.isFullscreen;

#endif
          gDisplayMode.w *= pointSizeScale;
          gDisplayMode.h *= pointSizeScale;
          
//    NJLI_HandleResize(gDisplayMode.w, gDisplayMode.h, gDisplayMode.format,
//                      gDisplayMode.refresh_rate);
          
          TestClass::get()->resize(gDisplayMode.w, gDisplayMode.h);
          
    //#endif

//      bool vsynch = true;
//      if(vsynch)
//      {
//          SDL_GL_SetSwapInterval(1);
//      }
//      else
//      {
//          SDL_GL_SetSwapInterval(0);
//      }
      
//    gDone = (njli::NJLIGameEngine::start(argc, argv) == false) ? 1 : 0;

#if defined(__EMSCRIPTEN__)
    emscripten_set_main_loop(mainloop, 0, 0);
#else

//          gUpdateThread = new std::thread(Update);
          
          while (!gDone)
          {
              
//              std::thread::id this_id = std::this_thread::get_id();
//              g_display_mutex.lock();
//              std::cout << "thread " << this_id << " sleeping...\n";
//              g_display_mutex.unlock();

#if defined(__IPHONEOS__) && __IPHONEOS__
              handleInput();
#else
              mainloop();
              
//              handleInput();
//              RenderFrame(gGraphics.get());
#endif
          }
          
//          gUpdateThread->join();
//          delete gUpdateThread;

//    NJLI_HandleSurfaceDestroyed();
          TestClass::destroy();

#endif

    return 0;
  }
//{
//    int i;
//    Uint32 then, now, frames;
//
//    /* Enable standard application logging */
//    SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);
//
//    /* Initialize parameters */
//    num_objects = NUM_OBJECTS;
//
//    /* Initialize test framework */
//    state = SDLTest_CommonCreateState(argv, SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
//    if (!state) {
//        return 1;
//    }
//    for (i = 1; i < argc;) {
//        int consumed;
//
//        consumed = SDLTest_CommonArg(state, i);
//        if (consumed == 0) {
//            consumed = -1;
//            if (SDL_strcasecmp(argv[i], "--blend") == 0) {
//                if (argv[i + 1]) {
//                    if (SDL_strcasecmp(argv[i + 1], "none") == 0) {
//                        blendMode = SDL_BLENDMODE_NONE;
//                        consumed = 2;
//                    } else if (SDL_strcasecmp(argv[i + 1], "blend") == 0) {
//                        blendMode = SDL_BLENDMODE_BLEND;
//                        consumed = 2;
//                    } else if (SDL_strcasecmp(argv[i + 1], "add") == 0) {
//                        blendMode = SDL_BLENDMODE_ADD;
//                        consumed = 2;
//                    } else if (SDL_strcasecmp(argv[i + 1], "mod") == 0) {
//                        blendMode = SDL_BLENDMODE_MOD;
//                        consumed = 2;
//                    }
//                }
//            } else if (SDL_strcasecmp(argv[i], "--cyclecolor") == 0) {
//                cycle_color = SDL_TRUE;
//                consumed = 1;
//            } else if (SDL_strcasecmp(argv[i], "--cyclealpha") == 0) {
//                cycle_alpha = SDL_TRUE;
//                consumed = 1;
//            } else if (SDL_isdigit(*argv[i])) {
//                num_objects = SDL_atoi(argv[i]);
//                consumed = 1;
//            }
//        }
//        if (consumed < 0) {
//            static const char *options[] = { "[--blend none|blend|add|mod]", "[--cyclecolor]", "[--cyclealpha]", NULL };
////            SDLTest_CommonLogUsage(state, argv[0], options);
//            return 1;
//        }
//        i += consumed;
//    }
//    if (!SDLTest_CommonInit(state)) {
//        return 2;
//    }
//
//    /* Create the windows and initialize the renderers */
//    for (i = 0; i < state->num_windows; ++i) {
//        SDL_Renderer *renderer = state->renderers[i];
//        SDL_SetRenderDrawBlendMode(renderer, blendMode);
//        SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
//        SDL_RenderClear(renderer);
//    }
//
//    srand((unsigned int)time(NULL));
//
//    /* Main render loop */
//    frames = 0;
//    then = SDL_GetTicks();
//    done = 0;
//
//#ifdef __EMSCRIPTEN__
//    emscripten_set_main_loop(loop, 0, 1);
//#else
//    while (!done) {
//        ++frames;
//        loop();
//    }
//#endif
//
//
//    SDLTest_CommonQuit(state);
//
//    /* Print out some timing information */
//    now = SDL_GetTicks();
//    if (now > then) {
//        double fps = ((double) frames * 1000) / (now - then);
//        SDL_Log("%2.2f frames per second\n", fps);
//    }
//    return 0;
//}

/* vi: set ts=4 sw=4 expandtab: */
