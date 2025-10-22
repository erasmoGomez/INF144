//
// Created by lmthelex on 20/10/2025.
//

#include "..\headers\auxiliary_functions.hpp"

bool read_register(ifstream &input, int &streams, int &duration, int &category,
                   char &language_c, int &language_n)
{
    char character;
    int hour, minute, second;

    input >> streams;
    if (input.eof())
        return false;
    input >> hour >> character >> minute >> character >> second;
    input >> category;
    input >> language_c >> language_n;

    duration = hour_to_integer(hour, minute, second);

    return true;
}

bool read_register(ifstream &input)
{
    char character;
    int integer;

    input >> integer;
    if (input.eof())
        return false;
    input >> character >> integer >> character >> integer;
    input >> character >> integer >> ws;
    input.ignore(100, ' ');

    return true;
}

bool read_register(ifstream &input, int &stream, int &date, int &start_time,
                   double &quality_rate, double &drop_off)
{
    char character;
    int day, month, year, hour, minute, second;

    input >> stream;
    input >> day >> character >> month >> character >> year;
    input >> hour >> character >> minute >> character >> second;
    input >> quality_rate;
    input >> drop_off;

    start_time = hour_to_integer(hour, minute, second);
    date = date_to_integer(day, month, year);

    return (input.get() == '\n') ? false : true;
}

int search_stream(int *streams, int index, int searched_stream)
{
    for (int i = 0; i < index; ++i)
    {
        if (streams[i] == searched_stream)
        {
            return i;
        }
    }

    return ERROR_NOT_FOUND;
}

void update_registers(int index, int date, int *reproductions_amount,
                      int *reproductions_durations, int *durations, double *quality_rates,
                      double *drop_offs, int *oldest_reproduction, int *newest_reproduction, double
                      quality_rate, double drop_off)
{
    reproductions_amount[index] += 1;
    reproductions_durations[index] += durations[index];
    quality_rates[index] += quality_rate;
    drop_offs[index] += drop_off;
    oldest_reproduction[index] =
    (oldest_reproduction[index] == 0 || date < oldest_reproduction[
         index])
        ? date
        : oldest_reproduction[index];
    if (newest_reproduction[index] == 0 || date > newest_reproduction[
            index])
    {
        newest_reproduction[index] = date;
    }
}

void calculate_mean(int index, double *quality_rates, double *drop_offs,
                    double *quality_rates1, int *reproductions_amount)
{
    for (int i = 0; i < index; ++i)
    {
        if (reproductions_amount[i] > 0)
        {
            quality_rates[i] /= reproductions_amount[i];
            quality_rates1[i] /= reproductions_amount[i];
        }
    }
}
