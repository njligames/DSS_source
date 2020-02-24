#ifndef POSITION_H
#define POSITION_H

#include "glm/glm.hpp"

namespace ECS {
    struct Position {
        Position(glm::vec3 position = glm::vec3(0, 0, 0))
            : position(position) {}

        glm::vec3 position;
    };
} // namespace ECS

#endif
