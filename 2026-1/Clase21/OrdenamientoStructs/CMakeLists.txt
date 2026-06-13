cmake_minimum_required(VERSION 4.0)
project(OrdenamientoStructs)

set(CMAKE_CXX_STANDARD 20)

add_executable(OrdenamientoStructs main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp
        Estructuras/VideoJuego.hpp)
