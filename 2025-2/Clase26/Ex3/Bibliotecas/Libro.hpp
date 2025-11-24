//
// Created by Erasmo on 24/11/25.
//

#ifndef EX3_LIBRO_HPP
#define EX3_LIBRO_HPP
#include "Libreria.hpp"
struct Libro{
    char* codigo;
    char* titulo;
    char* autor;
    double precio;
    Libreria librerias[5];
    int cantidad_librerias;
    double total_ventas;
    int unidades_vendidas;
    int cantidad_buenas_calificaciones;
    double suma_buenas_calificaciones;
};
#endif //EX3_LIBRO_HPP
