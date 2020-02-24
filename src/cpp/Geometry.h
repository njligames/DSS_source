//
//  Geometry.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef Geometry_h
#define Geometry_h

namespace NJLIC {
    class Camera;

    class Geometry {
        Geometry(const Geometry &) = delete;
        const Geometry &operator=(const Geometry &) = delete;

      public:
        Geometry();
        virtual ~Geometry();

        void render(Camera *camera);
    };
} // namespace NJLIC

#endif /* Geometry_hpp */
