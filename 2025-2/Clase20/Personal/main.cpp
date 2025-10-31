#include "src/Funciones.hpp"

int main() {
//    int dnis[MAX_DATOS], edades[MAX_DATOS], n_datos = 0;
//    char *nombres[MAX_DATOS], *distritos[MAX_DATOS];
//    leer_datos("Data/DatosPersonales.txt",
//               dnis, nombres, edades, distritos, n_datos);
//    ordenar_datos(dnis, nombres, edades, distritos, n_datos);
//    imprimir_datos("Reports/ReporteDePersonas.txt",
//                   dnis, nombres, edades, distritos, n_datos);
//
//    buscar_imprimir_dato("Lince", dnis, nombres, edades, distritos, n_datos);
//    buscar_imprimir_dato("Linca", dnis, nombres, edades, distritos, n_datos);

    char * nombres[80];
    int n_datos = 0;
    leer_datos_getline("Data/PersonasEspacios.txt", nombres, n_datos);
    imprimir_nombres("Reports/reporte_nombres.txt", nombres, n_datos);
    return 0;
}
