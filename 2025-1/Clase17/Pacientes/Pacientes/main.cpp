/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 15, 2025, 5:45 PM
 */
#include "funciones.hpp"


/*
 * 
 */

int main(int argc, char** argv) {
    int dnis[MAX_DATOS]{}, tiempos[MAX_DATOS]{}, cantidad_datos = 0;
    leer_acumular_sin_repeticion("Pacientes.txt", dnis, tiempos, cantidad_datos);
    ordenar_datos(dnis, tiempos, cantidad_datos);
    imprimir_datos("Reporte.txt", dnis, tiempos, cantidad_datos);
    
    return 0;
}

