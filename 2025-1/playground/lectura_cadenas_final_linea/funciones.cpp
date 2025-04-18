/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 17, 2025, 7:55 PM
 */

#include "funciones.hpp"

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

char leer_imprimir_texto(ifstream &input, ofstream & output) {
    char c;
    input>>ws;
    output<<setw(10)<<"";
    while (true) {
        c = input.get();
        if (c == ' ' or c == '\n') break;
        output.put(c);
    }
    return c;
}

void procesar_datos(ifstream& input, ofstream& output) {
    int codigo;
    char tipo, c;
    while (true) {
        input>>codigo;
        if (input.eof())break;
        output << codigo << endl;
        while (true) {
            input>>tipo;
            c = leer_imprimir_texto(input, output);
            if (c == '\n') break;
        }
        output << endl;
    }
}

void leer_cadenas_final_linea(const char*nombre_archivo_datos, const char*nombre_archivo_reporte) {
    ifstream input;
    ofstream output;
    apertura_archivo_lectura(input, nombre_archivo_datos);
    apertura_archivo_escritura(output, nombre_archivo_reporte);
    procesar_datos(input, output);
}