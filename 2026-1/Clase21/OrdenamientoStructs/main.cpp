#include "Bibliotecas/FuncionesAuxiliares.hpp"

int main() {
    VideoJuego videojuegos[MAX_VIDEOJUEGOS];
    int cantidad_videojuegos = 0;
    cargar_videojuegos("ArchivosDeDatos/videojuegos.csv",videojuegos, cantidad_videojuegos);
    //ordenar_videojuegos(videojuegos, cantidad_videojuegos);
    //mostrar_videojuegos(videojuegos, cantidad_videojuegos);
    return 0;
}