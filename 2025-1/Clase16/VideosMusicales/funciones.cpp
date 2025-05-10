/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 9, 2025, 3:45 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void fecha_dd_mm_aa(int f, int &dd, int &mm, int &aa) {
    //Fecha: 20240926
    aa = f / 10000; //2024
    f %= 10000; //0926
    mm = f / 100; //9
    dd = f % 100; //26
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void ignorar_cadena(ifstream& input, char del) {
    input>>ws;
    while (input.get() != del);
}

int leer_fecha(ifstream& input) {
    int fecha, dd, mm, aa;
    char c;
    input >> dd >> c >> mm >> c >> aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

int leer_int(ifstream& input) {
    int i;
    input >> i;
    return i;
}

char leer_char(ifstream& input) {
    char c;
    input >> c;
    return c;
}

double leer_double(ifstream& input) {
    double d;
    input >> d;
    return d;
}

void cargar_datos_videos(const char* nombre_archivo, char* tipos_videos, 
                         int* codigos_videos, double* duraciones_videos, 
                         int& cantidad_videos){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    
    //P001	3.32	feather/sabrina-carpenter
    char tipo;
    while(true){
        tipo = input.get();
        //input>>tipo;
        if(input.eof())break;
        tipos_videos[cantidad_videos] = tipo;
        codigos_videos[cantidad_videos] = leer_int(input);
        duraciones_videos[cantidad_videos] = leer_double(input);
        ignorar_cadena(input, '\n');
        cantidad_videos++;
    }
}

void cargar_datos_dispositivos(const char* nombre_archivo, int* dnis_dispositivos, 
                         char* tipos_dispositivos, int* codigo_dispositivos, 
                         int& cantidad_dispostivos){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    
    //78450044	MOB-015
    int dni;
    while(true){
        input>>dni;
        if(input.eof())break;
        dnis_dispositivos[cantidad_dispostivos] = dni;
        tipos_dispositivos[cantidad_dispostivos] = leer_char(input);
        ignorar_cadena(input,'-');
        codigo_dispositivos[cantidad_dispostivos] = leer_int(input);
        cantidad_dispostivos++;
    }
}