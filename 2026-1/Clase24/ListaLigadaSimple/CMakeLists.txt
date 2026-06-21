cmake_minimum_required(VERSION 4.0)
project(ListaLigadaSimple)

set(CMAKE_CXX_STANDARD 20)

add_executable(ListaLigadaSimple main.cpp
        BibliotecaListaSimple/NodoListaSImple.hpp
        BibliotecaListaSimple/ListaSimpleTAD.hpp
        BibliotecaFuncionesAuxiliares/FuncionesAuxiliares.cpp
        BibliotecaFuncionesAuxiliares/FuncionesAuxiliares.hpp
        BibliotecaFuncionesAuxiliares/Utils.hpp)
