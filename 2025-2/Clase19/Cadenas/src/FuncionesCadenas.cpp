//
// Created by Erasmo on 26/10/25.
//

#include "FuncionesCadenas.hpp"


void modificar_cadena(char *cadena) {
    for (int i = 0; cadena[i]; i++)
        if (cadena[i] == '/' or cadena[i] == '-')
            cadena[i] = ' ';
}


void camelizar(char *cadena) {
    bool inicio_palabra = true;
    for (int i = 0; cadena[i]; i++) {
        if (inicio_palabra){
            inicio_palabra = false;
            cadena[i] -= ('a' - 'A');
        }
        else
            if (cadena[i] == ' ')
                inicio_palabra = true;
    }
}

void copiar(char *destino, const char *fuente) {
    int i;
    for (i = 0; fuente[i]; i++)
        destino[i] = fuente[i];
    destino[i] = '\0'; // 0
}

int comparar(const char *A, const char *B) {
    int i = 0;
    while (A[i] == B[i]) {
        if (A[i] == '\0') return 0;
        i++;
    }
    return A[i] - B[i];
}

int longitud(const char *str) {
    int i = 0;
    for (i = 0; str[i]; i++);
    return i;
}

void concatenar(char *destino, const char *fuente) {
    int pos;
    pos = longitud(destino);
    copiar(&destino[pos], fuente);
}