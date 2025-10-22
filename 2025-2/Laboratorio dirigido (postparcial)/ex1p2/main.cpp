#include  "src\headers\functions.hpp"

int main()
{
    int stream_index,
            streams[MAX_SIZE]{}, //código del categories_ceam
            languages[MAX_SIZE]{}, //código del idioma del categories_ceam
            categories_n[MAX_SIZE]{}, //parte (n)númerica de la categoría del categories_ceam
            oldest_reproduction[MAX_SIZE]{}, //reproducción más antigua
            newest_reproduction[MAX_SIZE]{}, //reproducción más reciente
            durations[MAX_SIZE]{}, //duración del categories_ceam
            reproductions_amount[MAX_SIZE]{}, //cantidad de reproducciones
            reproductions_durations[MAX_SIZE]{}; //duración total de las reproducciones
    char categories_c[MAX_SIZE]{}; //(c)caracter de la categoría del categories_ceam
    double drop_offs[MAX_SIZE]{}, //tasa de drop-off
            quality_rates[MAX_SIZE]; //rating de calidad

    stream_index = read_stream(streams, languages, categories_n, oldest_reproduction,
                               newest_reproduction, durations, reproductions_amount,
                               reproductions_durations, categories_c, drop_offs, quality_rates);
    print_test_report(stream_index, streams, languages, categories_n, oldest_reproduction,
                      newest_reproduction, durations, reproductions_amount, reproductions_durations,
                      categories_c, drop_offs, quality_rates);
    read_channels(stream_index, streams, languages, categories_n, oldest_reproduction,
                      newest_reproduction, durations, reproductions_amount, reproductions_durations,
                      categories_c, drop_offs, quality_rates);
    print_report(stream_index, streams, languages, categories_n, oldest_reproduction,
                      newest_reproduction, durations, reproductions_amount, reproductions_durations,
                      categories_c, drop_offs, quality_rates);
    sort_streams(stream_index, streams, languages, categories_n, oldest_reproduction,
                newest_reproduction, durations, reproductions_amount, reproductions_durations,
                categories_c,
                drop_offs, quality_rates);
    print_report(stream_index, streams, languages, categories_n, oldest_reproduction,
                      newest_reproduction, durations, reproductions_amount, reproductions_durations,
                      categories_c, drop_offs, quality_rates);


    return 0;
}
