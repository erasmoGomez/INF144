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
#endif /* FUNCIONES_HPP */
