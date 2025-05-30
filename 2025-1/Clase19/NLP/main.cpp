/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 29, 2025, 4:34 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int seguidores[MAX_TIKTOKERS];
    double engagements[MAX_TIKTOKERS];
    int n_tiktokers = 0, pos;
    leer_archivo_imprimir_tiktokers("tiktokers.txt", seguidores, engagements, n_tiktokers);
    ordenar_seguidores(seguidores, engagements, n_tiktokers);
    for(int i=0; i<n_tiktokers; i++)
        cout<<setw(4)<<i<<setw(4)<<seguidores[i]<<endl;
    pos = busqueda_binaria(seguidores, n_tiktokers, 33);
    cout<<pos<<endl;
    return 0;
}

