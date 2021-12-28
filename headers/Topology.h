#ifndef TOPOLOGY_API_TOPOLOGY_H
#define TOPOLOGY_API_TOPOLOGY_H

#include <vector>
#include "ElectronicObject.h"
#include "Device.h"

class Topology : public ElectronicObject{
private:
    std::vector<Device*> components;

public:
    void addDevice(Device* device);
    std::vector<Device*> getDeviceList();
};


#endif //TOPOLOGY_API_TOPOLOGY_H
