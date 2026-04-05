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

void prepocesar(const char *palabra, char *preproc) {
    int k=0;
    for (int i=0; palabra[i]; i++) {
        if (palabra[i]>='A' and palabra[i]<='Z') {
            preproc[k] = palabra[i]+('a'-'A');
            k++;
        }
        else if(palabra[i]>='a' and palabra[i]<='z') {
            preproc[k] = palabra[i];
            k++;
        }
    }
    preproc[k]=0;

}

struct NodoPalabra* buscarPalabra(const char *preproc, struct NodoPalabra *inicio) {
    struct NodoPalabra *p = inicio;
    while (p) {
        if (strcmp(preproc,p->dato.palabra_procesada)==0)return p;
        p = p->siguiente;
    }
    return nullptr;
}

void insertar(struct NodoPalabra *&inicio,const char *palabra,const char *preproc) {
    struct NodoPalabra *nuevo = new NodoPalabra;
    nuevo->dato.palabra = asignar_cadena(palabra);
    nuevo->dato.palabra_procesada = asignar_cadena(preproc);

    nuevo->siguiente = inicio;
    inicio = nuevo;
}

void leer_palabras(ifstream &input, struct NodoPalabra *&inicio, struct NodoPalabra *&lexicon) {
    char palabra[50], palabra_procesada[50];
    char c , libro;
    struct NodoPalabra *p;
    //I should've known that you would be here Professor McGonagall., 1
    while (true) {
        input>>palabra;
        c = input.get();
        if (c=='\r') {
            palabra[strlen(palabra)-3] = '\0';
            libro = palabra[strlen(palabra)];
            input.get();
        }

        prepocesar(palabra,palabra_procesada);
         if (strlen(palabra_procesada)!=0) { //Si la cadena está vacía
             p = buscarPalabra(palabra_procesada,inicio);
             if (p==nullptr) // No está
                 insertar(inicio,palabra,palabra_procesada);
             else // Si está
                 cout<<p->dato.palabra<<endl;;
         }
        if (c=='\r') break;
    }
}

struct NodoPersonaje* buscar_personaje(char* nombre, struct ListaPersonaje &lista_personaje) {
    struct NodoPersonaje *recorrido = lista_personaje.inicio;
    while (recorrido) {
        if (strcmp(nombre, recorrido->dato.nombre) == 0) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

struct NodoPersonaje * insertar_personaje(struct ListaPersonaje &lista_personaje, struct Personaje &personaje) {
    // Crear el nodo
    struct NodoPersonaje *nuevo_nodo;
    nuevo_nodo = new struct NodoPersonaje;
    nuevo_nodo->dato = personaje;
    nuevo_nodo->dato.nombre = asignar_cadena(personaje.nombre);
    nuevo_nodo->siguiente = nullptr;

    nuevo_nodo->siguiente = lista_personaje.inicio;
    lista_personaje.inicio = nuevo_nodo; //Update de la TAD
    return nuevo_nodo;
}

void cargar_personajes_oraciones(const char *nombre_archivo, struct ListaPersonaje &personajes,
                                 struct ListaPalabra &lexicon) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    inicializa_lista_personaje(personajes);
    //Dumbledore,I should've known that you would be here Professor McGonagall.,1
    char buffer_nombre[50];
    struct Personaje p;
    while (true) {
        input.getline(buffer_nombre, 50, ',');
        if (input.eof())break;
        struct NodoPersonaje* personaje = buscar_personaje(buffer_nombre, personajes);
        if (!personaje) {
            p.nombre = asignar_cadena(buffer_nombre);
            p.cantidad_oraciones = 0;
            p.oraciones.inicio = nullptr;
            personaje = insertar_personaje(personajes, p);
        }
        leer_palabras(input, personaje->dato.oraciones.inicio, lexicon.inicio);

    }
}
