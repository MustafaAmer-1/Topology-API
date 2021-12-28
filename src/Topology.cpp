#include "Topology.h"

void Topology::addDevice(Device *device) {
    components.push_back(device);
}

std::vector<Device*> Topology::getDeviceList() {
    return components;
}
