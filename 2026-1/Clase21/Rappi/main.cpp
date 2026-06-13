#include "Bibliotecas/Auxiliares/Utils.hpp"
#include "Bibliotecas/Controlador/FuncionesEstructuras.hpp"

int main() {
    Conductor conductores[MAX_CONDUCTORES];
    int cantidad_conductores = 0;
    cargar_conductores("ArchivosDeEntrada/rutas.csv", conductores, cantidad_conductores);
    cout<<cantidad_conductores<<endl;
    crear_reporte_simple("ArchivosDeSalida/reporte_simple.txt",conductores, cantidad_conductores);
    return 0;
}