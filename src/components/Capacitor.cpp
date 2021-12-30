#include "Capacitor.h"
#include "JsonExportVisitor.h"

struct NetList{
    Node *pos_t = nullptr, *neg_t = nullptr;
};

Capacitor::Capacitor(double defaultValue, double min, double max) : Device(defaultValue, min, max) {
    netlist = new NetList();
}

void Capacitor::attachPos_t(Node *pos_t) {
    netlist->pos_t = pos_t;
}

void Capacitor::attachNeg_t(Node *neg_t) {
    netlist->neg_t = neg_t;
}

bool Capacitor::isAttached(Node *node) {
    if(node == nullptr) return false;
    if(netlist->pos_t != nullptr && *node == *netlist->pos_t) return true;
    if(netlist->neg_t != nullptr && *node == *netlist->neg_t) return true;
    return false;
}

Node* Capacitor::getPos_t() {
    return netlist->pos_t;
}

Node* Capacitor::getNeg_t() {
    return netlist->neg_t;
}

std::string Capacitor::accept(JsonExportVisitor *visitor) {
    return visitor->exportCapacitor(this);
}

Capacitor::~Capacitor() {
    if(netlist->pos_t != nullptr){
        Node* tmp = netlist->pos_t;
        netlist->pos_t = nullptr;
        tmp->free();
    }
    if(netlist->neg_t != nullptr){
        Node* tmp = netlist->neg_t;
        netlist->neg_t = nullptr;
        tmp->free();
    }
    delete netlist;
}
