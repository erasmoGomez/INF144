/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 13, 2025, 4:49 PM
 */

#include "FuncionesAuxiliares.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    struct Empleado* empleados;
    int cantidad_empleados = 0;
    //Reservar Memoria
    empleados = new struct Empleado[20]{};
    
    leer_empleados("personal_actualizado.csv", empleados, cantidad_empleados);
    imprimir_empleados("Reporte_Empleados.txt", empleados, cantidad_empleados);
    ordernar_empleados(empleados, cantidad_empleados);
    imprimir_empleados("Reporte_Ordenado.txt", empleados, cantidad_empleados);
    
    ordenar_arr_bonos(empleados,cantidad_empleados );
    imprimir_empleados("Reporte_Ordenado_Ordenado.txt", empleados, cantidad_empleados);
    return 0;
}

