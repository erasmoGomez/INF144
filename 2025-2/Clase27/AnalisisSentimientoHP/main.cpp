#include "src/Funciones.hpp"
int main() {
    struct ListaPersonaje personajes{};
    struct ListaPalabra lexicon{};
    cargar_lexicon("Data/lexicon.csv", lexicon);
    cargar_personajes_oraciones("Data/HarryPotterPhilosopherStone.csv", personajes, lexicon);
    return 0;
}