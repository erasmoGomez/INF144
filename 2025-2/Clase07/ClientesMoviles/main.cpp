// Erasmo Gomez Montoya
// 20082060
// Descripcion: Vamos a calcular e imprimir un reporte de clientes para una entidad de moviles
// En el reporte, haremos un quiebre por cliente y sus tipos de planes.

#include "src/FuncionesAuxiliares.hpp"

int main() {
    leer_procesar_clientes_moviles("Data/clientes_moviles_2025.txt", "Reports/reporte.txt");
    return 0;
}
