/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 25, 2025, 2:48 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    leer_procesar_clientes_moviles("clientes_moviles_2025.txt",
                                   "planes_moviles_2025.txt",
                                   "telefonos_moviles_2025.txt",
                                   "contratos_moviles_2025.txt",
                                   "reporte.txt");
    return 0;
}

