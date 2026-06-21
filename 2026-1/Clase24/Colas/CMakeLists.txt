cmake_minimum_required(VERSION 3.31)
project(Colas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Colas main.cpp
        src/Utils.hpp
        src/BibliotecaCola/Nodo.hpp
        src/BibliotecaCola/Cola.cpp
        src/BibliotecaCola/Cola.hpp
        src/BibliotecaFunciones/FuncionesAuxiliares.cpp
        src/BibliotecaFunciones/FuncionesAuxiliares.hpp
        src/BibliotecaCola/ColaTAD.hpp)
