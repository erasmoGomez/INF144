cmake_minimum_required(VERSION 3.31)
project(Cadenas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cadenas main.cpp
        src/FuncionesCadenas.cpp
        src/FuncionesCadenas.hpp
        src/Utils.hpp)
