#include"Bibliotecas/FuncionesAux.hpp"

int main() {
    int creation_date_array[MAX_CHANNELS]{};
    char letter_channel_array[MAX_CHANNELS]{};
    int code_channel_array[MAX_CHANNELS]{};
    double channel_rating_array[MAX_CHANNELS]{};
    int n_channels = 0;

    int tag_code_array[MAX_TAGS]{}, tag_duration_array[MAX_TAGS]{};
    int n_tags = 0;
    double tarifa_x_duration_tags = 0.78;
    // ask_for_tarifa_x_duration_tag(tarifa_x_duration_tags);
    load_channels("ArchivosDeDatos/Canales.txt", creation_date_array, letter_channel_array, code_channel_array,
                  channel_rating_array, n_channels);
    load_tags("ArchivosDeDatos/Etiquetas.txt", tag_code_array, tag_duration_array, n_tags);
    verify_channels("ArchivosDeReporte/reporte_simple_canales.txt", creation_date_array, letter_channel_array,
                    code_channel_array,
                    channel_rating_array, n_channels);
    verify_tags("ArchivosDeReporte/reporte_simple_Etiquetas.txt", tag_code_array, tag_duration_array, n_tags);


    int numero_total_reproducciones_array[MAX_CHANNELS]{}, tiempo_total_plays_array[MAX_CHANNELS]{};
    double porc_rating_quality_array[MAX_CHANNELS]{}, ingresos_por_plays_of_tag_array[MAX_CHANNELS]{};

    int cant_total_plays_tags_array[MAX_TAGS]{}, total_time_played_array[MAX_TAGS]{};
    update_arrays_channels_and_tags("ArchivosDeDatos/ReproduccionesDeEtiquetas.txt",
                                    creation_date_array,
                                    letter_channel_array, code_channel_array,
                                    channel_rating_array, n_channels, tag_code_array, tag_duration_array, n_tags,
                                    numero_total_reproducciones_array,
                                    tiempo_total_plays_array, porc_rating_quality_array,
                                    ingresos_por_plays_of_tag_array, cant_total_plays_tags_array,
                                    total_time_played_array,
                                    tarifa_x_duration_tags);
    print_final_report("ArchivosDeReporte/ReporteDeCanales_Y_Etiquetas.txt", creation_date_array, letter_channel_array,
                       code_channel_array,
                       channel_rating_array, n_channels, tag_code_array, tag_duration_array, n_tags,
                       numero_total_reproducciones_array,
                       tiempo_total_plays_array, porc_rating_quality_array, ingresos_por_plays_of_tag_array,
                       cant_total_plays_tags_array, total_time_played_array,
                       tarifa_x_duration_tags);
    return 0;
}
