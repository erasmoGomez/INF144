//
// Created by Erasmo on 6/11/25.
//

#ifndef STRUCTURAS_FUNCIONES_HPP
#define STRUCTURAS_FUNCIONES_HPP
#include "Utils.hpp"
#include "Cancion.hpp"
char* asignar_str(const char* );
void cargar_canciones(const char*, struct Cancion *canciones, int& n_canciones);
void ordenar_canciones(struct Cancion* canciones, int n_canciones);
void imprimir_canciones(const char*, struct Cancion *canciones, int n_canciones);
#endif //STRUCTURAS_FUNCIONES_HPP
