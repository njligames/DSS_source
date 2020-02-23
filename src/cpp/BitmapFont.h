//
//  BitmapFont.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef BitmapFont_h
#define BitmapFont_h

#include <string>
#include <map>

struct BitmapFontData;

class BitmapFont {
    
    using Map   = std::map<std::string, BitmapFontData*>;
    using Pair   = std::pair<std::string, BitmapFontData*>;
    
    Map mFontMap;
public:
    BitmapFont();
    ~BitmapFont();
    
    void load(const std::string &fontName);
    
    
    void printf(const char *fontName, const char *fmt, ...);
};

#endif /* BitmapFont_hpp */
