/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VideoJuego.hpp
 * Author: hecto
 *
 * Created on June 12, 2025, 5:31 PM
 */

#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP
#include "Empresa.hpp"

struct VideoJuego{
    int id;
    char* titulo;
    int fecha_lanzamiento;
    double precio;
    bool es_apto;
    char* dlcs[10];
    Empresa empresa_desarrolladora;
};

#endif /* VIDEOJUEGO_HPP */

