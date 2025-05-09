/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 8, 2025, 12:14 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    int codigos[MAX_VIDEOJUEGOS]{}, fechas[MAX_VIDEOJUEGOS]{};
    char pg13s[MAX_VIDEOJUEGOS]{};
    double precios[MAX_VIDEOJUEGOS]{};
    int cantidad_juegos = 0;
    leer_datos("videojuegos.txt",codigos,fechas,pg13s,precios,cantidad_juegos);
    imprimir_datos("ReporteVideojuegos.txt",codigos,fechas,pg13s,precios,cantidad_juegos);
    insertar_dato(8, 20082060, 20250508, 'T', 105.56, codigos, fechas, pg13s, precios, cantidad_juegos);
    eliminar_dato(10, codigos, fechas, pg13s, precios, cantidad_juegos);
    imprimir_datos("ReporteVideojuegosNuevoDato.txt",codigos,fechas,pg13s,precios,cantidad_juegos);
    ordenar_datos(codigos,fechas,pg13s,precios,cantidad_juegos);
    imprimir_datos("ReporteVideojuegosOrdenador.txt",codigos,fechas,pg13s,precios,cantidad_juegos);
    return 0;
}

