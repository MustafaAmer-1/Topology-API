/**
 * @file JsonExportVisitor.cpp
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "JsonExportVisitor.h"

/**
 * @brief Get the JsonExportVisitor singleton object
 * 
 * @return JsonExportVisitor* pointer to the singleton object
 */
JsonExportVisitor* JsonExportVisitor::getJsonExportVisitor() {
    if(visitor == nullptr) visitor = new JsonExportVisitor();
    return visitor;
}

/**
 * @brief exports the given resistor object data to json object
 * 
 * @param device - resistor pointer
 * @return std::string - json object containing the data of the resistor
 */
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

/**
 * @brief exports the given inductor object data to json object
 * 
 * @param device - inductor pointer
 * @return std::string - json object containing the data of the inductor
 */
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

/**
 * @brief exports the given capacitor object data to json object
 * 
 * @param device - capacitor pointer
 * @return std::string - json object containing the data of the capacitor
 */
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

/**
 * @brief private helper method for exporting the given Cmos object data to json object
 * 
 * @param device - Cmos pointer
 * @return std::string - part of the json object containing the data of the Cmos
 */
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

/**
 * @brief exports the given nmos object data to json object
 * 
 * @param device - nmos pointer
 * @return std::string - json object containing the data of the nmos
 */
std::string JsonExportVisitor::exportNmos(Nmos *device) {
    return R"({"type": "nmos",)" + exportCmos(device);
}

/**
 * @brief exports the given pmos object data to json object
 * 
 * @param device - pmos pointer
 * @return std::string - json object containing the data of the pmos
 */
std::string JsonExportVisitor::exportPmos(Pmos *device) {
    return R"({"type": "pmos",)" + exportCmos(device);
}

/**
 * @brief exports the given topology object data to json object
 * 
 * @param device - topology pointer
 * @return std::string - json object containing the data of the topology and list of its components
 */
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
