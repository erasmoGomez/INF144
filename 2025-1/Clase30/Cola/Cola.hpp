/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.hpp
 * Author: hecto
 *
 * Created on July 4, 2025, 2:06 PM
 */

#ifndef COLA_HPP
#define COLA_HPP

#include "Utils.hpp"
#include "Nodo.hpp"
struct Cola{
    struct Nodo* inicio;
    struct Nodo* fin;
};

void encolar(struct Cola &c, int d);
void desencolar(struct Cola &c, int &d);
bool esta_vacia(struct Cola c);
void inicializa(struct Cola &c);

#endif /* COLA_HPP */

