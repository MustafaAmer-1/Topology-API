cmake_minimum_required(VERSION 3.5)

project(TestAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../src ../headers catch2)

file(GLOB_RECURSE SRC "../src/*.cpp")
file(GLOB_RECURSE HEADERS "../headers/*.h")

add_executable(query_topologies
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_query_topologies.cc
        )

add_executable(delete_topologies
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_delete_topologies.cc
        )

add_executable(query_devices
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_query_devices.cc
        )

add_executable(query_devices_with_netlistNode
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        api_level_test/tst_query_devices_with_netlistNode.cc
        )

add_test(NAME queryTopologies COMMAND query_topologies)
add_test(NAME deleteTopologies COMMAND delete_topologies)
add_test(NAME queryDevices COMMAND query_devices)
add_test(NAME queryDevicesWithNetlistNode COMMAND query_devices_with_netlistNode)
