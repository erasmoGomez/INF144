//
// Created by erasmo on 6/11/26.
//

#ifndef POKE261_FUNCIONESAUXILIARES_HPP
#define POKE261_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
#include "../Estructuras/Pokemon.hpp"

void cargar_pokemones(const char*,
                      Pokemon *&pokemones,
                      int &cantidad_pokemones);

void generar_reporte_prueba(const char *file_name,
                            struct Pokemon *pokemones,
                            int cantidad_pokemones);

void cargar_pokemones_estatico(const char*,
                                Pokemon*,
                                int &cantidad_pokemones_estatico);

#endif //POKE261_FUNCIONESAUXILIARES_HPP