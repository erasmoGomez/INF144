/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 5, 2025, 3:05 PM
 */

#include "Funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    char* artistas[MAX_CANCIONES]; 
    char* titulos[MAX_CANCIONES];
    int reproducciones[MAX_CANCIONES];
    double bailables[MAX_CANCIONES];
    int n_canciones = 0;
    
    leer_canciones("music_dataset.csv", artistas, titulos, reproducciones, 
                   bailables, n_canciones);
    ordenar_canciones(artistas, titulos, reproducciones, 
                   bailables, n_canciones);
    mostrar_canciones(artistas, titulos, reproducciones, 
                   bailables, n_canciones);
    return 0;
}

