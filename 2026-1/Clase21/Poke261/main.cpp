#include "Bibliotecas/FuncionesAuxiliares.hpp"

int main() {
    Pokemon *pokemones; // Dinamica
    Pokemon pokemones_estaticos[MAX_POKEMONES]; // Estatica
    int cantidad_pokemones = 0;
    int cantidad_pokemones_estatico = 0;

    cargar_pokemones("ArchivosDeDatos/pokemon.csv", pokemones, cantidad_pokemones);
    generar_reporte_prueba("ArchivosDeReporte/prueba_pokemon.txt", pokemones, cantidad_pokemones);

    cargar_pokemones_estatico("ArchivosDeDatos/pokemon.csv", pokemones_estaticos, cantidad_pokemones_estatico);
    generar_reporte_prueba("ArchivosDeReporte/prueba_pokemon_estatico.txt", pokemones, cantidad_pokemones_estatico);

    return 0;
}