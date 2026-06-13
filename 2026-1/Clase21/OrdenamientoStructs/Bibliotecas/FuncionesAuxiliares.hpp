//
// Created by erasmo on 6/13/26.
//

#ifndef ORDENAMIENTOSTRUCTS_FUNCIONESAUXILIARES_HPP
#define ORDENAMIENTOSTRUCTS_FUNCIONESAUXILIARES_HPP
#include "../Estructuras/VideoJuego.hpp"

void cargar_videojuegos(const char *nombre_archivo,
                        VideoJuego *videojuegos,
                        int &cantidad_videojuegos);

void ordenar_videojuegos(VideoJuego *videojuegos,
                         int cantidad_videojuegos);

void mostrar_videojuegos(const char* nombre_archivo,
                         const VideoJuego *videojuegos,
                         int cantidad_videojuegos);

#endif //ORDENAMIENTOSTRUCTS_FUNCIONESAUXILIARES_HPP
