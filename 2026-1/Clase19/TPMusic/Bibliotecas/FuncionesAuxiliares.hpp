//
// Created by erasmo on 6/4/26.
//

#ifndef TPMUSIC_FUNCIONESAUXILIARES_HPP
#define TPMUSIC_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo);

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo);

void imprimir_linea(ofstream &output, char c);

void impresion_titulo(ofstream &output, const char *titulo);

char *leer_cadena(ifstream &input, char del);

int leer_entero(ifstream &input);

double leer_double(ifstream &input);

void lectura_arch_canciones_csv(char **, char **, int *, char **, double *, int &, const char *);

void imprime_linea(ofstream &, char, int);

void lectura_canciones(ifstream &, ofstream &);

void lectura_impresion_reporte(ifstream &, ofstream &);

void ordenar_canciones(char **, char **, int *, char **, double *, int);

void impresion_canciones(char **, char **, int *, char **, double *, int , const char *);

void calcular_frecuencias(char** arr_generos, int cant_datos,
                          int* frecuencias, char** generos_sin_repeticion, int& n_generos);

void imprimir_frecuencias(char **generos_sin_repeticion,
                          int *frecuencias,
                          int n_generos,
                          const char *nombre_archivo);
#endif //TPMUSIC_FUNCIONESAUXILIARES_HPP
