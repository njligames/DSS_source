#include <string>
#include "TestExample.h"
#include "TestClass.h"

//using namespace google_test_sample;
using namespace std;

TestExample::TestExample() {}

TestExample::~TestExample() {};

void TestExample::SetUp() {
    
    SDL_SetMainReady();
    
    char *argv[] = {"", nullptr};
    state = SDLTest_CommonCreateState(argv, SDL_INIT_VIDEO);
    
    if (!SDLTest_CommonInit(state)) {
//        quit(2);
    }
    
    /* Create the windows and initialize the renderers */
    for (int i = 0; i < state->num_windows; ++i) {
        SDL_Renderer *renderer = state->renderers[i];
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
        SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
        SDL_RenderClear(renderer);
    }
};

void TestExample::TearDown() {
//    SDLTest_CommonQuit(state);
};

//TEST(test_cookie_interface, ShouldReturnZero) {
//    TestClass t(10);
//
//    ASSERT_EQ(t.increment(10), 20);
//}

TEST_F(TestExample, loadfile) {
    bool ret = true;
    
    TestClass::create(nullptr, nullptr);
    
    drawstates = SDL_stack_alloc(DrawState, state->num_windows);
    for (int i = 0; i < state->num_windows; ++i) {
        DrawState *drawstate = &drawstates[i];

        drawstate->window = state->windows[i];
        drawstate->renderer = state->renderers[i];
        
        ret = ret && TestClass::get()->loadfile(state->renderers[i]);
        
//        SDL_QueryTexture(drawstate->sprite, NULL, NULL, &drawstate->sprite_rect.w, &drawstate->sprite_rect.h);
        drawstate->scale_direction = 1;
    }
    ASSERT_EQ(true, ret);
}
