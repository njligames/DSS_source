//
//  Image.cpp
//  JLIGameEngineTest
//
//  Created by James Folk on 1/8/15.
//  Copyright (c) 2015 James Folk. All rights reserved.
//

#include "Image.h"

#include "stb_image.h"
#include "SDL.h"

namespace NJLIC {
    Image::Image()
        : m_RawData(NULL), m_RawDataSize(0),
          m_Width(0), m_Height(0), m_Componenents(0), m_Filename("") {}

    Image::Image(const Image &copy)
        :m_RawData(NULL), m_RawDataSize(0),
          m_Width(copy.getWidth()), m_Height(copy.getHeight()),
          m_Componenents(copy.getNumberOfComponents()),
          m_Filename(copy.getFilename()) {
        copyData(copy.getDataPtr(), copy.getDataSize(), copy.getWidth(),
                 copy.getHeight(), copy.getNumberOfComponents(), copy.getFilename());
    }

    Image::~Image() {
        if (m_RawData)
            delete[] m_RawData;
        m_RawData = NULL;
    }

    Image &Image::operator=(const Image &rhs) {
        if (this != &rhs) {
            copyData(rhs.getDataPtr(), rhs.getDataSize(), rhs.getWidth(),
                     rhs.getHeight(), rhs.getNumberOfComponents(), rhs.getFilename());
        }
        return *this;
    }

    Image *Image::createSubImage(const Image &imageSource,
                                 const glm::vec2 &position,
                                 const glm::vec2 &dimensions) {
        Image *img = new Image();
        img->generate(dimensions.x, dimensions.y,
                      imageSource.getNumberOfComponents());
        img->setPixels(position, dimensions, imageSource);
        return img;
    }

    bool Image::setPixel(const glm::vec2 &position, const glm::vec4 &color) {
//        if (!isPvr()) {
            if ((m_RawData) && (position.x < getWidth()) &&
                (position.y < getHeight())) {
                int x_indice = position.x * getNumberOfComponents();
                int y_indice =
                    position.y * getNumberOfComponents() * getWidth();

                switch (getNumberOfComponents()) {
                case 4:
                    m_RawData[x_indice + y_indice + 3] = (color.w * 255.0f);
                case 3:
                    m_RawData[x_indice + y_indice + 2] = (color.z * 255.0f);
                case 2:
                    m_RawData[x_indice + y_indice + 1] = (color.y * 255.0f);
                case 1:
                    m_RawData[x_indice + y_indice + 0] = (color.x * 255.0f);
                }
                return true;
            }
//        }

        return false;
    }

    bool Image::setPixel(const glm::vec2 &position, const Image &imageSource) {
        glm::vec4 pixel;
        imageSource.getPixel(position, pixel);
        return setPixel(position, pixel);
    }

    bool Image::getPixel(const glm::vec2 &position, glm::vec4 &pixel) const {
//        if (!isPvr()) {
            if ((m_RawData) && (position.x < getWidth()) &&
                (position.y < getHeight())) {
                int x_indice = position.x * getNumberOfComponents();
                int y_indice =
                    position.y * getNumberOfComponents() * getWidth();
                float red = 0.0f;
                float green = 0.0f;
                float blue = 0.0f;
                float alpha = 0.0f;

                switch (getNumberOfComponents()) {
                case 4:
                    alpha = m_RawData[x_indice + y_indice + 3] / 255.0f;
                case 3:
                    blue = m_RawData[x_indice + y_indice + 2] / 255.0f;
                case 2:
                    green = m_RawData[x_indice + y_indice + 1] / 255.0f;
                case 1:
                    red = m_RawData[x_indice + y_indice + 0] / 255.0f;
                }

                pixel = glm::vec4(red, green, blue, alpha);
                return true;
            }
//        }
        pixel = glm::vec4(0, 0, 0, 0);
        return false;
    }

    glm::vec4 Image::getPixel(const glm::vec2 &position) const {
        glm::vec4 pixel;
        getPixel(position, pixel);
        return pixel;
    }

    bool Image::setPixels(const glm::vec2 &destinationPosition,
                          const glm::vec2 &destinationDimensions,
                          const glm::vec4 &color) {
        if (m_RawData) {

            int width = destinationDimensions.x;
            int height = destinationDimensions.y;
            int xOffset = destinationPosition.x;
            int yOffset = destinationPosition.y;

            if ((width > 0) && (height > 0) && (xOffset <= getWidth()) &&
                (xOffset <= getWidth())) {
                int *fillRow = createFillRow_createsmemory(0, getWidth(), color);
                assert(fillRow);

                if ((xOffset + width) > getWidth())
                    width = getWidth() - xOffset;
                if ((yOffset + height) > getHeight())
                    height = getHeight() - yOffset;

                for (int y = yOffset; y < (yOffset + height); ++y) {
                    setPixelRow(fillRow, y, width, xOffset);
                }

                delete[] fillRow;
                fillRow = NULL;
            }
            //            if(xOffset > getWidth())
            //                return false;
            //            if(yOffset > getHeight())
            //                return false;
            //
            //            if((xOffset + width) > getWidth())
            //                width = getWidth() - xOffset;
            //            else if(width < 0)
            //                return false;
            //
            //            if((yOffset + height) > getHeight())
            //                height = getHeight() - yOffset;
            //            else if(height < 0)
            //                return false;

            return true;
        }

        return false;
    }

    bool Image::setPixels(const glm::vec2 &position, const glm::vec2 &dimension,
                          const Image &imageSource,
                          const glm::vec2 &sourcePosition) {
        bool error = false;
        glm::vec4 pixel;

        glm::vec2 fromPos, toPos;
        for (int x = 0; x < dimension.x; ++x) {
            for (int y = 0; y < dimension.y; ++y) {
                fromPos = glm::vec2(x, y) + position;
                toPos = glm::vec2(x, y) + sourcePosition;

                if (imageSource.getPixel(fromPos, pixel)) {
                    if (!setPixel(toPos, pixel)) {
                        SDL_LogError(SDL_LOG_CATEGORY_TEST,
                                     "error writing (%d, %d)", x, y);
                        error = true;
                    }
                } else {
                    SDL_LogError(SDL_LOG_CATEGORY_TEST,
                                 "error reading (%d, %d)", x, y);
                    error = true;
                }
            }
        }

        return error;
    }

    bool Image::getPixels(const glm::vec2 &position,
                          const glm::vec2 &dimensions, Image &image,
                          const glm::vec2 &sourcePosition) const {
        return image.setPixels(position, dimensions, image, sourcePosition);
    }

    int Image::getNumberOfComponents() const { return m_Componenents; }

    int Image::getWidth() const { return m_Width; }

    int Image::getHeight() const { return m_Height; }

    const char *Image::getFilename() const { return m_Filename.c_str(); }

    int Image::getBytesPerPixel() const {
        return sizeof(int) * getNumberOfComponents();
    }

    bool Image::copyData(void *dataPtr, long dataSize, int width, int height,
                         int components,
                         const std::string &filename) {
        if (dataPtr != NULL && dataSize > 0) {
            m_RawDataSize = dataSize;

            if (m_RawData)
                delete[] m_RawData;
            m_RawData = new int[m_RawDataSize];
            assert(m_RawData);

            memcpy(m_RawData, dataPtr, m_RawDataSize);

            assert(width >= 0 && width <= 4096);
            m_Width = width;

            assert(height >= 0 && height <= 4096);
            m_Height = height;

            assert(components >= 0 && components <= 4);
            m_Componenents = components;

//            assert(imageType > JLI_IMAGE_TYPE_NONE &&
//                       imageType < JLI_IMAGE_TYPE_MAX);
//            assert(njli::World::getInstance()->getWorldResourceLoader()->dataPtrSize(filename.c_str())
                   
//            njli::World::getInstance()->getWorldResourceLoader()->dataPtrSize(filename.c_str();
            //            != 0);
            m_Filename = filename;

            return true;
        }
        return false;
    }

//    bool Image::copyData(const WorldResourceLoader::ImageFileData *fileData) {
//        bool retVal = false;
//
//        if (fileData) {
//            retVal = copyData(fileData->getBufferPtr(), fileData->getSize(),
//                              fileData->getWidth(), fileData->getHeight(),
//                              fileData->numberOfComponents(),
//                              fileData->getType(), fileData->getFilename());
//        }
//
//        return retVal;
//    }

    int *Image::getDataPtr() const { return m_RawData; }

    long Image::getDataSize() const { return m_RawDataSize; }

    

//    bool Image::isCompressed() const {
////        if (isPvr()) {
//            assert(true);
//
//            //            PVRTextureHeaderV3 *header =
//            //            (PVRTextureHeaderV3*)getDataPtr();
//            //
//            //            PVRTuint64 PixelFormat = header->u64PixelFormat;
//            //
//            //            //Get the last 32 bits of the pixel format.
//            //            PVRTuint64 PixelFormatPartHigh =
//            //            PixelFormat&PVRTEX_PFHIGHMASK;
//            //
//            //            //Check for a compressed format (The first 8 bytes
//            //            will be 0, so the whole thing will be equal to the
//            //            last 32 bits). return (PixelFormatPartHigh==0);
////        }
//        return false;
//    }

    void Image::generate(int width, int height, int numberOfComponents,
                         const glm::vec4 &fillColor) {
//        if (!isPvr()) {
            assert(numberOfComponents > 0 && numberOfComponents < 5);

            if (m_RawData)
                delete[] m_RawData;
            m_RawData = NULL;

            m_Componenents = numberOfComponents;
            m_Width = width;
            m_Height = height;

            m_RawData =
                new int[getNumberOfComponents() * getWidth() * getHeight()];
            assert(m_RawData);

            int *fillRow = createFillRow_createsmemory(0, getWidth(), fillColor);
            assert(fillRow);

            for (int y_current = 0; y_current < getHeight(); y_current++) {
                setPixelRow(fillRow, y_current, getWidth());
            }

            delete[] fillRow;
            fillRow = NULL;

            char buffer[1024];
            sprintf(buffer, "Generated Width:%d, Height:%d, Components:%d",
                    width, height, numberOfComponents);
            m_Filename = buffer;
//        }
    }

    void Image::setPixelRow(int *data, int row, int width, int xOffset) {
//        if (!isPvr()) {
            assert(data);
            assert(m_RawData);
            assert((xOffset + width) <= getWidth());

            int toIncrement = xOffset + (row * getWidth());
            toIncrement *= getNumberOfComponents();
            memcpy(m_RawData + toIncrement, data,
                   getNumberOfComponents() * width);
//        }
    }

    void Image::getPixelRow(int *data, int row, int width) {
//        if (!isPvr()) {
            assert(data);
            assert(m_RawData);

            int x_indice = 0;

            int fromIncrement = x_indice + (row * getWidth());
            fromIncrement *= getNumberOfComponents();

            memcpy(data, m_RawData + fromIncrement,
                   getNumberOfComponents() * width);
//        }
    }

    //    int *Image::createFillRow(int components, int width, const glm::vec4
    //    &fillColor)
    int *Image::createFillRow_createsmemory(int xOffset, int fillWidth,
                                           const glm::vec4 &fillColor) {
//        if (!isPvr()) {
            if ((xOffset + fillWidth) > getWidth())
                fillWidth = getWidth() - xOffset;
            else if (fillWidth < 0)
                fillWidth = 0;

            int *fillRow = new int[getNumberOfComponents() * getWidth()];

            for (int xx = xOffset; xx < fillWidth; ++xx) {
                int x_indice = xx * getNumberOfComponents();
                int y_indice = 0 * getNumberOfComponents() * getWidth();

                switch (getNumberOfComponents()) {
                case 4:
                    fillRow[x_indice + y_indice + 3] = (fillColor.w * 255.0f);
                case 3:
                    fillRow[x_indice + y_indice + 2] = (fillColor.z * 255.0f);
                case 2:
                    fillRow[x_indice + y_indice + 1] = (fillColor.y * 255.0f);
                case 1:
                    fillRow[x_indice + y_indice + 0] = (fillColor.x * 255.0f);
                }
            }
            return fillRow;
//        }
//        return NULL;
    }

    void Image::drawLine(const glm::vec2 &from, const glm::vec2 &to,
                         const glm::vec4 &color) {
        // http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/

        int x = from.x;
        int y = from.y;
        int x2 = to.x;
        int y2 = to.y;

        int w = x2 - x;
        int h = y2 - y;
        int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
        if (w < 0)
            dx1 = -1;
        else if (w > 0)
            dx1 = 1;
        if (h < 0)
            dy1 = -1;
        else if (h > 0)
            dy1 = 1;
        if (w < 0)
            dx2 = -1;
        else if (w > 0)
            dx2 = 1;
        int longest = std::abs(w);
        int shortest = std::abs(h);

        if (!(longest > shortest)) {
            longest = std::abs(h);
            shortest = std::abs(w);
            if (h < 0)
                dy2 = -1;
            else if (h > 0)
                dy2 = 1;
            dx2 = 0;
        }
        int numerator = longest >> 1;

        for (int i = 0; i <= longest; i++) {
            setPixel(glm::vec2(x, y), color);
            numerator += shortest;
            if (!(numerator < longest)) {
                numerator -= longest;
                x += dx1;
                y += dy1;
            } else {
                x += dx2;
                y += dy2;
            }
        }
    }

    void Image::drawLine(const glm::vec2 &from, const glm::vec2 &to,
                         const Image &imageSource) {
        glm::vec4 pixel;

        // http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm/

        int x = from.x;
        int y = from.y;
        int x2 = to.x;
        int y2 = to.y;

        int w = x2 - x;
        int h = y2 - y;
        int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
        if (w < 0)
            dx1 = -1;
        else if (w > 0)
            dx1 = 1;
        if (h < 0)
            dy1 = -1;
        else if (h > 0)
            dy1 = 1;
        if (w < 0)
            dx2 = -1;
        else if (w > 0)
            dx2 = 1;
        int longest = std::abs(w);
        int shortest = std::abs(h);

        if (!(longest > shortest)) {
            longest = std::abs(h);
            shortest = std::abs(w);
            if (h < 0)
                dy2 = -1;
            else if (h > 0)
                dy2 = 1;
            dx2 = 0;
        }
        int numerator = longest >> 1;

        for (int i = 0; i <= longest; i++) {
            if (imageSource.getPixel(glm::vec2(x, y), pixel)) {
                if (!setPixel(glm::vec2(x, y), pixel)) {
                    SDL_LogError(SDL_LOG_CATEGORY_TEST,
                                 "error reading (%d, %d)", x, y);
                }
            } else {
                SDL_LogError(SDL_LOG_CATEGORY_TEST, "error writing (%d, %d)", x,
                             y);
            }

            numerator += shortest;
            if (!(numerator < longest)) {
                numerator -= longest;
                x += dx1;
                y += dy1;
            } else {
                x += dx2;
                y += dy2;
            }
        }
    }

    void Image::blur() {
//        if (!isPvr()) {
            int x = 1, y, width = getWidth() - 1, height = getHeight() - 1,
                bw = getWidth() * getNumberOfComponents();

            if (getNumberOfComponents() < 3) {
                return;
            }

            while (x != height) {
                y = 1;
                while (y < width) {
                    int jb = y * getNumberOfComponents(),
                        jp = (y + 1) * getNumberOfComponents(),
                        jm = (y - 1) * getNumberOfComponents(), ib = x * bw,
                        im = (x - 1) * bw, ip = (x + 1) * bw, ibjb = ib + jb;

                    int *px1 = &m_RawData[ib + jb], *px2 = &m_RawData[ib + jm],
                       *px3 = &m_RawData[ib + jp], *px4 = &m_RawData[im + jb],
                       *px5 = &m_RawData[ip + jb], *px6 = &m_RawData[im + jm],
                       *px7 = &m_RawData[im + jp], *px8 = &m_RawData[ip + jm],
                       *px9 = &m_RawData[ip + jp];

                    m_RawData[ibjb] =
                        ((px1[0] << 2) +
                         ((px2[0] + px3[0] + px4[0] + px5[0]) << 1) + px6[0] +
                         px7[0] + px8[0] + px9[0]) >>
                        4;

                    m_RawData[ibjb + 1] =
                        ((px1[1] << 2) +
                         ((px2[1] + px3[1] + px4[1] + px5[1]) << 1) + px6[1] +
                         px7[1] + px8[1] + px9[1]) >>
                        4;

                    m_RawData[ibjb + 2] =
                        ((px1[2] << 2) +
                         ((px2[2] + px3[2] + px4[2] + px5[2]) << 1) + px6[2] +
                         px7[2] + px8[2] + px9[2]) >>
                        4;
                    ++y;
                }

                ++x;
            }
//        }
    }

    bool Image::setAlpha(const Image &image) {
//        if (!isPvr()) {
            if (((getNumberOfComponents() == 3) ||
                 (getNumberOfComponents() == 4)) &&
                ((image.getNumberOfComponents() == 1) ||
                 (image.getNumberOfComponents() == 4)) &&
                getWidth() == image.getWidth() &&
                getHeight() == image.getWidth()) {
                int i = 0, rgb = 0, a = 0, size;

                int prevComponents = getNumberOfComponents();

                int *tex;

                m_Componenents = 4;
                size = getWidth() * getHeight() * getNumberOfComponents();

                tex = new int[size];

                while (i != size) {
                    tex[i] = m_RawData[rgb + 2];
                    tex[i + 1] = m_RawData[rgb + 1];
                    tex[i + 2] = m_RawData[rgb];

                    if (image.getNumberOfComponents() == 1)
                        tex[i + 3] = image.m_RawData[a];
                    if (image.getNumberOfComponents() == 4)
                        tex[i + 3] = image.m_RawData[i + 3];

                    ++a;
                    rgb += prevComponents;
                    i += getNumberOfComponents();
                }

                delete[] m_RawData;
                m_RawData = NULL;

                m_RawData = tex;

                return true;
            }
//        }
        return false;
    }

    bool Image::setAlpha(float alpha) {
//        if (!isPvr()) {
            if (((getNumberOfComponents() == 3) ||
                 (getNumberOfComponents() == 4))) {
                int i = 0, rgb = 0, a = 0, size;
                int prevComponents = getNumberOfComponents();
                int *tex = NULL;

                m_Componenents = 4;
                size = getWidth() * getHeight() * getNumberOfComponents();

                tex = new int[size];
                assert(tex);

                while (i != size) {
                    tex[i] = m_RawData[rgb + 2];
                    tex[i + 1] = m_RawData[rgb + 1];
                    tex[i + 2] = m_RawData[rgb];
                    tex[i + 3] = alpha;

                    ++a;
                    rgb += prevComponents;
                    i += getNumberOfComponents();
                }

                delete[] m_RawData;
                m_RawData = tex;

                return true;
            }
//        }

        return false;
    }

    bool Image::hasAlpha() const {
        return ((getNumberOfComponents() == 2) ||
                (getNumberOfComponents() == 4));
    }

    void Image::preMultiplyAlpha() {
        glm::vec4 color;
        float r, g, b, a;

        if (getNumberOfComponents() == 4) {
            for (int x = 0; x < getWidth(); ++x) {
                for (int y = 0; y < getHeight(); ++y) {
                    if (getPixel(glm::vec2(x, y), color)) {
                        r = color.x;
                        g = color.y;
                        b = color.z;
                        a = color.w;

                        setPixel(glm::vec2(x, y),
                                 glm::vec4(r * a, g * a, b * a, a));
                    }
                }
            }
        }
    }

    void Image::flip() {
//        if (!isPvr()) {
            int i = 0,
                size = getWidth() * getHeight() * getNumberOfComponents(),

                rows = getWidth() * getNumberOfComponents();

            int *buf = new int[size];
            assert(buf);

            while (i != getHeight()) {
                memcpy(buf + (i * rows),
                       m_RawData + (((getHeight() - i) - 1) * rows), rows);
                ++i;
            }

            memcpy(&m_RawData[0], &buf[0], size);

            delete[] buf;
            buf = NULL;
//        }
    }

    void Image::rotate() {
        assert(false);

        if (getHeight() == getWidth()) {
            int n = getHeight();
            for (int layer = 0; layer < n / 2; ++layer) {
                int first = layer;
                int last = n - 1 - layer;
                for (int i = first; i < last; ++i) {
                    int offset = i - first;

                    // save top
                    glm::vec4 top = (*this)[first][i];

                    // left -> top
                    (*this)[first][i] = (*this)[last - offset][first];

                    // bottom -> left
                    (*this)[last - offset][first] =
                        (*this)[last][last - offset];

                    // right -> bottom
                    (*this)[last][last - offset] = (*this)[i][last];

                    // top -> right
                    (*this)[i][last] = top;
                }
            }
        }
    }

    std::vector<glm::vec4> Image::operator[](int row) {
        std::vector<glm::vec4> ret;
        ret.resize(getWidth());

        for (int x_indice = 0; x_indice < getWidth(); ++x_indice)
            ret[x_indice] = getPixel(glm::vec2(x_indice, row));

        return ret;
    }

    bool Image::isWidthHeightPowerOf2() const {
        int w = getWidth();
        int h = getHeight();
        bool bw = (w != 0) && ((w & (w - 1)) == 0);
        bool bh = (h != 0) && ((h & (h - 1)) == 0);
        return bw && bh;
    }

    int Image::getClosestValidGLDim(const int dim) const {
        for (int shift = 0; shift < 12; shift++) {
            if ((1 << shift) > dim)
                return 1 << (shift);
        }
        return 1 << 11;
    }
} // namespace NJLIC
