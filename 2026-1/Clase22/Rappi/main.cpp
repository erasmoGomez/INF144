#include "Bibliotecas/Auxiliares/Utils.hpp"
#include "Bibliotecas/Controlador/FuncionesEstructuras.hpp"

int main() {
    Conductor *conductores;
    int cantidad_conductores = 0;
    cargar_conductores("ArchivosDeEntrada/rutas.csv", conductores, cantidad_conductores);
    crear_reporte_simple("ArchivosDeSalida/reporte_simple.txt", conductores, cantidad_conductores);
    ordenar_conductores(conductores, cantidad_conductores);
    crear_reporte_simple("ArchivosDeSalida/reporte_simple_ordenado.txt", conductores, cantidad_conductores);
    Envio envios[MAX_ENVIOS];
    int cantidad_envios = 0;
    cargar_envios("ArchivosDeEntrada/envios.csv", envios, cantidad_envios);
    ordenar_envios(envios, cantidad_envios);

    return 0;
}
