#include "Bibliotecas/FuncionesEstructuras.hpp"

int main() {
    struct Categoria *categorias;
    int cantidad_categorias = 0;
    cargar_categorias("ArchivosDeDatos/Categorias.csv", categorias, cantidad_categorias);
    imprimir_reporte("ArchivosDeReportes/ReporteDePruebaDeCategorias.txt", categorias, cantidad_categorias);
    return 0;
}
