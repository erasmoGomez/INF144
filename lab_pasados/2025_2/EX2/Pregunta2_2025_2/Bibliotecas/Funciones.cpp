//
// Created by Erasmo on 20/11/25.
//

#include "Funciones.hpp"

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

void linea(char ch, int width, ofstream &output) {
    output << setfill(ch) << setw(width) << "" << setfill(' ') << "\n";
}

int leer_entero(ifstream &input) {
    int i;
    input >> i;
    input.get(); //La coma
    return i;
}

double leer_double(ifstream &input) {
    double d;
    input >> d;
    input.get();
    return d;
}

char *asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

bool es_lista_vacia(struct ListaPalabra &l) {
    return l.inicio == nullptr;
}

char *leer_cadena(ifstream &input, int n, char delim) {
    char *cadena, buffer[n];
    input.getline(buffer, n, delim);
    if (input.eof()) return nullptr;
    cadena = asignar_cadena(buffer);
    return cadena;
}

char *pre_proc(char *raw) {
    if (!raw) return nullptr;

    int n = strlen(raw);

    // Reservamos memoria del mismo tamaño +1
    char *tmp = new char[n + 1];
    int j = 0;

    // 1. Convertir a minúsculas y reemplazar no-letras por espacio
    for (int i = 0; i < n; ++i) {
        char c = raw[i];

        if (isalpha(c)) {
            tmp[j++] = tolower(c);
        } else {
            tmp[j++] = ' ';
        }
    }
    tmp[j] = '\0';
    // 2. Quitar espacios múltiples y espacios al inicio y final
    char *preproc = new char[n + 1];
    int k = 0;
    bool prev_space = true; // evita espacio inicial

    for (int i = 0; tmp[i]; ++i) {
        if (tmp[i] == ' ') {
            if (!prev_space) {
                // solo agregamos un espacio si antes no había otro
                preproc[k++] = ' ';
            }
            prev_space = true;
        } else {
            preproc[k++] = tmp[i];
            prev_space = false;
        }
    }

    // eliminar posible espacio final
    //    if (k > 0 and preproc[k - 1] == ' ')
    //        k--;

    preproc[k] = '\0';

    delete[] tmp;
    return preproc;
}

struct Palabra asignar_struct_palabra(Palabra & p){
    struct Palabra palabra{};
    palabra.original = asignar_cadena(p.original);
    palabra.preproc = asignar_cadena(p.preproc);
    palabra.cantidad = p.cantidad;
    return palabra;
}

void insertar_nodo_palabra_inicio(struct ListaPalabra &lista, struct Palabra &p) {
    // Crear el nodo
    struct NodoPalabra *nuevo_nodo;
    nuevo_nodo = new struct NodoPalabra;
    nuevo_nodo->palabra = asignar_struct_palabra(p); //Asignacion de structs
    nuevo_nodo->siguiente = lista.inicio;

    // Insertar el nuevo_no
    if (es_lista_vacia(lista))
        lista.inicio = nuevo_nodo;

    lista.inicio = nuevo_nodo; //Update de la TAD
    lista.cantidad++;
}

void inicializar_lista(struct ListaPalabra &l) {
    l.inicio = nullptr;
    l.cantidad = 0;
}

void cargar_stopwords(const char *file_name, ListaPalabra &stopwords) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    inicializar_lista(stopwords); //No olvidar llamar ala funcion inicializar_lista
    char buffer[40]; //Aqui va afuera puesto q esta variable si se puede actualizar
    while (true) {
        input >> buffer;
        if (input.eof())break;
        struct Palabra p{}; //Aqui va dentro puesto que necesitas una instancia nueva siempre para agregar a la lista
        p.original = asignar_cadena(buffer);
        p.preproc = pre_proc(p.original);
        p.cantidad = 1;
        insertar_nodo_palabra_inicio(stopwords, p);
    }
}

NodoPalabra *buscar_nodo_palabra(const ListaPalabra &lista, const char *preproc) {
    NodoPalabra *actual = lista.inicio;

    while (actual) {
        // Comparación por palabra preprocesada
        if (strcmp(actual->palabra.preproc, preproc) == 0) {
            return actual; // Encontrado
        }
        actual = actual->siguiente;
    }

    return nullptr; // No encontrado
}

void insertar_nodo_palabra_sin_repeticion(ListaPalabra &lista, Palabra &p) {
    NodoPalabra *nodo = buscar_nodo_palabra(lista, p.original);

    if (nodo) {
        nodo->palabra.cantidad++;
        return;
    }

    NodoPalabra *nuevo_nodo = new NodoPalabra;

    // Copia profunda de cadenas
    nuevo_nodo->palabra.original = asignar_cadena(p.original);
    nuevo_nodo->palabra.preproc = asignar_cadena(p.preproc);
    nuevo_nodo->palabra.cantidad = p.cantidad;

    // Insertar al inicio
    nuevo_nodo->siguiente = lista.inicio;
    lista.inicio = nuevo_nodo;
    lista.cantidad++;
}

void tokenizar_char_by_char(char *comentario, struct ListaPalabra &palabras) {
    char token[120];
    int i = 0, j = 0;

    while (true) {
        char c = comentario[i];

        if (c == ' ' or c == '\0') {
            if (j > 0) {
                token[j] = '\0';

                Palabra p{};
                p.original = asignar_cadena(token);
                p.preproc = asignar_cadena(token);
                p.cantidad = 1;

                insertar_nodo_palabra_sin_repeticion(palabras, p);

                j = 0;
            }
            if (c == '\0') break;
        } else {
            token[j++] = c;
        }
        i++;
    }
}

void prepocesar(const char *palabra, char *preproc) {
    int k = 0;
    //palabra - > Hola!!!
    for (int i = 0; palabra[i] ; i++) {
        if (palabra[i] >= 'A' and palabra[i] <= 'Z') {
            preproc[k] = palabra[i] + ('a' - 'A');
            k++;
        } else if (palabra[i] >= 'a' and palabra[i] <= 'z') {
            preproc[k] = palabra[i];
            k++;
        }
    }
    //preproc -> hola
    preproc[k] = 0;
}

struct NodoPalabra *buscar_palabra(const char *preproc, struct ListaPalabra &lista_palabras) {
    struct NodoPalabra *recorrido = lista_palabras.inicio;
    while (recorrido) {
        if (strcmp(preproc, recorrido->palabra.preproc) == 0)return recorrido;
        recorrido = recorrido->siguiente;
    }
    return nullptr;
}

void insertar(struct ListaPalabra &lista_palabras, const char *palabra, const char *preproc) {
    // Creacion del nodo
    struct NodoPalabra *nuevo_nodo = new NodoPalabra;
    nuevo_nodo->palabra.original = asignar_cadena(palabra);
    nuevo_nodo->palabra.preproc = asignar_cadena(preproc);
    nuevo_nodo->palabra.cantidad = 1;
    nuevo_nodo->siguiente = lista_palabras.inicio;
    // Insertar el nodo
    if (es_lista_vacia(lista_palabras)) {
        lista_palabras.inicio = nuevo_nodo;
    }
    lista_palabras.inicio = nuevo_nodo; //Update de la TAD
    lista_palabras.cantidad ++;
}

void tokenizar(ifstream &arch, struct ListaPalabra &lista_palabras) {
    char palabra[50], preproc[50];
    char c;
    //Hoy si sale ranked 💪\n o mac \r\n
    //Chat, no sean toxicos pls. hoy.
    while (true) {
        arch >> palabra; //Hoy
        prepocesar(palabra, preproc); //hoy
        struct NodoPalabra *p;
        if (strlen(preproc) != 0) {
            //Si la cadena está vacía
            p = buscar_palabra(preproc, lista_palabras);
            if (p == nullptr) // No está la palabra en la listqa
                insertar(lista_palabras, palabra, preproc); // hoy -> sale -> ranked ->nullptr
            else // Si está la palabra en la lista
                p->palabra.cantidad++; //incrementar la cantidad de palabras
        }
        c = arch.get();
        if (c == '\r')break;
    }
}

void cargar_palabras(const char *file_name, ListaPalabra &palabras) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    inicializar_lista(palabras);
    char nombre[40];
    int id_transmision;
    while (true) {
        input >> id_transmision;
        if (input.eof())break;
        input.get();
        input.getline(nombre, 60, ',');
        tokenizar(input, palabras);
    }

}

void imprimir_palabras(const char *file_name, ListaPalabra &palabras) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    /*
     *    imprimir: a->b->c->d->nullptr -> si quiero ir hasta el final final, cuando se caiga del arrelo uso while(recorrido)
     *    buscar o encontrar una pos: a->b->c->d->nullptr lo q necesitas aqui es while(recorrido->siguiente) no te caes del arreglo
     */

    struct NodoPalabra *recorrido = palabras.inicio; // Esto es obligatorio, se crea un recorrido antes de la impresion.
    while (recorrido) {
        output << setw(20) << recorrido->palabra.preproc << setw(50) << recorrido->palabra.cantidad << endl;
        recorrido = recorrido->siguiente;
    }
    output.close();
}

void eliminar_stopwords(ListaPalabra &palabras, ListaPalabra &stopwords) {
    NodoPalabra *recorrido = stopwords.inicio;

    // Recorrer cada stopword
    while (recorrido) {
        char *objetivo = recorrido->palabra.preproc;

        NodoPalabra *actual = palabras.inicio;
        NodoPalabra *anterior = nullptr; //Aqui estamos buscando y x eso usamo *anterior

        // Recorrer la lista de palabras
        while (actual) {
            if (strcmp(actual->palabra.preproc, objetivo) == 0) { //hoy y hoy x q ambas estan pre procesadas
                                                                  //hoy y Hoy, eso es erroneo
                // Eliminar nodo
                NodoPalabra *tmp = actual; //esto es como recorrido

                if (anterior == nullptr) {
                    // El nodo a eliminar está al inicio
                    palabras.inicio = actual->siguiente;
                } else {
                    anterior->siguiente = actual->siguiente;
                }

                actual = actual->siguiente;

                // Liberar cadenas y nodo
                delete[] tmp->palabra.original;
                delete[] tmp->palabra.preproc;
                delete tmp;

                palabras.cantidad--;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
        }

        recorrido = recorrido->siguiente;
    }
}

void insertar_ordenado(struct ListaPalabra &lista, struct Palabra &p) {
    struct NodoPalabra *nuevo_nodo;
    struct NodoPalabra *recorrido = lista.inicio;
    struct NodoPalabra *anterior = nullptr;

    //Armar el nodo nuevo
    nuevo_nodo = new struct NodoPalabra;
    nuevo_nodo->palabra = asignar_struct_palabra(p);

    //Buscar Posicion y actualizar recorrido y anterior
    while (recorrido) {
        // recorrido != nullptr
        if (recorrido->palabra.cantidad < p.cantidad) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    //Hacer las conexiones.
    nuevo_nodo->siguiente = recorrido;
    if (anterior == nullptr) lista.inicio = nuevo_nodo;
    else anterior->siguiente = nuevo_nodo;
}

void cargar_palabras_ordenado(const char *file_name, struct ListaPalabra &ranking) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    inicializar_lista(ranking);
    char buffer[40];
    while (true) {
        input >> buffer;
        if (input.eof())break;
        struct Palabra p{};
        p.original = asignar_cadena(buffer);
        p.preproc = asignar_cadena(buffer);
        input >> p.cantidad;
        insertar_ordenado(ranking, p);
    }
}
