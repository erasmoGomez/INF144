//
// Created by aml on 27/10/2025.
//

#include "FuncionesAux.hpp"


void load_streams(const char *archivosdedatos_streams_txt, int *stream_code_array, int *duration_stream_array,
                  int *language_code_stream_array, char *letter_category_stream_array, int *code_category_stream_array,
                  int &n_streams) {
    ifstream input_streams;
    open_ifs(archivosdedatos_streams_txt, input_streams);
    int stream_code;
    int duration;
    int language_code;
    char letter_category;
    int code_category;
    while (true) {
        input_streams >> stream_code;
        if (input_streams.eof())break;
        duration = read_date_or_hour(input_streams, 'H');
        input_streams >> language_code >> letter_category >> code_category;
        //hasta aqui todo esta leido
        insertion_in_order(stream_code, duration, language_code, letter_category, code_category,
                           stream_code_array, duration_stream_array, language_code_stream_array,
                           letter_category_stream_array, code_category_stream_array, n_streams);
    }
}

void open_ifs(const char *file_name, ifstream &arch) {
    arch.open(file_name, ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << file_name << endl;
        exit(1);
    }
}

int read_date_or_hour(ifstream &input, char type) {
    int dd, mm, aa;
    char c;
    int value_final = 0;
    input >> dd >> c >> mm >> c >> aa;
    if (type == 'F')value_final = aa * 10000 + mm * 100 + dd;
    if (type == 'H')value_final = dd * 3600 + mm * 60 + aa;
    return value_final;
}

void insertion_in_order(int stream_code, int duration, int language_code, char letter_category, int code_category,
                        int *stream_code_array, int *duration_stream_array, int *language_code_stream_array,
                        char *letter_category_stream_array, int *code_category_stream_array, int &n_streams) {
    int i = n_streams - 1;
    while (i >= 0 and stream_code_array[i] > stream_code) {
        stream_code_array[i + 1] = stream_code_array[i];
        duration_stream_array[i + 1] = duration_stream_array[i];
        language_code_stream_array[i + 1] = language_code_stream_array[i];
        letter_category_stream_array[i + 1] = letter_category_stream_array[i];
        code_category_stream_array[i + 1] = code_category_stream_array[i];
        i--;
    }
    stream_code_array[i + 1] = stream_code;
    duration_stream_array[i + 1] = duration;
    language_code_stream_array[i + 1] = language_code;
    letter_category_stream_array[i + 1] = letter_category;
    code_category_stream_array[i + 1] = code_category;
    n_streams++;
}


void verify_streams(const char *archivosdereporte_report_simple_streams_txt, int *stream_code_array,
                    int *duration_stream_array, int *language_code_stream_array, char *letter_category_stream_array,
                    int *code_category_stream_array, int n_streams) {
    ofstream output_report;
    open_ofs(archivosdereporte_report_simple_streams_txt, output_report);
    output_report << fixed << setprecision(2);
    // header
    int width = 100 / 4;
    print_header_simple(output_report, width);
    for (int i = 0; i < n_streams; ++i) {
        output_report << setw(width - 8) << stream_code_array[i];
        output_report << setw(width) << "";
        print_date_or_hour(output_report, duration_stream_array[i], 'H');
        output_report << setw(width) << language_code_stream_array[i];
        output_report << setw(width) << letter_category_stream_array[i] << code_category_stream_array[i] << endl;
    }
    output_report.close();
}

void open_ofs(const char *file_name, ofstream &arch) {
    arch.open(file_name, ios::out);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo " << file_name << endl;
        exit(1);
    }
}


void print_header_simple(ofstream &output, int width) {
    print_text(output, "Juego de datos de stream", 50, true);
    print_text(output, "Codigo de stream", width - 8, false);
    print_text(output, "Duracion de stream", width + 8, false);
    print_text(output, "Lenguaje de stream", width, false);
    print_text(output, "Categoria de stream", width + 4, true);
}

void print_text(ofstream &output, const char *text, int width, bool enter) {
    output << setw(width) << text;
    if (enter)output << endl;
}

void print_date_or_hour(ofstream &output, int value, char type) {
    int dd, mm, aa;
    char symbol;
    if (type == 'F') {
        aa = value / 10000;
        value %= 10000;
        mm = value / 100;
        value %= 100;
        dd = value;
        symbol = '/';
    }
    if (type == 'H') {
        dd = value / 3600;
        value %= 3600;
        mm = value / 60;
        value %= 60;
        aa = value;
        symbol = ':';
    }
    output << setfill('0') << setw(2) << dd << symbol << setw(2) << mm << symbol << setw(2) << aa << setfill(' ');
}


void update_with_channels(const char *archivosdedatos_canales_txt, int *stream_code_array, int *duration_stream_array,
                          int *language_code_stream_array, char *letter_category_stream_array,
                          int *code_category_stream_array, int n_streams,
                          int *rep_antigua_array, int *rep_reciente_array, double *avg_rating_quality,
                          double *avg_tasa_drop_off_array,
                          int *plays_count_array, int *total_time_plays_array) {
    ifstream input_channels;
    open_ifs(archivosdedatos_canales_txt, input_channels);
    while (true) {
        read_static_part(input_channels);
        if (input_channels.eof())break;
        read_dynamic_part(input_channels, stream_code_array, duration_stream_array, language_code_stream_array,
                          letter_category_stream_array, code_category_stream_array, n_streams,
                          rep_antigua_array, rep_reciente_array, avg_rating_quality, avg_tasa_drop_off_array,
                          plays_count_array, total_time_plays_array);
    }
    calculate_mean(avg_rating_quality, avg_tasa_drop_off_array, plays_count_array, n_streams);
}

void read_static_part(ifstream &input_channels) {
    int reader;
    char c;
    reader = read_date_or_hour(input_channels, 'F');
    if (input_channels.eof())return;
    input_channels >> c >> reader;
    input_channels >> ws;
    while (input_channels.get() != ' ');
}


void read_dynamic_part(ifstream &input_channels, int *stream_code_array, int *duration_stream_array,
                       int *language_code_stream_array, char *letter_category_stream_array,
                       int *code_category_stream_array, int n_streams,
                       int *rep_antigua_array, int *rep_reciente_array, double *avg_rating_quality,
                       double *avg_tasa_drop_off_array,
                       int *plays_count_array, int *total_time_plays_array) {
    int stream_code;
    int play_date;
    int start_hour;
    double rating;
    double tasa;
    char c;
    int pos_stream;
    while (true) {
        input_channels.get(c);
        if (c == '\r')break; // Esto es solo x q el profe usa MAC
        input_channels >> stream_code;
        play_date = read_date_or_hour(input_channels, 'F');
        start_hour = read_date_or_hour(input_channels, 'H');
        input_channels >> rating >> tasa;

        pos_stream = find_pos_binary(stream_code, stream_code_array, n_streams);

        if (pos_stream != NOT_FOUNDED) {
            calculate_dates(play_date, rep_antigua_array[pos_stream],
                            rep_reciente_array[pos_stream]);
            avg_rating_quality[pos_stream] += rating;
            avg_tasa_drop_off_array[pos_stream] += tasa;
            plays_count_array[pos_stream]++;
            total_time_plays_array[pos_stream] += duration_stream_array[pos_stream];
        }
    }
}

int find_pos_binary(int stream_code, int *stream_code_array, int n_streams) {
    int start = 0;
    int end = n_streams - 1;
    int middle;
    while (true) {
        if (start > end)return NOT_FOUNDED;
        middle = (start + end) / 2;
        if (stream_code_array[middle] == stream_code)return middle;
        if (stream_code > stream_code_array[middle])start = middle + 1;
        else end = middle - 1;
    }
}

void calculate_dates(int play_date, int &rep_antigua, int &rep_reciente) {
    if (rep_antigua == 0 or play_date < rep_antigua) {
        rep_antigua = play_date;
    }
    if (rep_reciente == 0 or play_date > rep_reciente) {
        rep_reciente = play_date;
    }
}


void print_final_report(const char *archivosdereporte_reproducciones_streams_txt, int *stream_code_array,
                        int *duration_stream_array, int *language_code_stream_array, char *letter_category_stream_array,
                        int *code_category_stream_array, int n_streams, int *rep_antigua_array, int *rep_reciente_array,
                        double *avg_rating_quality, double *avg_tasa_drop_off_array, int *plays_count_array,
                        int *total_time_plays_array, bool
                        delete_resume, bool modify_title) {
    ofstream output_final_report;
    open_ofs(archivosdereporte_reproducciones_streams_txt, output_final_report);
    output_final_report << fixed << setprecision(2);
    // header
    print_header_final_report(output_final_report, modify_title);
    for (int i = 0; i < n_streams; ++i) {
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 8) << stream_code_array[i];
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 1) << language_code_stream_array[i];
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 5) << letter_category_stream_array[i] <<
                code_category_stream_array[i];
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 6) << "";
        print_date_or_hour(output_final_report, duration_stream_array[i], 'H');
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 10) << "";
        print_date_or_hour(output_final_report, rep_antigua_array[i], 'F');
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 10) << "";
        if (total_time_plays_array[i] == 0)output_final_report << setw(2) << "";
        print_date_or_hour(output_final_report, rep_reciente_array[i], 'F');
        if (total_time_plays_array[i] == 0)output_final_report << setw(2) << "";
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 2) << avg_rating_quality[i];
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS + 2) << avg_tasa_drop_off_array[i] * 100 << "%";
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS + 5) << plays_count_array[i];
        output_final_report << setw(REPORT_WIDTH / REPORT_COLUMNS - 7) << "";
        print_date_or_hour(output_final_report, total_time_plays_array[i], 'H');
        output_final_report << endl;
    }
    if (not delete_resume) {
        print_line(output_final_report,REPORT_WIDTH, '-');
        // uso la forma de buscar indices maximos y minimos enseñadas en clase :)
        calculate_stats(output_final_report, stream_code_array, duration_stream_array, n_streams);
        print_line(output_final_report,REPORT_WIDTH, '-');
    }
}


void print_header_final_report(ofstream &output, bool modify_title) {
    print_text(output, "PLATAFORMA DE STREAMING TP", (REPORT_WIDTH + TITLE_LENGTH) / 2, true);
    if (not modify_title)
        print_text(output, "DETALLE COMPLETO DE REPRODUCCION DE STREAMS",
                   (REPORT_WIDTH + SUBTITLE_LENGTH) / 2, true);
    else
        print_text(output, "DETALLE COMPLETO DE REPRODUCCION DE STREAMS ORDENADO POR CATEGORIA Y TASA DROP-OFF.",
                   (REPORT_WIDTH + SUBTITLE_LENGTH) / 2 + 21, true);
    print_line(output,REPORT_WIDTH, '=');
    print_text(output, "STREAM",REPORT_WIDTH / REPORT_COLUMNS - 8, false);
    print_text(output, "IDIOMA",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "CATEGORIA",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "DURACION",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "REP.ANTIGUA",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "REP.RECIENTE",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "PROM.RAT.CAL",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "PROM.TASA.DROP-OFF",REPORT_WIDTH / REPORT_COLUMNS + 8, false);
    print_text(output, "#REPR.",REPORT_WIDTH / REPORT_COLUMNS, false);
    print_text(output, "TOT.REPR.",REPORT_WIDTH / REPORT_COLUMNS, true);
    print_line(output,REPORT_WIDTH, '-');
}

void print_line(ofstream &output, int width, char symbol) {
    for (int i = 0; i < width; ++i) output.put(symbol);
    output << endl;
}


void calculate_stats(ofstream &output_final_report, int *stream_code_array, int *duration_stream_array, int n_streams) {
    int pos_max_duration = find_max_pos(duration_stream_array, n_streams);
    int pos_min_duration = find_min_pos(duration_stream_array, n_streams);
    print_text(output_final_report, "RESUMEN:", 0, true);
    output_final_report << left;
    print_text(output_final_report, "STREAM CON MAYOR DURACION:", 30, false);
    output_final_report << right << setw(10) << stream_code_array[pos_max_duration] << " - ";
    print_date_or_hour(output_final_report, duration_stream_array[pos_max_duration], 'H');
    output_final_report << " hrs." << endl;
    output_final_report << left;
    print_text(output_final_report, "STREAM CON MENOR DURACION:", 30, false);
    output_final_report << right << setw(10) << stream_code_array[pos_min_duration] << " - ";
    print_date_or_hour(output_final_report, duration_stream_array[pos_min_duration], 'H');
    output_final_report << " hrs." << endl;
}

int find_max_pos(int *duration_stream_array, int n_streams) {
    int duration = 0;
    int pos_max = 0;
    for (int i = 0; i < n_streams; ++i) {
        if (duration_stream_array[i] > duration) {
            duration = duration_stream_array[i];
            pos_max = i;
        }
    }
    return pos_max;
}

int find_min_pos(int *duration_stream_array, int n_streams) {
    int duration = 99999999;
    int pos_min = 0;
    for (int i = 0; i < n_streams; ++i) {
        if (duration_stream_array[i] < duration) {
            duration = duration_stream_array[i];
            pos_min = i;
        }
    }
    return pos_min;
}


void selection_sort(int *stream_code_array, int *duration_stream_array, int *language_code_stream_array,
                    char *letter_category_stream_array, int *code_category_stream_array, int n_streams,
                    int *rep_antigua_array,
                    int *rep_reciente_array, double *avg_rating_quality, double *avg_tasa_drop_off_array,
                    int *plays_count_array,
                    int *total_time_plays_array) {
    for (int i = 0; i < n_streams - 1; ++i) {
        for (int k = i + 1; k < n_streams; ++k) {
            // la condicion primero verifico que toda la categoria este ordenada ,el criterio de categoria es multiple conformado por dos criterios
            // luego sigo con la tasa de drop si es que las categorias son iguales
            if (letter_category_stream_array[i] > letter_category_stream_array[k] or
                letter_category_stream_array[i] == letter_category_stream_array[k] and code_category_stream_array[i] >
                code_category_stream_array[k]
                or code_category_stream_array[i] == code_category_stream_array[k] and avg_tasa_drop_off_array[k] >
                avg_tasa_drop_off_array[i]) {
                swap_int(stream_code_array[i], stream_code_array[k]);
                swap_int(language_code_stream_array[i], language_code_stream_array[k]);
                swap_char(letter_category_stream_array[i], letter_category_stream_array[k]);
                swap_int(code_category_stream_array[i], code_category_stream_array[k]);
                swap_int(duration_stream_array[i], duration_stream_array[k]);
                swap_int(rep_antigua_array[i], rep_antigua_array[k]);
                swap_int(rep_reciente_array[i], rep_reciente_array[k]);
                swap_double(avg_rating_quality[i], avg_rating_quality[k]);
                swap_double(avg_tasa_drop_off_array[i], avg_tasa_drop_off_array[k]);
                swap_int(plays_count_array[i], plays_count_array[k]);
                swap_int(total_time_plays_array[i], total_time_plays_array[k]);
            }
        }
    }
}

void swap_int(int &value_i, int &value_k) {
    int temp = value_i;
    value_i = value_k;
    value_k = temp;
}

void swap_double(double &value_i, double &value_k) {
    double temp = value_i;
    value_i = value_k;
    value_k = temp;
}

void swap_char(char &value_i, char &value_k) {
    char temp = value_i;
    value_i = value_k;
    value_k = temp;
}

void calculate_mean(double *avg_rating_quality, double *avg_tasa_drop_off_array, int *plays_count_array,
                    int n_streams) {
    for (int i = 0; i < n_streams; ++i) {
        if (plays_count_array[i] > 0) {
            avg_rating_quality[i] /= plays_count_array[i];
            avg_tasa_drop_off_array[i] /= plays_count_array[i];
        }
    }
}
