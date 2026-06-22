//
// Created by erasmo on 6/22/26.
//

#ifndef L8_CATEGORIA_HPP
#define L8_CATEGORIA_HPP
#include "Reproduccion.hpp"
struct Categoria {
    char* codigo;
    char* nombre;
    char* descripcion;
    struct Reproduccion* reproducciones;
    int n_reproducciones;
    double promedio_rating;
    int duracion_total;
};
#endif //L8_CATEGORIA_HPP