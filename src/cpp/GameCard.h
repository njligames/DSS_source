//
//  GameCard.h
//  SDLSkeleton
//
//  Created by James Folk on 2/23/20.
//

#ifndef GameCard_h
#define GameCard_h

#include "entityx/entityx.h"

#include "DebugSystem.h"

#include "Destination.h"
#include "Direction.h"
#include "Position.h"

class GameCard : public entityx::EntityX {
  public:
    explicit GameCard() {
        systems.add<ECS::DebugSystem>();
        //    systems.add<MovementSystem>();
        //    systems.add<CollisionSystem>();
        systems.configure();

        //    for (auto e : level.entity_data()) {
        //      entityx::Entity entity = entities.create();
        //      entity.assign<ECS::Position>();
        //      entity.assign<ECS::Direction>();
        //    }
    }

    void update(entityx::TimeDelta dt) {
        systems.update<ECS::DebugSystem>(dt);
        //    systems.update<MovementSystem>(dt);
        //    systems.update<CollisionSystem>(dt);
    }

    //  GameCard level;
};

#endif /* GameCard_hpp */
