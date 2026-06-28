//
// Created by Erasmo on 20/11/25.
//

#ifndef PREGUNTA1_2025_2_FUNCIONES_HPP
#define PREGUNTA1_2025_2_FUNCIONES_HPP

#include "Estructuras/Streamer.hpp"
#include "Estructuras/Comentario.hpp"
#include "Estructuras/Transmision.hpp"
#include "Lista/ListaPalabra.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo);

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo);

int leer_entero(ifstream &input);

double leer_double(ifstream &input);

char *leer_cadena(ifstream &input, int n, char delim);

char *asignar_cadena(const char *buffer);

void cargar_streamers(const char *file_name, struct Streamer *&streamers, int &cantidad_streamers);

void generar_reporte_prueba_streamers(const char *file_name, struct Streamer *streamers, int cantidad_streamers);

void lee_streamer(ifstream &input, int codigo, struct Streamer &s);

void imprime_streamer(ofstream &output, struct Streamer &s);

void cargar_comentarios(const char *file_name, struct Comentario *&comentarios, int &cantidad_comentarios);

void
generar_reporte_prueba_comentarios(const char *file_name, struct Comentario *comentarios, int cantidad_comentarios);

void cargar_streamers(const char *file_name, struct Transmision *transmisiones, int cantidad_transmisiones,
                      int &cantidad_streamers);

void generar_reporte_prueba_streamers(const char *file_name, struct Transmision *transmisiones, int cantidad_streamers);

void
cargar_comentarios(const char *file_name_comentarios, struct Transmision *&transmisiones, int cantidad_transmisiones,
                   int cantidad_streamers, int &cantidad_comentarios);

void
generar_reporte_prueba_comentarios(const char *file_name, struct Transmision *transmisiones, int cantidad_streamers);

void cargar_transmisiones(const char *file_name, struct Transmision *&transmisiones, int &cantidad_transmisiones);

void generar_reporte_prueba_transmisiones(const char *file_name, struct Transmision *transmisiones,
                                          int cantidad_transmisiones);

// Pregunta 2

void cargar_stopwords(const char *file_name, struct ListaPalabra &stopwords);

void cargar_palabras(const char *file_name, struct ListaPalabra &palabras);

void imprimir_palabras(const char *file_name, struct ListaPalabra &palabras);

void eliminar_stopwords(struct ListaPalabra &palabras, struct ListaPalabra &stopwords);

void cargar_palabras_ordenado(const char* file_name, struct ListaPalabra & ranking);
#endif //PREGUNTA1_2025_2_FUNCIONES_HPP
