/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.hpp
 * Author: hecto
 *
 * Created on June 27, 2025, 6:00 PM
 */

#ifndef LIBRO_HPP
#define LIBRO_HPP
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

#endif /* LIBRO_HPP */

