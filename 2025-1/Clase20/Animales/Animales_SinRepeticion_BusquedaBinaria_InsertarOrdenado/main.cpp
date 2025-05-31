/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 30, 2025, 3:00 PM
 */
#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    char animales[MAX_ENTRADAS];
    int avistamientos[MAX_ENTRADAS];
    int fotografias[MAX_ENTRADAS];
    int n = 0;
    leer_archivo("dataset.txt", animales, avistamientos, fotografias, n);
    imprimir_resultado("reporte.txt", animales, avistamientos, fotografias,n);
    return 0;
}

