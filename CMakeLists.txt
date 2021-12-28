cmake_minimum_required(VERSION 3.5)

project(Topology-API LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(headers headers/components)
add_subdirectory(TestAPI)

file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE SRC_C "src/components/*.cpp")
file(GLOB_RECURSE HEADERS "headers/*.h")
file(GLOB_RECURSE HEADERS_C "headers/components/*.h")

add_executable(Topology-API
        main.cpp
        ${SRC}
        ${SRC_C}
        ${HEADERS}
        ${HEADERS_C})
