#include "JsonExportVisitor.h"

JsonExportVisitor* JsonExportVisitor::getJsonExportVisitor() {
    if(visitor == nullptr) visitor = new JsonExportVisitor();
    return visitor;
}

std::string JsonExportVisitor::exportResistor(Resistor *device) {
    std::string res = R"({"type": "resistor",)"
                      R"("id": ")" + device->getId() + "\","
                      R"("resistance": {)"
                      R"("default": )" + std::to_string(device->getDefault()) + ","
                      R"("min": )" + std::to_string(device->getMin()) + ","
                      R"("max": )" + std::to_string(device->getMax()) + "},"
                      R"("netlist": {)"
                      R"("t1": ")" + device->getT1()->getId() + "\","
                      R"("t2": ")" + device->getT2()->getId() + "\"}}";
    return res;
}

std::string JsonExportVisitor::exportInductor(Inductor *device) {
    std::string res = R"({"type": "inductor",)"
                      R"("id": ")" + device->getId() + "\","
                      R"("inductance": {)"
                      R"("default": )" + std::to_string(device->getDefault()) + ","
                      R"("min": )" + std::to_string(device->getMin()) + ","
                      R"("max": )" + std::to_string(device->getMax()) + "},"
                      R"("netlist": {)"
                      R"("t1": ")" + device->getT1()->getId() + "\","
                      R"("t2": ")" + device->getT2()->getId() + "\"}}";
    return res;
}

std::string JsonExportVisitor::exportCapacitor(Capacitor *device) {
    std::string res = R"({"type": "capacitor",)"
                      R"("id": ")" + device->getId() + "\","
                      R"("capacitance": {)"
                      R"("default": )" + std::to_string(device->getDefault()) + ","
                      R"("min": )" + std::to_string(device->getMin()) + ","
                      R"("max": )" + std::to_string(device->getMax()) + "},"
                      R"("netlist": {)"
                      R"("pos_t": ")" + device->getPos_t()->getId() + "\","
                      R"("neg_t": ")" + device->getNeg_t()->getId() + "\"}}";
    return res;
}

std::string JsonExportVisitor::exportCmos(Cmos *device) {
    std::string res = R"("id": ")" + device->getId() + "\","
                      "\"m(l)\": {"
                      R"("default": )" + std::to_string(device->getDefault()) + ","
                      R"("min": )" + std::to_string(device->getMin()) + ","
                      R"("max": )" + std::to_string(device->getMax()) + "},"
                      R"("netlist": {)"
                      R"("drain": ")" + device->getDrain()->getId() + "\","
                      R"("gate": ")" + device->getGate()->getId() + "\","
                      R"("source": ")" + device->getSource()->getId() + "\"}}";
    return res;
}

std::string JsonExportVisitor::exportNmos(Nmos *device) {
    return R"({"type": "nmos",)" + exportCmos(device);
}

std::string JsonExportVisitor::exportPmos(Pmos *device) {
    return R"({"type": "pmos",)" + exportCmos(device);
}

std::string JsonExportVisitor::exportTopology(Topology *obj) {
    std::string res = R"({"id": ")" + obj->getId() + "\","
                      R"("components": [)";
    std::vector<Device*> devs = obj->getDeviceList();
    for(int i = 0; i < devs.size(); i++){
        res += devs[i]->accept(this);
        if(i < devs.size()-1) res += ",";
    }
    res += "]}";
    return res;
}
