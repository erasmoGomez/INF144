//
// Created by lmthelex on 20/10/2025.
//

#ifndef EX1P2_FUNCTIONS_HPP
#define EX1P2_FUNCTIONS_HPP

#include "auxiliary_functions.hpp"

int read_stream(int *streams, int *languages, int *categories_n, int *oldest_reproduction,
                int *newest_reproduction, int *durations, int *reproductions_amount,
                int *reproductions_durations, char *categories_c, double *drop_offs,
                double *quality_rates);

void print_test_report(int index, int *streams, int *languages, int *categories_n,
                       int *oldest_reproduction, int *newest_reproduction, int *durations,
                       int *reproductions_amount, int *reproductions_durations, char *str,
                       double *drop_offs, double *quality_rates);

void read_channels(int stream_index, int *streams, int *languages, int *categories_n,
                   int *oldest_reproduction, int *newest_reproduction, int *durations,
                   int *reproductions_amount, int *reproductions_durations, char *categories_c,
                   double *drop_offs, double *quality_rates);

void print_report(int stream_index, int *streams, int *languages, int *categories_n,
                  int *oldest_reproduction,
                  int *newest_reproduction, int *durations, int *reproductions_amount,
                  int *reproductions_durations, char *categories_c,
                  double *drop_offs, double *quality_rates);

void sort_streams(int stream_index, int * streams, int * arr, int * categories_n, int * oldest_reproduction,
                int * newest_reproduction, int * durations, int * reproductions_amount, int * reproductions_durations, char * str,
                double * drop_offs, double * quality_rates);

#endif //EX1P2_FUNCTIONS_HPP
