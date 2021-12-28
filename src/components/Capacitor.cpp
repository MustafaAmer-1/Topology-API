#include "Capacitor.h"

struct NetList{
    Node *pos_t, *neg_t;
};

Capacitor::Capacitor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}

void Capacitor::attachPos_t(Node *pos_t) {
    netlist->pos_t = pos_t;
}

void Capacitor::attachNeg_t(Node *neg_t) {
    netlist->neg_t = neg_t;
}

bool Capacitor::isAttached(Node *node) {
    return (*node == *netlist->neg_t || *node == *netlist->pos_t);
}

Node* Capacitor::getPos_t() {
    return netlist->pos_t;
}

Node* Capacitor::getNeg_t() {
    return netlist->neg_t;
}
