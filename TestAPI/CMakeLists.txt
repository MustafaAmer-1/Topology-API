cmake_minimum_required(VERSION 3.5)

project(TestAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../src ../headers catch2)

file(GLOB_RECURSE SRC "../src/*.cpp")
file(GLOB_RECURSE HEADERS "../headers/*.h")

add_executable(tst_query_topologies
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_query_topologies.cc
        )

add_executable(tst_delete_topologies
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_delete_topologies.cc
        )

add_executable(tst_query_devices
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_query_devices.cc
        )

add_executable(tst_query_devices_with_netlistNode
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_query_devices_with_netlistNode.cc
        )

add_executable(tst_write_json
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_write_json.cc
        )

add_test(NAME queryTopologies COMMAND tst_query_topologies)
add_test(NAME deleteTopologies COMMAND tst_delete_topologies)
add_test(NAME queryDevices COMMAND tst_query_devices)
add_test(NAME queryDevicesWithNetlistNode COMMAND tst_query_devices_with_netlistNode)
add_test(NAME writeJson COMMAND tst_write_json)
