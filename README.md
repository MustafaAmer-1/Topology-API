# Topology-API

C++ API to access, manage and store electronic device topologies.

---

# Background

A topology is a set of electronic components that are connected together, the API expects to receive any topology as JSON file as one of the examples [here](json__examples).

> :information_source: Note: every device in the topology must have a unique id relative to the devices of its type, the same is for the topologies, so please check for any repeated id's.
> 
> this is not applied on the nodes, as many devices can be attached to the same node.

## What can API do

1.  Read and write topologies to and from disk.

2.  Stores multiple topologies in memory.

3. Execute operations on topologies.

## API operations

1.  readJSON: read a topology from a given JSON file and store it in the memory.

2. writeJSON: write a given topology from the memory to a JSON file.

3. queryTopologies: query about which topologies are currently in the memory.

4. deleteTopology: delete a given topology from memory.

5. queryDevices: query about which devices are in a given topology.

6. queryDevicesWithNetlistNode: query about which devices are connected to a given netlist node in a given topology.

# Use API

you can use the API as shared library in your code and including only [API.h](API.h) file.

# Building steps

This project uses [Make](https://www.gnu.org/software/make/) building tool and use [CMake](https://cmake.org/download/) to control the software compilation and testing processes and generating Make build files.

### Manual build

after cloning the repo 

```bash
git clone https://github.com/MustafaAmer-1/Topology-API.git
```

create clean building directory

```bash
mkdir build
cd build
cmake ..
# compile
make
```

# Testing

the testing project with it's source code has been added to the root CMakeList.txt file as subdirectory, so building the library will build it's test codes as well.

this project uses [catch2](https://github.com/catchorg/Catch2) a unit testing framework for C++.

the testing source code is placed in [TestAPI](TestAPI) directory alongside with catch2 single-include header file.

> :warning: All of the tests use the json files located in [json_examples](json_examples) directory, to run the tests correctly you need to replace the macro defined in every test file named JSON_EXAMPLES_PATH with the absolute or relative path of the json file relative to the tests executable files.

This project has been analysed with [cppcheck](https://cppcheck.sourceforge.io/) static code analysis tool and has reported NO ERROR nor warning.
