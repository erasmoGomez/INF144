//
// Created by Erasmo on 20/11/25.
//

#ifndef PREGUNTA1_2025_2_TRANSMISION_HPP
#define PREGUNTA1_2025_2_TRANSMISION_HPP

#include "Streamer.hpp"
#include "Comentario.hpp"

struct Transmision {
    int id_transmision; // ID
    struct Streamer streamer; // Streamer
    struct Comentario *comentarios; // Arreglo de Comentarios
    int fecha;
    int duracion;
    int cantidad_comentarios;
};
#endif //PREGUNTA1_2025_2_TRANSMISION_HPP
