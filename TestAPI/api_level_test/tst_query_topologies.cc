#define JSON_EXAMPLES_PATH "../../json_examples/"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "API.h"

TEST_CASE("topology", "[queryTopologies]"){
    auto api1 = API::InitAPI();
    auto res1 = api1->readJSON(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    REQUIRE(res1 == success);
    TopologyList list = api1->queryTopologies();
    Topology* top1 = list["top1"];
    REQUIRE(top1->getId() == "top1");
    auto devs_top1 = top1->getDeviceList();
    REQUIRE(devs_top1[0]->getMin() == 10);
    REQUIRE(devs_top1[1]->getMax() == 2);
    REQUIRE(devs_top1[0]->getId() == "res1");
    REQUIRE(devs_top1[1]->isAttached(Node::getElementWithID("vin")) == true);
    REQUIRE(devs_top1[0]->isAttached(Node::getElementWithID("vss")) == false);
}

TEST_CASE("my_topologies", "[queryTopologies]"){
    auto api2 = API::InitAPI();
    auto res2 = api2->readJSON(std::string(JSON_EXAMPLES_PATH) + "my_topology.json");
    REQUIRE(res2 == success);
    TopologyList list = api2->queryTopologies();
    Topology* top2 = list["top2"];
    REQUIRE(top2->getId() == "top2");
    auto devs_top2 = top2->getDeviceList();
    REQUIRE("nmos1" == devs_top2[3]->getId());
    REQUIRE("ind1" == devs_top2[4]->getId());
    REQUIRE(50 == devs_top2[4]->getMin());
    REQUIRE(6.5 == devs_top2[3]->getDefault());
    REQUIRE(true == Device::getElementWithID("pmos1")->isAttached(Node::getElementWithID("c1")));
    REQUIRE(false == Device::getElementWithID("nmos1")->isAttached(Node::getElementWithID("c1")));
    REQUIRE(true == Device::getElementWithID("ind1")->isAttached(Node::getElementWithID("l1")));
    REQUIRE(true == Device::getElementWithID("myres1")->isAttached(Node::getElementWithID("r1")));
    REQUIRE(20 == Device::getElementWithID("myres1")->getMin());
    REQUIRE(10.25 == Device::getElementWithID("pmos1")->getMax());
}
