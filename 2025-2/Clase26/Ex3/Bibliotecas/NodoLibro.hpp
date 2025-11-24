//
// Created by Erasmo on 23/11/25.
//

#ifndef EX3_NODOLIBRO_HPP
#define EX3_NODOLIBRO_HPP
#include "Libro.hpp"
struct NodoLibro{
    struct Libro dato;
    struct NodoLibro* siguiente;
};

#endif //EX3_NODOLIBRO_HPP
