#include "Inductor.h"
#include "JsonExportVisitor.h"

struct NetList{
    Node *t1 = nullptr, *t2 = nullptr;
};

Inductor::Inductor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {}

void Inductor::attachT1(Node *t1) {
    netlist->t1 = t1;
}

void Inductor::attachT2(Node *t2) {
    netlist->t2 = t2;
}

bool Inductor::isAttached(Node *node) {
    if(node == nullptr) return false;
    if(netlist->t1 != nullptr && *node == *netlist->t1) return true;
    if(netlist->t2 != nullptr && *node == *netlist->t2) return true;
    return false;
}

Node *Inductor::getT1() {
    return netlist->t1;
}

Node *Inductor::getT2() {
    return netlist->t2;
}

std::string Inductor::accept(JsonExportVisitor *visitor) {
    return visitor->exportInductor(this);
}

Inductor::~Inductor() {
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
}
