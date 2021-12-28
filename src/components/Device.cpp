#include "Device.h"

struct Value{
    double defaultValue, min, max;

    Value(double defaultValue, double min, double max) : defaultValue(defaultValue), min(min), max(max) {}
};

double Device::getMin(){return value->min;}
double Device::getMax() {return value->max;}
double Device::getDefault(){return value->defaultValue;}

Device::Device(double defaultValue, double min, double max) {
    value = new Value(defaultValue, min, max);
}

