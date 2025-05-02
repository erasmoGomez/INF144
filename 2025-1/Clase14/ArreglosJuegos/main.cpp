/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 2, 2025, 5:09 PM
 */

#include "Funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //Seccion Datos
    int codigos_juegos[MAX_JUEGOS]{};
    double precios_rondas_juegos[MAX_JUEGOS]{};
    int cantidad_juegos = 0;
    //Seccion de Desarrollo del Problema
    cargar_datos_juegos("JuegosDisponibles.txt", codigos_juegos, precios_rondas_juegos, cantidad_juegos);
    prueba_impresion(codigos_juegos, precios_rondas_juegos, cantidad_juegos);
    calculo_por_jugador("PartidasJugadas.txt", "reporte.txt", codigos_juegos, precios_rondas_juegos, cantidad_juegos);
    return 0;
}

