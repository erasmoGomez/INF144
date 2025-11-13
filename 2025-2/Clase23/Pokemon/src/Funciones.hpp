//
// Created by Erasmo on 8/11/25.
//

#ifndef POKEMON_FUNCIONES_HPP
#define POKEMON_FUNCIONES_HPP

#include "Utils.hpp"
#include "Pokemon.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo);

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo);

int leer_entero(ifstream &input);

double leer_double(ifstream &input);

char *leer_cadena(ifstream &input, char delim, int n);

void cargar_pokemones(const char *file_name, struct Pokemon *&pokemones, int &n_pokemones);

void imprimir_header(ofstream &output);

void imprimir_titulo(ofstream &output);

void generar_reporte_prueba(const char *file_name, struct Pokemon *pokemones, int n_pokemones);

void cargar_movimientos(const char *file_name, struct Movimiento *&movimientos, int &n_movimientos);

void completar_info_pokemones(struct Pokemon *&pokemones, int n_pokemones, struct Movimiento *movimientos,
                              int n_movimientos);

void imprimir_reporte_pokemones(struct Pokemon *pokemones, int n_pokemones);

#endif //POKEMON_FUNCIONES_HPP
