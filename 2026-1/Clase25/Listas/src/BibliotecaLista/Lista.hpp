//
// Created by Erasmo on 12/11/25.
//

#ifndef LISTAS_LISTA_HPP
#define LISTAS_LISTA_HPP

#include "../BibliotecaFunciones/FuncionesAuxiliares.hpp"
#include "Nodo.hpp"

void crear_lista(struct Nodo *&lista, const char* file_name);

void insertar_final(struct Nodo *&lista, int valor);

void imprimir_lista(struct Nodo *lista, const char* file_name);

void crear_lista_ordenada(struct Nodo *&lista, const char* file_name);

void remover_elemento_lista(struct Nodo *&lista, int dato);

void inicializa_lista_tad(struct Lista &lista);

void insertar_nodo_tad(struct Lista &lista, int dato);

void crear_lista_tad(struct Lista &lista, const char *file_name);

void imprimir_lista_tad(struct Lista &lista, const char *file_name);

#endif //LISTAS_LISTA_HPP
