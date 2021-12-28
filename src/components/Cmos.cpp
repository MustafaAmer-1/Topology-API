#include "Cmos.h"

struct NetList{
    Node *drain, *gate, *source;
};

Cmos::Cmos(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}
