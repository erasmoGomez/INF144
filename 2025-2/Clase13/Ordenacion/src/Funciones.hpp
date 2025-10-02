//
// Created by Erasmo on 2/10/25.
//

#ifndef ORDENACION_FUNCIONES_HPP
#define ORDENACION_FUNCIONES_HPP

#include "Utils.hpp"

void imprime_datos(int* datos, int n);

void insertion_sort(int* datos, int n);

void selection_sort(int* datos, int n);

void bubble_sort(int* datos, int n);

void selection_sort_not_efficient(int* datos, int n);

void leer_empleados(const char *nombArch, int *dnis, int *fechasIng, char *sexos,
                    int *telefonos, double *sueldos, int &numDat);

void ordenar_por_dni(int *dnis, int *fechasIng,
                     char *sexos, int *telefonos, double *sueldos, int numDat);

void imprimir_empleados(const char *nombArch, int *dnis, int *fechasIng, char *sexos,
                        int *telefonos, double *sueldos, int numDat);

void leer_insertar_ordenado(const char *nombArch, int *dnis,
                            int *fechasIngreso, char *sexos,
                            int *telefonos, double *sueldos, int &numDat);
#endif //ORDENACION_FUNCIONES_HPP
