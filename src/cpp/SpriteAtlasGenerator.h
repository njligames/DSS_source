//
//  SpriteAtlasGenerator.h
//  SDLSkeleton
//
//  Created by James Folk on 3/2/20.
//

#ifndef SpriteAtlasGenerator_h
#define SpriteAtlasGenerator_h

#include "Date.h"
#include "PubSub.h"

#include "Image.h"
#include "nlohmann/json.hpp"

namespace NJLIC {
    class SpriteAtlasGenerator : public Publisher {
        static SpriteAtlasGenerator *sSpriteAtlasGenerator;
        SpriteAtlasGenerator();
        ~SpriteAtlasGenerator();
        SpriteAtlasGenerator(const SpriteAtlasGenerator &) = delete;
        const SpriteAtlasGenerator &operator=(const SpriteAtlasGenerator &);

        Image *mImage;

      public:
        static SpriteAtlasGenerator *getInstance();
        static void destroyInstance();

        void init(int width, int height, int numComponents);
        void init(int numComponents);
        void unInit();
        bool addImage(const std::string &name, void *buffer, int width,
                      int height);

        bool generate();

        int getHeight();
        int getWidth();
        int getNumComponents();
    };
} // namespace NJLIC

#endif /* SpriteAtlasGenerator_hpp */
