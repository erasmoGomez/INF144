cmake_minimum_required(VERSION 3.31)
project(Ex3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Ex3 main.cpp
        Bibliotecas/ListaCliente.hpp
        Bibliotecas/NodoCliente.hpp
        Bibliotecas/Cliente.hpp
        Bibliotecas/Utils.hpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        Bibliotecas/NodoLibro.hpp
        Bibliotecas/Libro.cpp
        Bibliotecas/Libro.hpp
        Bibliotecas/Libreria.hpp
        Bibliotecas/Venta.hpp
        Bibliotecas/ListaLibro.hpp)
