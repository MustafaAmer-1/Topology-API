#include "Node.h"
bool Node::operator==(const Node &a) {
    return this->getId() == a.getId();
}

void Node::free() {
    for(const auto& dev: Device::getElementList()){
        if(dev.second->isAttached(this)) return;
    }
    delete this;
}
