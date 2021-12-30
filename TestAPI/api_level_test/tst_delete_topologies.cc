#define JSON_EXAMPLES_PATH "../../json_examples/"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "API.h"

TEST_CASE("delete topologies", "[deleteTopology]"){
    API* api = API::InitAPI();
    auto res = api->readJSON(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    REQUIRE(res == success);
    res = api->readJSON(std::string(JSON_EXAMPLES_PATH) + "my_topology.json");
    REQUIRE(res == success);
    auto list = api->queryTopologies();
    REQUIRE(list.size() == 2);
    REQUIRE(Topology::getElementWithID("top1") != nullptr);
    api->deleteTopology("top1");
    list = api->queryTopologies();
    REQUIRE(list.size() == 1);
    REQUIRE(Topology::getElementWithID("top1") == nullptr);
    REQUIRE(Resistor::getElementWithID("res1") == nullptr);
    REQUIRE(Node::getElementWithID("vdd") == nullptr);
    REQUIRE(Topology::getElementWithID("top2") != nullptr);
    api->deleteTopology("top2");
    list = api->queryTopologies();
    REQUIRE(list.empty() == 1);
    REQUIRE(Topology::getElementWithID("top2") == nullptr);
    REQUIRE(Pmos::getElementWithID("pmos1") == nullptr);
    REQUIRE(Node::getElementWithID("vss2") == nullptr);
}
