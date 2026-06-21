//
// Created by erasmo on 6/18/26.
//

#ifndef ARREGLOSSTRUCTSPOINTERS_FUNCIONESAUXILIARES_HPP
#define ARREGLOSSTRUCTSPOINTERS_FUNCIONESAUXILIARES_HPP
#include <fstream>
using namespace std;

#include "Alumno.hpp"

void leerAlumnos(const char *nombArch, struct Alumno *&alumnos, int &numAl);
void reporteDeAlumnos(const char *nombArch, struct Alumno *alumnos, int numAl);
void imprimeLinea(ofstream &arch, char car, int n);
void asignarCursos(const char *nombArch, struct Alumno *alumnos, int numAl);
int buscarAulmno(int codAlum, struct Alumno *alumnos, int numAl);
void asignaCurso(struct Curso *cursos, int &numCur, char *codigoCur, int nota);
void imprimeCursos(ofstream &arch, struct Curso *cursos, int numCur);
void calcularPromedios(struct Alumno *alumnos, int numAl);
double promedio(struct Curso *cursos, int numCur);
#endif //ARREGLOSSTRUCTSPOINTERS_FUNCIONESAUXILIARES_HPP