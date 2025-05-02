/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.hpp
 * Author: hecto
 *
 * Created on May 2, 2025, 5:32 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
void apertura_archivo_lectura(ifstream &, const char*);
void apertura_archivo_escritura(ofstream &, const char*);
//Seccion Carga Datos
void cargar_datos_juegos(const char*, int*, double*, int&);
//Seccion Reporte
void calculo_por_jugador(const char*, const char*, int*, double*, int);
void prueba_impresion(int*, double*, int);
//Seccion Busqueda
double buscar_precio(int, int*, double*, int);
#endif /* FUNCIONES_HPP */
