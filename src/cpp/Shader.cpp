//
//  Shader.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#include "Shader.h"
#include "SDL.h"

// static void glErrorCheck()
//{
//    do \
//    { \
//      for (int error = glGetError(); error; error = glGetError()) \
//        {
//
//          switch (error) \
//            { \
//            case GL_NO_ERROR: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, \
//                             "GL_NO_ERROR - No error has been recorded. The "
//                             \
//                             "value of this symbolic constant is guaranteed "
//                             \
//                             "to be 0."); \
//              break; \
//            case GL_INVALID_ENUM: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, \
//                           "GL_INVALID_ENUM - An unacceptable value is " \
//                           "specified for an enumerated argument. The " \
//                           "offending command is ignored and has no other " \
//                           "side effect than to set the error flag."); \
//              break; \
//            case GL_INVALID_VALUE: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, \
//                           "GL_INVALID_VALUE - A numeric argument is out of "
//                           \
//                           "range. The offending command is ignored and has "
//                           \
//                           "no other side effect than to set the error " \
//                           "flag."); \
//              break; \
//            case GL_INVALID_OPERATION: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, \
//                           "GL_INVALID_OPERATION - The specified operation " \
//                           "is not allowed in the current state. The " \
//                           "offending command is ignored and has no other " \
//                           "side effect than to set the error flag."); \
//              break; \
//            case GL_INVALID_FRAMEBUFFER_OPERATION: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, \
//                           "GL_INVALID_FRAMEBUFFER_OPERATION - The command " \
//                           "is trying to render to or read from the " \
//                           "framebuffer while the currently bound " \
//                           "framebuffer is not framebuffer complete (i.e. " \
//                           "the return value from glCheckFramebufferStatus " \
//                           "is not GL_FRAMEBUFFER_COMPLETE). The offending " \
//                           "command is ignored and has no other side effect "
//                           \
//                           "than to set the error flag."); \
//              break; \
//            case GL_OUT_OF_MEMORY: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, \
//                           "GL_OUT_OF_MEMORY - There is not enough memory " \
//                           "left to execute the command. The state of the GL "
//                           \
//                           "is undefined, except for the state of the error "
//                           \
//                           "flags, after this error is recorded."); \
//              break; \
//            default: \
//              SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,  "Unknown (%x)",
//              error);\
//            } \
//        } \
//    } \
//  while (0);
//}

namespace NJLIC {

    Shader::Shader()
        : m_Program(0), m_mat4Buffer(new GLfloat[16]),
          m_vec3Buffer(new GLfloat[3]), m_vec4Buffer(new GLfloat[4]) {}

    Shader::~Shader() {
        delete[] m_vec4Buffer;
        m_vec4Buffer = NULL;

        delete[] m_vec3Buffer;
        m_vec3Buffer = NULL;

        delete[] m_mat4Buffer;
        m_mat4Buffer = NULL;

        unLoad();
    }

    bool Shader::load(const std::string &vertexSource,
                      const std::string &fragmentSource) {
        GLuint vertShader, fragShader;

        m_Program = glCreateProgram();

        if (!(vertShader = compileShader(vertexSource, GL_VERTEX_SHADER))) {
            glDeleteProgram(m_Program);
            return false;
        }

        if (!(fragShader = compileShader(fragmentSource, GL_FRAGMENT_SHADER))) {
            glDeleteProgram(m_Program);
            glDeleteShader(vertShader);
            return false;
        }

        glAttachShader(m_Program, vertShader);
        glAttachShader(m_Program, fragShader);

        if (!linkProgram(m_Program)) {
            if (vertShader) {
                glDeleteShader(vertShader);
                vertShader = 0;
            }
            if (fragShader) {
                glDeleteShader(fragShader);
                fragShader = 0;
            }
            if (m_Program) {
                glDeleteProgram(m_Program);
                m_Program = 0;
            }
            return false;
        }
#if !defined(NDEBUG)
        if (!validateProgram(m_Program)) {
            return false;
        }
#endif

        if (vertShader) {
            glDeleteShader(vertShader);
        }

        if (fragShader) {
            glDeleteShader(fragShader);
        }
        return true;
    }

    void Shader::unLoad() {
        if (m_Program)
            glDeleteProgram(m_Program);
        m_Program = 0;
    }

    bool Shader::isLoaded() const { return (m_Program != 0); }

    bool Shader::use() const {
        if (m_Program) {
            GLint id;
            glGetIntegerv(GL_CURRENT_PROGRAM, &id);
            if (id != m_Program)
                glUseProgram(m_Program);
            return true;
        }
        return false;
    }

    int Shader::getAttributeLocation(const std::string &attributeName) const {
        int location = glGetAttribLocation(m_Program, attributeName.c_str());

#if !defined(NDEBUG)
        if (location == -1) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                         "The named attribute variable %s is not an active "
                         "attribute in the specified program object or if name "
                         "starts with the reserved prefix \"gl_\"",
                         attributeName.c_str());
        }
#endif
        return location;
    }

    int Shader::getUniformLocation(const std::string &uniformName) {
        int location = -1;

        UniformMap::iterator iter = m_UniformMap.find(uniformName);
        if (iter != m_UniformMap.end()) {
            location = iter->second;
        } else {
            location = glGetUniformLocation(m_Program, uniformName.c_str());
            m_UniformMap.insert(UniformPair(uniformName, location));
        }

#if !defined(NDEBUG)
        if (location == -1) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                         "The named attribute variable %s is not an active "
                         "attribute in the specified program object or if name "
                         "starts with the reserved prefix \"gl_\"",
                         uniformName.c_str());
        }
#endif
        return location;
    }

    bool Shader::setUniformValue(const std::string &uniformName,
                                 const glm::mat4x4 &value, bool transpose) {
        //        value.getOpenGLMatrix(m_mat4Buffer);
        //        return setUniformValue(uniformName, value, transpose);

        int location = getUniformLocation(uniformName);
        if (location != -1) {
            memcpy(m_mat4Buffer, &value[0], sizeof(GLfloat) * 16);
            glUniformMatrix4fv(location, 1, (transpose) ? GL_TRUE : GL_FALSE,
                               m_mat4Buffer);
            return true;
        }
        return false;
    }

    bool Shader::setUniformValue(const std::string &uniformName,
                                 GLfloat *matrix4x4, bool transpose) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glUniformMatrix4fv(location, 1, (transpose) ? GL_TRUE : GL_FALSE,
                               matrix4x4);
            return true;
        }
        return false;
    }

    bool Shader::getUniformValue(const std::string &uniformName,
                                 glm::mat4x4 &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glGetUniformfv(m_Program, location, m_mat4Buffer);
            //            value.setFromOpenGLMatrix(m_mat4Buffer);

            memcpy(&value[0], m_mat4Buffer, sizeof(GLfloat) * 16);

            return true;
        }
        return false;
    }

    bool Shader::setUniformValue(const char *uniformName, GLuint value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            GLuint oldValue;
            if (getUniformValue(uniformName, oldValue)) {
                if (oldValue == value)
                    return true;
            }

            glUniform1i(location, value);
            return true;
        }
        return false;
    }

    bool Shader::getUniformValue(const char *uniformName, GLuint &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            GLint t;
            glGetUniformiv(m_Program, location, &t);
            value = t;
            return true;
        }
        return false;
    }

    bool Shader::setUniformValue(const char *uniformName,
                                 const glm::vec3 &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glm::vec3 oldValue;
            if (getUniformValue(uniformName, oldValue)) {
                if (oldValue == value)
                    return true;
            }

            glUniform3f(location, value.x, value.y, value.z);

            return true;
        }
        return false;
    }

    bool Shader::getUniformValue(const char *uniformName, glm::vec3 &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glGetUniformfv(m_Program, location, m_vec3Buffer);

            //            value.setX(m_vec3Buffer[0]);
            //            value.setY(m_vec3Buffer[1]);
            //            value.setZ(m_vec3Buffer[2]);
            //            value.setW(0.0);

            memcpy(&value[0], m_vec3Buffer, sizeof(GLfloat) * 3);

            return true;
        }
        return false;
    }

    bool Shader::setUniformValue(const char *uniformName, float value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            float oldValue;
            if (getUniformValue(uniformName, oldValue)) {
                if (oldValue == value)
                    return true;
            }

            glUniform1f(location, value);
            return true;
        }
        return false;
    }

    bool Shader::getUniformValue(const char *uniformName, float &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glGetUniformfv(m_Program, location, &value);
            return true;
        }
        return false;
    }

    bool Shader::setUniformValue(const char *uniformName,
                                 const glm::vec4 &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glm::vec4 oldValue;
            if (getUniformValue(uniformName, oldValue)) {
                if (oldValue == value)
                    return true;
            }

            glUniform4f(location, value.x, value.y, value.z, value.w);

            return true;
        }
        return false;
    }

    bool Shader::getUniformValue(const char *uniformName, glm::vec4 &value) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glGetUniformfv(m_Program, location, m_vec4Buffer);

            //            value.setX(m_vec4Buffer[0]);
            //            value.setY(m_vec4Buffer[1]);
            //            value.setZ(m_vec4Buffer[2]);
            //            value.setW(m_vec4Buffer[3]);
            memcpy(&value[0], m_vec4Buffer, sizeof(GLfloat) * 4);

            return true;
        }
        return false;
    }

    bool Shader::setUniformValue(const char *uniformName, float f1, float f2) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            float oldValue1, oldValue2;
            if (getUniformValue(uniformName, oldValue1, oldValue2)) {
                if (oldValue1 == f1)
                    return true;
                if (oldValue2 == f2)
                    return true;
            }

            glUniform2f(location, f1, f2);

            return true;
        }
        return false;
    }

    bool Shader::getUniformValue(const char *uniformName, float &f1,
                                 float &f2) {
        int location = getUniformLocation(uniformName);
        if (location != -1) {
            glGetUniformfv(m_Program, location, m_vec4Buffer);

            f1 = m_vec4Buffer[0];
            f2 = m_vec4Buffer[1];

            return true;
        }
        return false;
    }

    GLuint Shader::compileShader(const std::string &source, GLenum type) {
        GLuint shader;
        GLint status(GL_FALSE);
        shader = glCreateShader(type);

        GLchar *str = (GLchar *)source.c_str();

        glShaderSource(shader, 1, &str, NULL);
        glCompileShader(shader);

#if !defined(NDEBUG)
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 0) {
            GLchar *log = (GLchar *)malloc(logLength);
            glGetShaderInfoLog(shader, logLength, &logLength, log);
            //            std::cout << "Shader compile log:" << std::endl <<
            //            log;
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Shader compile log: %s",
                         log);
            free(log);
        }
#endif

        if (!compileStatus(shader)) {
            glDeleteShader(shader);
            shader = 0;
        }

        return shader;
    }

    bool Shader::compileStatus(GLuint shader) {
        GLint compileStatus = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

#if !defined(NDEBUG)
        GLint log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        if (log_length > 0) {
            GLchar log_buffer[1024];
            glGetShaderInfoLog(shader, log_length, NULL, log_buffer);
            //            std::cout << log_buffer << std::endl;
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", log_buffer);
        }
#endif
        return (compileStatus == GL_TRUE);
    }

    bool Shader::linkProgram(GLuint program) {
        GLint status;
        glLinkProgram(program);

#if !defined(NDEBUG)
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 0) {
            GLchar *log = (GLchar *)malloc(logLength);
            glGetProgramInfoLog(program, logLength, &logLength, log);
            //            std::cout << "Program link log:\n" << log;
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Program link log: %s\n",
                         log);
            free(log);
        }
#endif

        glGetProgramiv(program, GL_LINK_STATUS, &status);
        return (status == GL_TRUE);
    }

    bool Shader::validateProgram(GLuint programPointer) {
        GLint status(GL_FALSE);

        glValidateProgram(programPointer);

        glGetProgramiv(programPointer, GL_VALIDATE_STATUS, &status);
        if (status == GL_FALSE) {
            GLint logLength;
            glGetProgramiv(programPointer, GL_INFO_LOG_LENGTH, &logLength);
            if (logLength > 0) {
                GLchar *log = (GLchar *)malloc(logLength);
                glGetProgramInfoLog(programPointer, logLength, &logLength, log);

                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "Program validate log:\n%s", log);
                free(log);
            }
            return false;
        }

        return true;
    }
} // namespace NJLIC
