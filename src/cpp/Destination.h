
#ifndef Destination_H
#define Destination_H

#include "glm/glm.hpp"

namespace ECS {
    struct Destination {
        Destination(glm::vec3 destination = glm::vec3(0, 0, 0))
            : destination(destination) {}

        glm::vec3 destination;
    };
} // namespace ECS

#endif
