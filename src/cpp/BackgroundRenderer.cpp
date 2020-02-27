//
//  BackgroundRenderer.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/25/20.
//

#include "BackgroundRenderer.h"
#include "SDL.h"
#include "UtilDSS.h"
#include <string>

namespace NJLIC {

    static void glErrorCheck() {
        do {
            for (int error = glGetError(); error; error = glGetError()) {

                switch (error) {
                case GL_NO_ERROR:
                    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                                "GL_NO_ERROR - No error has been recorded. The "
                                "value of this symbolic constant is guaranteed "
                                "to be 0.");
                    break;
                case GL_INVALID_ENUM:
                    SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "GL_INVALID_ENUM - An unacceptable value is "
                        "specified for an enumerated argument. The "
                        "offending command is ignored and has no other "
                        "side effect than to set the error flag.");
                    break;
                case GL_INVALID_VALUE:
                    SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "GL_INVALID_VALUE - A numeric argument is out of "
                        "range. The offending command is ignored and has "
                        "no other side effect than to set the error "
                        "flag.");
                    break;
                case GL_INVALID_OPERATION:
                    SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "GL_INVALID_OPERATION - The specified operation "
                        "is not allowed in the current state. The "
                        "offending command is ignored and has no other "
                        "side effect than to set the error flag.");
                    break;
                case GL_INVALID_FRAMEBUFFER_OPERATION:
                    SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "GL_INVALID_FRAMEBUFFER_OPERATION - The command "
                        "is trying to render to or read from the "
                        "framebuffer while the currently bound "
                        "framebuffer is not framebuffer complete (i.e. "
                        "the return value from glCheckFramebufferStatus "
                        "is not GL_FRAMEBUFFER_COMPLETE). The offending "
                        "command is ignored and has no other side effect "
                        "than to set the error flag.");
                    break;
                case GL_OUT_OF_MEMORY:
                    SDL_LogError(
                        SDL_LOG_CATEGORY_APPLICATION,
                        "GL_OUT_OF_MEMORY - There is not enough memory "
                        "left to execute the command. The state of the GL "
                        "is undefined, except for the state of the error "
                        "flags, after this error is recorded.");
                    break;
                default:
                    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unknown (%x)",
                                 error);
                }
            }
        } while (0);
    }

    //    static GLuint sWidth(1920);
    //    static GLuint sHeight(1080);

    enum { ATTRIB_VERTEX, ATTRIB_COLOR, ATTRIB_TEXTUREPOSITON, NUM_ATTRIBUTES };

    static void setupVertexBuffer(GLuint &vao, GLuint &vertexBuffer,
                                  GLuint &indexBuffer) {

        static GLfloat _vertices[] = {
            1.0,  -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, // right-top
            1.0,  1.0,  1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, // right-bottom
            -1.0, 1.0,  1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, // left-bottom
            -1.0, -1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, // left-top
        };

        static GLubyte _indices[] = {0, 1, 2, 2, 3, 0};

        glGenVertexArraysAPPLE(1, &vao);

        glErrorCheck();
        glBindVertexArrayAPPLE(vao);
        glErrorCheck();

        glGenBuffers(GLsizei(1), &vertexBuffer);

        glErrorCheck();
        glBindBuffer(GLenum(GL_ARRAY_BUFFER), vertexBuffer);
        glErrorCheck();

        size_t v_count = 4; //_vertices.size() / 7;
        size_t v_size = sizeof(GLfloat) * 9;
        const void *vertices = (const void *)_vertices;
        glBufferData(GLenum(GL_ARRAY_BUFFER), v_count * v_size, vertices,
                     GLenum(GL_STATIC_DRAW));
        glErrorCheck();

        glGenBuffers(GLsizei(1), &indexBuffer);

        glErrorCheck();
        glBindBuffer(GLenum(GL_ELEMENT_ARRAY_BUFFER), indexBuffer);
        glErrorCheck();
        size_t i_count = 6; //_indices.size();
        size_t i_size = sizeof(GLubyte);
        const void *indices = (const void *)_indices;
        glBufferData(GLenum(GL_ELEMENT_ARRAY_BUFFER), i_count * i_size, indices,
                     GLenum(GL_STATIC_DRAW));
        glErrorCheck();

        GLsizei s1 = GLsizei(sizeof(GLfloat) * 9);
        int p1 = 0;
        glEnableVertexAttribArray(ATTRIB_VERTEX);
        glErrorCheck();
        glVertexAttribPointer(ATTRIB_VERTEX, 3, GLenum(GL_FLOAT),
                              GLboolean(GL_FALSE), s1, (const GLvoid *)p1);
        glErrorCheck();

        GLsizei s2 = GLsizei(sizeof(GLfloat) * 9);
        int p2 = (3 * sizeof(GLfloat));
        glEnableVertexAttribArray(ATTRIB_COLOR);
        glErrorCheck();
        glVertexAttribPointer(ATTRIB_COLOR, 4, GLenum(GL_FLOAT),
                              GLboolean(GL_FALSE), s2, (const GLvoid *)p2);
        glErrorCheck();

        GLsizei s3 = GLsizei(sizeof(GLfloat) * 9);
        int p3 = ((3 + 4) * sizeof(GLfloat));
        glEnableVertexAttribArray(ATTRIB_TEXTUREPOSITON);
        glErrorCheck();
        glVertexAttribPointer(ATTRIB_TEXTUREPOSITON, 2, GLenum(GL_FLOAT),
                              GLboolean(GL_FALSE), s3, (const GLvoid *)p3);
        glErrorCheck();

        glBindVertexArrayAPPLE(0);
        glBindBuffer(GLenum(GL_ARRAY_BUFFER), 0);
        glBindBuffer(GLenum(GL_ELEMENT_ARRAY_BUFFER), 0);
    }

    

    // bool Shader::load(const std::string &vertShaderSource, const std::string
    // &fragShaderSource, GLuint &programPointer);
    static bool loadShader(const std::string &vertShaderSource,
                           const std::string &fragShaderSource,
                           GLuint &programPointer) {
        GLuint vertexShader(0), fragShader(0);

        programPointer = glCreateProgram();

        if (!UtilDSS::compileShader(vertexShader, GL_VERTEX_SHADER, vertShaderSource)) {
            return false;
        }

        if (!UtilDSS::compileShader(fragShader, GL_FRAGMENT_SHADER, fragShaderSource)) {
            return false;
        }

        // Attach vertex shader to program.
        glAttachShader(programPointer, vertexShader);

        // Attach fragment shader to program.
        glAttachShader(programPointer, fragShader);

        // Bind attribute locations.
        // This needs to be done prior to linking.
        glBindAttribLocation(programPointer, ATTRIB_VERTEX, "a_Position");
        glErrorCheck();
        glBindAttribLocation(programPointer, ATTRIB_COLOR, "a_Color");
        glErrorCheck();
        glBindAttribLocation(programPointer, ATTRIB_TEXTUREPOSITON,
                             "a_Texture");
        glErrorCheck();
        //    glBindAttribLocation(programPointer, ATTRIB_TEXTUREPOSITON,
        //    "inputTextureCoordinate");

        // Link program.
        if (!UtilDSS::linkProgram(programPointer)) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                         "Failed to link program: %d", programPointer);

            if (vertexShader) {
                glDeleteShader(vertexShader);
                vertexShader = 0;
            }
            if (fragShader) {
                glDeleteShader(fragShader);
                fragShader = 0;
            }
            if (programPointer) {
                glDeleteProgram(programPointer);
                programPointer = 0;
            }

            return false;
        }

        if (!UtilDSS::validateProgram(programPointer)) {
            return false;
        }

        // Release vertex and fragment shaders.
        if (vertexShader) {
            glDeleteShader(vertexShader);
        }
        if (fragShader) {
            glDeleteShader(fragShader);
        }

        return true;
    }

    BackgroundRenderer *BackgroundRenderer::sBackgroundRenderer = nullptr;
    BackgroundRenderer *BackgroundRenderer::getInstance() {
        if (nullptr == sBackgroundRenderer)
            sBackgroundRenderer = new BackgroundRenderer();
        return sBackgroundRenderer;
    }

    void BackgroundRenderer::destroyInstance() {
        if (nullptr != sBackgroundRenderer)
            delete sBackgroundRenderer;
        sBackgroundRenderer = nullptr;
    }
    void BackgroundRenderer::init() {

        const std::string fragmentSource = R"(

        uniform sampler2D videoFrame;

        varying vec2 textureCoordinate;
        varying vec4 frag_Color;

        void main(void) {
            gl_FragColor = texture2D(videoFrame, textureCoordinate) * frag_Color;
        }

        )";

        const std::string vertexSource = R"(
         
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

        if (loadShader(vertexSource, fragmentSource, mProgram)) {

            int width, height, channels_in_file;
            mVideoFrameBuffer = (unsigned char *)UtilDSS::loadImage(
                "assets/MLBBackground.jpg", &width, &height, &channels_in_file);

            // Create a new texture from the camera frame data, display that
            // using the shaders
            glGenTextures(1, &mVideoFrameTexture);

            glErrorCheck();
            glBindTexture(GL_TEXTURE_2D, mVideoFrameTexture);
            glErrorCheck();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // This is necessary for non-power-of-two textures
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

            // Using BGRA extension to pull in video frame data directly
            // GL_API void GL_APIENTRY glTexImage2D (GLenum target, GLint level,
            // GLint internalformat, GLsizei width, GLsizei height, GLint
            // border, GLenum format, GLenum type, const void *pixels);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)width,
                         (GLsizei)height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                         nullptr);
            glErrorCheck();

            GLint videoFrame = glGetUniformLocation(mProgram, "videoFrame");
            mUniforms[UNIFORM_VIDEOFRAME] = videoFrame;

            setupVertexBuffer(mVao, mVertexBuffer, mIndexBuffer);

            glBindTexture(GL_TEXTURE_2D, mVideoFrameTexture);
            glErrorCheck();
            glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, GLsizei(width),
                            GLsizei(height), GL_RGBA, GL_UNSIGNED_BYTE,
                            mVideoFrameBuffer);
            glErrorCheck();
        }
    }

    void BackgroundRenderer::unInit() {

        glDeleteProgram(mProgram);
        glDeleteTextures(1, &mVideoFrameTexture);
        glDeleteVertexArraysAPPLE(1, &mVao);
        glDeleteBuffers(GLsizei(1), &mVertexBuffer);
        glDeleteBuffers(GLsizei(1), &mIndexBuffer);
    }
    void BackgroundRenderer::render(GLuint width, GLuint height) {
        
        glViewport(0, 0, width * 2, height * 2);

        glUseProgram(mProgram);
        glErrorCheck();

        glActiveTexture(GL_TEXTURE0);
        glErrorCheck();
        glBindTexture(GL_TEXTURE_2D, mVideoFrameTexture);
        glErrorCheck();

        // Update uniform values
        glUniform1i(mUniforms[UNIFORM_VIDEOFRAME], 0);
        glErrorCheck();

        glBindVertexArrayAPPLE(mVao);
        glErrorCheck();
        glDrawElements(GLenum(GL_TRIANGLES), GLsizei(6),
                       GLenum(GL_UNSIGNED_BYTE), 0);
        glErrorCheck();
        glBindVertexArrayAPPLE(0);
    }

} // namespace NJLIC
