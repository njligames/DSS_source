//
//  Scene.hpp
//  VerizonTest
//
//  Created by James Folk on 6/21/16.
//  Copyright © 2016 NJLIGames Ltd. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <vector>

namespace NJLIC {
    class Geometry;
    class Camera;
    class Node;

    class Scene {
      public:
        /* members */
        Scene();
        Scene(const Scene &rhs);
        const Scene &operator=(const Scene &rhs);
        ~Scene();

        void update(float timeStep, int maxSubSteps = 1,
                    float fixedTimeStep = float(1.) / float(60.));
        void render();

        void addActiveCamera(Camera *camera);
        void removeActiveCamera(Camera *camera);

        void addActiveNode(Node *node);
        void removeActiveNode(Node *node);

        Node *const getRootNode() const;

      protected:
      private:
        std::vector<Geometry *> m_ActiveGeometries;
        std::vector<Camera *> m_ActiveCameras;
        std::vector<Node *> m_ActiveNodes;
        Node *m_RootNode;
    };
} // namespace NJLIC

#endif /* Scene_hpp */
