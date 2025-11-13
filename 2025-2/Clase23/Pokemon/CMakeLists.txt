cmake_minimum_required(VERSION 3.31)
project(Pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pokemon main.cpp
        src/Utils.hpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Movimiento.hpp
        src/Pokemon.hpp
        src/Stats.hpp
        src/MoveSet.hpp)
