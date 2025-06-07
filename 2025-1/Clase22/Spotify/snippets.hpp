/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   snippets.hpp
 * Author: hecto
 *
 * Created on June 6, 2025, 5:01 PM
 */

#ifndef SNIPPETS_HPP
#define SNIPPETS_HPP
#include "Utils.hpp"
void leer_sin_repeticion(const char* nombre_archivo, char** nombres_sin_repeticion, 
                         char**generos, int* reproducciones, int& n_artistas);

void crear_reporte_prueba(const char*, char** nombres_sin_repeticion, 
                          char** generos, int* reproducciones, int n_artistas);

void insertar_ordenado(const char*, char** nombres, char** titulos_ordenados, int& n_canciones);

void crear_reporte_prueba_ordenado(const char*, char** nombres, 
                          char** titulos_ordenados, int n_canciones);
#endif /* SNIPPETS_HPP */
