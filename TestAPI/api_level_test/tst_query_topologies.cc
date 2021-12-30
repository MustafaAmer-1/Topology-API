#include "catch.hpp"

#include "API.h"

TEST_CASE("single_topology", "[queryTopologies]"){
    API* api = API::InitAPI();
    auto res = api->readJSON("/media/mustafa/E:/MasterMicro_Tasks/Topology-API/TestAPI/api_level_test/topology.json");
    REQUIRE(res == success);
    TopologyList list = api->queryTopologies();
    REQUIRE(list.size() == 1);
    Topology* top1 = list["top1"];
    REQUIRE(top1->getId() == "top1");
    auto devs = top1->getDeviceList();
    REQUIRE(devs.size() == 2);
    REQUIRE(devs[0]->getMin() == 10);
    REQUIRE(devs[1]->getMax() == 2);
    REQUIRE(devs[0]->getId() == "res1");
    REQUIRE(devs[1]->isAttached(Node::getElementWithID("vin")) == true);
    REQUIRE(devs[0]->isAttached(Node::getElementWithID("vss")) == false);
}

TEST_CASE("multiple_topologies", "[queryTopologies]"){
    API* api = API::InitAPI();
    Result res = api->readJSON("/media/mustafa/E:/MasterMicro_Tasks/Topology-API/TestAPI/api_level_test/topology.json");
    REQUIRE(res == success);
    res = api->readJSON("/media/mustafa/E:/MasterMicro_Tasks/Topology-API/TestAPI/api_level_test/my_topology.json");
    REQUIRE(res == success);
    TopologyList list = api->queryTopologies();
    REQUIRE(list.size() == 2);
    REQUIRE(true == Device::getElementWithID("pmos1")->isAttached(Node::getElementWithID("c1")));
    REQUIRE(false == Device::getElementWithID("nmos1")->isAttached(Node::getElementWithID("c1")));
    REQUIRE(true == Device::getElementWithID("ind1")->isAttached(Node::getElementWithID("l1")));
    REQUIRE(true == Device::getElementWithID("myres1")->isAttached(Node::getElementWithID("r1")));
    REQUIRE(20 == Device::getElementWithID("myres1")->getMin());
    REQUIRE(10.25 == Device::getElementWithID("pmos1")->getMax());
}
