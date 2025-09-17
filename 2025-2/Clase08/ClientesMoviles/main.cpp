// Erasmo Gomez Montoya
// 20082060
// Descripcion: Vamos a calcular e imprimir un reporte de clientes para una entidad de moviles
// En el reporte, haremos un quiebre por cliente y sus tipos de planes.

#include "src/FuncionesAuxiliares.hpp"

int main() {
//    ifstream input;
//    apertura_archivo_lectura(input, "Data/clientes_moviles_2025.txt");
//    ofstream output;
//    apertura_archivo_escritura(output, "Reports/reporte.txt");

    leer_procesar_clientes_moviles("Data/clientes_moviles_2025.txt",
                                   "Data/planes_clientes_moviles_2025.txt",
                                   "Reports/reporte.txt");
//    leer_procesar_clientes_moviles(input, output,
//                                   estadistica_1, estadistica_2);
//    impresion_estadistica(output, estadistica_1, estadistica_2);

    return 0;
}
