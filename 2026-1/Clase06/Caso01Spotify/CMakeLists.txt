cmake_minimum_required(VERSION 4.1)
project(Caso01Spotify)

set(CMAKE_CXX_STANDARD 20)

add_executable(Caso01Spotify main.cpp
        Librerias/Utils.hpp
        Librerias/AuxiliaryFunctions.cpp
        Librerias/AuxiliaryFunctions.hpp)
