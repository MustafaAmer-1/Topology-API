#include "Capacitor.h"

struct NetList{
    Node *pos_t, *neg_t;
};

Capacitor::Capacitor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}
