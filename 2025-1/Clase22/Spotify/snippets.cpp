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

#include "Funciones.hpp"
#include "snippets.hpp"

void reservar_memoria_fija(char** generos) {
    for (int i = 0; i < MAX_ARTISTAS; i++)
        generos[i] = new char[60];
}

void ignorar(ifstream &input, char c) {
    while (input.get() != c);
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
    // pop -> pop/rock
    pos = strstr(generos_actual, generos_nuevos);
    // si pos es nullptr significa q no ha encontrado la generos_actual en generos_nuevos
    // si pos es diferente de nullptr significa que si ha encontrado generos_actual en generos_nuevos
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

char* asignar_cadena(char*orig){
    char* cadena; //no buffer ni tampoco getline
    cadena = new char[strlen(orig)+1];
    strcpy(cadena, orig);
    return cadena;
}

void insertar_ordenado_canciones(char* nombre, char* titulo, char** nombres,
        char** titulos_ordenados, int& n_canciones) {
    int i = n_canciones-1; 
    while (i >= 0 and strcmp(titulo, titulos_ordenados[i])<0) {
        //titulos_ordenados[i+1] = titulos_ordenados[i];
        titulos_ordenados[i + 1] = asignar_cadena(titulos_ordenados[i]);
        nombres[i+1] = asignar_cadena(nombres[i]);
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
        str_to_upper(titulo);
        camelize(nombre); //erasmo montoya -> Erasmo Montoya
        insertar_ordenado_canciones(nombre, titulo, nombres, titulos_ordenados, n_canciones);
    }
}

void str_to_upper(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' and str[i] <= 'z') {
            str[i] -= ('a' - 'A');
        }
    }
}
//erasmo montoya
void camelize(char* str) {
    bool nueva_palabra = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            nueva_palabra = true;
        } else if (nueva_palabra and str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= ('a' - 'A');  // convertir a mayúscula
            nueva_palabra = false;
        } else if (!nueva_palabra and str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');  // convertir a minúscula
        } else {
            nueva_palabra = false;
        }
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
int calcular_n_generos(char* str){
    int n_generos = 1;
    for(int i=0; i<strlen(str); i++)
        if(str[i]=='/')n_generos++;
    return n_generos;
}

int buscar_inicio_token(char* tokens, int n) {
    if (n < 1) return -1;

    int current = 1;
    for (int i = 0; tokens[i]; i++) {
        if (current == n) return i;
        if (tokens[i] == '/') current++;
    }

    return -1; // No se encontró el token
}

int buscar_fin_token(char* tokens, int start) {
    int i = start;
    while (tokens[i] != '/' and tokens[i] != '\0') i++;
    return i;
}

void copiar_token(char* origen, int inicio, int fin, char* destino) {
    int j = 0;
    //destino = new char [15];
    for (int i = inicio; i < fin; i++)
        destino[j++] = origen[i];
    destino[j] = '\0';
}

void sacar_token(char* tokens, int n, char* token) {
    int start = buscar_inicio_token(tokens, n);
    if (start == -1) return;
    int end = buscar_fin_token(tokens, start);
    copiar_token(tokens, start, end, token);
}


void llenar_estadisticos(char**generos, int n_artistas, char**generos_est, int* estadisticas, int&n_generos){
    int n_generos_artista = 0, pos;
    char genero[15];
    for(int i=0; i<n_artistas; i++){
        n_generos_artista = calcular_n_generos(generos[i]);
        for(int j=0; j< n_generos_artista;j++){
            sacar_token(generos[i], j, genero);
            pos = buscar(genero, generos_est, n_generos);
            if(pos==NO_ENCONTRADO){
                generos_est[n_generos] = asignar_cadena(genero); //grave error de concepto si es q no se reserva memoria
                estadisticas[n_generos] += 1;
                n_generos++;
            }
            else{
                estadisticas[pos]+=1; 
            }
        }
    }
}

void ordenar(char**generos_est, int*estadisticas, int n_generos){
    for(int i=0; i<n_generos-1;i++)
        for(int j=i+1; j<n_generos; j++)
            if(estadisticas[i]<estadisticas[j]){
                cambiar_int(estadisticas[i], estadisticas[j]);
                cambiar_cadena(generos_est[i], generos_est[j]);
            }
}

void crear_reporte_prueba_estadistica(const char* nombre_archivo,
            char** generos_est, int* estadisticas, int n_generos){
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    impresion_titulo(output, "Reporte de Prueba Estadisticos Generos");
    output << setw(ANCHO_REPORTE_2 / 2) << "Genero";
    output << setw(ANCHO_REPORTE_2 / 2) << "Frecuencia"<<endl;
    for (int i = 0; i < n_generos; i++) {
        output << setw(ANCHO_REPORTE_2 / 2) << generos_est[i];
        output << setw(ANCHO_REPORTE_2 / 2) << estadisticas[i]<<endl;
    }
}