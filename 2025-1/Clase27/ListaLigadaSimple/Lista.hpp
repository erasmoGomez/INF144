/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.hpp
 * Author: hecto
 *
 * Created on June 20, 2025, 6:34 PM
 */

#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"

void crear_lista(struct Nodo *&lista);
void imprimir_lista(struct Nodo *lista);
void crear_lista_ordenada(struct Nodo *&lista);
void remover_elemento_lista(struct Nodo *&lista, int dato);
#endif /* LISTA_HPP */
