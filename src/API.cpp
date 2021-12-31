/**
 * @file API.cpp
 * @author Mustafa Amer (eng.MustafaAmer0@gmail.com)
 * @brief this file contain API class implementation 
 * which is the main class used for interacting with the API
 * @version 0.1
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "API.h"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;


/**
 * @brief singleton method used to return API object pointer
 * 
 * @return API* - pointer object of API class 
 */
API *API::InitAPI() {
    if(api == nullptr) api = new API();
    return api;
}

/**
 * @brief used to read json file containing single topology and store it in the memory
 * IMPORTANT note: every device in the topology must have a unique id relative to the devices of its type.
 * the same is for the topologies, so please check for any repeated id's.
 * this is not applied on the nodes, as many devices can be attached to the same node.
 * 
 * @param FileName - the name (or path) of the json file.
 * @return Result - the result of the reading proccess.
 */
Result API::readJSON(const std::string& FileName) {
    std::ifstream infile (FileName);
    if(!infile.is_open()) return failed;
    json j;
    infile >> j;
    infile.close();
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
            ((Capacitor*)dev)->attachNeg_t(netnodes[1]);
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
            for(auto name:{"drain", "gate", "source"}) {
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
            for(auto name:{"drain", "gate", "source"}) {
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

/**
 * @brief used to write a given topology to the given json file name.
 * 
 * @param top_id - the id of the topology to be written on the file.
 * @param FileName - the name (or path) of the output json file.
 * @return Result - the result of the writing proccess.
 */
Result API::writeJSON(TopologyID top_id, const std::string &FileName) {
    std::ofstream outfile(FileName);
    auto top = Topology::getElementWithID(top_id);
    if(!outfile.is_open() || top == nullptr) return failed;

    std::string out_j = top->accept(JsonExportVisitor::getJsonExportVisitor());
    json j = json::parse(out_j);
    outfile << std::setw(4) << j;
    outfile.close();
    return success;
}

/**
 * @brief used to query for all of the currently stored topologies in the memory.
 * 
 * @return TopologyList - std::map containing the list of topologies with key as the topology id and value topology object pointer.
 */
TopologyList API::queryTopologies() {
    return Topology::getElementList();
}

/**
 * @brief used to delete a given topology from the memory, and delete all it's components
 * 
 * @param top_id - the id of the topology to deleted.
 * @return Result - the result of the deleting proccess
 * return failed if there's no topology with the given id.
 */
Result API::deleteTopology(TopologyID top_id) {
    auto t = Topology::getElementWithID(top_id);
    if(t == nullptr) return failed;
    delete t;
    return success;
}

/**
 * @brief used to query about which devices are in a given topology.
 * 
 * @param top_id - the id of the topology containing the devices.
 * @return DeviceList - std::vector containing device object pointers.
 */
DeviceList API::queryDevices(TopologyID top_id) {
    auto t = Topology::getElementWithID(top_id);
    if(t == nullptr) return {};
    return t->getDeviceList();
}

/**
 * @brief used to query about which devices are connected to a given node in a given topology.
 * 
 * @param top_id - the id of the topology containing the devices.
 * @param node_id - the id of the node which the devices connected to.
 * @return DeviceList - std::vector containing device object pointers which are connected to the node.
 */
DeviceList API::queryDevicesWithNetlistNode(TopologyID top_id, NetlistNodeID node_id) {
    Topology* topology = Topology::getElementWithID(top_id);
    Node* node = Node::getElementWithID(node_id);
    if(topology == nullptr || node == nullptr) return {};
    DeviceList list, attached_list;
    list = topology->getDeviceList();
    for(auto elm :list)
        if(elm->isAttached(node)) attached_list.push_back(elm);
    return attached_list;
}
