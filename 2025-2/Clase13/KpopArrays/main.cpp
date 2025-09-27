#include "src/FuncionesAuxiliares.hpp"

int main() {
    // Artistas.txt
    int fechas_artistas[MAX_ARTISTAS]{};
    char codigos_char_artistas[MAX_ARTISTAS]{};
    int codigos_int_artistas[MAX_ARTISTAS]{};
    double ratings_artistas[MAX_ARTISTAS]{};
    int n_artistas = 0; //Indice de sus arreglos 0 -> N-1

    // Canciones.txt
    int codigos_canciones[MAX_CANCIONES]{};
    int duraciones_canciones[MAX_CANCIONES]{};
    int n_canciones = 0;

    // Reproducciones.txt
    int replays_total_time[MAX_ARTISTAS]{};
    double revenue_total[MAX_ARTISTAS]{}, precio_mil;
    int total_replays[MAX_CANCIONES]{};
//    cout<<"Ingrese el precio por mil reproducciones : "<<endl;
//    cin>>precio_mil;
    precio_mil = 0.85;
    cargar_artistas("Data/Artistas.txt", fechas_artistas, codigos_char_artistas,
                    codigos_int_artistas, ratings_artistas, n_artistas);
    probar_artistas("Reports/reporte_prueba_artistas.txt", fechas_artistas, codigos_char_artistas,
                    codigos_int_artistas, ratings_artistas, n_artistas);

    cargar_canciones("Data/Canciones.txt", codigos_canciones, duraciones_canciones, n_canciones);
    probar_canciones("Reports/reporte_prueba_canciones.txt", codigos_canciones, duraciones_canciones, n_canciones);

    procesar_reproducciones("Data/Reproducciones.txt", codigos_int_artistas, codigos_canciones,
                            duraciones_canciones,
                            replays_total_time, revenue_total,
                            total_replays, n_artistas, n_canciones, precio_mil);

    generar_reporte("Reports/reporte.txt", fechas_artistas, codigos_char_artistas,
                    codigos_int_artistas, ratings_artistas, codigos_canciones, duraciones_canciones,
                    replays_total_time, revenue_total, total_replays, n_artistas, n_canciones);
    return 0;
}
