#include"Bibliotecas/FuncionesAux.hpp"

int main() {
    // define arrays to read streams.txt
    int stream_code_array[MAX_STREAMS]{};
    int duration_stream_array[MAX_STREAMS]{};
    int language_code_stream_array[MAX_STREAMS]{};
    char letter_category_stream_array[MAX_STREAMS]{};
    int code_category_stream_array[MAX_STREAMS]{};
    int n_streams = 0;

    load_streams("ArchivosDeDatos/Streams.txt", stream_code_array, duration_stream_array, language_code_stream_array,
                 letter_category_stream_array, code_category_stream_array, n_streams);
    verify_streams("ArchivosDeReporte/report_simple_streams.txt", stream_code_array, duration_stream_array,
                   language_code_stream_array,
                   letter_category_stream_array, code_category_stream_array, n_streams);

    // define arrays to update
    int rep_antigua_array[MAX_STREAMS]{};
    int rep_reciente_array[MAX_STREAMS]{};
    double avg_rating_quality[MAX_STREAMS]{};
    double avg_tasa_drop_off_array[MAX_STREAMS]{};
    int plays_count_array[MAX_STREAMS]{};
    int total_time_plays_array[MAX_STREAMS]{};

    update_with_channels("ArchivosDeDatos/Canales.txt", stream_code_array, duration_stream_array,
                         language_code_stream_array,
                         letter_category_stream_array, code_category_stream_array, n_streams,
                         rep_antigua_array, rep_reciente_array, avg_rating_quality, avg_tasa_drop_off_array,
                         plays_count_array, total_time_plays_array);

    print_final_report("ArchivosDeReporte/Reproducciones_Streams.txt", stream_code_array, duration_stream_array,
                       language_code_stream_array,
                       letter_category_stream_array, code_category_stream_array, n_streams,
                       rep_antigua_array, rep_reciente_array, avg_rating_quality, avg_tasa_drop_off_array,
                       plays_count_array, total_time_plays_array, false, false);

    selection_sort(stream_code_array, duration_stream_array, language_code_stream_array,
                   letter_category_stream_array, code_category_stream_array, n_streams,
                   rep_antigua_array, rep_reciente_array, avg_rating_quality, avg_tasa_drop_off_array,
                   plays_count_array, total_time_plays_array);

    print_final_report("ArchivosDeReporte/Reproducciones_Streams-Ordenado.txt", stream_code_array,
                       duration_stream_array, language_code_stream_array,
                       letter_category_stream_array, code_category_stream_array, n_streams,
                       rep_antigua_array, rep_reciente_array, avg_rating_quality, avg_tasa_drop_off_array,
                       plays_count_array, total_time_plays_array,
                       true, true);

    return 0;
}
