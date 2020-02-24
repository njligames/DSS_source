
#ifndef DIRECTION_H
#define DIRECTION_H

#include "glm/glm.hpp"

namespace ECS {
    struct Direction {
        Direction(glm::vec3 direction = glm::vec3(0, 0, 0))
            : direction(direction) {}

        glm::vec3 direction;
    };
} // namespace ECS

#endif
