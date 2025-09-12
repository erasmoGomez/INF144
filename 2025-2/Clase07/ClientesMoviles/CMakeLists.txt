cmake_minimum_required(VERSION 3.31)
project(ClientesMoviles)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClientesMoviles main.cpp
        src/Utils.hpp
        src/FuncionesAuxiliares.cpp
        src/FuncionesAuxiliares.hpp)
