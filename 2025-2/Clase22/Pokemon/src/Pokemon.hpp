//
// Created by Erasmo on 8/11/25.
//

#ifndef POKEMON_POKEMON_HPP
#define POKEMON_POKEMON_HPP
#include "Movimiento.hpp"
#include "MoveSet.hpp"
#include "Stats.hpp"
struct Pokemon{
    int pokemon_index;
    char* nombre;
    char* tipo_1;
    char* tipo_2;
    struct Stats stadisticas;
    bool _es_legendario;
    struct Movimiento ataques[4];
    struct MoveSet moveset;
    int nivel;
};
#endif //POKEMON_POKEMON_HPP
