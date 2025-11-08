#include "src/Funciones.hpp"
#include "src/Pokemon.hpp"
int main() {
    struct Pokemon * pokemones;
    // struct Pokemon pokemones_estatico[200];
    int n_pokemones = 0;
    cargar_pokemones("Data/pokemon.csv", pokemones, n_pokemones);
    generar_reporte_prueba("Reports/prueba_pokemon.txt", pokemones, n_pokemones);
    return 0;
}
