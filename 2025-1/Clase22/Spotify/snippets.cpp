/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   snippets.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 6, 2025, 5:01 PM
 */
#include <valarray>

#include "Funciones.hpp"
#include "snippets.hpp"

void reservar_memoria_fija(char** generos) {
    for (int i = 0; i < MAX_ARTISTAS; i++)
        generos[i] = new char[60];
}

void ignorar(ifstream &input, char c) {
    while (input.get() != c)
        if (input.eof()) break;
}

int buscar(char* nombre, char** nombres_sin_repeticion, int n_artistas) {
    for (int i = 0; i < n_artistas; i++)
        if (strcmp(nombre, nombres_sin_repeticion[i]) == 0) return i;
    return NO_ENCONTRADO;
}
//pop
//hip hop/r&b

void procesar_generos(char*generos_actual, char*generos_nuevos) {
    if (generos_actual == nullptr) return;
    char* pos;
    pos = strstr(generos_actual, generos_nuevos);
    if (pos != nullptr) {
        strcpy(generos_actual, generos_nuevos);
    } else {
        strcat(generos_actual, "/");
        strcat(generos_actual, generos_nuevos);
    }

}

void leer_sin_repeticion(const char* nombre_archivo, char** nombres_sin_repeticion,
        char**generos, int* reproducciones, int& n_artistas) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //Daniel Bedingfield,Gotta Get Thru This,162333,0.836,hip hop/pop/R&B
    //Reservar memoria FIJA para Generos
    reservar_memoria_fija(generos);
    char *nombre;
    double bailable;
    char *genero;
    int pos, reproduccion;
    while (true) {
        nombre = leer_cadena(input, ',');
        if (input.eof())break;
        ignorar(input, ',');
        reproduccion = leer_entero(input);
        bailable = leer_double(input);
        genero = leer_cadena(input, '\n');
        pos = buscar(nombre, nombres_sin_repeticion, n_artistas);
        if (pos == NO_ENCONTRADO) {
            nombres_sin_repeticion[n_artistas] = nombre;
            reproducciones[n_artistas] += reproduccion;
            strcpy(generos[n_artistas], genero);
            n_artistas++;
        } else {
            reproducciones[n_artistas] += reproduccion;
            procesar_generos(generos[n_artistas], genero);
        }

    }
}

void crear_reporte_prueba(const char*nombre_archivo, char** nombres_sin_repeticion,
        char** generos, int* reproducciones, int n_artistas) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    impresion_titulo(output, "Reporte de Prueba de Spotify");
    output << setw(ANCHO_REPORTE / 3) << "Artista";
    output << setw(ANCHO_REPORTE / 3) << "Total Reproducciones";
    output << setw(ANCHO_REPORTE / 3) << "Generos"<<endl;
    for (int i = 0; i < n_artistas; i++) {
        output << setw(ANCHO_REPORTE / 3) << nombres_sin_repeticion[i];
        output << setw(ANCHO_REPORTE / 3) << reproducciones[i];
        output << setw(ANCHO_REPORTE / 3) << generos[i] << endl;
    }

}

int buscar_pos_orden(char* nombre, char** nombres_sin_repeticion, int n_artistas) {
    for (int i = 0; i < n_artistas; i++)
        if (strcmp(nombre, nombres_sin_repeticion[i]) > 0) return i;
    return NO_ENCONTRADO;
}

char* asigna_cadena(char*orig){
    char* cadena;
    cadena = new char[strlen(orig)+1];
    strcpy(cadena, orig);
    return cadena;
}

void insertar_ordenado_canciones(char* nombre, char* titulo, char** nombres,
        char** titulos_ordenados, int& n_canciones) {
    int i = n_canciones-1; 
    while (i >= 0 and strcmp(titulo, titulos_ordenados[i])<0) {
        //titulos_ordenados[i+1] = titulos_ordenados[i];
        titulos_ordenados[i + 1] = asigna_cadena(titulos_ordenados[i]);
        nombres[i+1] = asigna_cadena(nombres[i]);
        i--;
    }
    titulos_ordenados[i + 1] = titulo;
    nombres[i + 1] = nombre;
    n_canciones++;
}

void insertar_ordenado(const char*nombre_archivo, char** nombres,
        char** titulos_ordenados, int& n_canciones) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //Daniel Bedingfield,Gotta Get Thru This,162333,0.836,hip hop/pop/R&B
    char* nombre;
    char* titulo;
    while (true) {
        nombre = leer_cadena(input, ',');
        if (input.eof())break;
        titulo = leer_cadena(input, ',');
        ignorar(input, '\n');
        insertar_ordenado_canciones(nombre, titulo, nombres, titulos_ordenados, n_canciones);
    }
}

void crear_reporte_prueba_ordenado(const char*nombre_archivo, char** nombres,
        char** titulos_ordenados, int n_canciones) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    impresion_titulo(output, "Reporte de Prueba de Spotify Ordenado por Titulo");
    output << setw(ANCHO_REPORTE_2 / 2) << "Titulo";
    output << setw(ANCHO_REPORTE_2 / 2) << "Artista"<<endl;
    for (int i = 0; i < n_canciones; i++) {
        output << setw(ANCHO_REPORTE_2 / 2) << titulos_ordenados[i];
        output << setw(ANCHO_REPORTE_2 / 2) << nombres[i]<<endl;
    }
}