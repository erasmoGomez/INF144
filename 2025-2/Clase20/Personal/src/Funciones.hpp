//
// Created by Erasmo on 30/10/25.
//

#ifndef PERSONAL_FUNCIONES_HPP
#define PERSONAL_FUNCIONES_HPP

#include "Utils.hpp"

void apertura_archivo_lectura(ifstream &input, const char *file_name);

void apertura_archivo_escritura(ofstream &output, const char *file_name);

void swap_int(int &datoI, int &datoK);

void swap_str(char *&datoI, char *&datoK);

void leer_datos(const char *file_name, int *dnis, char **nombres, int *edades,
                char **distritos, int &n_datos);

void ordenar_datos(int *dnis, char **nombres, int *edades,
                   char **distritos, int n_datos);

void imprimir_datos(const char *file_name,
                    int *dnis, char **nombres, int *edades, char **distritos, int n_datos);

void buscar_imprimir_dato(const char* distrito, int*, char**, int*, char**, int);

void leer_datos_getline(const char* file_name, char**nombres, int &n_datos);

void imprimir_nombres(const char* file_name, char** nombres, int n_datos);
#endif //PERSONAL_FUNCIONES_HPP
