/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.hpp
 * Author: hecto
 *
 * Created on April 25, 2025, 2:49 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
#include "utils.hpp"
void apertura_archivo_lectura(ifstream &, const char*);
void apertura_archivo_escritura(ofstream &, const char*);
void leer_procesar_clientes_moviles(const char*, const char*, const char*, 
                                    const char*, const char*);
#endif /* FUNCIONES_HPP */
