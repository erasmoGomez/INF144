//
// Created by erasmo on 6/19/26.
//

#include "FuncionesAuxiliares.hpp"
void inicializar_lista(struct ListaTAD &lista) {
    lista.cantidad_nodos = 0;
    lista.inicio = nullptr;
    lista.ultimo = nullptr;
}

void insertar_lista_inicio(struct ListaTAD & codigos, int codigo) {
    //Creacion del NODO
    struct NodoListaSimple *nuevo_nodo;
    nuevo_nodo = new struct NodoListaSimple;
    // nuevo_nodo = new struct NodoListaSimple[1]
    nuevo_nodo->dato = codigo;
    nuevo_nodo->siguiente = nullptr;
    //Insertar el NODO en LISTA
    // Cuando la Lista esta vacia
    if (codigos.inicio == nullptr and codigos.ultimo == nullptr) {
        codigos.inicio = nuevo_nodo;
        codigos.cantidad_nodos = 1;
        //Bonus: si tenemos el puntero ultimo
        codigos.ultimo = nuevo_nodo;
    }
    else {
        // Cuando la lista esta llena
        nuevo_nodo->siguiente = codigos.inicio;
        codigos.inicio = nuevo_nodo;
        codigos.cantidad_nodos++;
    }

}

void cargar_lista_codigos_al_inicio(struct ListaTAD &lista_codigos,
                                    const char *nombre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int codigo = 0;
    inicializar_lista(lista_codigos);
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.ignore();
        insertar_lista_inicio(lista_codigos, codigo);
    }
}
