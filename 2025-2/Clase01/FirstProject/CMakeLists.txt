cmake_minimum_required(VERSION 3.31)
project(FirstProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(FirstProject main.cpp
        src/Utils.hpp
        src/MathFunctions.cpp
        src/MathFunctions.hpp)
