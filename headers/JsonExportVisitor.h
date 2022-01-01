/**
 * @file JsonExportVisitor.h
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TOPOLOGY_API_JSONEXPORTVISITOR_H
#define TOPOLOGY_API_JSONEXPORTVISITOR_H

#include <string>

#include "components.h"
#include "Topology.h"

/**
 * @brief visitor singleton class used to export the devices to json object
 * 
 */
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
