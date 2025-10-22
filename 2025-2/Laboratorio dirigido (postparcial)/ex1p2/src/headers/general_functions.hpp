//
// Created by lmthelex on 20/10/2025.
//

#ifndef EX1P2_GENERAL_FUNCTIONS_HPP
#define EX1P2_GENERAL_FUNCTIONS_HPP

#include "utils.hpp"

ifstream open_file_read(const char * filename);
ofstream open_file_write(const char * filename);

int hour_to_integer(int hour, int minute, int second);
int date_to_integer(int day, int month, int year);

void swap_int(int &integer_a, int &integer_b);
void swap_char(char &character_a, char &character_b);
void swap_double(double &double_a, double &double_b);

#endif //EX1P2_GENERAL_FUNCTIONS_HPP