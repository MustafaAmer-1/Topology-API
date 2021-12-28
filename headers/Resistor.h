#ifndef TOPOLOGY_API_RESISTOR_H
#define TOPOLOGY_API_RESISTOR_H

#include "Device.h"

#define DEFAULT_RES_VALUE 100
#define DEFAULT_MIN_RES_VALUE 10
#define DEFAULT_MAX_RES_VALUE 1000

class Resistor : public Device{
public:
    explicit Resistor(int defaultValue=DEFAULT_RES_VALUE,
            int min=DEFAULT_MIN_RES_VALUE, int max=DEFAULT_MAX_RES_VALUE);
};


#endif //TOPOLOGY_API_RESISTOR_H
