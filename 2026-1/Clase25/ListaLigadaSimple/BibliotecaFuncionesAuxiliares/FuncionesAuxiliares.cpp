//
// Created by erasmo on 6/19/26.
//

#include "FuncionesAuxiliares.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

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
    if (codigos.inicio == nullptr and
        codigos.ultimo == nullptr) {
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

void insertar_lista_final_opc1(struct ListaTAD & lista_tad, int codigo) {
    //Insercion al final como si no existieria el .ultimo
    //Creacion del nuevo_nodo
    struct NodoListaSimple *nuevo_nodo;
    nuevo_nodo = new struct NodoListaSimple;
    nuevo_nodo->dato = codigo;
    nuevo_nodo->siguiente = nullptr;

    if (lista_tad.inicio == nullptr) {
        lista_tad.inicio = nuevo_nodo;
    } else {
        //lista ya tiene valores
        //Hacer un recorrido hasta el ultimo elemento
        struct NodoListaSimple *recorrido = lista_tad.inicio;
        while (recorrido->siguiente != nullptr) {
            //AVANZAR!
            recorrido = recorrido->siguiente;
        }
        //ultimo -> nuevo_nodo
        recorrido->siguiente = nuevo_nodo;
    }
}

void insertar_lista_final_opc2(struct ListaTAD & lista_tad, int codigo) {
    //Insercion al final como si existe el .ultimo
    //Creacion del nuevo_nodo
    struct NodoListaSimple *nuevo_nodo;
    nuevo_nodo = new struct NodoListaSimple;
    nuevo_nodo->dato = codigo;
    nuevo_nodo->siguiente = nullptr;

    if (lista_tad.inicio == nullptr and
        lista_tad.ultimo == nullptr) {
        lista_tad.inicio = nuevo_nodo;
        lista_tad.ultimo = nuevo_nodo;
        lista_tad.cantidad_nodos = 1;
    } else {
        //lista ya tiene valores
        //ultimo -> nuevo_nodo
        lista_tad.ultimo->siguiente = nuevo_nodo;
        lista_tad.ultimo = nuevo_nodo;
    }
}

void cargar_lista_codigos_al_final_opc1(struct ListaTAD &lista_codigos, const char *nombre_archivo) {
    //La insercion al final como si no existiera el .ultimo
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int codigo = 0;
    inicializar_lista(lista_codigos);
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.ignore();
        insertar_lista_final_opc1(lista_codigos, codigo);
    }
}

void cargar_lista_codigos_al_final_opc2(struct ListaTAD &lista_codigos, const char *nombre_archivo) {
    //La insercion al final como usando .ultimo
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int codigo = 0;
    inicializar_lista(lista_codigos);
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.ignore();
        insertar_lista_final_opc2(lista_codigos, codigo);
    }
}

void insertar_ordenado(struct ListaTAD & lista_codigos, int codigo) {
    //nuevo nodo
    struct NodoListaSimple *nuevo_nodo;
    nuevo_nodo = new struct NodoListaSimple;
    nuevo_nodo->dato = codigo;
    nuevo_nodo->siguiente = nullptr;
    //Buscar la posicion para insertar
    struct NodoListaSimple *recorrido;
    recorrido = lista_codigos.inicio;
    struct NodoListaSimple *anterior;
    anterior = nullptr;
    while (recorrido != nullptr) {
        //Caso en el q termina el bucle
        if (recorrido->dato > codigo) break;
        //OJO! primero se debe actualizar el puntero ANTERIOR
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    //Conexiones
    nuevo_nodo->siguiente = recorrido;
    if (anterior == nullptr) lista_codigos.inicio = nuevo_nodo;
    else anterior->siguiente = nuevo_nodo;
}

void cargar_lista_codigos_ordenado(struct ListaTAD &lista_codigos,
                                   const char *nombre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int codigo = 0;
    inicializar_lista(lista_codigos);
    while (true) {
        input>>codigo;
        if (input.eof())break;
        input.ignore();
        insertar_ordenado(lista_codigos, codigo);
    }
}

void imprimir_lista(const char *nombre_archivo, struct ListaTAD &lista_codigos) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    struct NodoListaSimple *recorrido = lista_codigos.inicio;
    while (recorrido != nullptr) {
        output << recorrido->dato << " ";
        recorrido = recorrido->siguiente;
    }
    output << endl;
}
