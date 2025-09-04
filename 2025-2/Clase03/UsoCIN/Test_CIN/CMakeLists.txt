cmake_minimum_required(VERSION 3.31)
project(Test_CIN)

set(CMAKE_CXX_STANDARD 20)

add_executable(Test_CIN main.cpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp
        src/Utils.hpp)
