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

// Procesamiento principal
void leer_y_procesar_papeletas();
void procesar_papeleta(int, int, double&, double&, int&, int&);

// Validación y actualización
bool esta_en_rango(int, int, int);
void actualizar_resumen(double&, double&, int&, int&, int, double, double, bool);

// Cálculos y conversiones
double calcula_distancia();
double grados_a_decimal(double, double, double);
double convertir_radianes(double);
double haversine(double, double, double, double);

// Entrada de datos
int leer_fecha();
int leer_hora();
void ignorar_nombre();

// Impresión
double calcula_distancia();
void imprimir_linea_papeleta(int, int, double, double, bool);
void imprime_resumen(double, double,
        int, int);
void imprimir_titulo(const char*, int, int);
void imprimir_headers();
void imprime_fecha(int);
void lee_imprime_nombre();
void imprime_hora(int);
void leer_imprimir_location(const char*);
void imprimir_linea(char);
void imprimir_rango_meses(int, int);

// Utilitarios
const char* conseguir_nombre_mes(int);
const char* conseguir_tipo_falta(int);

#endif /* FUNCIONES_HPP */
