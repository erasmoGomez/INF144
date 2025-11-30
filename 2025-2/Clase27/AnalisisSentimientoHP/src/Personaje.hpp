//
// Created by erasmo on 11/29/25.
//

#ifndef ANALISISSENTIMIENTOHP_PERSONAJE_HPP
#define ANALISISSENTIMIENTOHP_PERSONAJE_HPP
#include "BibliotecaLista/ListaPalabra.hpp"

struct Personaje {
    char *nombre;
    struct ListaPalabra oraciones;
    int polaridades[200];
    int cantidad_oraciones;
};
#endif //ANALISISSENTIMIENTOHP_PERSONAJE_HPP
