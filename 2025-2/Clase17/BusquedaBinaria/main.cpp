#include "src/Funciones.hpp"

int main() {
    // /////////////////////////////////////////////////////////////
    //                    ARREGLOS DEL DATASET                   //
    // ///////////////////////////////////////////////////////////
    int dnis[MAX_DATOS]{}, fechasIng[MAX_DATOS]{}, telefonos[MAX_DATOS]{}, numDat = 0;
    char sexos[MAX_DATOS]{};
    double sueldos[MAX_DATOS]{};
    char *nombres[MAX_DATOS]{};



    // /////////////////////////////////////////////////////////////
    //              INSERTAR ORDENADO UN DATASET                 //
    // ///////////////////////////////////////////////////////////

    leer_insertar_ordenado("Data/Empleados.txt", dnis, fechasIng,
                           sexos, telefonos, sueldos, nombres, numDat);
    imprimir_empleados("Reports/ReporteEmpleadosInsertarOrdenado.txt", dnis,
                       fechasIng, sexos, telefonos, sueldos, nombres, numDat);

    int pos;
    pos = busqueda_binaria(67255116, dnis, numDat);

    if (pos != -1) {
        cout << setw(3) << pos + 1 << ") " << setw(10) << dnis[pos] << " "
             << setw(2) << setw(5) << sexos[pos]
             << setw(2) << setw(30) << nombres[pos]
             << setw(10) << telefonos[pos] << setw(10) << sueldos[pos]
             << endl;
    } else cout << "No se encontró" << endl;
    return 0;
}
