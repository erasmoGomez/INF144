cmake_minimum_required(VERSION 3.31)
project(Pregunta2_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pregunta2_2025_2 main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp
        Bibliotecas/Estructuras/Streamer.hpp
        Bibliotecas/Estructuras/Comentario.hpp
        Bibliotecas/Estructuras/Transmision.hpp
        Bibliotecas/Lista/NodoPalabra.hpp
        Bibliotecas/Estructuras/Palabra.hpp
        Bibliotecas/Lista/ListaPalabra.hpp
)
