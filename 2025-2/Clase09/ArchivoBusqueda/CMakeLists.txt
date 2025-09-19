cmake_minimum_required(VERSION 3.31)
project(ArchivoBusqueda)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArchivoBusqueda main.cpp
        src/Utils.hpp
        src/FuncionesAuxiliares.cpp
        src/FuncionesAuxiliares.hpp)
