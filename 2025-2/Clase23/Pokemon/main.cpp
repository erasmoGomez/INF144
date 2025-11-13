#include "src/Funciones.hpp"
#include "src/Pokemon.hpp"

int main() {
    struct Pokemon *pokemones; //Arreglo dinámico
    struct Movimiento *movimientos;
    int n_pokemones = 0, n_movimientos = 0;
    cargar_pokemones("Data/pokemon.csv", pokemones, n_pokemones);
    generar_reporte_prueba("Reports/prueba_pokemon.txt", pokemones, n_pokemones);
    cargar_movimientos("Data/move-data.csv", movimientos, n_movimientos);
    completar_info_pokemones(pokemones, n_pokemones, movimientos, n_movimientos);
    imprimir_reporte_pokemones(pokemones, n_pokemones);
    return 0;
}
