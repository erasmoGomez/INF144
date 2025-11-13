//
// Created by Erasmo on 12/11/25.
//

#include "Lista.hpp"
#include "ListaTAD.hpp"

void insertar(struct Nodo *&lista, int valor) {
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
        recorrido->siguiente = nuevo_nodo; //Insertamos al final
    }
}

void crear_lista(struct Nodo *&lista, const char *file_name) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int valor;
    lista = nullptr;
    while (true) {
        input >> valor;
        if (input.eof())break;
        insertar(lista, valor);
    }
}

void imprimir_lista(struct Nodo *lista, const char *file_name) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    struct Nodo *recorrido;
    recorrido = lista;
    while (recorrido) {
        output << setw(5) << recorrido->dato;
        recorrido = recorrido->siguiente;
    }
}

void insertar_ordenado(struct Nodo *&lista, int dato) {
    struct Nodo *nuevo_nodo;
    struct Nodo *recorrido = lista;
    struct Nodo *anterior = nullptr;

    //Armar el nodo nuevo
    nuevo_nodo = new struct Nodo;
    nuevo_nodo->dato = dato;

    //Buscar Posicion y actualizar recorrido y anterior
    while (recorrido) {
        if (recorrido->dato > dato) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    //Hacer las conexiones.
    nuevo_nodo->siguiente = recorrido;
    if (anterior == nullptr) lista = nuevo_nodo;
    else anterior->siguiente = nuevo_nodo;
}

void crear_lista_ordenada(struct Nodo *&lista, const char *file_name) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    lista = nullptr;
    int dato;
    while (true) {
        input >> dato;
        if (input.eof())break;
        insertar_ordenado(lista, dato);
    }
}

void remover_elemento_lista(struct Nodo *&lista, int dato) {
    struct Nodo *recorrido = lista;
    struct Nodo *anterior = nullptr;
    while (recorrido and recorrido->dato < dato) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    if (recorrido == nullptr or recorrido->dato != dato)
        cout << "No se encontro el dato en la lista" << endl;
    else {
        if (anterior == nullptr) lista = recorrido->siguiente;
        else anterior->siguiente = recorrido->siguiente;

        delete recorrido;
    }
}

void crear_lista_tad(struct Lista &lista, const char *file_name) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    inicializa_lista_tad(lista);
    int valor;
    while (true) {
        input >> valor;
        if (input.eof())break;
        insertar_nodo_tad(lista, valor); //Aqui debemos insertar en la tad el dato dentro del struct nodo
    }
}

void imprimir_lista_tad(struct Lista &lista, const char *file_name) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    struct Nodo* recorrido = lista.inicio;
    while(recorrido){
        output<<setw(10)<<recorrido->dato<<endl;
        recorrido = recorrido->siguiente;
    }
    output<<lista.cantidad_datos<<endl;
}

void inicializa_lista_tad(struct Lista &lista) {
    lista.cantidad_datos = 0;
    lista.inicio = nullptr;
}

void insertar_nodo_tad(struct Lista &lista, int dato) {
    // Crear el nodo
    struct Nodo *nuevo_nodo;
    nuevo_nodo = new struct Nodo;
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = lista.inicio; // Insertamos al inicio
    lista.inicio = nuevo_nodo; //Update de la TAD
    lista.cantidad_datos++;
}