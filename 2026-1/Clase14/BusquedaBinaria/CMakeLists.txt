cmake_minimum_required(VERSION 3.31)
project(BusquedaBinaria)

set(CMAKE_CXX_STANDARD 20)

add_executable(BusquedaBinaria main.cpp
        src/Utils.hpp
        src/Funciones.cpp
        src/Funciones.hpp)
