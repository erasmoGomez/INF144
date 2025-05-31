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
void sacar_token(const char* tokens, int n, char* token);
int my_strlen(const char* str);
void my_strcpy(char* dest, const char* src);
int buscar_inicio_token(const char* tokens, int n);
int buscar_fin_token(const char* tokens, int inicio);
void copiar_token(const char* origen, int inicio, int fin, char* destino);
int contar_tokens(const char* cadena);
void agregar_token(char* tokens, const char* token);
void imprimir_tokens(const char*);

void modificaTexto(char* nombre_completo, const char* apellido_materno);
#endif /* FUNCIONES_HPP */
