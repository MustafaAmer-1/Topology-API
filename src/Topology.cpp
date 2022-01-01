/**
 * @file Topology.cpp
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief Topology class implementation
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Topology.h"
#include "JsonExportVisitor.h"

/**
 * @brief adds given device to the topology component list
 * 
 * @param device - the given device
 */
void Topology::addDevice(Device *device) {
    components.push_back(device);
}

/**
 * @brief get the list of the components in the topology
 * 
 * @return std::vector<Device*> 
 */
std::vector<Device*> Topology::getDeviceList() {
    return components;
}

/**
 * @brief acceptance method for JsonExportVisitor visitor
 * 
 * @param visitor - JsonExportVisitor visitor
 * @return std::string - json object representation of the topology
 */
std::string Topology::accept(JsonExportVisitor *visitor) {
    return visitor->exportTopology(this);
}

Topology::~Topology() {
    for(auto comp: components) delete comp;
}
