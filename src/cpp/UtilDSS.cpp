//
//  UtilDSS.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/25/20.
//

#include "UtilDSS.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#endif

#ifndef STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#endif

#ifndef STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"
#endif

void *UtilDSS::loadImage(const std::string &filePath, int *width, int *height,
                         int *channels_in_file) {

    const std::string base_path(SDL_GetBasePath());

    std::string fullFilePath = base_path + filePath;

    void *buffer = (void *)stbi_load(fullFilePath.c_str(), width, height,
                                     channels_in_file, 4);
    return buffer;
}

void *UtilDSS::loadDefaultCardImage(int *width, int *height,
                                    int *channels_in_file, size_t *fileSize) {

    std::string base_path(SDL_GetBasePath());
    std::string defaultImage("assets/Default.png");
    base_path += defaultImage;

    void *buffer = (void *)stbi_load(base_path.c_str(), width, height,
                                     channels_in_file, 0);

    if (nullptr != buffer) {
        *fileSize = ((*width) * (*height) * (*channels_in_file));
    }

    return buffer;
}
