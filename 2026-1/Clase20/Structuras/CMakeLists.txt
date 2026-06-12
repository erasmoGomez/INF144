cmake_minimum_required(VERSION 3.31)
project(Structuras)

set(CMAKE_CXX_STANDARD 20)

add_executable(Structuras main.cpp
        src/VideoJuego.hpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Empresa.hpp
        src/Cancion.hpp
        src/Utils.hpp)
