/**
 * @file Node.cpp
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief Node class implementation
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Node.h"
#include <algorithm>

/**
 * @brief operator overload to check for nodes objects equality
 * 
 * @return true - if they have same id
 * @return false - if they have diffrent id
 */
bool Node::operator==(const Node &a) {
    return this->getId() == a.getId();
}

/**
 * @brief check if the node doesn't attached to any device then it will be deleted to free its memory
 * 
 */
void Node::free() {
    auto list = Device::getElementList();

    bool attached = std::any_of(list.begin(), list.end(),
                                [this](const auto& dev) { return dev.second->isAttached(this); } );
    if(attached) return;
    delete this;
}
