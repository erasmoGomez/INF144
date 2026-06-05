#include "Bibliotecas/FuncionesAuxiliares.hpp"

int main() {
    //definir los arreglos
    //Tyga,Taste,232959,hiphop-pop,0.884
    char *arr_nombre_artistas[MAX_DATOS]{};
    char *arr_nombre_temas[MAX_DATOS]{};
    int arr_duraciones[MAX_DATOS]{};
    char *arr_generos[MAX_DATOS]{};
    double arr_danceabilities[MAX_DATOS]{};

    int cant_datos = 0;
    lectura_arch_canciones_csv(arr_nombre_artistas,
                               arr_nombre_temas,
                               arr_duraciones,
                               arr_generos,
                               arr_danceabilities,
                               cant_datos,
                               "ArchivosDeEntrada/music_dataset_2.csv");
    impresion_canciones(arr_nombre_artistas,
                        arr_nombre_temas,
                        arr_duraciones,
                        arr_generos,
                        arr_danceabilities,
                        cant_datos,
                        "ArchivosDeSalida/canciones.txt");

    return 0;
}
