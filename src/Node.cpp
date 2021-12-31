#include "Node.h"
#include <algorithm>

bool Node::operator==(const Node &a) {
    return this->getId() == a.getId();
}

void Node::free() {
    auto list = Device::getElementList();

    bool attached = std::any_of(list.begin(), list.end(),
                                [this](const auto& dev) { return dev.second->isAttached(this); } );
    if(attached) return;
    delete this;
}
