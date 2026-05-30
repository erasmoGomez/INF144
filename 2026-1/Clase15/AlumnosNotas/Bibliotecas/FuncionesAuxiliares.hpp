//
// Created by erasmo on 5/15/26.
//

#ifndef ALUMNOSNOTAS_FUNCIONESAUXILIARES_HPP
#define ALUMNOSNOTAS_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"

void leerDatosYJuntarRepetidos(
    const char *nombArch,
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int &cantidad_alumnos
);

void imrpimirPromedios(
    const char *nombArch,
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int numNotas
);

int buscarCodigo(
    int codigo,
    int *alumCodigo,
    int numNotas
);

void eliminarDesaprobados(
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int &numNotas
);

void eliminar(
    int pos,
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int &cantidad_alumnos
);

void ordenarDatos(
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int numNotas
);

void cambiar(
    int &datoI,
    int &datoK
);

int buscarBinario(
    int codigo,
    int *alumCodigo,
    int numNotas
);

#endif //ALUMNOSNOTAS_FUNCIONESAUXILIARES_HPP