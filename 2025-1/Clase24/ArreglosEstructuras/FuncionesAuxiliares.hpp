/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.hpp
 * Author: hecto
 *
 * Created on June 13, 2025, 4:53 PM
 */

#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP
#include "Empleado.hpp"

void leer_empleados(const char* nombre_archivo, struct Empleado *empleados, int &cantidad_empleados);
void imprimir_empleados(const char* nombre_archivo, struct Empleado *empleados, int cantidad_empleados);
void ordenar_arr_bonos(struct Empleado* empleados, int cantidad_empleados);
void ordernar_empleados(struct Empleado*empleados, int cantidad_empleados);
#endif /* FUNCIONESAUXILIARES_HPP */
