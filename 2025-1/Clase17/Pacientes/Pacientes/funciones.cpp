/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 15, 2025, 5:46 PM
 */

#include "funciones.hpp"

int buscar(int dato, int* arr, int n){
    for(int i = 0; i< n; i++)
        if(dato == arr[i]) return i;
    return NO_ENCONTRADO;
}

int buscar(double dato, double* arr, int n){
    for(int i = 0; i< n; i++)
        if(dato == arr[i]) return i;
    return NO_ENCONTRADO;
}

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
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

int leer_hora(ifstream& input){
    int hora, hh, mm, ss;
    char c;
    input>>hh>>c>>mm>>c>>ss;
    hora = hh*3600+mm*60+ss;
    return hora;
}

void leer_acumular_sin_repeticion(const char* nombre_archivo, int* dnis, 
                                  int* tiempos, int& cantidad_datos){
    //9/09/2023   94683380   2.60   11:17:52   12:48:30
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int dni, hora_inicio, hora_fin, fecha, pos;
    double precio;
    while(true){
        fecha = leer_fecha(input);
        if(input.eof())break;
        //input>>dnis[cantidad_datos]; // No funcion cuando hay repetidos
        dni = leer_int(input);
        precio = leer_double(input);
        hora_inicio = leer_hora(input);
        hora_fin = leer_hora(input);
        pos = buscar(dni, dnis, cantidad_datos);
        if( pos == NO_ENCONTRADO){
            dnis[cantidad_datos] = dni;
            tiempos[cantidad_datos] +=  hora_fin - hora_inicio;
            cantidad_datos++;
        }
        else tiempos[pos] += hora_fin - hora_inicio;
    }
}

void time_to_hh_mm_ss(int tiempo, int&hh, int& mm, int& ss){
    hh = tiempo/3600;
    tiempo %= 3600;
    mm = tiempo/60;
    ss = tiempo%60;
}

void imprimir_datos(const char* nombre_archivo, int*dnis, int*tiempos, int cantidad_datos){
    int hh,mm,ss;
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    for (int i = 0; i<cantidad_datos; i++){
        time_to_hh_mm_ss(tiempos[i], hh,mm,ss);
        output<<setw(10)<<dnis[i]<<"   ";
        output<<setfill('0')<<setw(2)<<hh<<':'<<setw(2)<<mm<<':'<<setw(2)<<ss;
        output<<setfill(' ')<<endl;
    }    
}

void intercambiar_double(double& x, double&y){
    double aux;
    aux = x;
    x = y;
    y = aux;
}

void intercambiar_int(int& x, int&y){
    int aux;
    aux = x;
    x = y;
    y = aux;
}

void ordenar_datos(int* dnis, int* tiempos, int cantidad_datos){
    for(int i=0; i<cantidad_datos-1; i++)
        for(int k = i+1; k<cantidad_datos; k++)
            if(tiempos[i]>tiempos[k])
                intercambiar_int(tiempos[i], tiempos[k]);
}