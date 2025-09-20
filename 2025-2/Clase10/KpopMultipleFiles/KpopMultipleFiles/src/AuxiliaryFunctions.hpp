//
// Created by Erasmo on 6/09/25.
//

#ifndef PROFESORES_AUXILIARYFUNCTIONS_HPP
#define PROFESORES_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"

int read_time();

void open_file_read(ifstream &, const char *);

void open_file_write(ofstream &, const char *);

void calculate_report(const char *file_name_artists,
                      const char *file_name_songs,
                      const char *file_name_plays,
                      const char *file_name_output);

void to_upper(char &c);
#endif //PROFESORES_AUXILIARYFUNCTIONS_HPP
