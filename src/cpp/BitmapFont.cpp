//
//  BitmapFont.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#include "BitmapFont.h"
#include "UtilDSS.h"

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Dss data = nlohmann::json::parse(jsonString);

#include "nlohmann/json.hpp"

#include <optional>
#include <regex>
#include <stdexcept>
#include <stdio.h>

#include "SDL.h"

#include "stb_image.h"
#include "stb_image_write.h"

namespace BMF {
    using nlohmann::json;

    inline json get_untyped(const json &j, const char *property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json &j, std::string property) {
        return get_untyped(j, property.data());
    }

    class Info {
      public:
        Info() = default;
        virtual ~Info() = default;

      private:
        std::string fontface;
        int64_t lineHeight;
        int64_t base;

      public:
        const std::string &getFontface() const { return fontface; }
        std::string &getMutableFontface() { return fontface; }
        void setFontface(const std::string &value) { this->fontface = value; }

        const int64_t &getLineHeight() const { return lineHeight; }
        int64_t &getMutableLineHeight() { return lineHeight; }
        void setLineHeight(const int64_t &value) { this->lineHeight = value; }

        const int64_t &getBase() const { return base; }
        int64_t &getMutableBase() { return base; }
        void setBase(const int64_t &value) { this->base = value; }
    };

    class Dss {
      public:
        Dss() = default;
        virtual ~Dss() = default;

      private:
        Info info;
        std::map<std::string, int64_t> kernings;
        std::map<std::string, int64_t> mapping;
        std::vector<std::map<std::string, int64_t>> frames;

      public:
        const Info &getInfo() const { return info; }
        Info &getMutableInfo() { return info; }
        void setInfo(const Info &value) { this->info = value; }

        const std::map<std::string, int64_t> &getKernings() const {
            return kernings;
        }
        std::map<std::string, int64_t> &getMutableKernings() {
            return kernings;
        }
        void setKernings(const std::map<std::string, int64_t> &value) {
            this->kernings = value;
        }

        const std::map<std::string, int64_t> &getMapping() const {
            return mapping;
        }
        std::map<std::string, int64_t> &getMutableMapping() { return mapping; }
        void setMapping(const std::map<std::string, int64_t> &value) {
            this->mapping = value;
        }

        const std::vector<std::map<std::string, int64_t>> &getFrames() const {
            return frames;
        }
        std::vector<std::map<std::string, int64_t>> &getMutableFrames() {
            return frames;
        }
        void
        setFrames(const std::vector<std::map<std::string, int64_t>> &value) {
            this->frames = value;
        }
    };
} // namespace BMF

namespace nlohmann {
    void from_json(const json &j, BMF::Info &x);
    void to_json(json &j, const BMF::Info &x);

    void from_json(const json &j, BMF::Dss &x);
    void to_json(json &j, const BMF::Dss &x);

    inline void from_json(const json &j, BMF::Info &x) {
        x.setFontface(j.at("fontface").get<std::string>());
        x.setLineHeight(j.at("lineHeight").get<int64_t>());
        x.setBase(j.at("base").get<int64_t>());
    }

    inline void to_json(json &j, const BMF::Info &x) {
        j = json::object();
        j["fontface"] = x.getFontface();
        j["lineHeight"] = x.getLineHeight();
        j["base"] = x.getBase();
    }

    inline void from_json(const json &j, BMF::Dss &x) {
        x.setInfo(j.at("info").get<BMF::Info>());
        x.setKernings(j.at("kernings").get<std::map<std::string, int64_t>>());
        x.setMapping(j.at("mapping").get<std::map<std::string, int64_t>>());
        x.setFrames(
            j.at("frames").get<std::vector<std::map<std::string, int64_t>>>());
    }

    inline void to_json(json &j, const BMF::Dss &x) {
        j = json::object();
        j["info"] = x.getInfo();
        j["kernings"] = x.getKernings();
        j["mapping"] = x.getMapping();
        j["frames"] = x.getFrames();
    }
} // namespace nlohmann

struct BitmapFontData {
    BMF::Dss _jsonData;
    int _width, _height, _channels_in_file;
    void *_imageFileData;

    ~BitmapFontData() { free(_imageFileData); }
};

BitmapFont *BitmapFont::sBitmapFont = nullptr;

BitmapFont::BitmapFont()
    : mCurrentBounds(glm::vec2(std::numeric_limits<float>::max(),
                               std::numeric_limits<float>::max())),
      mCurrentFontName(""), mCurrentPrintf("") {}

BitmapFont::~BitmapFont() {
    for (Map::iterator iter = mFontMap.begin(); iter != mFontMap.end();
         ++iter) {
        delete iter->second;
    }
}

bool BitmapFont::load(const std::string &fontName) {
    std::string fontNameLower(UtilDSS::tolower(fontName));

    if (mFontMap.find(fontNameLower) == mFontMap.end()) {
        const std::string base_path(SDL_GetBasePath());
        static char buff[4096];

        BitmapFontData *bfd = new BitmapFontData();

        size_t jsonFileSize;
        std::string defaultJson("assets/fonts/%s.json");
        snprintf(buff, sizeof(buff), defaultJson.c_str(), fontName.c_str());
        char *jsonFileBuffer =
            UtilDSS::loadFile(std::string(buff), jsonFileSize);
        if (nullptr != jsonFileBuffer) {

#if !(defined(NDEBUG))
            std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
            n += "_bitmapfont_";
            n += fontName;
            n += ".json";
            FILE *fp = fopen(n.c_str(), "wb");
            if (fp) {
                fwrite(jsonFileBuffer, sizeof(char), jsonFileSize, fp);

                fclose(fp);
            } else {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                             "!!! Failed to create file on the disk\n");
            }
#endif

            bfd->_jsonData = nlohmann::json::parse(jsonFileBuffer);
            free(jsonFileBuffer);
        }

        std::string defaultImage("assets/fonts/%s.png");
        snprintf(buff, sizeof(buff), defaultImage.c_str(), fontName.c_str());
        std::string imageFilePath = base_path + std::string(buff);

        bfd->_imageFileData =
            (void *)stbi_load(imageFilePath.c_str(), &bfd->_width,
                              &bfd->_height, &bfd->_channels_in_file, 0);

#if !(defined(NDEBUG))
        std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
        n += "_bitmapfont_";
        n += fontName;
        n += ".jpg";
        stbi_write_jpg(n.c_str(), bfd->_width, bfd->_height,
                       bfd->_channels_in_file, bfd->_imageFileData, 100);
#endif
        mFontMap.insert(Pair(fontNameLower, bfd));

        return true;
    }
    return false;
}

bool BitmapFont::unLoad(const std::string &fontName) {
    std::string fontNameLower(UtilDSS::tolower(fontName));

    Map::iterator iter = mFontMap.find(fontNameLower);
    if (iter != mFontMap.end()) {
        BitmapFontData *bfd = iter->second;
        delete bfd;

        mFontMap.erase(iter);

        return true;
    }
    return false;
}

const glm::vec2 &BitmapFont::getCurrentBounds() const { return mCurrentBounds; }

const std::string &BitmapFont::getCurrentFontName() const {
    return mCurrentFontName;
}

void BitmapFont::setCurrentBounds(const glm::vec2 &bounds) {
    mCurrentBounds = bounds;
}

void BitmapFont::setCurrentFontName(const std::string &fontName) {
    mCurrentFontName = fontName;
    load(mCurrentFontName);
}

void BitmapFont::printf(const char *fmt, ...) {
    char buffer[2048];
    va_list args;

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    va_end(args);

    mCurrentPrintf = std::string(buffer);

    SDL_LogVerbose(SDL_LOG_CATEGORY_TEST, "BitmapFont::printf: %s\n",
                   mCurrentPrintf.c_str());
}
