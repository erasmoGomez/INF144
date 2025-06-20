/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 19, 2025, 2:05 PM
 */


#include "Functions.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Pokemon *pokemones, *equipoA, *equipoB;
    struct Move* movimientos;
    int n_pokemones = 0, n_movimientos = 0;
    cargar_pokemones(pokemones, n_pokemones);
    
    cargar_movimientos(movimientos, n_movimientos);
    completar_info_pokemones(pokemones, n_pokemones, movimientos, n_movimientos);
    imprimir_reporte_pokemones(pokemones, n_pokemones);
    return 0;
}

