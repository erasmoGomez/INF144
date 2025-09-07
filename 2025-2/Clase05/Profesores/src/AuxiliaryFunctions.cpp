//
// Created by Erasmo on 6/09/25.
//

#include "AuxiliaryFunctions.hpp"

int read_time() {
    //16:30 -> : Caso 1
    //08:30:20 -> :  Caso 2
    //8 -> ' ' Caso 3
    int hh, mm, ss;
    //cin >> ws;

    // 1) leer horas obligatorias
    cin >> hh;

    // 2) por defecto minutos y segundos = 0
    mm = 0;
    ss = 0;

    //cin >> ws;
    if (cin.peek() == ':') {
        char c;
        cin >> c;             // consumir ':'
        cin >> mm;
        //cin >> ws;
        if (cin.peek() == ':') {
            cin >> c;         // consumir segundo ':'
            cin >> ss;
        }
    }
    return hh * 3600 + mm * 60 + ss;
}

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

void print_time(int s) {
    cout << setfill('0') << setw(2) << s / 3600 << ':'
         << setw(2) << (s / 60) % 60 << ':'
         << setw(2) << s % 60;
    cout << setfill(' ');
}

int read_date() {
    int dd, mm, yyyy, date;
    char c;
    cin >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void print_title() {
    cout << setw((ANCHO_REPORTE + TITULO_SIZE) / 2) << "LISTA DE PROFESORES" << endl;
    print_line(ANCHO_REPORTE, '=');
}

void print_headers() {
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << "CODIGO";
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << "HORA";
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << "EDAD";
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << "SUELDO";
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << "#CURSOS" << endl;
}

void print_static_values(int codigo, int time, int edad, double sueldo) {
    double new_sueldo = sueldo;
    cout << fixed;
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << codigo;
    cout << setw(ANCHO_REPORTE / N_COLUMNS - 4) << "";
    print_time(time);
    cout << setw(ANCHO_REPORTE / N_COLUMNS - 4) << edad;
    if (edad > 50) new_sueldo = new_sueldo * 1.025;
    cout << setw(ANCHO_REPORTE / N_COLUMNS) << setprecision(2) << new_sueldo; // 455.45
}

void calcular_imprimir_reporte() {
    //Titulo
    print_title();
    //Estatica y Variable
    print_headers();
    //20082060   16:30    55	10500.01	INF144 INF361 INF135
    int codigo, time, edad, n_cursos = 0; //Usa memoria una vez
    double sueldo;
    char c;
    while (true) {
        cin >> codigo; //Leemos codigo
        if (cin.eof())break;
        time = read_time();//Leemos hora
        cin >> edad >> sueldo;
        print_static_values(codigo, time, edad, sueldo);
        cin >> ws;
        //Contar la cantidad de cursos que dicta el profesor;
        //INF144 INF361 INF135\n -> 3
        //MAT007 FIS009\n -> 2
        while (true) {
            c = cin.get();
            if (c == '\n') break;
            if (c == ' ') n_cursos++;
        }
        cout << setw(ANCHO_REPORTE / N_COLUMNS) << n_cursos << endl;
    }
    print_line(ANCHO_REPORTE, '=');
    //Estadisticas
}