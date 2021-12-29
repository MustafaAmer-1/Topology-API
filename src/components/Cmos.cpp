#include "Cmos.h"

struct NetList{
    Node *drain, *gate, *source;
};

Cmos::Cmos(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}

void Cmos::attachDrain(Node * drain) {
    netlist->drain = drain;
}

void Cmos::attachGate(Node * gate) {
    netlist->gate = gate;
}

void Cmos::attachSource(Node * source) {
    netlist->source = source;
}

bool Cmos::isAttached(Node *node) {
    if(node == nullptr) return false;
    if(netlist->drain != nullptr && *node == *netlist->drain) return true;
    if(netlist->gate != nullptr && *node == *netlist->gate) return true;
    if(netlist->source != nullptr && *node == *netlist->source) return true;
    return false;
}

Node *Cmos::getSource() {
    return netlist->source;
}

Node *Cmos::getDrain() {
    return netlist->drain;
}

Node *Cmos::getGate() {
    return netlist->gate;
}
