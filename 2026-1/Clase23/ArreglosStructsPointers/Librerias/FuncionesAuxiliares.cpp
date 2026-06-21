//
// Created by erasmo on 6/18/26.
//

#include "FuncionesAuxiliares.hpp"

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "Alumno.hpp"
#include "FuncionesAuxiliares.hpp"

char* leer_cadena_exacta(ifstream& input, int n, char delim) {
    char* str;
    char buffer[n];
    input.getline(buffer, n, delim);
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void leerAlumnos(const char *nombArch, struct Alumno *&alumnos, int &numAl) {
    ifstream arch(nombArch, ios::in);

    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }

    alumnos = new Alumno[30]; // La buena práctica
    //Podemos continuar con la lectura

    numAl = 0;
    int codigo;
    //20182284,Vega Munoz Gonzalo
    while (true) {
        arch >> codigo;
        if (arch.eof()) break;
        arch.get();
        alumnos[numAl].codigo = codigo;
        alumnos[numAl].nombre = leer_cadena_exacta(arch, 30, '\n');
        alumnos[numAl].cursos = new Curso[70]{};
        numAl++;
    }
}

void reporteDeAlumnos(const char *nombArch, struct Alumno *alumnos, int numAl) {
    ofstream arch(nombArch, ios::out);

    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }

    arch.precision(2);
    arch << fixed;

    arch << "REPORTE DE NOTAS DE LOS ALUMNOS" << endl;

    for (int i = 0; i < numAl; i++) {
        arch << "CODIGO: " << alumnos[i].codigo << endl;
        arch << "NOMBRE: " << alumnos[i].nombre << endl;

        if (alumnos[i].numCur != 0) {
            imprimeCursos(arch, alumnos[i].cursos, alumnos[i].numCur);
            arch << "PROMEDIO: " << alumnos[i].promedio << endl;
        }

        imprimeLinea(arch, '=', 80);
    }
}

void imprimeCursos(ofstream &arch, struct Curso *cursos, int numCur) {
    arch << "CURSOS:" << endl;

    for (int i = 0; i < numCur; i++) {
        arch << " " << left << setw(10) << cursos[i].codigo
             << right << setw(4) << cursos[i].nota << endl;
    }
}

void imprimeLinea(ofstream &arch, char car, int n) {
    for (int i = 0; i < n; i++) arch.put(car);
    arch << endl;
}

void asignarCursos(const char *nombArch, struct Alumno *alumnos, int numAl) {
    ifstream arch(nombArch, ios::in);

    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << nombArch << endl;
        exit(1);
    }

    int codAlum, nota, pos;
    char *codigoCur;
    //20189596,MEC269,7
    while (true) {
        arch >> codAlum;
        if (arch.eof()) break;
        arch.get(); // arch.ignore()
        codigoCur = leer_cadena_exacta(arch, 7, ',');
        arch >> nota;
        pos = buscarAulmno(codAlum, alumnos, numAl);

        if (pos != -1) {
            // alumnos[pos].cursos[alumnos[pos].numCur] = curso;
            asignaCurso(alumnos[pos].cursos,
                     alumnos[pos].numCur,
                        codigoCur, nota);
        }
    }
}

char* asignar_cadena(char* cadena) {
    char* str;
    str = new char[strlen(cadena)+1];
    strcpy(str, cadena);
    return str;
}

void asignaCurso(Curso *cursos, int &numCur,
                 char *codigoCur, int nota) {
    cursos[numCur].codigo = asignar_cadena(codigoCur);
    cursos[numCur].nota = nota;
    numCur++;
}

int buscarAulmno(int codAlum, struct Alumno *alumnos, int numAl) {
    for (int i = 0; i < numAl; i++) {
        if (alumnos[i].codigo == codAlum) return i;
    }
    return -1;
}

void calcularPromedios(struct Alumno *alumnos, int numAl) {
    for (int i = 0; i < numAl; i++) {
        alumnos[i].promedio = promedio(alumnos[i].cursos,
                                       alumnos[i].numCur);
    }
}

double promedio(struct Curso *cursos, int numCur) {
    int suma = 0;

    if (numCur != 0) {
        for (int i = 0; i < numCur; i++) {
            suma += cursos[i].nota;
        }

        return (double)suma / numCur;
    } else {
        return 0.0;
    }
}

void swap_struct(Alumno& a, Alumno& b) {
    Alumno aux;
    aux = a;
    a = b;
    b = aux;
}