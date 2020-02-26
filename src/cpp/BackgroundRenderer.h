
////
////  BackgroundRenderer.h
////  SDLSkeleton
////
////  Created by James Folk on 2/25/20.
////

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

namespace NJLIC {
    class BackgroundRenderer {
        static BackgroundRenderer *sBackgroundRenderer;

        enum { UNIFORM_VIDEOFRAME, NUM_UNIFORMS };

        GLint mUniforms[NUM_UNIFORMS];
        GLuint mProgram;

        GLuint mVao;
        GLuint mVertexBuffer;
        GLuint mIndexBuffer;
        GLuint mVideoFrameTexture;
        unsigned char *mVideoFrameBuffer;

      public:
        static BackgroundRenderer *getInstance();
        static void destroyInstance();

        void init();
        void unInit();
        void render(GLuint width, GLuint height);
    };
} // namespace NJLIC
