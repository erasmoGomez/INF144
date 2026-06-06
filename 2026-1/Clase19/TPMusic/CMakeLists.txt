cmake_minimum_required(VERSION 4.0)
project(TPMusic)

set(CMAKE_CXX_STANDARD 20)

add_executable(TPMusic main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp)
