cmake_minimum_required(VERSION 4.0)
project(Poke261)

set(CMAKE_CXX_STANDARD 20)

add_executable(Poke261 main.cpp
        Estructuras/Pokemon.hpp
        Estructuras/Estadisticas.hpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp
        Bibliotecas/Utils.hpp)
