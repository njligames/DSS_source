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

#include "stb_rect_pack.h"

namespace NJLIC {
    class SpriteAtlas {
        friend class SpriteAtlasGenerator;
        SpriteAtlas(const SpriteAtlas &) = delete;
        const SpriteAtlas &operator=(const SpriteAtlas &) = delete;

        Image *mSourceImage;
        nlohmann::json mSourceImageMap;

      public:
        SpriteAtlas() {}
        virtual ~SpriteAtlas() {}
    };
    class SpriteAtlasGenerator : public Publisher {

        SpriteAtlasGenerator(const SpriteAtlasGenerator &) = delete;
        const SpriteAtlasGenerator &
        operator=(const SpriteAtlasGenerator &) = delete;

        using ImageMap = std::map<int, Image *>;
        using ImagePair = std::pair<int, Image *>;

        ImageMap mImageMap;
        int mImageId;

        Image *mImage;

        using RectMap = std::map<int, struct stbrp_rect>;
        using RectPair = std::pair<int, struct stbrp_rect>;

      protected:
        void packRects(int width, int height,
                       const std::vector<Image *> &images, RectMap &packed,
                       std::vector<Image *> &imageLeftOver);

      public:
        SpriteAtlasGenerator();
        ~SpriteAtlasGenerator();

        //        void init(int width, int height, int numComponents);
        //        void init(int numComponents = 4);
        //        void unInit();
        int addImage(void *buffer, int width, int height, int components);
        bool removeImage(int _id);
        void reset();

        void generate(std::vector<SpriteAtlas *> &spriteAtlasVector, unsigned int width, unsigned int height,
                      int numComponents = 3);

        int getHeight();
        int getWidth();
        int getNumComponents();
    };
} // namespace NJLIC

#endif /* SpriteAtlasGenerator_hpp */
