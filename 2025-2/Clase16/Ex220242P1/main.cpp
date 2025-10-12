#include "src/Funciones.hpp"

int main() {
    procesarRepartosDeClientes("Data/Clientes.txt",
                               "Data/PlatosOfrecidos.txt",
                               "Data/Repartidores.txt",
                               "Data/RepartosARealizar.txt",
                               "Reports/Reporte.txt");
    return 0;
}
