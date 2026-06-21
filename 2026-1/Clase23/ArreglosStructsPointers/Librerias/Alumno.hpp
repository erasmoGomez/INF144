//
// Created by erasmo on 6/18/26.
//

#ifndef ARREGLOSSTRUCTSPOINTERS_ALUMNO_HPP
#define ARREGLOSSTRUCTSPOINTERS_ALUMNO_HPP

#include "Curso.hpp"

struct Alumno {
    int codigo;
    char *nombre;
    Curso *cursos;
    int numCur;
    double promedio;
};
#endif //ARREGLOSSTRUCTSPOINTERS_ALUMNO_HPP