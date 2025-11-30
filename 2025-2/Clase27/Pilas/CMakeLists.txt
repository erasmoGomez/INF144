cmake_minimum_required(VERSION 3.31)
project(Pilas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pilas main.cpp
        src/Utils.hpp
        src/BibliotecaPila/Nodo.hpp
        src/BibliotecaPila/Pila.cpp
        src/BibliotecaPila/Pila.hpp
        src/BibliotecaFunciones/FuncionesAuxiliares.cpp
        src/BibliotecaFunciones/FuncionesAuxiliares.hpp
        src/BibliotecaPila/PilaTAD.hpp)
