#ifndef TOPOLOGY_API_DEVICE_H
#define TOPOLOGY_API_DEVICE_H

#include "ElectronicObject.h"

struct Value;

class Device : public ElectronicObject{
private:
    Value* value;

public:
    explicit Device(double defaultValue=0, double min=0, double max=0);

    double getMin();
    double getMax();
    double getDefault();
};

#endif //TOPOLOGY_API_DEVICE_H
