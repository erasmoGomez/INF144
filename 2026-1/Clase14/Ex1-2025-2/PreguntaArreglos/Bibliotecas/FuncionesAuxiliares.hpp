//
// Created by erasmog on 8/10/2025.
//

#ifndef PREGUNTAARREGLOS_FUNCIONES_H
#define PREGUNTAARREGLOS_FUNCIONES_H

#include "Utils.hpp"

void cargarStreams(const char*, int *, int *, int *, char *, int *, int &);

int convertirSegundos(int h, int m, int s);

void insertarOrdenado(int, int, int, char, int, int *, int *, int *, char *, int *,
                      int);

void mostrarStreams(int *, int *, int *, char *, int *, int);

void completarCanales(const char* nombre_archivo, int *arrStream, int *arrIdioma, char *arrCarCat, int *arrNumCat,
                      int *arrDuracion, int *arrRepAntigua, int *arrRepReciente, double *arrPromRat, double *arrPromTasa,
                      int *arrNumReprod, int *arrTotReprod,
                      int cantStreams);

int buscarStream(int, int *, int);

void calcularPromedios(double *, double *, int *, int);

void emitirReporte(const char *, const char *, bool, int *, int *, char *, int *, int *,
                   int *, double *, double *, int *, int *, int *, int);

void convertirImprimirFecha(ofstream &, int);

void convertirImprimirHora(ofstream &, int);

void ordenarStreams(int *, int *, char *, int *, int *, int *, double *, double *, int *,
                    int *, int *, int);

void cambiarInt(int &, int &);

void cambiarChar(char &, char &);

void cambiarDouble(double &, double &);

void imprimirLinea(ofstream &, char, int);
#endif //PREGUNTAARREGLOS_FUNCIONES_H
