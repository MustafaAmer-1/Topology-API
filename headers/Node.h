/**
 * @file Node.h
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOPOLOGY_API_NODE_H
#define TOPOLOGY_API_NODE_H

#include "ElectronicObject.h"
#include "Device.h"

/**
 * @brief netlist node class implementation
 * 
 */
class Node : public ElectronicObject<Node>{
public:
    bool operator==(const Node& a);
    void free();
};


#endif //TOPOLOGY_API_NODE_H
