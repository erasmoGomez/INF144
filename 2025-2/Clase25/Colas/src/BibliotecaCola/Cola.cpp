//
// Created by Erasmo on 12/11/25.
//

#include "Cola.hpp"

void inicializa(struct Cola &c){
    c.inicio = nullptr;
    c.fin = nullptr;
}

bool esta_vacia(struct Cola c){
    if(c.inicio == nullptr and c.fin == nullptr) return true;
    else return false;
}

void encolar(struct Cola &c, int d){
    struct Nodo* nuevo_nodo;
    nuevo_nodo = new struct Nodo;
    nuevo_nodo->dato = d;
    nuevo_nodo->siguiente = nullptr;

    if (esta_vacia(c)) {
        c.inicio = nuevo_nodo;
        c.fin = nuevo_nodo;
    } else {
        c.fin->siguiente = nuevo_nodo;
        c.fin = nuevo_nodo;
    }
}

void desencolar(struct Cola &c, int &d){
    if (esta_vacia(c)) return;

    struct Nodo* aux = c.inicio;
    d = aux->dato;
    c.inicio = aux->siguiente;

    if (c.inicio == nullptr) {
        c.fin = nullptr;
    }

    delete aux;
}