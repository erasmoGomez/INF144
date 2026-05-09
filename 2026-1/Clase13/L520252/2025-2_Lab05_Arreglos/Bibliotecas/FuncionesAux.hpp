//
// Created by aml on 27/10/2025.
//

#ifndef FUNCIONESAUX_HPP
#define FUNCIONESAUX_HPP
#include"utils.hpp"
void load_streams(const char * archivosdedatos_streams_txt, int * stream_code_array, int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array,
                 int & n_streams);
void open_ifs(const char * file_name, ifstream & arch);
int read_date_or_hour(ifstream & input, char type);
void insertion_in_order(int stream_code, int duration, int language_code, char letter_category, int code_category, int * stream_code_array,
                       int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array, int & n_streams);
void verify_streams(const char * archivosdereporte_report_simple_streams_txt, int * stream_code_array, int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array,
                   int n_streams);
void open_ofs(const char * file_name, ofstream & arch);
void print_header_simple(ofstream & output, int width);
void print_text(ofstream & output, const char * text, int width, bool enter);
void print_date_or_hour(ofstream & output, int value, char type);
void update_with_channels(const char * archivosdedatos_canales_txt, int * stream_code_array, int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array,
                         int n_streams, int * rep_antigua_array, int * rep_reciente_array, double * avg_rating_quality, double * avg_tasa_drop_off_array, int * plays_count_array,
                         int * total_time_plays_array);
void read_static_part(ifstream & input_channels);
void read_dynamic_part(ifstream & input_channels, int * stream_code_array, int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array,
                      int n_streams, int * rep_antigua_array, int * rep_reciente_array, double * avg_rating_quality, double * avg_tasa_drop_off_array, int * plays_count_array,
                      int * total_time_plays_array);
int find_pos_binary(int stream_code, int * stream_code_array, int n_streams);
void calculate_dates(int play_date, int & rep_antigua, int & rep_reciente);
void print_final_report(const char * archivosdereporte_reproducciones_streams_txt, int * stream_code_array, int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array,
                        int n_streams, int * rep_antigua_array, int * rep_reciente_array, double * avg_rating_quality, double * avg_tasa_drop_off_array, int * plays_count_array,
                        int * total_time_plays_array, bool delete_resume, bool modify_title);
void print_header_final_report(ofstream & output, bool modify_title);
void print_line(ofstream & output, int width, char symbol);
void calculate_stats(ofstream & output_final_report, int * stream_code_array, int * duration_stream_array, int n_streams);
int find_max_pos(int * duration_stream_array, int n_streams);
int find_min_pos(int * duration_stream_array, int n_streams);
void selection_sort(int * stream_code_array, int * duration_stream_array, int * language_code_stream_array, char * letter_category_stream_array, int * code_category_stream_array, int n_streams,
                   int * rep_antigua_array, int * rep_reciente_array, double * avg_rating_quality, double * avg_tasa_drop_off_array, int * plays_count_array, int * total_time_plays_array);
void swap_int(int & value_i, int & value_k);
void swap_double(double & value_i, double & value_k);
void swap_char(char & value_i, char & value_k);
void calculate_mean(double * avg_rating_quality, double * avg_tasa_drop_off_array, int * plays_count_array, int n_streams);

#endif //FUNCIONESAUX_HPP
