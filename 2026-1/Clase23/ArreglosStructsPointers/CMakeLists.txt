cmake_minimum_required(VERSION 4.0)
project(ArreglosStructsPointers)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArreglosStructsPointers main.cpp
        Librerias/Curso.hpp
        Librerias/Alumno.hpp
        Librerias/FuncionesAuxiliares.cpp
        Librerias/FuncionesAuxiliares.hpp)
