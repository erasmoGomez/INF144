/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 12, 2025, 5:31 PM
 */

#include "Utils.hpp"
#include "VideoJuego.hpp"
#include "FuncionesLectura.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    //Creamos primero la empresa
    Empresa empresa1;
    empresa1.cantidad_desarrolladores = 41;
    empresa1.nombre = asignar_cadena("Tp es Chevere");
    cout<<setw(20)<<empresa1.nombre<<setw(4)<<empresa1.cantidad_desarrolladores<<endl;
    //Creamos el VideoJuego
    VideoJuego videojuego;
    
    videojuego.id = 123654;
    videojuego.titulo = asignar_cadena("El juego de la Vida");
    cout<<"Ingrese la Fecha De Release del Videojuego: "<<endl;
    cin>>videojuego.fecha_lanzamiento;
    videojuego.precio = 200.99;
    videojuego.es_apto = false;
    for(int i=0; i<5;i++){
        videojuego.dlcs[i] = asignar_cadena("DLC");
    }
    //videojuego.empresa_desarrolladora = empresa1;   
    videojuego.empresa_desarrolladora.cantidad_desarrolladores = empresa1.cantidad_desarrolladores;
    videojuego.empresa_desarrolladora.nombre = asignar_cadena(empresa1.nombre);
    empresa1.nombre[0] = 'X';
    cout<<videojuego.empresa_desarrolladora.nombre<<endl;
    
    imprimir(videojuego);
    return 0;
}

