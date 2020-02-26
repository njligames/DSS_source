//
//  UtilDSS.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef UtilDSS_h
#define UtilDSS_h

#include "SDL.h"
#include <algorithm>
#include <cctype>
#include <optional>
#include <regex>
#include <stdexcept>
#include <string>

#include "glm/glm.hpp"

#define FORMATSTRING_MAT4x4                                                    \
    "{\"glm::mat4x4\":[{\"xx\":\"%f\", \"xy\":\"%f\", \"xz\":\"%f\", "         \
    "\"xw\":\"%f\", \"yx\":\"%f\", \"yy\":\"%f\", \"yz\":\"%f\", "             \
    "\"yw\":\"%f\", \"zx\":\"%f\", \"zy\":\"%f\", \"zz\":\"%f\", "             \
    "\"zw\":\"%f\", \"wx\":\"%f\", \"wy\":\"%f\", \"wz\":\"%f\", "             \
    "\"ww\":\"%f\"}]}"

class UtilDSS {
  public:
    static const char *string_format(const char *fmt, ...) {
        static char sBuffer[4096] = "";

        va_list args;
        va_start(args, fmt);
        vsnprintf(sBuffer, 2048, fmt, args);
        //    perror (sBuffer);
        va_end(args);
        return sBuffer;
    }

    //    static std::string to_string(const glm::vec2 &from) {
    //        std::string ret(string_format(
    //        FORMATSTRING_MAT4x4, m_buffer[0], m_buffer[1], m_buffer[2],
    //        m_buffer[3], m_buffer[4], m_buffer[5], m_buffer[6], m_buffer[7],
    //        m_buffer[8], m_buffer[9], m_buffer[10], m_buffer[11],
    //        m_buffer[12], m_buffer[13],
    //                                      m_buffer[14], m_buffer[15]));
    //        return ret;
    //    }
    //
    //    static std::string to_string(const glm::vec3 &from) {
    //        std::string ret(string_format(
    //        FORMATSTRING_MAT4x4, m_buffer[0], m_buffer[1], m_buffer[2],
    //        m_buffer[3], m_buffer[4], m_buffer[5], m_buffer[6], m_buffer[7],
    //        m_buffer[8], m_buffer[9], m_buffer[10], m_buffer[11],
    //        m_buffer[12], m_buffer[13],
    //                                      m_buffer[14], m_buffer[15]));
    //        return ret;
    //    }
    //
    //    static std::string to_string(const glm::vec4 &from) {
    //        std::string ret(string_format(
    //        FORMATSTRING_MAT4x4, m_buffer[0], m_buffer[1], m_buffer[2],
    //        m_buffer[3], m_buffer[4], m_buffer[5], m_buffer[6], m_buffer[7],
    //        m_buffer[8], m_buffer[9], m_buffer[10], m_buffer[11],
    //        m_buffer[12], m_buffer[13],
    //                                      m_buffer[14], m_buffer[15]));
    //        return ret;
    //    }

    //    glm::mat4 m;
    //    const btMatrix3x3 &basis = m_btTransform->getBasis();
    //    for (int r = 0; r < 3; r++)
    //    {
    //        for (int c = 0; c < 3; c++)
    //        {
    //            m[c][r] = basis[r][c];
    //        }
    //    }
    //
    //    btVector3 origin = m_btTransform->getOrigin();
    //
    //    m[3][0] = origin.getX();
    //    m[3][1] = origin.getY();
    //    m[3][2] = origin.getZ();
    //    // unit scale
    //    m[0][3] = 0.0f;
    //    m[1][3] = 0.0f;
    //    m[2][3] = 0.0f;
    //    m[3][3] = 1.0f;
    //
    //    return m;
    static std::string to_string(const glm::mat4x4 &from) {

        std::string ret(string_format(
            FORMATSTRING_MAT4x4, from[0][0], from[0][1], from[0][2], from[0][3],
            from[1][0], from[1][1], from[1][2], from[1][3], from[2][0],
            from[2][1], from[2][2], from[2][3], from[3][0], from[3][1],
            from[3][2], from[3][3]));
        return ret;
    }

    static std::string to_string(const float *transformMatrix) {

        if (transformMatrix) {

            std::string ret(string_format(
                FORMATSTRING_MAT4x4, transformMatrix[0], transformMatrix[1],
                transformMatrix[2], transformMatrix[3], transformMatrix[4],
                transformMatrix[5], transformMatrix[6], transformMatrix[7],
                transformMatrix[8], transformMatrix[9], transformMatrix[10],
                transformMatrix[11], transformMatrix[12], transformMatrix[13],
                transformMatrix[14], transformMatrix[15]));
            return ret;
        }
        return "NULL";
    }

    static bool validUrl(const std::string &url) {
        std::regex url_regex(
            R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)",
            std::regex::extended);
        std::smatch url_match_result;

        bool ret = std::regex_match(url, url_match_result, url_regex);
        assert(ret);
        return ret;
    }

    static uint64_t timeSinceEpochMillisec() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(
                   system_clock::now().time_since_epoch())
            .count();
    }

    static std::string tolower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return str;
    }

    static char *loadFile(const std::string &filePath, size_t &fileSize) {
        const std::string base_path(SDL_GetBasePath());

        std::string jsonFilePath = base_path + filePath;
        char *_buffer = nullptr;

        SDL_RWops *rw = SDL_RWFromFile(jsonFilePath.c_str(), "rb");
        if (rw) {
            fileSize = SDL_RWsize(rw);

            _buffer = (char *)malloc(fileSize + 1);
            memset(_buffer, 0, sizeof(char) * fileSize + 1);

            Sint64 nb_read_total = 0, nb_read = 1;
            char *buf = (char *)_buffer;
            while (nb_read_total < fileSize && nb_read != 0) {
                nb_read = SDL_RWread(rw, buf, 1, (fileSize - nb_read_total));
                nb_read_total += nb_read;
                buf += nb_read;
            }
            SDL_RWclose(rw);
            if (nb_read_total != fileSize) {
                free(_buffer);
                _buffer = nullptr;
            }
        }
        return _buffer;
    }

    static unsigned int getClosestValidGLDim(const unsigned int dim) {
        for (unsigned int shift = 0; shift < 12; shift++) {
            if ((1 << shift) > dim)
                return 1 << (shift);
        }
        return 1 << 11;
    }

    static void *loadImage(const std::string &filePath, int *width, int *height,
                           int *channels_in_file);
};

#endif /* Util_h */
