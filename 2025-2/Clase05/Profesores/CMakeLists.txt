cmake_minimum_required(VERSION 3.31)
project(Profesores)

set(CMAKE_CXX_STANDARD 20)

add_executable(Profesores main.cpp
        src/Utils.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)
