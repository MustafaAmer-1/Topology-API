/**
 * @file API.h
 * @author Mustafa Amer (eng.mustafaamer0@gmail.com)
 * @brief this file contain API class signature 
 * which is the main class used for interacting with the API
 * @version 0.1
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TOPOLOGY_API_API_H
#define TOPOLOGY_API_API_H

#include <string>
#include <vector>
#include <map>
#include "Topology.h"
#include "Device.h"
#include "components.h"
#include "Node.h"
#include "JsonExportVisitor.h"

enum Result{success, failed};
typedef const std::string& TopologyID;
typedef const std::string& NetlistNodeID;
typedef std::map<std::string, Topology*> TopologyList;
typedef std::vector<Device*> DeviceList;

/**
 * @brief API class signature
 * which is a singleton class containing the primarily methods for interacting with the API
 * 
 */
class API {
private:
    API(){};
    inline static API* api;
public:
    static API* InitAPI();
    
    Result readJSON(const std::string& FileName);
    Result writeJSON(TopologyID, const std::string& FileName);
    TopologyList queryTopologies();
    Result deleteTopology(TopologyID);
    DeviceList queryDevices(TopologyID);
    DeviceList queryDevicesWithNetlistNode(TopologyID, NetlistNodeID);
};


#endif //TOPOLOGY_API_API_H
