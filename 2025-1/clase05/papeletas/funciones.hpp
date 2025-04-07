/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on April 3, 2025, 4:46 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "utils.hpp"
// Funciones principales / de mayor nivel

void leer_y_procesar_papeletas();
void imprime_resumen(double, double, int, int);
void imprimir_titulo(const char*, int, int);
void imprimir_headers();

// Funciones de procesamiento medio

void imprime_fecha(int);
void lee_imprime_nombre();
void imprime_hora(int);
double calcula_distancia();

// Funciones de conversión geográfica

double grados_a_decimal(double, double, double);
double convertir_radianes(double);
double haversine(double, double, double, double);

// Funciones auxiliares de entrada

int leer_fecha();
int leer_hora();
void ignorar_nombre();
void leer_imprimir_location(const char*);

// Funciones auxiliares de salida

void imprimir_rango_meses(int, int);
const char* conseguir_nombre_mes(int);
const char* conseguir_tipo_falta(int);
void imprimir_linea(char);
void lee_imprime_nombre();

#endif /* FUNCIONES_HPP */
