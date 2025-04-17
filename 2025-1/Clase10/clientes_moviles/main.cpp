/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 11, 2025, 12:25 PM
 */

#include "funciones.hpp"

/*
 * 
 */

int main(int argc, char** argv) {
    leer_procesar_clientes_moviles("clientes_moviles_2025.txt", 
                                   "planes_clientes_moviles_2025.txt", 
                                   "reporte.txt");
    return 0;
}

