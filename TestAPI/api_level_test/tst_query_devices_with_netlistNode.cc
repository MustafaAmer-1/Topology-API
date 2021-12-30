#define JSON_EXAMPLES_PATH "../../json_examples/"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "API.h"

TEST_CASE("topology", "[queryDevicesWithNetlistNode]"){
    auto api1 = API::InitAPI();
    auto res1 = api1->readJSON(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    REQUIRE(res1 == success);
    DeviceList list = api1->queryDevicesWithNetlistNode("top1", "n1");

    REQUIRE(list.size() == 2);
    REQUIRE(list[1]->getId() == "m1");
    REQUIRE(list[1]->getDefault() == 1.5);
    REQUIRE(list[0]->getMax() == 1000);
    REQUIRE(list[0]->isAttached(Node::getElementWithID("n1")) == true);
    REQUIRE(list[1]->isAttached(Node::getElementWithID("vin")) == true);
    REQUIRE(list[0]->isAttached(Node::getElementWithID("vin")) == false);
    REQUIRE(list[1]->isAttached(Node::getElementWithID("vdd")) == false);

    list = api1->queryDevicesWithNetlistNode("top1", "vss");
    REQUIRE(list.size() == 1);
    REQUIRE(list[0]->getId() == "m1");
    REQUIRE(list[0]->isAttached(Node::getElementWithID("vin")) == true);
    REQUIRE(list[0]->getMax() == 2);
}

TEST_CASE("my_topologies", "[queryDevicesWithNetlistNode]"){
    auto api2 = API::InitAPI();
    auto res2 = api2->readJSON(std::string(JSON_EXAMPLES_PATH) + "my_topology.json");
    REQUIRE(res2 == success);

    DeviceList list = api2->queryDevicesWithNetlistNode("top2", "vss2");
    REQUIRE(list.size() == 2);
    REQUIRE("pmos1" == list[0]->getId());
    REQUIRE("myres2" == list[1]->getId());

    list = api2->queryDevicesWithNetlistNode("top2", "c1");
    REQUIRE(list.size() == 2);
    REQUIRE("cap1" == list[0]->getId());
    REQUIRE("pmos1" == list[1]->getId());

    list = api2->queryDevicesWithNetlistNode("top2", "l1");
    REQUIRE(list.size() == 3);
    REQUIRE("myres1" == list[0]->getId());
    REQUIRE("nmos1" == list[1]->getId());
    REQUIRE("ind1" == list[2]->getId());

    REQUIRE(true == list[1]->isAttached(Node::getElementWithID("vin2")));
    REQUIRE(100 == list[0]->getDefault());
    REQUIRE(50 == list[2]->getMin());
}
