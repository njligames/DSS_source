//
//  UtilDSS.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef UtilDSS_h
#define UtilDSS_h

#include <optional>
#include <stdexcept>
#include <regex>
#include <algorithm>
#include <cctype>
#include <string>

class UtilDSS {
public:
    
    static bool validUrl(const std::string &url) {
        std::regex url_regex (
          R"(^(([^:\/?#]+):)?(//([^\/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?)",
          std::regex::extended
        );
        std::smatch url_match_result;

        bool ret = std::regex_match(url, url_match_result, url_regex);
        assert(ret);
        return ret;
    }
    
    static uint64_t timeSinceEpochMillisec() {
      using namespace std::chrono;
      return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
    
    static std::string tolower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
        return str;
    }
};



#endif /* Util_h */
