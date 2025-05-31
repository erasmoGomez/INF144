/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 30, 2025, 3:00 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input) {
        cout << "No se pudo abrir el archivo.\n";
        exit(1);
    }
}

void apertura_archivo_impresion(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output) {
        cout << "No se pudo abrir el archivo.\n";
        exit(1);
    }
}

bool busqueda_binaria(char* animales, int n, char solicitado, int &pos) {
    int lim_inf, lim_sup, punto_medio;
    lim_inf = 0;
    lim_sup = n - 1;

    while (true) {
        if (lim_inf > lim_sup) {
            pos = lim_inf;
            return false;
        }
        punto_medio = (lim_inf + lim_sup) / 2;
        if (solicitado == animales[punto_medio]) {
            pos = punto_medio;
            return true;
        }
        if (solicitado > animales[punto_medio])
            lim_inf = punto_medio + 1;
        else
            lim_sup = punto_medio - 1;
    }
    return false;
}

void insertar_o_acumular(char clave, int v1, int v2, char* animales, int*avistamientos, int*fotografias, int&n) {
    int pos = 0;
    if (busqueda_binaria(animales, n, clave, pos)) {
        avistamientos[pos] += v1;
        fotografias[pos] += v2;
    } else {
        for (int i = n; i > pos; --i) {
            animales[i] = animales[i - 1];
            avistamientos[i] = avistamientos[i - 1];
            fotografias[i] = fotografias[i - 1];
        }
        animales[pos] = clave;
        avistamientos[pos] = v1;
        fotografias[pos] = v2;
        n++;
    }
}

void leer_archivo(const char*nombre_archivo, char* animales, int* avistamientos, int *fotografias, int&n) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    char clave;
    int avistamiento = 0, fotografia = 0;
    //Jaguar 7 2
    while (true) {
        input >> clave;
        if (input.eof())break;
        while (input.get() != ' '); //ignorar
        input >> avistamiento>>fotografia;
        input.get();
        insertar_o_acumular(clave, avistamiento, fotografia, animales, avistamientos, fotografias, n);
    }

    input.close();
}

void imprimir_resultado(const char* nombre_archivo, char* animales, int* avistamientos, int*fotografias, int n) {
    ofstream output;
    apertura_archivo_impresion(output, nombre_archivo);
    output << "\nResumen de animales observados:\n";
    for (int i = 0; i < n; ++i) {
        output << animales[i] << " => Avistamientos: " << avistamientos[i]
                << ", Fotografías: " << fotografias[i] << endl;
    }
}
