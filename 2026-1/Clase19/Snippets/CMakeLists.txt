cmake_minimum_required(VERSION 4.0)
project(Snippets)

set(CMAKE_CXX_STANDARD 20)

add_executable(Snippets main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp
        Bibliotecas/Utils.hpp)
