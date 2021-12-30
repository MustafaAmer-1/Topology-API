#define JSON_EXAMPLES_PATH "../../json_examples/"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "API.h"

TEST_CASE("topology", "[queryDevices]"){
    auto api1 = API::InitAPI();
    auto res1 = api1->readJSON(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    REQUIRE(res1 == success);
    DeviceList list = api1->queryDevices("top1");

    REQUIRE(list.size() == 2);
    REQUIRE(list[1]->getId() == "m1");
    REQUIRE(list[1]->getDefault() == 1.5);
    REQUIRE(list[0]->getMax() == 1000);
    REQUIRE(list[0]->isAttached(Node::getElementWithID("n1")) == true);
    REQUIRE(list[1]->isAttached(Node::getElementWithID("vin")) == true);
    REQUIRE(list[0]->isAttached(Node::getElementWithID("vin")) == false);
    REQUIRE(list[1]->isAttached(Node::getElementWithID("vdd")) == false);
}

TEST_CASE("my_topologies", "[queryDevices]"){
    auto api2 = API::InitAPI();
    auto res2 = api2->readJSON(std::string(JSON_EXAMPLES_PATH) + "my_topology.json");
    REQUIRE(res2 == success);
    DeviceList list = api2->queryDevices("top2");

    REQUIRE(list.size() == 6);
    REQUIRE("cap1" == list[0]->getId());
    REQUIRE("pmos1" == list[2]->getId());
    REQUIRE(150 == list[4]->getDefault());
    REQUIRE(3.5 == list[3]->getMin());
    REQUIRE(true == list[1]->isAttached(Node::getElementWithID("l1")));
    REQUIRE(true == list[2]->isAttached(Node::getElementWithID("c1")));
    REQUIRE(false == list[5]->isAttached(Node::getElementWithID("vin2")));
    REQUIRE(false == Device::getElementWithID("ind1")->isAttached(Node::getElementWithID("n1")));
    REQUIRE(true == Device::getElementWithID("myres1")->isAttached(Node::getElementWithID("r1")));
    REQUIRE(100 == list[5]->getMin());
    REQUIRE(10.25 == list[3]->getMax());
}
