#include "Inductor.h"

struct NetList{
    Node *t1, *t2;
};

Inductor::Inductor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}
