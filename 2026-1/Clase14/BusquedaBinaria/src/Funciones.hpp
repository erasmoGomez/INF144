//
// Created by Erasmo on 23/10/25.
//

#ifndef BUSQUEDABINARIA_FUNCIONES_HPP
#define BUSQUEDABINARIA_FUNCIONES_HPP

#include "Utils.hpp"

void apertura_archivo_lectura(ifstream &input, const char *file_name);

void apertura_archivo_escritura(ofstream &output, const char *file_name);

void imprimir_empleados(const char *nombArch, int *dnis, int *fechasIng, char *sexos,
                        int *telefonos, double *sueldos, char** nombres, int numDat);

void leer_insertar_ordenado(const char *nombArch, int *dnis,
                            int *fechasIngreso, char *sexos,
                            int *telefonos, double *sueldos, char **nombres, int &numDat);

int busqueda_binaria(int d, const int *dni, int numDat);

#endif //BUSQUEDABINARIA_FUNCIONES_HPP
