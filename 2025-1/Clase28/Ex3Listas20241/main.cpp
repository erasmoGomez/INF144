/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 27, 2025, 5:48 PM
 */

#include "ListaCliente.hpp"
#include "Funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    struct ListaCliente lista_clientes;
    leer_lista_clientes(lista_clientes, "Clientes.csv");
    imprimir_reporte_prueba_clientes(lista_clientes, "reporte_clientes_prueba.txt");
    return 0;
}

