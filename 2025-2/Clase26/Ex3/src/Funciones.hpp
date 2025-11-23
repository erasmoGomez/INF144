//
// Created by Erasmo on 22/11/25.
//

#ifndef EX3_FUNCIONES_HPP
#define EX3_FUNCIONES_HPP
#include "Utils.hpp"
#include "../Bibliotecas/ListaCliente.hpp"

void leer_lista_clientes_bloques(struct ListaCliente &lista_clientes, const char* nombre_archivo);
void leer_lista_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo, const char* opt);
void imprimir_reporte_prueba_clientes(struct ListaCliente &lista_clientes, const char* nombre_archivo);
void leer_lista_libros(struct ListaLibro &lista_libros, const char*);
void imprimir_reporte_prueba_libros(struct ListaLibro &lista_libros, const char* nombre_archivo);
#endif //EX3_FUNCIONES_HPP
