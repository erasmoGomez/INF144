//
// Created by erasmo on 6/4/26.
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

void imprimir_linea(ofstream &output, char c) {
    for (int i = 0; i < ANCHO_REPORTE; i++)
        output.put(c);
    output << endl;
}

void impresion_titulo(ofstream &output, const char *titulo) {
    output << setw((ANCHO_REPORTE + strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

char *leer_cadena(ifstream &input, char del) {
    char buffer[MAX_TAM_CADENA], *cadena;
    input.getline(buffer, MAX_TAM_CADENA, del);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

int leer_entero(ifstream &input) {
    int dato;
    input >> dato;
    input.get(); //Leer la coma
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get();
    input.get(); //Solo para el profe x q usa MAC
    return dato;
}

void lectura_arch_canciones_csv(char **artistas,
                                char **titulos,
                                int *reproducciones,
                                char **generos,
                                double *bailables,
                                int &n_canciones,
                                const char *nombre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //Tyga,Taste,232959,hiphop-pop,0.884
    char *artista;
    while (true) {
        //Sisqo,Thong_Song,253733,hiphop-pop-R&B,0.706
        artista = leer_cadena(input, ',');
        if (input.eof()) {
            delete artista;
            break;
        }
        titulos[n_canciones] = leer_cadena(input, ',');
        reproducciones[n_canciones] = leer_entero(input);
        generos[n_canciones] = leer_cadena(input, ',');
        bailables[n_canciones] = leer_double(input);
        artistas[n_canciones] = artista;
        n_canciones++;
    }
}

void intercambiar_int(int& a, int& b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiar_double(double& a, double& b) {
    double aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiar_str(char*& a, char*& b) {
    char* aux;
    aux = a;
    a = b;
    b = aux;
}

void ordenar_canciones(char **artistas,
                       char **titulos,
                       int *reproducciones,
                       char **generos,
                       double *bailables,
                       int n_canciones) {
    for (int i = 0; i < n_canciones - 1; i++) {
        for (int j = i + 1; j < n_canciones; j++) {
            if (strcmp(artistas[i], artistas[j]) > 0 or
                (strcmp(artistas[i], artistas[j]) == 0 and
                strcmp(titulos[i], titulos[j]) > 0)) {
                intercambiar_str(artistas[i], artistas[j]);
                intercambiar_str(titulos[i], titulos[j]);
                intercambiar_int(reproducciones[i], reproducciones[j]);
                intercambiar_str(generos[i], generos[j]);
                intercambiar_double(bailables[i],bailables[j]);
            }
        }
    }
}

void impresion_canciones(char **artistas,
                         char **titulos,
                         int *reproducciones,
                         char **generos,
                         double *bailables,
                         int n_canciones,
                         const char *nombre_archivo) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    for (int i = 0; i < n_canciones; i++) {
        output << setw(ANCHO_REPORTE / 5) << artistas[i];
        output << setw(ANCHO_REPORTE / 5) << titulos[i];
        output << setw(ANCHO_REPORTE / 5) << reproducciones[i];
        output << setw(ANCHO_REPORTE / 5) << generos[i];
        output << setw(ANCHO_REPORTE / 5) << bailables[i];
        output << endl;
    }
}

char* asignar_cadena(char* cadena) {
    char* str;
    str = new char[strlen(cadena) + 1];
    strcpy(str, cadena);
    return str;
}

int buscar_cadena(char* genero, char** generos_sin_repeticion, int n_generos) {
        for (int i = 0; i < n_generos; i++) {
            if (strcmp(genero, generos_sin_repeticion[i])==0) return i;
        }
    return -1;
}

void insertar_genero(char* genero,
                     char**generos_sin_repeticion,
                     int* frecuencias,
                     int& n_generos) {
    int pos = buscar_cadena(genero, generos_sin_repeticion, n_generos);
    if (pos == -1) {
        generos_sin_repeticion[n_generos] = asignar_cadena(genero);
        frecuencias[n_generos] = 1;
        n_generos++;
    }
    else {
        frecuencias[pos]++;
    }
}

void calcular_frecuencias(char** arr_generos_totales,
                          int cant_datos,
                          int* frecuencias,
                          char** generos_sin_repeticion,
                          int& n_generos) {
    char genero[40]{};
    int k = 0;
    //cout<<arr_generos_totales[4]<<endl;
    cout<<cant_datos<<endl;
    for (int i = 0; i < cant_datos; i++) {
        char *generos;
        generos = asignar_cadena(arr_generos_totales[i]);
        //cout<<generos<<endl;
        // pop-rock-Dance/Electronic
        for (int j=0; j<strlen(generos)+1; j++) {
            if (generos[j] == '-' or
                generos[j] == '\0') {
                genero[k] = '\0'; //pop
                insertar_genero(genero,
                                generos_sin_repeticion,
                                frecuencias,
                                n_generos);
                k=0;
            }
            else {
                genero[k] = generos[j];
                k++;
            }
        }
    }
}

void imprimir_frecuencias(char **generos_sin_repeticion,
                          int *frecuencias,
                          int n_generos,
                          const char *nombre_archivo) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    for (int i = 0; i < n_generos; i++) {
        output<<setw(40)<<generos_sin_repeticion[i];
        output<<setw(10)<<frecuencias[i]<<endl;
    }
}