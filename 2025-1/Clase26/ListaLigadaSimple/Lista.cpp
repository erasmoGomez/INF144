/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 20, 2025, 6:34 PM
 */

#include "Lista.hpp"

void insertar(struct Nodo*&lista, int valor) {
    struct Nodo *nuevo_nodo;
    nuevo_nodo = new struct Nodo;
    nuevo_nodo->dato = valor;
    nuevo_nodo->siguiente = nullptr;

    if (lista == nullptr) {
        lista = nuevo_nodo;
    } else {
        struct Nodo *recorrido;
        recorrido = lista;
        while (recorrido->siguiente != nullptr) {
            recorrido = recorrido->siguiente;
        }
        recorrido->siguiente = nuevo_nodo;
    }
}

void crear_lista(struct Nodo *&lista) {
    ifstream input("datos.txt", ios::in);
    int valor;
    lista = nullptr;
    while (true) {
        input>>valor;
        if (input.eof())break;
        insertar(lista, valor);
    }
}

void imprimir_lista(struct Nodo *lista) {
    struct Nodo *recorrido;
    recorrido = lista;
    while (recorrido) {
        cout << setw(5) << recorrido->dato;
        recorrido = recorrido->siguiente;
    }
}