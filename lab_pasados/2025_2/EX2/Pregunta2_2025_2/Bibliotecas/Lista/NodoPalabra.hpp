//
// Created by Erasmo on 24/11/25.
//

#ifndef PREGUNTA2_2025_2_NODOPALABRA_HPP
#define PREGUNTA2_2025_2_NODOPALABRA_HPP

#include "../Estructuras/Palabra.hpp"

struct NodoPalabra {
    struct Palabra palabra; // Esto es el DATO
    struct NodoPalabra *siguiente;
};
#endif //PREGUNTA2_2025_2_NODOPALABRA_HPP
