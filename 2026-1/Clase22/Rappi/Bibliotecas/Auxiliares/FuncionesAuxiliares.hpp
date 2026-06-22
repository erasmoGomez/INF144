//
// Created by erasmo on 6/13/26.
//

#ifndef RAPPI_FUNCIONESAUXILIARES_HPP
#define RAPPI_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo);

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo);

void imprimir_linea(char ch, int width, ofstream &output);

int leer_entero(ifstream &input, bool leer_char);

double leer_double(ifstream &input, bool leer_char);

char *leer_cadena(ifstream &input, char delim, int n);

void leer_cadena_estatica(ifstream& input, char* cadena, char delim, int n);

bool leer_boolean(ifstream &input);

char leer_char(ifstream &input);

char* asignar_cadena(char* origen);

#endif //RAPPI_FUNCIONESAUXILIARES_HPP