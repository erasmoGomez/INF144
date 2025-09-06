//
// Created by Erasmo on 4/09/25.
//

#ifndef PLAYS_AUXILIARYFUNCTIONS_HPP
#define PLAYS_AUXILIARYFUNCTIONS_HPP

#include "Utils.hpp"

void print_line(int n, char c);

void print_width(int width, int columns, int extra);

void print_date(int date);

void print_time(int s);

void print_report_range(int start_date, int end_date);

void print_title(const char *title, const char *subtitle, int start_date, int end_date);

int read_date();

int read_time();

int read_int();

bool is_valid_date(int date, int start_date, int end_date);

void read_print_code();

void to_uppercase(char &c);

void read_print_username();

void read_print_int();

void print_int(int i);

void print_header_info(int n, int created_at_date);

void print_header_report();

void print_user_stats(int hour_plays_user, int number_plays_user);

void read_print_data_report(int date, int &max_time_plays, int &date_max_time_plays);

void print_general_stats(int n_users, int max_time_plays, int date_max_time_plays);

void calculate_report(int start_date, int end_date);


#endif //PLAYS_AUXILIARYFUNCTIONS_HPP
