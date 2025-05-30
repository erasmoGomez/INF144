/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 29, 2025, 4:41 PM
 */

#include "Funciones.hpp"

int my_strchr(const char* str, char c) {
    for (int i = 0; str[i]; i++)
        if (str[i] == c)return i;
    return -1;
}

void remove_up_to(char* str, int pos) {
    int i = pos, j = 0;
    while (str[i] != '\0') {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
}

int my_strlen(const char* str) {
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

void my_strcpy(char* destination, const char *source) {
    int i = 0;
    while (true) {
        destination[i] = source[i];
        if (not source[i]) break;
        i++;
    }
}

void my_strcat(char* str1, const char* str2) {
    int pos = my_strlen(str1);
    my_strcpy(&str1[pos], str2);
}

void prepend(char*origin, const char* add) {
    //int new_len = strlen(origin)+strlen(add);
    char aux[100]{};
    my_strcpy(aux, add);
    my_strcat(aux, origin);
    my_strcpy(origin, aux);
}

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void camelizar(char* nombre) {
    int i;
    for (i = 0; nombre[i]; i++) {
        if (nombre[i] == '_') nombre[i] = ' ';
        if (i > 0 and nombre[i - 1] != ' ' and nombre[i] >= 'A' and nombre[i] <= 'Z') {
            nombre[i] += 'a' - 'A';
        }
    }
    nombre[i] = 0;
}

void imprimir_linea(ofstream &output, char c) {
    for (int i = 0; i < ANCHO_REPORTE; i++)
        output.put(c);
    output << endl;
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

void ordenar_seguidores(int *seguidores, double* engagements, int n_tiktokers) {
    for (int i = 0; i < n_tiktokers - 1; i++)
        for (int j = i + 1; j < n_tiktokers; j++)
            if (seguidores[i] > seguidores[j]) {
                intercambiar_int(seguidores[i], seguidores[j]);
                intercambiar_double(engagements[i], engagements[j]);
            }
}

void impresion_titulo(ofstream& output, const char*titulo) {
    output << setw((ANCHO_REPORTE + my_strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

void leer_archivo_imprimir_tiktokers(const char*nombre_archivo,
        int*arr_seguidores, double* engagements,
        int&n_tiktokers) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    ofstream output;
    apertura_archivo_escritura(output, "reporte.txt");

    char usuario[MAX_CADENA]{}, nombre[MAX_CADENA]{};
    int seguidores;
    double engagement;
    //dream_102	CLAY_SANDERSON	26	6.43
    impresion_titulo(output, "Lista de Influencers");
    while (true) {
        input>>usuario;
        if (input.eof())break;
        input >> nombre >> seguidores>>engagement;
        arr_seguidores[n_tiktokers] = seguidores;
        engagements[n_tiktokers] = engagement;
        prepend(usuario, "@");
        camelizar(nombre);
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << usuario;
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << nombre;
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << seguidores;
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << engagement << endl;
        n_tiktokers++;
    }
}

int busqueda_binaria(int* arr, int n, int solicitado) {
    int lim_inf, lim_sup, punto_medio;
    lim_inf = 0;
    lim_sup = n - 1;

    while (true) {
        if (lim_inf > lim_sup) return NO_ENCONTRADO;
        punto_medio = (lim_inf + lim_sup) / 2;
        if (solicitado == arr[punto_medio]) return punto_medio;
        if (solicitado < arr[punto_medio])
            lim_sup = punto_medio - 1;
        else
            lim_inf = punto_medio + 1;
    }
}