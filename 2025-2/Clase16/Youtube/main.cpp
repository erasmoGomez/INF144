#include "src/Funciones.hpp"

int main() {
    //videos.txt
    int codigos[MAX_VIDEOS]{};
    int duraciones[MAX_VIDEOS]{};
    int codigos_idioma[MAX_VIDEOS]{};
    int n_videos = 0;
    cargar_videos("Data/videos.txt", codigos, duraciones, codigos_idioma, n_videos);
    // reporte_previo("Reports/reporte_previo.txt", codigos, duraciones, codigos_idioma, n_videos);
    // CanalesYoutube.txt
    int fechas_antiguas[MAX_VIDEOS]{};
    int fechas_recientes[MAX_VIDEOS]{};
    double promedios_rating[MAX_VIDEOS]{};
    double tasas[MAX_VIDEOS]{};
    //CASO 1: Puede repetir el archivo

//    llenar_nuevos_arreglos("Data/CanalesYoutube.txt",
//                           codigos,
//                           fechas_antiguas,
//                           fechas_recientes,
//                           promedios_rating,
//                           tasas,
//                           n_videos);
    //CASO 2: No se puede repetir el archivo

    llenar_nuevos_arreglos_caso_2("Data/CanalesYoutube.txt", codigos,duraciones,codigos_idioma,
                                  fechas_antiguas, fechas_recientes, promedios_rating, tasas,
                                  n_videos);
    //imprimir_datos()
    ordenacion(codigos, duraciones, codigos_idioma,
               fechas_antiguas, fechas_recientes,
               promedios_rating, tasas, n_videos);
    imprimir_datos("Reports/reporte_ordenado.txt",
                   codigos, duraciones, codigos_idioma,
                   fechas_antiguas, fechas_recientes,
                   promedios_rating, tasas, n_videos);
    return 0;
}
