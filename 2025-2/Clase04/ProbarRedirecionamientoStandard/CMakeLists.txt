cmake_minimum_required(VERSION 3.31)
project(ProbarRedirecionamientoStandard)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProbarRedirecionamientoStandard main.cpp
        src/Utils.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)
