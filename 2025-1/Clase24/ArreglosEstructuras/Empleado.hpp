/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empleado.hpp
 * Author: hecto
 *
 * Created on June 13, 2025, 4:55 PM
 */
#include "Fecha.hpp"
#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

struct Empleado{
    int codigo;
    char* nombre;
    double sueldo;
    Fecha fecha_ingreso;
    double bonos[10]{};
    int n_bonos = 0;
};

#endif /* EMPLEADO_HPP */

