//
// Created by erasmo on 11/29/25.
//

#include "Funciones.hpp"

bool es_lista_vacia(struct ListaPalabra &l) {
    return l.inicio == nullptr;
}

char *leer_cadena(ifstream &input, char delim) {
    char *cadena, buffer[100];
    input.getline(buffer, 100, delim);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char *asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void inicializa_lista_palabra(struct ListaPalabra &lista_palabra) {
    lista_palabra.inicio = nullptr;
}

void inicializa_lista_personaje(struct ListaPersonaje &lista_personaje) {
    lista_personaje.inicio = nullptr;
}

void insertar_palabra(struct ListaPalabra &lista_palabra, struct Palabra &palabra) {
    // Crear el nodo
    struct NodoPalabra *nuevo_nodo;
    nuevo_nodo = new struct NodoPalabra;
    nuevo_nodo->dato.palabra = asignar_cadena(palabra.palabra);
    nuevo_nodo->dato.palabra_procesada = asignar_cadena(palabra.palabra_procesada);
    nuevo_nodo->dato.polaridad = palabra.polaridad;
    //nuevo_nodo->dato = palabra;
    nuevo_nodo->siguiente = nullptr;

    nuevo_nodo->siguiente = lista_palabra.inicio;
    lista_palabra.inicio = nuevo_nodo; //Update de la TAD
}

void cargar_lexicon(const char *nombre_archivo, struct ListaPalabra &lexicon) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    inicializa_lista_palabra(lexicon); // No olvidar
    //abandoned,-2
    struct Palabra p;
    char palabra[100];
    while (true) {
        input.getline(palabra, 100, ',');
        if (input.eof()) break;
        p.palabra = asignar_cadena(palabra);
        p.palabra_procesada = asignar_cadena(palabra);
        input >> p.polaridad;
        insertar_palabra(lexicon, p);
    }
}

void leer_palabras(ifstream &input, struct NodoPalabra *&inicio, struct NodoPalabra *&lexicon) {
    char palabra[50], palabra_procesada[50];
    struct NodoPalabra *p;
    //I should've known that you would be here Professor McGonagall., 1
    while (true) {
        input >> palabra;
        // preprocesar(palabra, palabra_procesada);
        // if (strlen(palabra_procesada) != 0) {
        //     p = new NodoPalabra;
        //     p->dato.palabra = asignar_cadena(palabra);
        //     p->dato.palabra_procesada = asignar_cadena(palabra_procesada);
        //     p->dato.polaridad = buscar_palabra(lexicon, palabra_procesada);
        //     insertar_nodo_palabra(inicio, p);
        // }
        if (input.get() == ' ') break;
        // if (input.eof())break;
    }
}

void cargar_personajes_oraciones(const char *nombre_archivo, struct ListaPersonaje &personajes,
                                 struct ListaPalabra &lexicon) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    inicializa_lista_personaje(personajes);
    //Dumbledore,I should've known that you would be here Professor McGonagall.,1
    struct Personaje p;
    char buffer_nombre[50];
    struct NodoPalabra *inicio;
    while (true) {
        input.getline(buffer_nombre, 50, ',');
        if (input.eof())break;
        p.nombre = asignar_cadena(buffer_nombre);
        inicio = p.oraciones.inicio;
        leer_palabras(input, inicio, lexicon.inicio);
    }
}
