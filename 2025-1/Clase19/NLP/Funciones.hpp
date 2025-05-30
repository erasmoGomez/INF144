/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.hpp
 * Author: hecto
 *
 * Created on May 29, 2025, 4:41 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "Utils.hpp"
void prepend(char*, const char*);

void leer_archivo_imprimir_tiktokers(const char*nombre, int*arr_seguidores, double* engagements,
        int&n_tiktokers);

int busqueda_binaria(int* seguidores, int n_tiktokers, int solicitado);
void ordenar_seguidores(int *seguidores, double* engagements, int n_tiktokers);
#endif /* FUNCIONES_HPP */
