#include "Topology.h"
#include "JsonExportVisitor.h"

void Topology::addDevice(Device *device) {
    components.push_back(device);
}

std::vector<Device*> Topology::getDeviceList() {
    return components;
}

std::string Topology::accept(JsonExportVisitor *visitor) {
    return visitor->exportTopology(this);
}

Topology::~Topology() {
    for(auto comp: components) delete comp;
}
