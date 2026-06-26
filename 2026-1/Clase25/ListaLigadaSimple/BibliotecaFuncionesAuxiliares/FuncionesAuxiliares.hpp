//
// Created by erasmo on 6/19/26.
//

#ifndef LISTALIGADASIMPLE_FUNCIONESAUXILIARES_HPP
#define LISTALIGADASIMPLE_FUNCIONESAUXILIARES_HPP
#include "../BibliotecaListaSimple/ListaSimpleTAD.hpp"
#include "Utils.hpp"
void cargar_lista_codigos_al_inicio(struct ListaTAD& lista_codigos, const char* nombre_archivo);
void cargar_lista_codigos_al_final_opc1(struct ListaTAD& lista_codigos, const char* nombre_archivo);
void cargar_lista_codigos_al_final_opc2(struct ListaTAD& lista_codigos, const char* nombre_archivo);
void cargar_lista_codigos_ordenado(struct ListaTAD & lista_codigos, const char * nombre_archivo);

void imprimir_lista(const char* nombre_archivo, struct ListaTAD& lista_codigos);

#endif //LISTALIGADASIMPLE_FUNCIONESAUXILIARES_HPP