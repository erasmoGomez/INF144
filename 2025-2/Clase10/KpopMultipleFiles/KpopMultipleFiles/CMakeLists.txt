cmake_minimum_required(VERSION 3.31)
project(KpopMultipleFiles)

set(CMAKE_CXX_STANDARD 20)

add_executable(KpopMultipleFiles main.cpp
        src/Utils.hpp
        src/AuxiliaryFunctions.hpp
        src/AuxiliaryFunctions.cpp)
