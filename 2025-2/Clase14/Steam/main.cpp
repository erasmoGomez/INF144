#include "src/Utils.hpp"

int main() {
    //Juegos.txt
    //15/03/2021   G4812   TheElderRunes     4.75
    int fechas_juegos[MAX_JUEGOS]{};
    char codigos_juegos_char[MAX_JUEGOS]{};
    int codigos_juegos_int[MAX_JUEGOS]{};
    double ratings_juegos[MAX_JUEGOS]{};
    int n_juegos = 0;

    cargar_juegos("Data/Juegos.txt", fechas_juegos,
                  codigos_juegos_char, codigos_juegos_int,
                  ratings_juegos, n_juegos);
    //Logros.txt
    //501201     dragon_slayer     12:45
    int codigos_logros[MAX_LOGROS]{};
    int tiempos_logros[MAX_LOGROS]{};
    int n_logros = 0;

    cargar_logros("Data/Logros.txt", codigos_logros,
                  tiempos_logros, n_logros);

    //LogrosEnJuegos
    //G4812   501201
    char codigos_char_juegos_logros[MAX_LOGROS_JUEGOS]{};
    int codigos_int_juegos_logros[MAX_LOGROS_JUEGOS]{};
    int codigos_logros_juegos_logros[MAX_LOGROS_JUEGOS]{};
    int cantidad_juegos_logros[MAX_LOGROS]{};
    int n_logros_juegos = 0;

    cargar_logros_juegos("Data/LogrosEnJuegos.txt", codigos_char_juegos_logros,
                         codigos_int_juegos_logros, codigos_logros_juegos_logros,
                         cantidad_juegos_logros, codigos_logros,
                         n_logros_juegos, n_logros);

    //PartidasRegistradas.txt
    //05/10/2025   P0035   G4812   501201   14
    int cantidad_veces_completado_promedio_juego[MAX_JUEGOS]{};
    cargar_partidas_registradas(cantidad_veces_completado_promedio_juego, n_juegos,
                                codigos_juegos_char, codigos_juegos_int);

    ordenar_arreglos_logros(codigos_logros, tiempos_logros, cantidad_juegos_logros, n_logros);

    return 0;
}
