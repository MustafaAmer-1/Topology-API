#ifndef TOPOLOGY_API_NODE_H
#define TOPOLOGY_API_NODE_H

#include "ElectronicObject.h"

class Node : public ElectronicObject{
public:
    bool operator==(const Node& a);
};


#endif //TOPOLOGY_API_NODE_H
