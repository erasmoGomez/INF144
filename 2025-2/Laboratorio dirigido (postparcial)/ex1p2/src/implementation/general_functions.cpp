//
// Created by lmthelex on 20/10/2025.
//

#include "..\headers\general_functions.hpp"

ifstream open_file_read(const char *filename)
{
    ifstream input(filename, ios::in);

    if (!input.is_open())
    {
        cerr << "Error opening file " << filename << endl;
    }

    return input;
}

ofstream open_file_write(const char *filename)
{
    ofstream input(filename, ios::out);

    if (!input.is_open())
    {
        cerr << "Error opening file " << filename << endl;
    }

    return input;
}

int hour_to_integer(int hour, int minute, int second)
{
    return hour * 3600 + minute * 60 + second;
}

int date_to_integer(int day, int month, int year)
{
    return year * 10000 + month * 100 + day;
}

void swap_int(int &integer_a, int &integer_b)
{
    int auxiliary = integer_a;
    integer_a = integer_b;
    integer_b = auxiliary;
}

void swap_char(char &character_a, char &character_b)
{
    char auxiliary = character_a;
    character_a = character_b;
    character_b = auxiliary;
}

void swap_double(double &double_a, double &double_b)
{
    double auxiliary = double_a;
    double_a = double_b;
    double_b = auxiliary;
}