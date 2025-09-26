cmake_minimum_required(VERSION 3.31)
project(Arreglos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Arreglos main.cpp
        src/FuncionesAuxiliares.cpp
        src/FuncionesAuxiliares.hpp
        src/Utils.hpp)
