/**
 * @file Topology.h
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief Topology class signature
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOPOLOGY_API_TOPOLOGY_H
#define TOPOLOGY_API_TOPOLOGY_H

#include <vector>
#include "ElectronicObject.h"
#include "Device.h"

class Topology : public ElectronicObject<Topology>{
private:
    std::vector<Device*> components;

public:
    virtual ~Topology();
    void addDevice(Device* device);
    std::vector<Device*> getDeviceList();
    std::string accept(JsonExportVisitor* visitor);
};


#endif //TOPOLOGY_API_TOPOLOGY_H
