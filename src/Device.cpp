#include "Device.h"

struct Value{
    int defaultValue, min, max;

    Value(int defaultValue, int min, int max) : defaultValue(defaultValue), min(min), max(max) {}
};

int Device::getMin(){return value->min;}
int Device::getMax() {return value->max;}
int Device::getDefault(){return value->defaultValue;}

Device::Device(int defaultValue, int min, int max) {
    value = new Value(defaultValue, min, max);
}

