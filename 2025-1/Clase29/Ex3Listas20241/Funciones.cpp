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
#include "ListaLibro.hpp"
#include "ListaCliente.hpp"
#include "Libro.hpp"

bool es_lista_vacia(struct ListaCliente &l) {
    return l.inicio == nullptr;
}

char* leer_cadena(ifstream & input, char delim) {
    char* cadena, buffer[100];
    input.getline(buffer, 100, delim);
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

void apertura_archivo_escritura(ofstream& output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void inicializa_lista_clientes(struct ListaCliente &lista_clientes) {
    lista_clientes.cantidad_clientes = 0;
    lista_clientes.cantidad_impares = 0;
    lista_clientes.cantidad_pares = 0;
    lista_clientes.inicio = nullptr;
    lista_clientes.fin = nullptr;
}

void inicializa_lista_libros(struct ListaLibro &lista_libros) {
    lista_libros.cantidad_libros = 0;
    lista_libros.inicio = nullptr;
}

bool es_lista_vacia_2(struct ListaCliente &lista_clientes){ 
  return lista_clientes.inicio == nullptr and lista_clientes.fin == nullptr; 
}

void insertar_nodo_cliente_inicio(struct ListaCliente &lista_clientes, struct Cliente c) {
    // Crear el nodo
    struct NodoCliente *nuevo_nodo;
    nuevo_nodo = new struct NodoCliente;
    nuevo_nodo->dato = c;
    nuevo_nodo->siguiente = lista_clientes.inicio;
    
    if(es_lista_vacia_2(lista_clientes)){
        lista_clientes.inicio = nuevo_nodo;
        lista_clientes.fin = nuevo_nodo;
    }
    lista_clientes.inicio = nuevo_nodo; //Update de la TAD
    lista_clientes.cantidad_pares++;
    lista_clientes.cantidad_clientes++;
}

void insertar_nodo_libro_inicio(struct ListaLibro &lista_libros, struct Libro l) {
    // Crear el nodo
    struct NodoLibro *nuevo_nodo;
    nuevo_nodo = new struct NodoLibro;
    nuevo_nodo->dato = l;
    nuevo_nodo->siguiente = lista_libros.inicio;
    
    lista_libros.inicio = nuevo_nodo; //Update de la TAD
    lista_libros.cantidad_libros++;
}

void insertar_nodo_cliente_fin(struct ListaCliente &lista_clientes, struct Cliente c) {
    // Crear el nodo
    struct NodoCliente *nuevo_nodo;
    nuevo_nodo = new struct NodoCliente;
    nuevo_nodo->dato = c;
    nuevo_nodo->siguiente = nullptr;
    if(es_lista_vacia_2(lista_clientes)){
        lista_clientes.inicio = nuevo_nodo;
        lista_clientes.fin = nuevo_nodo;
    }
    lista_clientes.fin->siguiente = nuevo_nodo;
    lista_clientes.fin = nuevo_nodo; //Update de la TAD
    lista_clientes.cantidad_impares++;
    lista_clientes.cantidad_clientes++;
    
}

void leer_lista_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo, const char* opt) {
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
        if(strcmp(opt, "inicio")==0)
            insertar_nodo_cliente_inicio(lista_clientes, c);
        else
            insertar_nodo_cliente_fin(lista_clientes,c);
    }
}

void imprimir_reporte_prueba_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo){
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    
    struct NodoCliente* recorrido = lista_clientes.inicio;
    while(recorrido){
        output<<setw(10)<<recorrido->dato.dni<<setw(50)<<recorrido->dato.nombre<<endl;
        recorrido = recorrido->siguiente;
    }
    output<<setw(30)<<"Total Clientes: "<<lista_clientes.cantidad_clientes<<endl;
    output<<setw(30)<<"Total Clientes con DNI Par: "<<lista_clientes.cantidad_pares<<endl;
    output<<setw(30)<<"Total Clientes con DNI Impar: "<<lista_clientes.cantidad_impares<<endl;
}

void leer_lista_clientes_bloques(struct ListaCliente &lista_clientes, const char* nombre_archivo){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    inicializa_lista_clientes(lista_clientes); // No olvidar
    struct Cliente c;
    int dni_cliente;
    while (true) {
        input>>dni_cliente;
        if (input.eof())break;
        input.get();
        c.nombre = leer_cadena(input, '\n');
        c.dni = dni_cliente;
        //hasta aqui tenemos el Cliente.
        //Tenemos que validar como hacer la insercion
        if(dni_cliente%2 == 0){
            insertar_nodo_cliente_inicio(lista_clientes, c);
        }
        else
            insertar_nodo_cliente_fin(lista_clientes, c);
    }
}

double leer_double(ifstream& input){
    double d;
    input>>d;
    input.get();
    return d;
}
void leer_lista_libros(struct ListaLibro &lista_libros, const char* nombre_archivo){
    inicializa_lista_libros(lista_libros);
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,69.02
    struct Libro l;
    char codigo_libro[20];
    while (true) {
        input.getline(codigo_libro, 20, ',');
        if(input.eof()) break;
        l.titulo = leer_cadena(input, ',');
        l.autor = leer_cadena(input, ',');
        l.precio = leer_double(input);
        l.codigo = asignar_cadena(codigo_libro);
        
        insertar_nodo_libro_inicio(lista_libros, l);
    }
}