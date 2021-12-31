# Topology-API

C++ API to access, manage and store electronics devices topologies.

---

This project uses [Make](https://www.gnu.org/software/make/) building tool and use [CMake](https://cmake.org/download/) to control the software compilation and testing processes and generating Make build files.

# Building steps

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
