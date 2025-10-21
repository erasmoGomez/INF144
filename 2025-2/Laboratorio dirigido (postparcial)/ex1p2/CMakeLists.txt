cmake_minimum_required(VERSION 4.0)
project(ex1p2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex1p2 main.cpp
        src/implementation/read_functions.cpp
        src/headers/read_functions.hpp
        src/headers/utils.hpp
        src/implementation/functions.cpp
        src/headers/functions.hpp
        src/implementation/auxiliary_functions.cpp
        src/headers/auxiliary_functions.hpp
        src/implementation/general_functions.cpp
        src/headers/general_functions.hpp)
