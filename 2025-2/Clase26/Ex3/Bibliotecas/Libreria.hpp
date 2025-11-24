//
// Created by Erasmo on 24/11/25.
//

#ifndef EX3_LIBRERIA_HPP
#define EX3_LIBRERIA_HPP
#include "Venta.hpp"
struct Libreria{
    int codigo;
    Venta *ventas;
    int cantidad_ventas;
    double total_ventas;
};
#endif //EX3_LIBRERIA_HPP
