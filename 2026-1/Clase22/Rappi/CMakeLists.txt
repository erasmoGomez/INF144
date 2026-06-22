cmake_minimum_required(VERSION 4.0)
project(Rappi)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rappi main.cpp
        Bibliotecas/Auxiliares/Utils.hpp
        Bibliotecas/Modelo/Estructuras/Conductor.hpp
        Bibliotecas/Modelo/Estructuras/Fecha.hpp
        Bibliotecas/Modelo/Estructuras/Hora.hpp
        Bibliotecas/Modelo/Estructuras/Codigo.hpp
        Bibliotecas/Modelo/Estructuras/Envio.hpp
        Bibliotecas/Auxiliares/FuncionesAuxiliares.cpp
        Bibliotecas/Auxiliares/FuncionesAuxiliares.hpp
        Bibliotecas/Controlador/FuncionesEstructuras.cpp
        Bibliotecas/Controlador/FuncionesEstructuras.hpp
)
