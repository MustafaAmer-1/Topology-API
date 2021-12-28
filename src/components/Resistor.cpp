#include "Resistor.h"

struct NetList{
    Node *t1, *t2;
};

Resistor::Resistor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}
