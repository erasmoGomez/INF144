//
// Created by erasmo on 6/22/26.
//

#ifndef L8_FUNCIONESESTRUCTURAS_HPP
#define L8_FUNCIONESESTRUCTURAS_HPP
#include "FuncionesAuxiliares.hpp"

void cargar_categorias(const char *nombre_archivo,
                       struct Categoria *&categorias,
                       int &cantidad_categorias);

void imprimir_reporte(const char *nombre_archivo,
                      struct Categoria *categorias,
                      int cantidad_categorias);

#endif //L8_FUNCIONESESTRUCTURAS_HPP
