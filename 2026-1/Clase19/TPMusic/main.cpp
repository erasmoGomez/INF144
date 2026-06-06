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

    ordenar_canciones(arr_nombre_artistas,
                      arr_nombre_temas,
                      arr_duraciones,
                      arr_generos,
                      arr_danceabilities,
                      cant_datos);

    impresion_canciones(arr_nombre_artistas,
                        arr_nombre_temas,
                        arr_duraciones,
                        arr_generos,
                        arr_danceabilities,
                        cant_datos,
                        "ArchivosDeSalida/canciones_ordenado.txt");

    int frecuencias[MAX_GENEROS]{};
    char* generos_sin_repeticion[MAX_GENEROS]{};
    int n_generos = 0;
    calcular_frecuencias(arr_generos, cant_datos,
                         frecuencias, generos_sin_repeticion, n_generos);
    cout<< n_generos<<endl;
    imprimir_frecuencias(generos_sin_repeticion,
                         frecuencias,
                         n_generos,
                         "ArchivosDeSalida/generos_frecuencias.txt");

    return 0;
}
