#include "Node.h"

bool Node::operator==(const Node &a) {
    return this->getId() == a.getId();
}
