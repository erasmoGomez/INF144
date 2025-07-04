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
#include "ListaLibro.hpp"
#include "Funciones.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
//    struct ListaCliente lista_clientes_inicio;
//    struct ListaCliente lista_clientes_fin;
//    leer_lista_clientes(lista_clientes_inicio, "Clientes.csv", "inicio");
//    imprimir_reporte_prueba_clientes(lista_clientes_inicio, "reporte_clientes_prueba_inicio.txt");
//    leer_lista_clientes(lista_clientes_fin, "Clientes.csv", "fin");
//    imprimir_reporte_prueba_clientes(lista_clientes_fin, "reporte_clientes_prueba_fin.txt");
    
    struct ListaCliente lista_clientes;
    struct ListaLibro lista_libros;
    leer_lista_clientes_bloques(lista_clientes, "Clientes.csv");
    imprimir_reporte_prueba_clientes(lista_clientes, "reporte_clientes_prueba_bloques.txt");
    leer_lista_libros(lista_libros, "Libros.csv");
    imprimir_reporte_prueba_libros(lista_libros, "reporte_libros_prueba.txt");
    return 0;
}

