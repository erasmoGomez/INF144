//
// Created by erasm on 9/04/2026.
//

#include "AuxiliaryFunctions.hpp"

void print_line(int n, char c) {
    for (int i = 0; i < n; ++i) cout << c;
    cout << endl;
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

void print_title(const char *title, const char *subtitle, int start_date, int end_date) {
    print_line(REPORT_WIDTH, '*');
    cout << setw((REPORT_WIDTH + TITLE_LENGTH) / 2) << title << endl;
    cout << setw((REPORT_WIDTH - SUB_TITLE_LENGTH) / 3) << ""; // reservar espacios de impresion
    cout << subtitle << ":";
    print_date(start_date);
    cout<< "y";
    print_date(end_date);
    cout<<endl;
    print_line(REPORT_WIDTH, '=');
}

void calculate_report(int start_date, int end_date) {
    print_title("PLATAFORMA SPOTIFY", "REPORTE PARA FECHAS ENTRE: ", start_date, end_date);
    //31/05/1994   A001   carlos.perez0   305331   02/02/2021   05:17:39   9   01/11/2023   22:15:50   10  20/03/2023   22:25:08   67
    //Bucle principal de lectura
    int creation_date = 0, n_users = 0;
    int max_time_plays = 0, date_max_time_plays = 0; // Estadisticas
    // while (true) {
    //     //Vamos a leer por linea - usuario
    //     creation_date = read_date();
    //     if (cin.eof()) break;
    //     if (not is_valid_date(creation_date, start_date, end_date)) {
    //         // Fecha NO es valida
    //         cin.ignore(150, '\n');
    //         continue;
    //     }
    //     print_header_info(n_users, creation_date); // Parte Statica
    //     read_print_data_report(creation_date, max_time_plays, date_max_time_plays); // Parte Dinamica
    //     n_users++;
    // }
    // print_statistics(n_users, max_time_plays, date_max_time_plays);
}
