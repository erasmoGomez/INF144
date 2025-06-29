/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pila.hpp
 * Author: hecto
 *
 * Created on June 26, 2025, 4:40 PM
 */

#ifndef PILA_HPP
#define PILA_HPP
#include "Utils.hpp"
#include "Nodo.hpp"
struct Pila{
    struct Nodo* cima;
};

void pop(struct Pila &p, int&d);
void push(struct Pila &p, int d);
bool esta_vacia(struct Pila &p);
void inicializa(struct Pila p);

#endif /* PILA_HPP */

