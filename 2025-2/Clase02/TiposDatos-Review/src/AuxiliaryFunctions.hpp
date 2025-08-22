//
// Created by Erasmo on 25/08/25.
//

#ifndef TIPOSDATOS_REVIEW_AUXILIARYFUNCTIONS_HPP
#define TIPOSDATOS_REVIEW_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"

// Copia segura para char[], asegura terminación en '\0'
void safe_copy(char *dest, const char *src, int max_len);

// Convierte a mayúsculas in-place (solo letras ASCII a-z)
void CifrarMayusculas(char *s);

// Línea con un carácter repetido
void print_line(int n, char c);

// Centra un texto dentro de un ancho con relleno
void print_center(const char *text, int width, char fill = ' '); //Tarea: Entender parametro por defecto

void imprimirReporte(
        int fecha,
        const char *nombreRestaurante,
        const char *comentario,
        double rating,
        double latitud, double longitud,
        bool recomendado,
        char listaComentarios[][MAX_ITEMLEN],
        int cantComentarios,
        int width
);

void demoCifrarComentario(char *comentario, int width);

#endif //TIPOSDATOS_REVIEW_AUXILIARYFUNCTIONS_HPP
