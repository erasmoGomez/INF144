//
// Created by lmthelex on 20/10/2025.
//

#include "../headers/functions.hpp"

int read_stream(int *streams, int *languages, int *categories_n, int *oldest_reproduction,
                int *newest_reproduction, int *durations, int *reproductions_amount,
                int *reproductions_durations, char *categories_c, double *drop_offs,
                double *quality_rates)
{
    bool end_of_file;
    char category_c;
    int stream, duration, language, category_n;
    ifstream input;

    input = open_file_read("data/Streams.txt");

    for (int i = 0; true; i++)
    {
        end_of_file = read_register(input, stream, duration,
                                    language, category_c, category_n);
        if (end_of_file)
        {
            streams[i] = stream;
            languages[i] = language;
            durations[i] = duration;
            categories_c[i] = category_c;
            categories_n[i] = category_n;
        }
        else
        {
            return i;
        }
    }
}


void print_test_report(int index, int *streams, int *languages, int *categories_n,
                       int *oldest_reproduction, int *newest_reproduction, int *durations,
                       int *reproductions_amount, int *reproductions_durations, char *str,
                       double *drop_offs, double *quality_rates)
{
    ofstream output;

    output = open_file_write("reports/test_report.txt");

    for (int i = 0; i < index; ++i)
    {
        output << streams[i] << " " << languages[i] << " " << durations[i] << " " << endl;
    }
}

void read_channels(int index, int *streams, int *languages, int *categories_n,
                   int *oldest_reproduction, int *newest_reproduction, int *durations,
                   int *reproductions_amount, int *reproductions_durations, char *categories_c,
                   double *drop_offs, double *quality_rates)
{
    bool end_of_file, end_of_line;
    char category_c;
    int stream, date, start_time, found_index;
    double quality_rate, drop_off;
    ifstream input;

    input = open_file_read("data/Canales.txt");

    for (int i = 0; true; i++)
    {
        end_of_file = read_register(input);
        cout << i << endl;
        if (end_of_file)
        {
            do
            {
                end_of_line = read_register(input, stream, date, start_time, quality_rate,
                                            drop_off);

                found_index = search_stream(streams, index, stream);

                if (found_index != ERROR_NOT_FOUND)
                {
                    update_registers(found_index, date, reproductions_amount,
                                     reproductions_durations, durations, quality_rates, drop_offs,
                                     oldest_reproduction, newest_reproduction, quality_rate,
                                     drop_off);
                }
            }
            while (end_of_line);
        }
        else
        {
            break;
        }
    }

    calculate_mean(index, quality_rates, drop_offs, quality_rates, reproductions_amount);
}

void print_report(int index, int *streams, int *languages, int *categories_n,
                  int *oldest_reproduction, int *newest_reproduction, int *durations,
                  int *reproductions_amount,
                  int *reproductions_durations, char *categories_c, double *drop_offs,
                  double *quality_rates)
{
    ofstream output;

    output = open_file_write("reports/report.txt");

    for (int i = 0; i < index; ++i)
    {
        output << streams[i] << "\t";
        output << languages[i] << "\t";
        output << oldest_reproduction[i] << "\t";
        output << newest_reproduction[i] << "\t";
        output << quality_rates[i] << "\t";
        output << drop_offs[i] << "\t";
        output << durations[i] << "\t";
        output << reproductions_amount[i] << "\t";
        output << reproductions_durations[i] << "\t";
        output << endl;
    }
}

void sort_streams(int index, int *streams, int *languages, int *categories_n,
                  int *oldest_reproduction, int *newest_reproduction, int *durations,
                  int *reproductions_amount, int *reproductions_durations, char *categories_c,
                  double *drop_offs, double *quality_rates)
{
    bool swapped;
    for (int i = 0; i < index - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < index - 1 - i; ++j)
        {
            if (languages[j] < languages[j + 1] ||
                (languages[j] == languages[j + 1] && drop_offs[j] < drop_offs[j + 1]))
            {
                swap_int(streams[j], streams[j + 1]);
                swap_int(languages[j], languages[j + 1]);
                swap_int(categories_n[j], categories_n[j + 1]);
                swap_int(oldest_reproduction[j], oldest_reproduction[j + 1]);
                swap_int(newest_reproduction[j], newest_reproduction[j + 1]);
                swap_int(durations[j], durations[j + 1]);
                swap_int(reproductions_amount[j], reproductions_amount[j + 1]);
                swap_int(reproductions_durations[j], reproductions_durations[j + 1]);
                swap_char(categories_c[j], categories_c[j + 1]);
                swap_double(drop_offs[j], drop_offs[j + 1]);
                swap_double(quality_rates[j], quality_rates[j + 1]);

                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
