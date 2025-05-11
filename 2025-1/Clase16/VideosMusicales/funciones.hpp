/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on May 9, 2025, 3:45 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
void apertura_archivo_lectura(ifstream &, const char*);
void apertura_archivo_escritura(ofstream &, const char*);
void cargar_datos_videos(const char*, char*, int*, double*, int&);
void cargar_datos_dispositivos(const char*, int*, char*, int*, int&);
void cargar_datos_usuarios(ifstream&, int*, int&);
void ordenar_usuarios_registrados(int*, int);
void leer_procesar_usuarios(const char* , int* , int ,
                            char* , int* , double* , int ,
                            int * , char* , int* , int ,
                            int *, double* ,
                            int& , double &);
void imprimir_linea(ofstream &, char);
void buscar_imprimir_nombre(int, ifstream&, ofstream&);
void imprimir_reporte(const char* ,int* , int ,ifstream& ,int* ,double* ,int ,double); 
#endif /* FUNCIONES_HPP */
