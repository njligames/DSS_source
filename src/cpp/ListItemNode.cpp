//
//  ListItemNode.cpp
//  SDLSkeleton
//
//  Created by James Folk on 2/29/20.
//

#include "ListItemNode.h"

ListItemNode::ListItemNode() {}

ListItemNode::~ListItemNode() {}

void ListItemNode::setNextPosition(const glm::vec3 &next) {}

void ListItemNode::setPreviousPosition(const glm::vec3 &previousPosition) {}

void ListItemNode::scroll() {}

void ListItemNode::setOrigin(const glm::vec3 &origin) {
    Node::setOrigin(origin);
    mNextPosition = (origin);
    mPrevPosition = (origin);
}

void ListItemNode::setOrigin(const glm::vec2 &origin) {
    ListItemNode::setOrigin(origin);
}
void ListItemNode::update(float timestep) {}
