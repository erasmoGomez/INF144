//
// Created by aml on 29/09/2025.
//

#include "FuncionesAux.hpp"


void load_channels(const char *archivodedatos_canales_txt, int *creation_date_array, char *letter_channel_array,
                   int *code_channel_array, double *channel_rating_array, int &n_channels) {
    ifstream input_channels;
    open_ifs(archivodedatos_canales_txt, input_channels);
    int creation_date;
    char letter_channel;
    int code_channel;
    double channel_rating;
    while (true) {
        creation_date = read_date_or_hour(input_channels, 'F');
        if (input_channels.eof())break;
        input_channels >> letter_channel >> code_channel;
        ignore_values(input_channels, ' ');
        input_channels >> channel_rating;
        ignore_values(input_channels, '\n');
        creation_date_array[n_channels] = creation_date;
        letter_channel_array[n_channels] = letter_channel;
        code_channel_array[n_channels] = code_channel;
        channel_rating_array[n_channels] = channel_rating;
        n_channels++;
    }
    input_channels.close();
}

void open_ifs(const char *file_name, ifstream &arch) {
    arch.open(file_name, ios::in);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << file_name << endl;
        exit(1);
    }
}

int read_date_or_hour(ifstream &input, char type) {
    int dd, mm, aa, final_value = 0;
    char c;
    if (type == 'F') {
        input >> dd >> c >> mm >> c >> aa;
        final_value = aa * 10000 + mm * 100 + dd;
    }
    if (type == 'H') {
        input >> mm >> c >> aa;
        final_value = mm * 60 + aa;
    }
    return final_value;
}

void ignore_values(ifstream &input, char delimiter) {
    input >> ws;
    while (input.get() != delimiter);
}

void load_tags(const char *archivosdedatos_etiquetas_txt, int *tag_code_array, int *tag_duration_array, int &n_tags) {
    ifstream input_etiquetas;
    open_ifs(archivosdedatos_etiquetas_txt, input_etiquetas);
    int tag_code;
    int tag_duration;
    while (true) {
        input_etiquetas >> tag_code;
        if (input_etiquetas.eof())break;
        ignore_values(input_etiquetas, ' ');
        tag_duration = read_date_or_hour(input_etiquetas, 'H');
        tag_code_array[n_tags] = tag_code;
        tag_duration_array[n_tags] = tag_duration;
        n_tags++;
    }
    input_etiquetas.close();
}

void ask_for_tarifa_x_duration_tag(double &tarifa_x_duration_tags) {
    cout << "Por faovr ingrese  la tarifa por duracion de las etiuqetas : " << endl;
    cin >> tarifa_x_duration_tags;
}


void verify_channels(const char *archivosdereportes_reporte_simple_canales_txt, int *creation_date_array,
                     char *letter_channel_array, int *code_channel_array, double *channel_rating_array,
                     int n_channels) {
    ofstream output_channels;
    open_ofs(archivosdereportes_reporte_simple_canales_txt, output_channels);
    output_channels << fixed;
    output_channels << setprecision(2);
    // header
    print_text(output_channels, "Canales", 0);
    output_channels << endl;
    print_text(output_channels, "Fecha create", 40 / 3 - 1);
    print_text(output_channels, "Codigo Canal", 40 / 3 + 4);
    print_text(output_channels, "Rating", 40 / 3);
    output_channels << endl;
    for (int i = 0; i < n_channels; ++i) {
        output_channels << setw(40 / 3);
        print_date_or_hour(output_channels, 'F', creation_date_array[i]);
        output_channels << setw(40 / 3) << letter_channel_array[i] << code_channel_array[i];
        output_channels << setw(40 / 3) << channel_rating_array[i] << endl;
    }
}

void open_ofs(const char *file_name, ofstream &arch) {
    arch.open(file_name, ios::out);
    if (!arch.is_open()) {
        cout << "Error al abrir el archivo " << file_name << endl;
        exit(1);
    }
}

void print_text(ofstream &output, const char *text, int width) {
    output << setw(width) << text;
}

void print_date_or_hour(ofstream &output, char type, int value) {
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
    if (type == 'H') {
        output << setfill('0') << setw(3) << dd;
    } else {
        output << setfill('0') << setw(2) << dd;
    }
    output << symbol << setw(2) << mm << symbol << setw(2) << aa << setfill(' ');
}

void verify_tags(const char *archivosdereporte_reporte_simple_etiquetas_txt, int *tag_code_array,
                 int *tag_duration_array, int n_tags) {
    ofstream output_etiquetas;
    open_ofs(archivosdereporte_reporte_simple_etiquetas_txt, output_etiquetas);
    output_etiquetas << fixed;
    output_etiquetas << setprecision(2);
    // header
    print_text(output_etiquetas, "Etiquetas", 0);
    output_etiquetas << endl;
    print_text(output_etiquetas, "Codigo de tag", 40 / 2);
    print_text(output_etiquetas, "duracion de etiqueta", 40 / 2 + 9);
    output_etiquetas << endl;
    for (int i = 0; i < n_tags; ++i) {
        output_etiquetas << setw(40 / 2) << tag_code_array[i];
        output_etiquetas << setw(40 / 2) << "";
        print_date_or_hour(output_etiquetas, 'H', tag_duration_array[i]);
        output_etiquetas << endl;
    }
}


void update_arrays_channels_and_tags(const char *nombre_archivo,
                                     int *creation_date_array, char *letter_channel_array, int *code_channel_array,
                                     double *channel_rating_array,
                                     int n_channels, int *tag_code_array, int *tag_duration_array, int n_tags,
                                     int *numero_total_reproducciones_array,
                                     int *tiempo_total_plays_array, double *porc_rating_quality_array,
                                     double *ingresos_por_plays_of_tag_array,
                                     int *cant_total_plays_tags_array, int *total_time_played_array,
                                     double tarifa_x_duration_tags) {
    ifstream input_plays_tags;
    open_ifs(nombre_archivo, input_plays_tags);
    int reader;
    char letter_channel, c;
    int code_channel;
    int tag_code;
    int plays_count_of_tag;
    int pos_channel, pos_tag;
    while (true) {
        input_plays_tags >> reader;
        if (input_plays_tags.eof())break;
        input_plays_tags >> c >> reader >> c >> reader;
        input_plays_tags >> letter_channel >> code_channel >> tag_code >> plays_count_of_tag;
        pos_channel = find_channel(letter_channel_array, code_channel_array, letter_channel, code_channel, n_channels);
        pos_tag = find_tag(tag_code_array, tag_code, n_tags);
        if (pos_channel != NOT_FOUNDED) {
            update_channels(pos_tag, plays_count_of_tag, tarifa_x_duration_tags, channel_rating_array[pos_channel],
                            tag_duration_array, numero_total_reproducciones_array, tiempo_total_plays_array,
                            porc_rating_quality_array,
                            ingresos_por_plays_of_tag_array, pos_channel);
        }
        if (pos_tag != NOT_FOUNDED) {
            update_tag(plays_count_of_tag, pos_tag, cant_total_plays_tags_array, total_time_played_array,
                       tag_duration_array);
        }
    }
}

int find_channel(char *letter_channel_array, int *code_channel_array, char letter_channel, int code_channel,
                 int n_channels) {
    for (int i = 0; i < n_channels; ++i) {
        if (letter_channel_array[i] == letter_channel and code_channel_array[i] == code_channel)return i;
    }
    return NOT_FOUNDED;
}

int find_tag(int *tag_code_array, int tag_code, int n_tags) {
    for (int i = 0; i < n_tags; ++i)if (tag_code_array[i] == tag_code) return i;
    return NOT_FOUNDED;
}

void update_channels(int pos_tag, int plays_count_of_tag, double tarifa_x_duration_tags, double rating,
                     int *tag_duration_array, int *numero_total_reproducciones_array, int *tiempo_total_plays_array,
                     double *porc_rating_quality_array, double *ingresos_por_plays_of_tag_array, int pos_channel) {
    double time_play = tag_duration_array[pos_tag] * plays_count_of_tag;
    double new_rating;
    numero_total_reproducciones_array[pos_channel] += plays_count_of_tag;
    if (pos_tag != NOT_FOUNDED)tiempo_total_plays_array[pos_channel] += time_play;
    if (rating > 4 and rating <= 5)porc_rating_quality_array[pos_channel] = 30.0;
    if (rating > 3 and rating <= 4)porc_rating_quality_array[pos_channel] = 20.0;
    if (rating > 2 and rating <= 3)porc_rating_quality_array[pos_channel] = 00.0;
    if (rating > 1 and rating <= 2)porc_rating_quality_array[pos_channel] = 25.0;
    if (porc_rating_quality_array[pos_channel] == 0) {
        new_rating = rating - rating * porc_rating_quality_array[pos_channel] / 100.0;
    } else {
        new_rating = rating + rating * porc_rating_quality_array[pos_channel] / 100.0;
    }
    ingresos_por_plays_of_tag_array[pos_channel] += (time_play / 60.0) * new_rating * tarifa_x_duration_tags;
}

void update_tag(int plays_count_of_tag, int pos_tag, int *cant_total_plays_tags_array, int *total_time_played_array,
                int *
                tag_duration_array) {
    cant_total_plays_tags_array[pos_tag] += plays_count_of_tag;
    total_time_played_array[pos_tag] += plays_count_of_tag * tag_duration_array[pos_tag];
}


void print_final_report(const char *file_name_report, int *creation_date_array, char *letter_channel_array,
                        int *code_channel_array, double *channel_rating_array, int n_channels, int *tag_code_array,
                        int *tag_duration_array,
                        int n_tags, int *numero_total_reproducciones_array, int *tiempo_total_plays_array,
                        double *porc_rating_quality_array, double *ingresos_por_plays_of_tag_array,
                        int *cant_total_plays_tags_array,
                        int *total_time_played_array, double tarifa_x_duration_tags) {
    ofstream output_report;
    open_ofs(file_name_report, output_report);
    output_report << fixed;
    output_report << setprecision(2);
    print_header_report(output_report, tarifa_x_duration_tags);
    print_channel_header(output_report,REPORT_WIDTH / REPORT_CHANNELS_COLUMN);
    for (int i = 0; i < n_channels; ++i) {
        output_report << setw(3) << i + 1 << ")";
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN - 13) << letter_channel_array[i] <<
                code_channel_array[i];
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN - 5) << "";
        print_date_or_hour(output_report, 'F', creation_date_array[i]);
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN) << channel_rating_array[i];
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN) << numero_total_reproducciones_array[i];
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN - 5) << "";
        print_date_or_hour(output_report, 'H', tiempo_total_plays_array[i]);
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN) << (int) porc_rating_quality_array[i] << " %";
        output_report << setw(REPORT_WIDTH / REPORT_CHANNELS_COLUMN + 8) << ingresos_por_plays_of_tag_array[i] << endl;
    }
    print_tag_report(output_report);
    for (int i = 0; i < n_tags; ++i) {
        output_report << setw(3) << i + 1 << ")";
        output_report << setw(REPORT_WIDTH / REPORT_TAGS_COLUMN - 17) << tag_code_array[i];
        output_report << setw(REPORT_WIDTH / REPORT_TAGS_COLUMN - 21) << "";
        print_date_or_hour(output_report, 'H', tag_duration_array[i]);
        output_report << setw(REPORT_WIDTH / REPORT_TAGS_COLUMN - 12) << cant_total_plays_tags_array[i];
        output_report << setw(REPORT_WIDTH / REPORT_TAGS_COLUMN - 6) << "";
        print_date_or_hour(output_report, 'H', total_time_played_array[i]);
        output_report << endl;
    }
}


void print_header_report(ofstream &output, double tarifa_x_duration_tags) {
    print_text(output, "PLATAFORMA TP_Twitch", (REPORT_WIDTH + TITLE_LENGTH) / 2);
    output << endl;
    print_text(output, "TARIFA POR DURACION DE ETIQUETAS: ", (REPORT_WIDTH + TITLE_LENGTH) / 2 - 8);
    output << setw(4) << tarifa_x_duration_tags << " POR CADA MINUTO Y FRACCION" << endl;
    print_line(output,REPORT_WIDTH, '=');
}

void print_line(ofstream &output, int width, char symbol) {
    for (int i = 0; i < width; ++i)output.put(symbol);
    output << endl;
}

void print_channel_header(ofstream &output_report, int width) {
    print_text(output_report, "CANALES ADSCRITOS A LA PLATAFORMA", 0);
    output_report << endl;
    print_line(output_report, REPORT_WIDTH, '-');
    output_report << setw(1) << "" << left;
    print_text(output_report, "No.", width - 20);
    output_report << right;
    print_text(output_report, "CODIGO", width - 8);
    print_text(output_report, "FECHA DE CREACION", width + 8);
    print_text(output_report, "RATING DE", width);
    print_text(output_report, "NUMERO TOTAL ", width + 4);
    print_text(output_report, "TIEMPO TOTAL DE", width);
    print_text(output_report, "PORCENTAJE POR", width + 4);
    print_text(output_report, "INGRESOS POR REPRODUCCION", width + 12);
    output_report << endl;
    print_text(output_report, "CALIDAD", 4 * width - 16);
    print_text(output_report, "DE REPRODUCCIONES", width + 6);
    print_text(output_report, "REPRODUCCIONES", width - 1);
    print_text(output_report, "RATING DE CALIDAD", width + 8);
    print_text(output_report, "DE ETIQUETAS", width);
    output_report << endl;
}

void print_tag_report(ofstream &output_report) {
    print_line(output_report, REPORT_WIDTH, '=');
    output_report << endl;
    print_text(output_report, "ETIQUETAS DE LA PLATAFORMA", 0);
    output_report << endl;
    print_line(output_report, REPORT_WIDTH, '-');
    output_report << setw(1) << "" << left;
    print_text(output_report, "No.", REPORT_WIDTH / REPORT_TAGS_COLUMN - 20);
    output_report << right;
    print_text(output_report, "ETIQUETA", REPORT_WIDTH / REPORT_TAGS_COLUMN - 26);
    print_text(output_report, "DURACION", REPORT_WIDTH / REPORT_TAGS_COLUMN - 14);
    print_text(output_report, "CANTIDAD TOTAL ", REPORT_WIDTH / REPORT_TAGS_COLUMN - 4);
    print_text(output_report, "TIEMPO TOTAL DE ", REPORT_WIDTH / REPORT_TAGS_COLUMN);
    output_report << endl;
    print_text(output_report, "DE REPRODUCCIONES", 3 * REPORT_WIDTH / REPORT_TAGS_COLUMN - 28);
    print_text(output_report, "REPRODUCIDO", REPORT_WIDTH / REPORT_TAGS_COLUMN - 4);
    output_report << endl;
}
