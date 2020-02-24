#ifndef DEBUGSYSTEM_H
#define DEBUGSYSTEM_H

#include "entityx/entityx.h"

#include "Position.h"
//#include "../Position.h"

namespace ECS {
    struct DebugSystem : public entityx::System<DebugSystem>,
                         public entityx::Receiver<DebugSystem> {
        void configure(entityx::EventManager &event_manager) {
            event_manager.subscribe<ECS::Position>(*this);
        }

        void update(entityx::EntityManager &entities,
                    entityx::EventManager &events, entityx::TimeDelta dt) {}

        void receive(const ECS::Position &position) {
            //            LOG(DEBUG) << "entities collided: " << collision.left
            //            << " and "
            //                       << collision.right << endl;
        }
    };
} // namespace ECS

#endif
