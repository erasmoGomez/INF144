//
// Created by lmthelex on 20/10/2025.
//

#ifndef EX1P2_AUXILIARY_FUNCTIONS_HPP
#define EX1P2_AUXILIARY_FUNCTIONS_HPP

#include  "general_functions.hpp"

bool read_register(ifstream &input, int &streams, int &duration, int &category, char &language_c,
                   int &language_n);

bool read_register(ifstream &input);

bool read_register(ifstream &input, int &stream, int &date, int &start_time,
                   double &quality_rate, double &drop_off);

int search_stream(int *streams, int index, int searched_stream);

void update_registers(int index, int date, int *reproductions_amount,
                      int *reproductions_durations, int *durations, double *quality_rates,
                      double *drop_offs, int *oldest_reproduction, int *newest_reproduction, double quality_rate, double
                      drop_off);

void calculate_mean(int index, double *quality_rates, double *drop_offs, double *quality_rates1,
                    int *reproductions_amount);


#endif //EX1P2_AUXILIARY_FUNCTIONS_HPP
