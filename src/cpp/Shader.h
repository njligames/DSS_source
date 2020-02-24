//
//  Shader.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef Shader_h
#define Shader_h

#include <map>
#include <string>

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#include "glm/glm.hpp"

namespace NJLIC {

    class Shader {
        Shader(const Shader &) = delete;
        Shader &operator=(const Shader &) = delete;

      public:
        Shader();
        virtual ~Shader();

        bool load(const std::string &vertexSource,
                  const std::string &fragmentSource);

        void unLoad();
        bool isLoaded() const;

        bool use() const;

        int getAttributeLocation(const std::string &attributeName) const;

        int getUniformLocation(const std::string &uniformName);

        bool setUniformValue(const std::string &uniformName,
                             const glm::mat4x4 &value, bool transpose = false);
        bool setUniformValue(const std::string &uniformName, GLfloat *matrix4x4,
                             bool transpose = false);
        bool getUniformValue(const std::string &uniformName,
                             glm::mat4x4 &value);

        bool setUniformValue(const char *uniformName, GLuint value);
        bool getUniformValue(const char *uniformName, GLuint &value);

        bool setUniformValue(const char *uniformName, const glm::vec3 &value);
        bool getUniformValue(const char *uniformName, glm::vec3 &value);

        bool setUniformValue(const char *uniformName, float value);
        bool getUniformValue(const char *uniformName, float &value);

        bool setUniformValue(const char *uniformName, const glm::vec4 &value);
        bool getUniformValue(const char *uniformName, glm::vec4 &value);

        bool setUniformValue(const char *uniformName, float f1, float f2);
        bool getUniformValue(const char *uniformName, float &f1, float &f2);

      protected:
        GLuint compileShader(const std::string &source, GLenum type);
        bool compileStatus(GLuint shader);

        bool linkProgram(GLuint program);
        bool validateProgram(GLuint program);

      private:
        GLuint m_Program;

        GLfloat *m_mat4Buffer;
        GLfloat *m_vec3Buffer;
        GLfloat *m_vec4Buffer;

        using UniformMap = std::map<std::string, int>;
        using UniformPair = std::pair<std::string, int>;

        UniformMap m_UniformMap;
    };

    // class Shader {
    //    static bool compileShader(GLuint &shader, GLenum type, const
    //    std::string &source); static bool linkProgram(GLuint programPointer);
    //    static bool validateProgram(GLuint programPointer);
    // public:
    //    static bool load(const std::string &vertShaderSource, const
    //    std::string &fragShaderSource, GLuint &programPointer);
    // private:
    //
    //};
} // namespace NJLIC

#endif /* Shader_hpp */
