/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libreria.hpp
 * Author: hecto
 *
 * Created on June 27, 2025, 5:58 PM
 */

#ifndef LIBRERIA_HPP
#define LIBRERIA_HPP
#include "Venta.hpp"
struct Libreria{
    int codigo;
    Venta *ventas;
    int cantidad_ventas;
    double total_ventas;
};

#endif /* LIBRERIA_HPP */

