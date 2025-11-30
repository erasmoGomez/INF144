//
// Created by Erasmo on 12/11/25.
//

#ifndef PILAS_LISTA_HPP
#define PILAS_LISTA_HPP

#include "../BibliotecaFunciones/FuncionesAuxiliares.hpp"
#include "Nodo.hpp"
#include "PilaTAD.hpp"

void pop(struct Pila &p, int &d);

void push(struct Pila &p, int d);

bool esta_vacia(struct Pila &p);

void inicializa(struct Pila p);

#endif //PILAS_LISTA_HPP
