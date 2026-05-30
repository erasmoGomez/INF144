//
// Created by erasmo on 5/15/26.
//

// ==========================================================
// FuncionesAuxiliares.cpp
// ==========================================================

#include "FuncionesAuxiliares.hpp"

void leerDatosYJuntarRepetidos(
    const char *nombArch,
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int &cantidad_alumnos
) {
    ifstream arch(nombArch, ios::in);

    if (not arch.is_open()) {
        cout << "Error al abrir el archivo "
                << nombArch << endl;
        exit(1);
    }

    int codigo, nota, pos;

    cantidad_alumnos = 0;

    while (true) {
        arch >> codigo;

        if (arch.eof()) break;

        arch >> nota;

        pos = buscarCodigo(
            codigo,
            alumCodigo,
            cantidad_alumnos
        );

        if (pos != NO_ENCONTRADO) {
            //Actualizamos
            alumSuma[pos] += nota;
            alumCantNotas[pos]++;
        } else {
            //Insertamos
            alumCodigo[cantidad_alumnos] = codigo;
            alumSuma[cantidad_alumnos] = nota;
            alumCantNotas[cantidad_alumnos] = 1;
            cantidad_alumnos++;
        }
    }
}

int buscarCodigo(
    int codigo,
    int *alumCodigo,
    int numNotas
) {
    for (int i = 0; i < numNotas; i++)
        if (alumCodigo[i] == codigo)
            return i;

    return NO_ENCONTRADO;
}

void eliminarDesaprobados(
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int &numNotas
) {
    int i = 0;

    while (i < numNotas) {
        if ((double) alumSuma[i] / alumCantNotas[i] < 10.5)

            eliminar(
                i,
                alumCodigo,
                alumSuma,
                alumCantNotas,
                numNotas
            );

        else
            i++;
    }
}

void eliminar(
    int pos,
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int &cantidad_alumnos
) {
    for (int i = pos; i < cantidad_alumnos - 1; i++) {
        alumCodigo[i] = alumCodigo[i + 1];
        alumSuma[i] = alumSuma[i + 1];
        alumCantNotas[i] = alumCantNotas[i + 1];
    }

    cantidad_alumnos--;
}

void imrpimirPromedios(
    const char *nombArch,
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int numNotas
) {
    ofstream arch(nombArch, ios::out);

    if (not arch.is_open()) {
        cout << "Error al abrir el archivo "
                << nombArch << endl;
        exit(1);
    }

    arch.precision(2);
    arch << fixed;

    for (int i = 0; i < numNotas; i++)

        arch << setw(10) << alumCodigo[i]
                << setw(5) << alumSuma[i]
                << setw(3) << alumCantNotas[i]
                << setw(10)
                << (double) alumSuma[i] /
                alumCantNotas[i]
                << endl;
}

void ordenarDatos(
    int *alumCodigo,
    int *alumSuma,
    int *alumCantNotas,
    int numNotas
) {
    for (int i = 0; i < numNotas - 1; i++)

        for (int k = i + 1; k < numNotas; k++)

            if (alumCodigo[i] > alumCodigo[k]) {
                cambiar(alumCodigo[i],
                        alumCodigo[k]);

                cambiar(alumSuma[i],
                        alumSuma[k]);

                cambiar(alumCantNotas[i],
                        alumCantNotas[k]);
            }
}

void cambiar(
    int &datoI,
    int &datoK
) {
    int aux;

    aux = datoI;
    datoI = datoK;
    datoK = aux;
}

int buscarBinario(
    int codigo,
    int *alumCodigo,
    int numNotas
) {
    int limiteInferior = 0,
            limiteSuperior = numNotas - 1,
            puntoMedio;

    while (true) {
        if (limiteInferior > limiteSuperior)
            return NO_ENCONTRADO;

        puntoMedio =
                (limiteInferior + limiteSuperior) / 2;

        if (codigo == alumCodigo[puntoMedio])
            return puntoMedio;

        if (codigo < alumCodigo[puntoMedio])
            limiteSuperior = puntoMedio - 1;
        else
            limiteInferior = puntoMedio + 1;
    }
}
