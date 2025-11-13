//
// Created by Erasmo on 12/11/25.
//

#ifndef COLAS_COLA_HPP
#define COLAS_COLA_HPP

#include "../BibliotecaFunciones/FuncionesAuxiliares.hpp"
#include "Nodo.hpp"
#include "ColaTAD.hpp"

void encolar(struct Cola &c, int d);

void desencolar(struct Cola &c, int &d);

bool esta_vacia(struct Cola c);

void inicializa(struct Cola &c);

#endif //COLAS_LISTA_HPP
