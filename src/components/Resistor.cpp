#include "Resistor.h"

struct NetList{
    Node *t1, *t2;
};

Resistor::Resistor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}

void Resistor::attachT1(Node *t1) {
    netlist->t1 = t1;
}

void Resistor::attachT2(Node *t2) {
    netlist->t2 = t2;
}

bool Resistor::isAttached(Node *node) {
    return (*node == *netlist->t1 || *node == *netlist->t2);
}
