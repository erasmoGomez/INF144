/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 5, 2025, 3:05 PM
 */

#include "Funciones.hpp"

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

void imprimir_linea(ofstream &output, char c) {
    for (int i = 0; i < ANCHO_REPORTE; i++)
        output.put(c);
    output << endl;
}

void impresion_titulo(ofstream& output, const char*titulo) {
    output << setw((ANCHO_REPORTE + strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

void actualizar_estadistico_tokens(char* cadena, char**generos, int* tally, int& n_generos) {
    int len = strlen(cadena);
    char token[100];
    int j = 0;

    for (int i = 0; i <= len; ++i) {
        if (cadena[i] == '-' or cadena[i] == '\0') {
            token[j] = '\0';
            //Hacer algo con token
            j = 0;
        } else {
            token[j++] = cadena[i];
        }
    }
}

char* leer_cadena(ifstream& input, char del) {
    char buffer[MAX_CAR], *cadena;
    input.getline(buffer, MAX_CAR, del);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

int leer_entero(ifstream& input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

double leer_double(ifstream& input) {
    double dato;
    input>>dato;
    input.get();
    return dato;
}

void leer_canciones(const char* nombre_archivo, char** artistas, char** titulos,
        int* reproducciones, double* bailables, int& n_canciones) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //Ariana Grande,boyfriend,186106,0.4
    char* artista, *titulo;
    while (true) {
        artista = leer_cadena(input, ',');
        if (input.eof())break;
        titulo = leer_cadena(input, ',');
        reproducciones[n_canciones] = leer_entero(input);
        bailables[n_canciones] = leer_double(input);
        //camelizar(titulo);
        artistas[n_canciones] = artista;
        titulos[n_canciones] = titulo;
        n_canciones++;
    }
}

void cambiar_int(int& a, int&b) {
    int aux = a;
    a = b;
    b = aux;
}

void cambiar_double(double& a, double&b) {
    double aux = a;
    a = b;
    b = aux;
}

void cambiar_cadena(char*&a, char*&b) {
    char* aux = a;
    a = b;
    b = aux;
}

void ordenar_canciones(char** artistas, char** titulos,
        int* reproducciones, double* bailables, int n_canciones) {
    for (int i = 0; i < n_canciones - 1; i++)
        for (int j = i + 1; j < n_canciones; j++)
            if (strcmp(artistas[i], artistas[j]) > 0 or strcmp(artistas[i], artistas[j])==0 and 
                   bailables[i]<bailables[j] ) {
                cambiar_cadena(artistas[i], artistas[j]);
                cambiar_cadena(titulos[i], titulos[j]);
                cambiar_int(reproducciones[i], reproducciones[j]);
                cambiar_double(bailables[i], bailables[j]);
            }
}

void mostrar_canciones(char** artistas, char** titulos,
        int* reproducciones, double* bailables, int n_canciones) {
    ofstream output;
    apertura_archivo_escritura(output, "reporte.txt");
    output<<fixed;
    output<<setprecision(2);
    for(int i=0; i<n_canciones;i++){
        output<<setw(30)<<artistas[i]<<setw(50)<<titulos[i];
        output<<setw(10)<<reproducciones[i]<<setw(6)<<bailables[i]<<endl;
    }
}