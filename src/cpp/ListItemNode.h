//
//  ListItemNode.h
//  SDLSkeleton
//
//  Created by James Folk on 2/29/20.
//

#ifndef ListItemNode_h
#define ListItemNode_h

#include "Node.h"

class ListItemNode : public NJLIC::Node {
    glm::vec3 mNextPosition;
    glm::vec3 mPrevPosition;

  public:
    ListItemNode();
    virtual ~ListItemNode();

    void setNextPosition(const glm::vec3 &next);
    void setPreviousPosition(const glm::vec3 &previousPosition);
    void scroll();

    virtual void setOrigin(const glm::vec3 &origin) override;

    virtual void setOrigin(const glm::vec2 &origin) override;
    virtual void update(float timestep) override;
};

#endif /* ListItemNode_h */
