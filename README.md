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
