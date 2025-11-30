//
// Created by erasmo on 11/29/25.
//

#ifndef ANALISISSENTIMIENTOHP_NODOPALABRA_HPP
#define ANALISISSENTIMIENTOHP_NODOPALABRA_HPP
#include "../Palabra.hpp"

struct NodoPalabra {
    struct Palabra dato;
    struct NodoPalabra *siguiente;
};
#endif //ANALISISSENTIMIENTOHP_NODOPALABRA_HPP
