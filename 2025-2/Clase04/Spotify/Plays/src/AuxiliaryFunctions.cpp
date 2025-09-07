//
// Created by Erasmo on 4/09/25.
//

#include "AuxiliaryFunctions.hpp"

void print_line(int n, char c) {
    for (int i = 0; i < n; ++i) cout << c;
    cout << endl;
}

void print_width(int width, int columns, int extra) {
    for (int i = 0; i < (width / columns) - extra; i++)
        cout.put(' ');
}

void print_date(int date) { //20250904
    int anio = date / 10000;        // 2025
    int mes = (date / 100) % 100;  // 09
    int dia = date % 100;          // 04

    cout << right;
    cout << setw(2) << setfill('0') << dia;
    cout << "/";
    cout << setw(2) << setfill('0') << mes;
    cout << "/";
    cout << setw(4) << anio;

    cout << setfill(' ');  // restaurar fill a espacio
}

void print_time(int s) {
    cout << setw(REPORT_WIDTH / REPORT_COLUMNS - 2) << ""
         << setfill('0') << setw(2) << s / 3600 << ':'
         << setw(2) << (s / 60) % 60 << ':'
         << setw(2) << s % 60;
    cout << setfill(' ');
}

void print_report_range(int start_date, int end_date) {
    print_date(start_date);
    cout << " Y ";
    print_date(end_date);
    cout << endl;
}

void print_title(const char *title, const char *subtitle, int start_date, int end_date) {
    print_line(REPORT_WIDTH, '*');
    cout << setw((REPORT_WIDTH + TITLE_LENGTH) / 2) << title << endl; // reserva espacios e imprime al final
    cout << setw((REPORT_WIDTH - SUB_TITLE_LENGTH) / 3) << ""; // reserva espacios
    cout << subtitle << ": "; //Imprimimos despues
    print_report_range(start_date, end_date);
    print_line(REPORT_WIDTH, '=');
}

int read_date() {
    int dd, mm, yyyy, date;
    char c;
    cin >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

int read_time() {
    //05:17:39
    int hh, mm, ss, hour;
    char c;
    cin >> hh >> c >> mm >> c >> ss;
    hour = ss * 3600 + mm * 60 + ss;
    return hour;
}

int read_int() {
    int i;
    cin >> i;
    return i;
}

bool is_valid_date(int date, int start_date, int end_date) {
    return date >= start_date and date <= end_date;
}

void read_print_code() {
    char c;
    int code;
    cin >> ws;
    cin >> c >> code;
    cout << c << right << setw(4) << setfill('0') << code << setfill(' ');
    int with = REPORT_WIDTH / REPORT_COLUMNS;
    for (int i = 0; i < with - 5; i++) cout.put(' ');
    // El 5 es para ajustar la impresion en la misma columna que el siguiente header
}

void to_uppercase(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

void read_print_username() {
    int size = 0;
    char c;
    cin >> ws; //Leer todos los espacios en blanco
    while (true) {
        cin.get(c); //Lee un caracter
        if (c == ' ') break;
        // if (c == '.') c = ' ';
        if (c >= 'a' and c <= 'z') to_uppercase(c);
        cout.put(c); //Imprime un caracter
        size++;
    }
    int width = REPORT_WIDTH / REPORT_COLUMNS;
    for (int i = 0; i < width - size; i++) cout.put(' ');
}

void read_print_int() {
    int i;
    cin >> ws;
    cin >> i;
    cout << left << setw(REPORT_WIDTH / REPORT_COLUMNS) << i;
}

void print_int(int i) {
    cout << right << setw(REPORT_WIDTH / (REPORT_COLUMNS - 1) - 4) << i << endl;
}

void print_header_info(int n, int created_at_date) {
    cout << left << setw(REPORT_WIDTH / REPORT_COLUMNS) << "CODE";
    cout << "USERNAME " << right << setw(2) << setfill('0') << n + 1 << setfill(' ');
    print_width(REPORT_WIDTH, REPORT_COLUMNS, 11); //11 -> USERNAME 24, son 11 characteres aprox
    cout << left << setw(REPORT_WIDTH / REPORT_COLUMNS) << "#FOLLOWERS";
    cout << left << setw(REPORT_WIDTH / REPORT_COLUMNS) << "CREATED AT" << endl;
    read_print_code();
    read_print_username();
    read_print_int();
    print_date(created_at_date);
    cout << endl;
    print_line(REPORT_WIDTH, '-');
}

void print_header_report() {
    cout << "MOST RECENT PLAYS:" << endl;
    cout << right << setw(REPORT_WIDTH / (REPORT_COLUMNS - 1)) << "DATE";
    cout << right << setw(REPORT_WIDTH / (REPORT_COLUMNS - 1)) << "TIME";
    cout << right << setw(REPORT_WIDTH / (REPORT_COLUMNS - 1)) << "#PLAYS" << endl;
}

void print_user_stats(int hour_plays_user, int number_plays_user) {
    cout << "Stats per User:" << endl;
    cout << "Total Time played: ";
    print_time(hour_plays_user);
    cout << endl;
    cout << "Total Records Played: " << setw(REPORT_WIDTH / REPORT_COLUMNS) << number_plays_user << endl;
    print_line(REPORT_WIDTH, '-');
}

void read_print_data_report(int date, int & max_time_plays, int & date_max_time_plays) {
    int date_plays, hour_plays, plays;
    char c;
    print_header_report();
    int hour_plays_user = 0, number_plays_user = 0; //Estadisticas por Usuario
    while (true) {
        //02/02/2021   05:17:39   9
        date_plays = read_date();
        hour_plays = read_time();
        plays = read_int();
        cin.get(c);
        hour_plays_user += hour_plays; //Actualizo local stats
        number_plays_user += plays;  //Actualizo local stats
        print_width(REPORT_WIDTH, 3, 4);
        print_date(date_plays);
        print_time(hour_plays);
        //print_width(REPORT_WIDTH, 3, 0);
        print_int(plays);
        if (c == '\n')break;
    }
    if (max_time_plays < hour_plays_user) {
        max_time_plays = hour_plays_user; //Actualizo stats totales
        date_max_time_plays = date; //Actualizo stats totales
    }
    print_line(REPORT_WIDTH, '-');
    print_user_stats(hour_plays_user, number_plays_user);
}

void print_general_stats(int n_users, int max_time_plays, int date_max_time_plays) {
    cout << "Final Stats!" << endl;
    cout << right << setw(REPORT_WIDTH / REPORT_COLUMNS) << "Users:" << setw(REPORT_WIDTH / REPORT_COLUMNS + 1) << right
         << n_users + 1 << " users." << endl;
    cout << setw(REPORT_WIDTH / REPORT_COLUMNS) << "Play back Time Max:";
    print_time(max_time_plays);
    cout << "." << endl;
    cout << setw(REPORT_WIDTH / REPORT_COLUMNS) << "Date with Max playbacks:";
    print_width(REPORT_WIDTH, REPORT_COLUMNS, 2);
    print_date(date_max_time_plays);
    cout << endl;
    print_line(REPORT_WIDTH, '*');
}

void calculate_report(int start_date, int end_date) {
    print_title("PLATAFORMA SPOTIFY", "REPORTE PARA FECHAS ENTRE", start_date, end_date);
    //31/05/1994   A001   carlos.perez0   305331   02/02/2021   05:17:39   9   01/11/2023   22:15:50   10  20/03/2023   22:25:08   67
    int created_at_date, n_users = 0;
    int max_time_plays = 0, date_max_time_plays = 0; //Estadisticas Generales
    while (true) {
        created_at_date = read_date();
        if (cin.eof())break; //Siempre tener una condicion de parada
        if (not is_valid_date(created_at_date, start_date, end_date)) {
            cin.ignore(180, '\n'); //Saltarme esta linea
            continue; //Me lleva hasta la linea 205
        }
        print_header_info(n_users, created_at_date); // Parte Estatica
        read_print_data_report(created_at_date, max_time_plays, date_max_time_plays); // Parte Variable
        n_users++;
    }
    print_general_stats(n_users, max_time_plays, date_max_time_plays);
}
