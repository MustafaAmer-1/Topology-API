#ifndef TOPOLOGY_API_NODE_H
#define TOPOLOGY_API_NODE_H

#include "ElectronicObject.h"
#include "Device.h"

class Node : public ElectronicObject<Node>{
public:
    bool operator==(const Node& a);
    void free();
};


#endif //TOPOLOGY_API_NODE_H
