#include "Bibliotecas/FuncionesAuxiliares.hpp"

int main(int argc, char **argv) {

    int alumCodigo[MAX_ALUMNOS]{};
    int alumSuma[MAX_ALUMNOS]{};
    int alumCantNotas[MAX_ALUMNOS]{};
    int cantidad_alumnos = 0, pos = 0;

    leerDatosYJuntarRepetidos(
        "ArchivosDeDatos/NotasDeAlumnos.txt",
        alumCodigo,
        alumSuma,
        alumCantNotas,
        cantidad_alumnos
    );

    imrpimirPromedios(
        "ArchivosDeReporte/ReporteDePromedios.txt",
        alumCodigo,
        alumSuma,
        alumCantNotas,
        cantidad_alumnos
    );

    eliminarDesaprobados(
        alumCodigo,
        alumSuma,
        alumCantNotas,
        cantidad_alumnos
    );

    imrpimirPromedios(
        "ArchivosDeReporte/ReporteDePromediosElimDes.txt",
        alumCodigo,
        alumSuma,
        alumCantNotas,
        cantidad_alumnos
    );

    ordenarDatos(
        alumCodigo,
        alumSuma,
        alumCantNotas,
        cantidad_alumnos
    );

    imrpimirPromedios(
        "ArchivosDeReporte/ReporteDePromediosOrd.txt",
        alumCodigo,
        alumSuma,
        alumCantNotas,
        cantidad_alumnos
    );

    pos = buscarBinario(20243136, alumCodigo, cantidad_alumnos);

    if (pos != -1)
        cout << setw(10) << alumCodigo[pos]
             << setw(5) << alumSuma[pos]
             << setw(3) << alumCantNotas[pos]
             << setw(10)
             << (double)alumSuma[pos] / alumCantNotas[pos]
             << endl;
    else
        cout << "NO SE ENCONTRO" << endl;

    return 0;
}