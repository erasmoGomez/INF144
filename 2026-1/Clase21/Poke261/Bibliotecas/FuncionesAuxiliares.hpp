//
// Created by erasmo on 6/11/26.
//

#ifndef POKE261_FUNCIONESAUXILIARES_HPP
#define POKE261_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
#include "../Estructuras/Pokemon.hpp"
#include "../Estructuras/Movimiento.hpp"

void cargar_pokemones(const char *,
                      Pokemon *&pokemones,
                      int &cantidad_pokemones); //Arreglo Dinamico

void generar_reporte_prueba(const char *file_name,
                            struct Pokemon *pokemones,
                            int cantidad_pokemones);

void cargar_pokemones_estatico(const char *,
                               Pokemon *,
                               int &cantidad_pokemones_estatico); // Estatico

void cargar_movimientos(const char *,
                        Movimiento *&movimientos,
                        int &n_movimientos);

void completar_info_pokemones(Pokemon *&pokemones,
                              int cantidad_pokemones,
                              Movimiento *movimientos,
                              int n_movimientos);

void ordenar_movimientos_disponibles(MoveSet &moveset);

void llenar_movimientos_pokemon(int id_pokemon, const MoveSet &moveset, const ifstream &input);

void imprimir_reporte_pokemones(Pokemon* pokemones, int cantidad_pokemones);

#endif //POKE261_FUNCIONESAUXILIARES_HPP
