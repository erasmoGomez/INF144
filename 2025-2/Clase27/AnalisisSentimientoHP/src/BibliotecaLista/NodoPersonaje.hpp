//
// Created by erasmo on 11/29/25.
//

#ifndef ANALISISSENTIMIENTOHP_NODOPERSONAJE_HPP
#define ANALISISSENTIMIENTOHP_NODOPERSONAJE_HPP
#include "../Personaje.hpp"

struct NodoPersonaje {
    struct Personaje dato;
    struct NodoPersonaje *siguiente;
};
#endif //ANALISISSENTIMIENTOHP_NODOPERSONAJE_HPP
