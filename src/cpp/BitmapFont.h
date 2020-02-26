//
//  BitmapFont.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef BitmapFont_h
#define BitmapFont_h

#include <map>
#include <string>

#include "glm/glm.hpp"

struct BitmapFontData;

class BitmapFont {

    using Map = std::map<std::string, BitmapFontData *>;
    using Pair = std::pair<std::string, BitmapFontData *>;

    Map mFontMap;

    static BitmapFont *sBitmapFont;
    BitmapFont();
    ~BitmapFont();

    glm::vec2 mCurrentBounds;
    std::string mCurrentFontName;
    std::string mCurrentPrintf;

    bool load(const std::string &fontName);
    bool unLoad(const std::string &fontName);

  public:
    static BitmapFont *getInstance() {
        if (nullptr == sBitmapFont)
            sBitmapFont = new BitmapFont();
        return sBitmapFont;
    }

    static void destroyInstance() {
        if (nullptr != sBitmapFont)
            delete sBitmapFont;
        sBitmapFont = nullptr;
    }

    const glm::vec2 &getCurrentBounds() const;
    const std::string &getCurrentFontName() const;

    void setCurrentBounds(const glm::vec2 &bounds);
    void setCurrentFontName(const std::string &fontName);

    void printf(const char *fmt, ...);
};

#endif /* BitmapFont_hpp */
