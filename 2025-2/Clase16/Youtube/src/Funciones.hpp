//
// Created by Erasmo on 9/10/25.
//

#ifndef YOUTUBE_FUNCIONES_HPP
#define YOUTUBE_FUNCIONES_HPP

#include "Utils.hpp"

void cargar_videos(const char *file_name,
                   int *codigos,
                   int *duraciones,
                   int *codigos_idioma,
                   int &n_videos);

void llenar_nuevos_arreglos(const char *file_name,
                            int *codigos,
                            int *fechas_antiguas,
                            int *fechas_recientes,
                            double *promedios_rating,
                            double *tasas,
                            int n_videos);

void ordenacion(int *codigos, int *duraciones,
                int *codigos_idioma,
                int *fechas_antiguas, int *fechas_recientes,
                double *promedios_rating, double *tasas, int n_videos);

void imprimir_datos(const char *file_name,
                    int *codigos, int* duraciones, int* codigos_idioma,
                    int* fechas_antiguas, int* fechas_recientes,
                    double* promedios_rating, double* tasas, int n_videos);

void llenar_nuevos_arreglos_caso_2(const char* file_name,
                                   int* codigos, int* duraciones, int* codigos_idioma,
                                   int* fechas_antiguas, int* fechas_recientes,
                                   double* promedios_rating, double* tasas, int n_videos);

#endif //YOUTUBE_FUNCIONES_HPP
