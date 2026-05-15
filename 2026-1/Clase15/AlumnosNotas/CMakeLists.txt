cmake_minimum_required(VERSION 4.0)
project(AlumnosNotas)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlumnosNotas main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/FuncionesAuxiliares.hpp
        Bibliotecas/FuncionesAuxiliares.cpp)
