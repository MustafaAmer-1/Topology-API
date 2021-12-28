#ifndef TOPOLOGY_API_JSONEXPORTVISITOR_H
#define TOPOLOGY_API_JSONEXPORTVISITOR_H

#include <string>

#include "components.h"
#include "Topology.h"

class JsonExportVisitor {
private:
    JsonExportVisitor(){};
    inline static JsonExportVisitor* visitor;
private:
    std::string exportCmos(Cmos* device);
public:
    static JsonExportVisitor* getJsonExportVisitor();
    
    std::string exportResistor(Resistor* device);
    std::string exportInductor(Inductor* device);
    std::string exportNmos(Nmos* device);
    std::string exportPmos(Pmos* device);
    std::string exportCapacitor(Capacitor* device);
    std::string exportTopology(Topology* obj);
};


#endif //TOPOLOGY_API_JSONEXPORTVISITOR_H
