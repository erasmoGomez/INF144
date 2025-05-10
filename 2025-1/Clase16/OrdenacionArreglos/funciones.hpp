/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on May 8, 2025, 12:15 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"

void apertura_archivo_lectura(ifstream &, const char*);
void apertura_archivo_escritura(ofstream &, const char*);

void leer_datos(const char *, int *, int *, char*, double *, int &);
void imprimir_datos(const char *, int *, int *, char*, double *, int);
void insertar_dato(int, int, int, char, double, int*, int*, char*, double*, int&);
void eliminar_dato(int, int *, int *, char*, double *, int &);
void ordenar_datos(int*, int*, char*, double*, int);
void leer_insertar_ordenado(const char* , int*, int*, char*,double*, int&);
#endif /* FUNCIONES_HPP */
