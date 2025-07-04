/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.hpp
 * Author: hecto
 *
 * Created on June 27, 2025, 6:16 PM
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP
void leer_lista_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo, const char* opt);
void imprimir_reporte_prueba_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo);
void leer_lista_clientes_bloques(struct ListaCliente &lista_clientes, const char* nombre_archivo);
void leer_lista_libros(struct ListaLibro &lista_libros, const char*);
void imprimir_reporte_prueba_libros(struct ListaLibro &lista_libros, const char* nombre_archivo);
#endif /* FUNCIONES_HPP */
