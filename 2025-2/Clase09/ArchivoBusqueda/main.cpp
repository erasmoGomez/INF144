#include "src/FuncionesAuxiliares.hpp"

int main() {
    leer_procesar_clientes_moviles("Data/clientes_moviles_2025.txt",
                                   "Data/planes_clientes_moviles_2025.txt",
                                   "Reports/reporte.txt");

    return 0;
}
