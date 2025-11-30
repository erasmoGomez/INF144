cmake_minimum_required(VERSION 4.0)
project(AnalisisSentimientoHP)

set(CMAKE_CXX_STANDARD 20)

add_executable(AnalisisSentimientoHP main.cpp
        src/BibliotecaLista/NodoPalabra.hpp
        src/BibliotecaLista/ListaPalabra.hpp
        src/Palabra.hpp
        src/Utils.hpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/BibliotecaLista/NodoPersonaje.hpp
        src/Personaje.hpp
        src/BibliotecaLista/ListaPersonaje.hpp)
