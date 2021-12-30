#include "Resistor.h"
#include "JsonExportVisitor.h"

struct NetList{
    Node *t1 = nullptr, *t2 = nullptr;
};

Resistor::Resistor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {
    netlist = new NetList();
}

void Resistor::attachT1(Node *t1) {
    netlist->t1 = t1;
}

void Resistor::attachT2(Node *t2) {
    netlist->t2 = t2;
}

bool Resistor::isAttached(Node *node) {
    if(node == nullptr) return false;
    if(netlist->t1 != nullptr && *node == *netlist->t1) return true;
    if(netlist->t2 != nullptr && *node == *netlist->t2) return true;
    return false;
}

Node *Resistor::getT1() {
    return netlist->t1;
}

Node *Resistor::getT2() {
    return netlist->t2;
}

std::string Resistor::accept(JsonExportVisitor *visitor) {
    return visitor->exportResistor(this);
}

Resistor::~Resistor() {
    if(netlist->t1 != nullptr){
        Node* tmp = netlist->t1;
        netlist->t1 = nullptr;
        tmp->free();
    }
    if(netlist->t2 != nullptr){
        Node* tmp = netlist->t2;
        netlist->t2 = nullptr;
        tmp->free();
    }
    delete netlist;
}
