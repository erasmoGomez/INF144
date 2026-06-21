#include "Librerias/Alumno.hpp"
#include "Librerias/FuncionesAuxiliares.hpp"

int main() {
    Alumno *alumnos; //Arreglo dinamico de Alumno
    int numAl;

    //Reserva de Memoria Dinamica Antes de llamar a la funcion - Mala Práctica
    //alumnos  = new Alumno[30]{};

    leerAlumnos("ArchivosDeDatos/Alumnos.csv", alumnos, numAl);

    reporteDeAlumnos("ArchivosDeReporte/ReporteDeAlumnos.txt", alumnos, numAl);

    asignarCursos("ArchivosDeDatos/CursosNotas.csv", alumnos, numAl);

    reporteDeAlumnos("ArchivosDeReporte/ReporteDeAlumnosConCursos.txt", alumnos, numAl);

    calcularPromedios(alumnos, numAl);

    reporteDeAlumnos("ArchivosDeReporte/ReporteDeAlumnosConCursosProm.txt", alumnos, numAl);
    return 0;
}