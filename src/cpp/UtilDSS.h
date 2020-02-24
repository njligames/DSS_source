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

class UtilDSS {
  public:
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
};

#endif /* Util_h */
