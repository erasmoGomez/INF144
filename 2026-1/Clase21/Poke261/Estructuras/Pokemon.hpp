//
// Created by erasmo on 6/11/26.
//



#ifndef POKE261_POKEMON_HPP
#define POKE261_POKEMON_HPP
#include "Estadisticas.hpp"
#include "Movimiento.hpp"
#include "MoveSet.hpp"

struct Pokemon {
    int numero;
    char* nombre;
    char* tipo1;
    char* tipo2;
    Estadisticas estadisticas;
    int generacion;
    bool es_legendario;
    Movimiento *movimientos_activados;
    MoveSet movimientos_disponibles;
    int nivel;

};
#endif //POKE261_POKEMON_HPP