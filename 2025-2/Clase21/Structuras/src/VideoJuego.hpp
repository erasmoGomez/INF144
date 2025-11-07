//
// Created by Erasmo on 6/11/25.
//

#ifndef STRUCTURAS_VIDEOJUEGO_HPP
#define STRUCTURAS_VIDEOJUEGO_HPP
#include "Empresa.hpp"

struct VideoJuego{
    int id;
    char* titulo;//Cadena Dinamica
    //char titulo[20]; // estatico
    int fecha_lanzamiento;
    double precio;
    bool es_apto;
    char* dlcs[10];
    Empresa empresa_desarrolladora;
};
#endif //STRUCTURAS_VIDEOJUEGO_HPP
