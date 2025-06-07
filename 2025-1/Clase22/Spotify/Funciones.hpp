/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.hpp
 * Author: hecto
 *
 * Created on June 5, 2025, 3:05 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"

void leer_canciones(const char*, char**, char**, int*, 
                   double*, int&);
void ordenar_canciones(char**, char**, int*, 
                   double*, int);
void mostrar_canciones(char**, char**, int*, 
                   double*, int);
void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo);
void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo);
int leer_entero(ifstream& input);
double leer_double(ifstream& input);
char* leer_cadena(ifstream& input, char del);
void impresion_titulo(ofstream& output, const char*titulo);
#endif /* FUNCIONES_HPP */
