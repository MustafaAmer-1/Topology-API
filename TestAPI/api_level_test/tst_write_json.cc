#define JSON_EXAMPLES_PATH "../../json_examples/"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "API.h"
#include "json.hpp"
using json = nlohmann::json;

TEST_CASE("top1 json input file", "[writeJson]"){
    auto api = API::InitAPI();
    auto res = api->readJSON(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    REQUIRE(res == success);
    res = api->writeJSON("top1", "top1_out.json");
    REQUIRE(res == success);
    std::ifstream top1_out( "top1_out.json");
    json top1_out_j;
    top1_out >> top1_out_j;
    json top1_in_j;
    std::ifstream top1_in(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    top1_in >> top1_in_j;
    REQUIRE(top1_in_j == top1_out_j);
    api->deleteTopology("top1");
}

TEST_CASE("top2 json input file", "[writeJson]"){
    auto api = API::InitAPI();
    auto res = api->readJSON(std::string(JSON_EXAMPLES_PATH) + "my_topology.json");
    REQUIRE(res == success);
    res = api->writeJSON("top2", "top2_out.json");
    REQUIRE(res == success);
    std::ifstream top2_out("top2_out.json");
    json top2_out_j;
    top2_out >> top2_out_j;
    json top2_in_j;
    std::ifstream top2_in(std::string(JSON_EXAMPLES_PATH) + "my_topology.json");
    top2_in >> top2_in_j;
    REQUIRE(top2_in_j == top2_out_j);
    api->deleteTopology("top2");
}

TEST_CASE("top1 objects", "[writeJson]"){
    auto api = API::InitAPI();
    Topology* top = new Topology();
    top->setId("top1");
    Resistor* res1 = new Resistor(100, 10, 1000);
    res1->setId("res1");
    auto vdd = new Node();
    vdd->setId("vdd");
    res1->attachT1(vdd);
    auto n1 = new Node();
    n1->setId("n1");
    res1->attachT2(n1);

    top->addDevice(res1);

    Nmos* nmos1 = new Nmos(1.5, 1, 2);
    nmos1->setId("m1");
    nmos1->attachDrain(n1);
    auto vin = new Node();
    vin->setId("vin");
    nmos1->attachGate(vin);
    auto vss = new Node();
    vss->setId("vss");
    nmos1->attachSource(vss);
    

    top->addDevice(nmos1);

    Result res = api->writeJSON("top1", "top1_objects_out.json");
    REQUIRE(res == success);
    std::ifstream top1_out( "top1_objects_out.json");
    json top1_out_j;
    top1_out >> top1_out_j;
    json top1_in_j;
    std::ifstream top1_in(std::string(JSON_EXAMPLES_PATH) + "topology.json");
    top1_in >> top1_in_j;
    REQUIRE(top1_in_j == top1_out_j);
}