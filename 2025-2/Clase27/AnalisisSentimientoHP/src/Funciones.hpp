//
// Created by erasmo on 11/29/25.
//

#ifndef ANALISISSENTIMIENTOHP_FUNCIONES_HPP
#define ANALISISSENTIMIENTOHP_FUNCIONES_HPP
#include "BibliotecaLista/ListaPersonaje.hpp"
#include "BibliotecaLista/ListaPalabra.hpp"

void cargar_lexicon(const char* nombre_archivo, struct ListaPalabra &lexicon);
void cargar_personajes_oraciones(const char* nombre_archivo, struct ListaPersonaje &personajes, struct ListaPalabra &lexicon);
#endif //ANALISISSENTIMIENTOHP_FUNCIONES_HPP