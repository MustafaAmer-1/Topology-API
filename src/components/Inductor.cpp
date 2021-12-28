#include "Inductor.h"

struct NetList{
    Node *t1, *t2;
};

Inductor::Inductor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}

void Inductor::attachT1(Node *t1) {
    netlist->t1 = t1;
}

void Inductor::attachT2(Node *t2) {
    netlist->t2 = t2;
}

bool Inductor::isAttached(Node *node) {
    return (*node == *netlist->t1 || *node == *netlist->t2);
}

Node *Inductor::getT1() {
    return netlist->t1;
}

Node *Inductor::getT2() {
    return netlist->t2;
}
