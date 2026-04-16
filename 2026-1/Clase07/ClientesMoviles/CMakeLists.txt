cmake_minimum_required(VERSION 3.31)
project(ClientesMoviles)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClientesMoviles main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp)
