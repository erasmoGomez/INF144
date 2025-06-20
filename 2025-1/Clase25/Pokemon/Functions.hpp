/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Functions.hpp
 * Author: hecto
 *
 * Created on June 19, 2025, 2:36 PM
 */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "Pokemon.hpp"
#include "Functions.hpp"
#include "Stats.hpp"

void cargar_pokemones(struct Pokemon *&pokemones, int &n_pokemones);
void cargar_movimientos(struct Move *&arrMovimientos, int &cantMovimientos);
void completar_info_pokemones(struct Pokemon *&pokemones, int n_pokemones, struct Move* movimientos, int n_movimientos);
char* leer_cadena(ifstream&, char, int=60);
void imprimir_reporte_pokemones(struct Pokemon *pokemones, int n_pokemones);
#endif /* FUNCTIONS_HPP */

