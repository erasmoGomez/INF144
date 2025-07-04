/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLibro.hpp
 * Author: hecto
 *
 * Created on July 3, 2025, 6:39 PM
 */

#ifndef NODOLIBRO_HPP
#define NODOLIBRO_HPP
#include "Libro.hpp"
struct NodoLibro{
    struct Libro dato;
    struct NodoLibro* siguiente;
};


#endif /* NODOLIBRO_HPP */

