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

void llenar_estadisticos(char**generos, int n_artistas, char**generos_est, int* estadisticas, int&n_generos);

int buscar_inicio_token(char* tokens, int n) ;
int buscar_fin_token(char* tokens, int start);
void copiar_token(char* origen, int inicio, int fin, char* destino);
void sacar_token(char* tokens, int n, char* token);

void str_to_upper(char* str);
void camelize(char* str);

void ordenar(char**generos_est, int*estadisticas, int n_generos);
void crear_reporte_prueba_estadistica(const char* nombre_archivo,
            char** generos_est, int* estadisticas, int n_generos);
#endif /* SNIPPETS_HPP */
