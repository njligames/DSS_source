//
//  SpriteAtlasGenerator.cpp
//  SDLSkeleton
//
//  Created by James Folk on 3/2/20.
//

#include "SpriteAtlasGenerator.h"

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

#include "Image.h"
#include "SpriteAtlasGenerator.h"
#include "UtilDSS.h"

#include "stb_image.h"
#include "stb_image_write.h"

#include "nlohmann/json.hpp"
#include <random>
#include <sstream>
#include <string>

#include <cassert>
#include <cstdio>
#include <string>

template <typename... Args>
std::string string_sprintf(const char *format, Args... args) {
    int length = std::snprintf(nullptr, 0, format, args...);
    assert(length >= 0);

    char *buf = new char[length + 1];
    std::snprintf(buf, length + 1, format, args...);

    std::string str(buf);
    delete[] buf;
    return str;
}

namespace NJLIC {

    static unsigned int random_char() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        return dis(gen);
    }

    static std::string generate_hex(const unsigned int len) {
        std::stringstream ss;
        for (auto i = 0; i < len; i++) {
            const auto rc = random_char();
            std::stringstream hexstream;
            hexstream << std::hex << rc;
            auto hex = hexstream.str();
            ss << (hex.length() < 2 ? '0' + hex : hex);
        }
        return ss.str();
    }

    SpriteAtlasGenerator::SpriteAtlasGenerator() : mImageId(0) {
        mImage = new Image();
    }

    SpriteAtlasGenerator::~SpriteAtlasGenerator() { delete mImage; }

    //    void SpriteAtlasGenerator::init(int width, int height, int
    //    numComponents) {
    //        mImage->generate(width, height, numComponents);
    //    }
    //    void SpriteAtlasGenerator::init(int numComponents) {
    //        GLint maxSize[1];
    //        glGetIntegerv(GL_MAX_TEXTURE_SIZE, maxSize);
    //        init(maxSize[0], maxSize[0], numComponents);
    //    }
    //    void SpriteAtlasGenerator::unInit() {
    //        delete mImage;
    //        mImage = new Image();
    //    }
    int SpriteAtlasGenerator::addImage(void *buffer, int width, int height,
                                       int components) {

        Image *img = new Image();

        img->copyData(buffer, width, height, components, "data");

        int id = mImageId++;
        img->setId(id);
        mImageMap.insert(ImagePair(id, img));

        return id;
    }
    bool SpriteAtlasGenerator::removeImage(int _id) {
        ImageMap::const_iterator iter = mImageMap.find(_id);
        if (iter != mImageMap.end()) {
            mImageMap.erase(iter);
            delete iter->second;

            return true;
        }
        return false;
    }
    void SpriteAtlasGenerator::reset() {
        for (ImagePair p : mImageMap)
            removeImage(p.first);
    }

    // Sample
    /*
    stbrp_context context;

    struct stbrp_rect rects[100];

    for (int i=0; i< 100; i++)
    {
        rects[i].id = i;
        rects[i].w = 100+i;
        rects[i].h = 100+i;
        rects[i].x = 0;
        rects[i].y = 0;
        rects[i].was_packed = 0;
    }

    int rectsLength = sizeof(rects)/sizeof(rects[0]);

    int nodeCount = 4096*2;
    struct stbrp_node nodes[nodeCount];


    stbrp_init_target(&context, 4096, 4096, nodes, nodeCount);
    stbrp_pack_rects(&context, rects, rectsLength);

    for (int i=0; i< 100; i++)
    {
        printf("rect %i (%hu,%hu) was_packed=%i\n", rects[i].id, rects[i].x,
    rects[i].y, rects[i].was_packed);
    }
     */

    void SpriteAtlasGenerator::packRects(int width, int height,
                                         const std::vector<Image *> &images,
                                         RectMap &packed,
                                         std::vector<Image *> &imageLeftOver) {
        int nodeCount = 4096 * 2;
        struct stbrp_node nodes[nodeCount];

        stbrp_context context;

        int i = 0;
        struct stbrp_rect *rects = new struct stbrp_rect[images.size()];

        for (Image *pImage : images) {

            rects[i].id = pImage->getId();
            rects[i].w = pImage->getWidth();
            rects[i].h = pImage->getHeight();
            rects[i].x = 0;
            rects[i].y = 0;
            rects[i].was_packed = 0;

            ++i;
        }

        stbrp_init_target(&context, width, height, nodes, nodeCount);
        stbrp_pack_rects(&context, rects, images.size());

        //        pImage->generate(16384, 16384, numComponents);
        //    sourceImage->generate(_width, _height, 3, glm::vec4(1.0, 0.0,
        //    0.0, 1.0));

        //    RectMap _map;

        packed.clear();
        imageLeftOver.clear();
        for (int i = 0; i < images.size(); i++) {
            printf("rect %i (%hu,%hu) was_packed=%i\n", rects[i].id, rects[i].x,
                   rects[i].y, rects[i].was_packed);

            stbrp_rect rect;
            rect.id = rects[i].id;
            rect.w = rects[i].w;
            rect.h = rects[i].h;
            rect.x = rects[i].x;
            rect.y = rects[i].y;
            rect.was_packed = rects[i].was_packed;

            if (rect.was_packed != 0) {
                packed.insert(RectPair(rect.id, rect));
            } else {
                imageLeftOver.push_back(mImageMap[rect.id]);
            }
        }

        delete[] rects;
    }
    void SpriteAtlasGenerator::generate(
        std::vector<SpriteAtlas *> &spriteAtlasVector, unsigned int width, unsigned int height, int numComponents) {



        auto _width = width;///16384;
        auto _height = height;//16384;

        std::vector<Image *> images;
        RectMap packed;
        std::vector<Image *> imageLeftOver;

        std::vector<Image *> imageMaps;
        std::vector<nlohmann::json> jsonMaps;

        for (ImagePair p : mImageMap) {
            Image *pImage = p.second;
            images.push_back(pImage);
        }

        do {
            RectMap packed;

            packRects(_width, _height, images, packed, imageLeftOver);

            SpriteAtlas *pSpriteAtlas = new SpriteAtlas();
            pSpriteAtlas->mSourceImage = new Image();

            pSpriteAtlas->mSourceImage->generate(_width, _height, 3,
                                                 glm::vec4(0.0, 0.0, 0.0, 1.0));

            int idx = 0;
            for (ImagePair p : mImageMap) {
                Image *pImage = p.second;
                auto iter = packed.find(pImage->getId());
                if (iter != packed.end()) {
                    struct stbrp_rect rect = iter->second;
                    pSpriteAtlas->mSourceImage->setPixels(
                        glm::vec2(rect.x, rect.y), *pImage);
                    std::string object = R"(
                    {
                        "x":%d,
                        "y":%d,
                        "width":%d,
                        "height":%d,
                        "id":%d
                    }
                    )";
                    std::string str_obj(
                        string_sprintf(object.c_str(), rect.x, rect.y,
                                       pImage->getWidth(), pImage->getHeight(),
                                       pImage->getId())
                            .c_str());

                    pSpriteAtlas->mSourceImageMap.push_back(
                        nlohmann::json::parse(str_obj.c_str()));
//#if !(defined(NDEBUG))
//                    std::string n(
//                        std::to_string(UtilDSS::timeSinceEpochMillisec()));
//                    std::string indice(std::to_string(idx++));
//                    n += "_" + indice + "_";
//                    n += "_downloaded_image_stbi.jpg";
//                    stbi_write_jpg(n.c_str(), pImage->getWidth(),
//                                   pImage->getHeight(),
//                                   pImage->getNumberOfComponents(),
//                                   pImage->getDataPtr(), 100);
//#endif
                }
            }

            spriteAtlasVector.push_back(pSpriteAtlas);

            images.clear();

            if (imageLeftOver.size() > 0)
                std::copy(images.begin(), imageLeftOver.begin(),
                          imageLeftOver.end());

        } while (imageLeftOver.size() > 0);

        //#if !(defined(NDEBUG))
        int idx = 0;
        for (SpriteAtlas *sa : spriteAtlasVector) {

            std::string n(std::to_string(UtilDSS::timeSinceEpochMillisec()));
            std::string indice(std::to_string(idx++));
            n += "_" + indice + "_";
            n += "_generated_image_stbi.jpg";
            stbi_write_jpg(n.c_str(), sa->mSourceImage->getWidth(),
                           sa->mSourceImage->getHeight(),
                           sa->mSourceImage->getNumberOfComponents(),
                           sa->mSourceImage->getDataPtr(), 100);
        }

        //#endif
    }

    int SpriteAtlasGenerator::getHeight() {}
    int SpriteAtlasGenerator::getWidth() {}
    int SpriteAtlasGenerator::getNumComponents() {}
} // namespace NJLIC
