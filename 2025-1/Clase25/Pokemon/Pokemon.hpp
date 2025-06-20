/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pokemon.hpp
 * Author: hecto
 *
 * Created on June 19, 2025, 2:27 PM
 */

#ifndef POKEMON_HPP
#include "Utils.hpp"
#include "Stats.hpp"
#include "Move.hpp"
#include "MoveSet.hpp"

struct Pokemon{
    int pokedex_index;
    char *name;
    char *type_Primary;
    char *type_Secondary;
    struct Stats stats;
    bool isLegendary;
    struct Move* attacks;
    struct MoveSet moveset;
    int cantMoveSet;
    int level;
};

#endif /* POKEMON_HPP */

