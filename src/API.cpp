#include "API.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

API *API::InitAPI() {
    if(api == nullptr) api = new API();
    return api;
}

Result API::readJSON(const std::string& FileName) {
    std::ifstream infile (FileName);
    if(!infile.is_open()) return failed;
    json j;
    infile >> j;
    Topology* topology = new Topology();
    try {
        topology->setId(j["id"]);
    }
    catch(IdException &e){
        return failed;
    }

    for (auto comp: j["components"]){
        Device* dev;
        auto netlist = comp["netlist"];
        std::vector<Node* > netnodes;
        if (comp["type"] == "resistor") {
            auto value = comp["resistance"];
            dev = new Resistor(value["default"], value["min"], value["max"]);
            for(auto name:{"t1", "t2"}) {
                auto node = Node::getElementWithID(netlist[name]);
                if (node == nullptr) {
                    node = new Node();
                    node->setId(netlist[name]);
                }
                netnodes.push_back(node);
            }
            ((Resistor*)dev)->attachT1(netnodes[0]);
            ((Resistor*)dev)->attachT2(netnodes[1]);
        }
        else if (comp["type"] == "capacitor") {
            auto value = comp["capacitance"];
            dev = new Capacitor(value["default"], value["min"], value["max"]);
            for(auto name:{"pos_t", "neg_t"}) {
                auto node = Node::getElementWithID(netlist[name]);
                if (node == nullptr) {
                    node = new Node();
                    node->setId(netlist[name]);
                }
                netnodes.push_back(node);
            }
            ((Capacitor*)dev)->attachPos_t(netnodes[0]);
            ((Capacitor*)dev)->attachNeg_t(netnodes[2]);
        }
        else if (comp["type"] == "inductor") {
            auto value = comp["inductance"];
            dev = new Inductor(value["default"], value["min"], value["max"]);
            for(auto name:{"t1", "t2"}) {
                auto node = Node::getElementWithID(netlist[name]);
                if (node == nullptr) {
                    node = new Node();
                    node->setId(netlist[name]);
                }
                netnodes.push_back(node);
            }
            ((Inductor*)dev)->attachT1(netnodes[0]);
            ((Inductor*)dev)->attachT2(netnodes[1]);
        }
        else if (comp["type"] == "nmos") {
            auto value = comp["m(l)"];
            dev = new Nmos(value["default"], value["min"], value["max"]);
            for(auto name:{"drain", "gata", "source"}) {
                auto node = Node::getElementWithID(netlist[name]);
                if (node == nullptr) {
                    node = new Node();
                    node->setId(netlist[name]);
                }
                netnodes.push_back(node);
            }
            ((Nmos*)dev)->attachDrain(netnodes[0]);
            ((Nmos*)dev)->attachGate(netnodes[1]);
            ((Nmos*)dev)->attachSource(netnodes[2]);
        }
        else if (comp["type"] == "pmos") {
            auto value = comp["m(l)"];
            dev = new Pmos(value["default"], value["min"], value["max"]);
            for(auto name:{"drain", "gata", "source"}) {
                auto node = Node::getElementWithID(netlist[name]);
                if (node == nullptr) {
                    node = new Node();
                    node->setId(netlist[name]);
                }
                netnodes.push_back(node);
            }
            ((Pmos*)dev)->attachDrain(netnodes[0]);
            ((Pmos*)dev)->attachGate(netnodes[1]);
            ((Pmos*)dev)->attachSource(netnodes[2]);
        }
        else{return failed;}
        try {
            dev->setId(comp["id"]);
        }catch(IdException &e){
            return failed;
        }
        topology->addDevice(dev);
    }
    return success;
}

Result API::writeJSON(TopologyID top_id, const std::string &FileName) {
    std::ofstream outfile(FileName);
    auto top = Topology::getElementWithID(top_id);
    if(!outfile.is_open() || top == nullptr) return failed;

    json j = json::parse(top->accept(JsonExportVisitor::getJsonExportVisitor()));
    outfile << std::setw(4) << j;
    return success;
}

