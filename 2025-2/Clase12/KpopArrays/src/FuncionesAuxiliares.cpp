//
// Created by Erasmo on 27/09/25.
//

#include "FuncionesAuxiliares.hpp"

void open_file_read(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "The file can not be open: " << file_name << endl;
        exit(1);
    }
}

void open_file_write(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "The file can not be open: " << file_name << endl;
        exit(1);
    }
}

int read_time(ifstream &input) {
    //16:30 -> : 16 minutos 30 segundos
    int mm, ss;
    input >> mm;
    input.ignore();
    input >> ss;
    return mm * 60 + ss;
}

void print_line(ofstream &out, int n, char c) {
    for (int i = 0; i < n; ++i) out.put(c);
    out << endl;
}

void print_date(ofstream &output, int date) { //20250904
    int anio = date / 10000;        // 2025
    int mes = (date / 100) % 100;  // 09
    int dia = date % 100;          // 04

    output << right;
    output << setw(2) << setfill('0') << dia;
    output << "/";
    output << setw(2) << setfill('0') << mes;
    output << "/";
    output << setw(4) << anio;

    output << setfill(' ');  // restaurar fill a espacio
}

void print_time(ofstream &output, int s, bool in_days) {
    if (in_days) {
        output << setfill('0') << setw(4) << s / 86400 << ':';
        s = s % 86400;
    }
    output << setfill('0') << setw(2) << s / 3600 << ':'
           << setw(2) << (s / 60) % 60 << ':'
           << setw(2) << s % 60;
    output << setfill(' ');
}

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void print_title(ofstream &output, const char *title) {
    output << setw((ANCHO_REPORTE + TITULO_SIZE) / 2) << title << endl;
}

void ignorar(ifstream &input, char until) {
    //   BTS
    char c;
    input >> ws;
    while (true) {
        c = input.get();
        if (c == until) break;
    }

//    input>>ws;
//    input.ignore(10, ' ');
}

void
cargar_artistas(const char *file_name, int *fechas_artistas,
                char *codigos_char_artistas, int *codigos_int_artistas,
                double *ratings_artistas, int &n_artistas) {
    //12/03/2019   A1023   BTS        4.85   55001->90311->92110

    ifstream input;
    open_file_read(input, file_name);
    int date;
    char c;
    while (true) {
        date = read_date(input); //Leo Fecha
        if (input.eof())break;
        // input>>ws; // Espacios en Blanco
        input >> codigos_char_artistas[n_artistas]; // A
        input >> codigos_int_artistas[n_artistas]; // 1023
        ignorar(input, ' ');
        input >> ratings_artistas[n_artistas];
        ignorar(input, '\n');
        fechas_artistas[n_artistas] = date;
        n_artistas++;
    }
}

void
probar_artistas(const char *file_name, int *fechas_artistas,
                char *codigos_char_artistas, int *codigos_int_artistas,
                double *ratings_artistas, int n_artistas) {
    //Que es lo que tiene que tener su funcion de prueba?
    ofstream output;
    open_file_write(output, file_name);
    // Header
    output << setw((ANCHO_REPORTE + 27) / 2) << "PRUEBA DE CARGA DE ARTISTAS" << endl;
    print_line(output, ANCHO_REPORTE, '=');
    output << setw(ANCHO_REPORTE / 3) << "FECHA";
    output << setw(ANCHO_REPORTE / 3) << "CODIGO";
    output << setw(ANCHO_REPORTE / 3) << "RATING" << endl;
    // Contenido de los arreglos
    output << fixed;
    for (int i = 0; i < n_artistas; i++) {
        output << setw(ANCHO_REPORTE / 3 - 10) << "";
        print_date(output, fechas_artistas[i]);
        output << setw(ANCHO_REPORTE / 3 - 6) << "";
        output << codigos_char_artistas[i] << codigos_int_artistas[i];
        output << setw(ANCHO_REPORTE / 3) << setprecision(2) << ratings_artistas[i] << endl;
    }
    output.close();
}

void cargar_canciones(const char *file_name, int *codigos_canciones, int *duraciones_canciones, int &n_canciones) {
    ifstream input;
    open_file_read(input, file_name);
    //55001   Dynamite          3:45
    int codigo;
    while (true) {
        input >> codigo;
        if (input.eof())break;
        ignorar(input, ' ');
        duraciones_canciones[n_canciones] = read_time(input); // Guardo el tiempo en segundos
        codigos_canciones[n_canciones] = codigo;
        n_canciones++;
    }
}

void probar_canciones(const char *file_name, int *codigos_canciones, int *duraciones_canciones, int n_canciones) {
    //Que es lo que tiene que tener su funcion de prueba?
    ofstream output;
    open_file_write(output, file_name);
    // Header
    output << setw((ANCHO_REPORTE + 27) / 2) << "PRUEBA DE CARGA DE CANCIONES" << endl;
    print_line(output, ANCHO_REPORTE, '=');
    output << setw(ANCHO_REPORTE / 4) << "CODIGO";
    output << setw(ANCHO_REPORTE / 4) << "DURACION" << endl;
    // Contenido de los arreglos
    output << fixed;
    for (int i = 0; i < n_canciones; i++) {
        output << setw(ANCHO_REPORTE / 4) << codigos_canciones[i];
        output << setw(ANCHO_REPORTE / 4 - 8) << "";
        print_time(output, duraciones_canciones[i], false);
        output << endl;
    }
    output.close();
}

int buscar_canciones(int *codigos_canciones, int codigo_cancion_read, int n_canciones) {
    for (int i = 0; i < n_canciones; i++)
        if (codigos_canciones[i] == codigo_cancion_read) return i;
    return -1;
}

int buscar_artistas(int *codigos_int_artistas, int codigo_int_read, int n_artistas) {
    for (int i = 0; i < n_artistas; i++)
        if (codigos_int_artistas[i] == codigo_int_read) return i;
    return -1;
}

void procesar_reproducciones(const char *file_name, int *codigos_int_artistas,
                             int *codigos_canciones, int *duraciones_canciones,
                             int *replays_total_time,
                             double *revenue_total,
                             int *total_replays,
                             int n_artistas, int n_canciones, double precio_mil) {
    //02/01/2024   A1023   55001   1450000
    //total_replays depende de n_canciones
    //replays_total_time y revenue_total depende de n_artistas
    int date, codigo_int_read, codigo_cancion_read, cantidad_reproducciones;
    char codigo_char_read;
    int pos_artista, pos_cancion;
    ifstream input;
    open_file_read(input, file_name);
    while (true) {
        date = read_date(input);
        if (input.eof())break;
        input >> codigo_char_read;
        input >> codigo_int_read;
        input >> codigo_cancion_read;
        input >> cantidad_reproducciones;
        pos_artista = buscar_artistas(codigos_int_artistas, codigo_int_read, n_artistas);
        pos_cancion = buscar_canciones(codigos_canciones, codigo_cancion_read, n_canciones);
        if (pos_artista != -1) {
            replays_total_time[pos_artista] += cantidad_reproducciones; //Este arreglo estaba vacio y ahora acumula el total play time
            revenue_total[pos_artista] += cantidad_reproducciones * precio_mil;
        } else {
            cout << "No se pudo encontrar el codigo del artista" << endl;
        }
        if (pos_cancion != -1) {
            total_replays[pos_cancion] += cantidad_reproducciones * duraciones_canciones[pos_cancion];
        } else {
            cout << "No se pudo encontrar el codigo de la cancion" << endl;
        }

    }
}

void print_headers_artistas(ofstream &output) {
    output << setw(ANCHO_REPORTE / 5) << left << "DATE";
    output << setw(ANCHO_REPORTE / 5) << "CODE";
    output << setw(ANCHO_REPORTE / 5) << "RATING";
    output << setw(ANCHO_REPORTE / 5) << right << "REP TOTAL TIME";
    output << setw(ANCHO_REPORTE / 5) << "TOTAL REVENUE" << endl;
    print_line(output, ANCHO_REPORTE, '-');
}

void print_headers_canciones(ofstream &output) {
    output << setw(ANCHO_REPORTE / 3) << "CODE";
    output << setw(ANCHO_REPORTE / 3) << "DURATION";
    output << setw(ANCHO_REPORTE / 3) << "TOTAL TIME REPLAYS" << endl;
    print_line(output, ANCHO_REPORTE, '-');
}

void
generar_reporte(const char *file_name, int *fechas_artistas, char *codigos_char_artistas, int *codigos_int_artistas,
                double *ratings_artistas, int *codigos_canciones, int *duraciones_canciones, int *replays_total_time,
                double *revenue_total, int *total_replays, int n_artistas, int n_canciones) {

    ofstream output;
    open_file_write(output, file_name);
    print_line(output, ANCHO_REPORTE, '=');
    output << "ARTISTAS" << endl;
    print_headers_artistas(output);
    output << fixed;
    output << setprecision(2);
    for (int i = 0; i < n_artistas; i++) {
        print_date(output, fechas_artistas[i]);
        output << setw(ANCHO_REPORTE / 5 - 10) << "";
        output << codigos_char_artistas[i] << codigos_int_artistas[i];
        output << setw(ANCHO_REPORTE / 5) << ratings_artistas[i];
        output << setw(ANCHO_REPORTE / 5 + 12) << right << replays_total_time[i];
        output << setw(ANCHO_REPORTE / 5) << revenue_total[i] << endl;
    }
    print_line(output, ANCHO_REPORTE, '=');
    output << "CANCIONES" << endl;
    print_headers_canciones(output);
    for (int i = 0; i < n_canciones; i++) {
        output << setw(ANCHO_REPORTE / 3) << codigos_canciones[i];
        output << setw(ANCHO_REPORTE / 3 - 8) << "";
        print_time(output, duraciones_canciones[i], false);
        output << setw(ANCHO_REPORTE / 3 - 12) << "";
        print_time(output, total_replays[i], true);
        output<<endl;
    }
    print_line(output, ANCHO_REPORTE, '=');
}
