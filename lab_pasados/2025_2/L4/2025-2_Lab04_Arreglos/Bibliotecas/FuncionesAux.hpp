//
// Created by aml on 29/09/2025.
//

#ifndef FUNCIONESAUX_HPP
#define FUNCIONESAUX_HPP
#include"utils.hpp"

void load_channels(const char *archivodedatos_canales_txt, int *creation_date_array, char *letter_channel_array,
                   int *code_channel_array, double *channel_rating_array, int &n_channels);

void open_ifs(const char *file_name, ifstream &arch);

int read_date_or_hour(ifstream &input, char type);

void ignore_values(ifstream &input, char delimiter);

void load_tags(const char *archivosdedatos_etiquetas_txt, int *tag_code_array, int *tag_duration_array, int &n_tags);

void ask_for_tarifa_x_duration_tag(double &tarifa_x_duration_tags);

void verify_channels(const char *archivosdereportes_reporte_simple_canales_txt, int *creation_date_array,
                     char *letter_channel_array, int *code_channel_array, double *channel_rating_array, int n_channels);

void open_ofs(const char *file_name, ofstream &arch);

void print_text(ofstream &output, const char *text, int width);

void print_date_or_hour(ofstream &output, char type, int value);

void verify_tags(const char *archivosdereporte_reporte_simple_etiquetas_txt, int *tag_code_array,
                 int *tag_duration_array, int n_tags);

void update_arrays_channels_and_tags(const char *nombre_archivo,
                                     int *creation_date_array, char *letter_channel_array, int *code_channel_array,
                                     double *channel_rating_array,
                                     int n_channels, int *tag_code_array, int *tag_duration_array, int n_tags,
                                     int *numero_total_reproducciones_array,
                                     int *tiempo_total_plays_array, double *porc_rating_quality_array,
                                     double *ingresos_por_plays_of_tag_array, int *cant_total_plays_tags_array,
                                     int *total_time_played_array, double
                                     tarifa_x_duration_tags);

int find_channel(char *letter_channel_array, int *code_channel_array, char letter_channel, int code_channel,
                 int n_channels);

int find_tag(int *tag_code_array, int tag_code, int n_tags);

void update_channels(int pos_tag, int plays_count_of_tag, double tarifa_x_duration_tags, double rating,
                     int *tag_duration_array, int *numero_total_reproducciones_array,
                     int *tiempo_total_plays_array, double *porc_rating_quality_array,
                     double *ingresos_por_plays_of_tag_array, int pos_channel);

void update_tag(int plays_count_of_tag, int pos_tag, int *cant_total_plays_tags_array, int *total_time_played_array,
                int *
                tag_duration_array);

void print_final_report(const char *file_name_report, int *creation_date_array, char *letter_channel_array,
                        int *code_channel_array, double *channel_rating_array, int n_channels,
                        int *tag_code_array, int *tag_duration_array, int n_tags,
                        int *numero_total_reproducciones_array, int *tiempo_total_plays_array,
                        double *porc_rating_quality_array,
                        double *ingresos_por_plays_of_tag_array, int *cant_total_plays_tags_array,
                        int *total_time_played_array, double tarifa_x_duration_tags);

void print_header_report(ofstream &output, double tarifa_x_duration_tags);

void print_line(ofstream &output, int width, char symbol);

void print_channel_header(ofstream &output_report, int width);

void print_tag_report(ofstream &output_report);


#endif //FUNCIONESAUX_HPP
