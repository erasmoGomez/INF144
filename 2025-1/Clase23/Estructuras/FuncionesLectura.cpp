/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesLectura.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 12, 2025, 5:45 PM
 */

#include "FuncionesLectura.hpp"
char* asignar_cadena(const char*buffer){
    char* cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void imprimir(const struct VideoJuego& videojuego){
    cout<<videojuego.id<<endl;
    cout<<videojuego.titulo<<endl;
    cout<<videojuego.fecha_lanzamiento<<endl;
    cout<<videojuego.precio<<endl;
    cout<<videojuego.es_apto<<endl;
    for(int i=0; i<5; i++)
        cout<<setw(10)<<videojuego.dlcs[i];
    cout<<endl;
    cout<<setw(20)<<videojuego.empresa_desarrolladora.nombre;
    cout<<setw(5)<<videojuego.empresa_desarrolladora.cantidad_desarrolladores<<endl;
}