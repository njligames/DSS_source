//
//  UtilDSS.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef UtilDSS_h
#define UtilDSS_h

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
};



#endif /* Util_h */
