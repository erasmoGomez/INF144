cmake_minimum_required(VERSION 3.31)
project(Listas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Listas main.cpp
        src/Utils.hpp
        src/BibliotecaLista/Nodo.hpp
        src/BibliotecaLista/Lista.cpp
        src/BibliotecaLista/Lista.hpp
        src/BibliotecaFunciones/FuncionesAuxiliares.cpp
        src/BibliotecaFunciones/FuncionesAuxiliares.hpp
        src/BibliotecaLista/ListaTAD.hpp)
