/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: Este programa ofrece diferentes snippets para uso en estudio
 * Created on June 6, 2025, 3:05 PM
 */

#include "Funciones.hpp"
#include "snippets.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    //Leer sin repeticion
    //Vamos a leer sin repeticion los nombres de artistas y acumularemos las reproducciones y los generos
    char* nombres_sin_repeticion[MAX_ARTISTAS]{};
    char* generos[MAX_ARTISTAS]{};
    int reproducciones[MAX_ARTISTAS]{};
    int n_artistas = 0;
    leer_sin_repeticion("music_dataset_extended.csv", nombres_sin_repeticion, generos, reproducciones, n_artistas);
    //Hacer un reporte de prueba
    //Vamos a generar un reporte con titulo y headers
    crear_reporte_prueba("reporte_prueba.txt", nombres_sin_repeticion, generos, reproducciones, n_artistas);
    //Insertar Ordenado con Cadenas
    //Vamos a generar una insercion ordenada comparando los nombres de canciones
    char* nombres[MAX_CANCIONES]{};
    char* titulos_ordenados[MAX_CANCIONES]{};
    int n_canciones = 0;
    insertar_ordenado("music_dataset_extended.csv", nombres, titulos_ordenados, n_canciones);
    crear_reporte_prueba_ordenado("reporte_prueba_ordenado.txt", nombres, titulos_ordenados,  n_canciones);

    
//    char cadena[40] = "Este es un ejemplo de strstr";
//    char * pch;
//    pch = new char[20];
//    pch = strstr (cadena,"str");
//    if(pch!=nullptr)
//        cout<<"Se encontro"<<endl;
//    else
//        cout<<"No se encontro"<<endl;
    return 0;
}

