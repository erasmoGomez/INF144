cmake_minimum_required(VERSION 4.0)
project(L8)

set(CMAKE_CXX_STANDARD 20)

add_executable(L8 main.cpp
        Bibliotecas/Categoria.hpp
        Bibliotecas/Reproduccion.hpp
        Bibliotecas/Util.hpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.hpp
        Bibliotecas/FuncionesEstructuras.cpp
        Bibliotecas/FuncionesEstructuras.hpp)
