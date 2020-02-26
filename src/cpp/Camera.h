//
//  Camera.h
//  SDLSkeleton
//
//  Created by James Folk on 2/24/20.
//

#ifndef Camera_h
#define Camera_h

namespace NJLIC {
    class Shader;
    class Camera {
        Camera(const Camera &) = delete;
        const Camera &operator=(const Camera &) = delete;

      public:
        Camera();
        virtual ~Camera();

        void render(Shader *shader);
    };
} // namespace NJLIC

#endif /* Camera_hpp */
