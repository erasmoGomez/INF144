/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 27, 2025, 6:16 PM
 */

#include "Funciones.hpp"
#include "ListaCliente.hpp"

bool es_lista_vacia(struct ListaCliente &l) {
    return l.inicio == nullptr;
}

char* leer_cadena(ifstream & input, char delim) {
    char* cadena, buffer[50];
    input.getline(buffer, 50, delim);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char* asignar_cadena(const char* buffer) {
    char* cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void apertura_archivo_lectura(ifstream& input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void inicializa_lista_clientes(struct ListaCliente &lista_clientes) {
    lista_clientes.cantidad_clientes = 0;
    lista_clientes.inicio = nullptr;
}

void insertar_nodo_cliente(struct ListaCliente &lista_clientes, struct Cliente c) {
    // Crear el nodo
    struct NodoCliente *nuevo_nodo;
    nuevo_nodo = new struct NodoCliente;
    nuevo_nodo->dato = c;
    nuevo_nodo->siguiente = lista_clientes.inicio;
    lista_clientes.inicio = nuevo_nodo; //Update de la TAD
    lista_clientes.cantidad_clientes++;
}

void leer_lista_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo) {
    inicializa_lista_clientes(lista_clientes);
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //54393647,Reyes Tang Edward
    struct Cliente c;
    int dni_cliente;
    while (true) {
        input>>dni_cliente;
        if (input.eof())break;
        input.get();
        c.nombre = leer_cadena(input, '\n');
        c.dni = dni_cliente;
        insertar_nodo_cliente(lista_clientes, c);
    }
}

void imprimir_reporte_prueba_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo){
    struct NodoCliente* recorrido = lista_clientes.inicio;
    while(recorrido){
        cout<<setw(10)<<recorrido->dato.dni<<setw(50)<<recorrido->dato.nombre<<endl;
        recorrido = recorrido->siguiente;
    }
    cout<<lista_clientes.cantidad_clientes<<endl;
}