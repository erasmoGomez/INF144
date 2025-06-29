/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Pila.hpp"
void inicializa(struct Pila p){
    p.cima = nullptr;
}

bool esta_vacia(struct Pila &p){
    if(p.cima == nullptr) return true;
    else return false;
}

void push(struct Pila &p, int d){
    struct Nodo* nuevo_nodo;
    nuevo_nodo = new struct Nodo;
    nuevo_nodo->dato = d;
    
    nuevo_nodo->siguiente = p.cima;
    p.cima = nuevo_nodo;
}

void pop(struct Pila &p, int&d){
    if (esta_vacia(p)) return;
    struct Nodo* aux;
    aux = p.cima;
    p.cima = aux->siguiente;
    d = aux->dato;
    delete aux;
}