cmake_minimum_required(VERSION 3.5)

project(TestAPI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../src ../headers catch2)

file(GLOB_RECURSE SRC "../src/*.cpp")
file(GLOB_RECURSE HEADERS "../headers/*.h")
file(GLOB_RECURSE API_TESTS "api_level_test/*.cc")

add_executable(TestAPI
        ${SRC}
        ${HEADERS}
        catch2/catch.hpp
        ${API_TESTS}
        tst_main.cpp)

add_test(NAME TestAPI COMMAND TestAPI)
