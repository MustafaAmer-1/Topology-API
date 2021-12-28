cmake_minimum_required(VERSION 3.5)

project(Topology-API LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src headers)
add_subdirectory(TestAPI)

file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE HEADERS "headers/*.h")

add_executable(Topology-API
        main.cpp
        ${SRC}
        ${HEADERS})
