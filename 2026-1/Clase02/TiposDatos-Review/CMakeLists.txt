cmake_minimum_required(VERSION 3.31)
project(TiposDatos_Review)

set(CMAKE_CXX_STANDARD 20)

add_executable(TiposDatos_Review main.cpp
        src/Utils.hpp
        src/AuxiliaryFunctions.cpp
        src/AuxiliaryFunctions.hpp)
