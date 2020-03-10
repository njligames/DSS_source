//
//  SpriteAtlasGenerator.cpp
//  SDLSkeleton
//
//  Created by James Folk on 3/2/20.
//

#include "SpriteAtlasGenerator.h"

#include <OpenGL/gl.h>
#include <OpenGL/glext.h>

namespace NJLIC {
    SpriteAtlasGenerator *SpriteAtlasGenerator::sSpriteAtlasGenerator = nullptr;

    SpriteAtlasGenerator::SpriteAtlasGenerator() { mImage = new Image(); }

    SpriteAtlasGenerator::~SpriteAtlasGenerator() { delete mImage; }

    SpriteAtlasGenerator *SpriteAtlasGenerator::getInstance() {
        if (nullptr == sSpriteAtlasGenerator)
            sSpriteAtlasGenerator = new SpriteAtlasGenerator();
        return sSpriteAtlasGenerator;
    }

    void SpriteAtlasGenerator::destroyInstance() {
        if (nullptr != sSpriteAtlasGenerator)
            delete sSpriteAtlasGenerator;
        sSpriteAtlasGenerator = nullptr;
    }

    void SpriteAtlasGenerator::init(int width, int height, int numComponents) {
        mImage->generate(width, height, numComponents);
    }
    void SpriteAtlasGenerator::init(int numComponents) {
        GLint maxSize[1];
        glGetIntegerv(GL_MAX_TEXTURE_SIZE, maxSize);
        init(maxSize[0], maxSize[0], numComponents);
    }
    void SpriteAtlasGenerator::unInit() {
        delete mImage;
        mImage = new Image();
    }
    bool SpriteAtlasGenerator::addImage(const std::string &name, void *buffer,
                                        int width, int height) {}
    bool SpriteAtlasGenerator::generate() {}

    int SpriteAtlasGenerator::getHeight() {}
    int SpriteAtlasGenerator::getWidth() {}
    int SpriteAtlasGenerator::getNumComponents() {}
} // namespace NJLIC
