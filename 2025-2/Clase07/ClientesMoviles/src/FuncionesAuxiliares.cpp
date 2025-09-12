//
// Created by Erasmo on 11/09/25.
//

#include "FuncionesAuxiliares.hpp"

void print_line(int size, char c, ofstream &output) {
    for (int i = 0; i < size; i++)output.put(c);
    output << endl;
}

void to_uppercase(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

void leer_imprimir_nombre(ifstream &input, ofstream &output) {
    char c;

    int cont = 0, size = 0;
    input >> ws;
    while (true) {
        c = input.get();
        if (c == ' ')break;
        if (c == '-') {
            c = ' ';
            cont++;
        }
        if (cont == 2 and c != ' ') to_uppercase(c);
        output.put(c);
        size++;
    }
    int ancho = ANCHO_REPORTE / N_COLUMNS;
    for (int i = 0; i < ancho - size; i++)output.put(' ');
}

void print_date(int date, ofstream &output) { //20250904
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

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> yyyy >> c >> mm >> c >> dd;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void imrprime_header_datos(ofstream& output){
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"TELEFONO";
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"PLAN";
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"FECHA INICIO";
    output<<right<<setw(ANCHO_REPORTE/N_COLUMNS)<<"FECHA FIN";
    output<<right<<setw(ANCHO_REPORTE/N_COLUMNS)<<"MONTO"<<endl;
    print_line(ANCHO_REPORTE, '.', output);
}

void leer_planes(ifstream &input, ofstream &output) {
    char c;
    //932479584 PostpagoBasico 2025-08-07 2025-12-18 97.12
    int telefono, inicio_plan, fin_plan;
    double monto;
    output << fixed;
    imrprime_header_datos(output);
    while (true) {
        input >> telefono;
        output << left << setw(ANCHO_REPORTE / N_COLUMNS) << telefono;
        leer_imprimir_nombre(input, output);
        inicio_plan = read_date(input);
        fin_plan = read_date(input);
        input >> monto;
        //output << setw(ANCHO_REPORTE / N_COLUMNS) << "";
        print_date(inicio_plan, output);
        output << setw(ANCHO_REPORTE / N_COLUMNS) << "";
        print_date(fin_plan, output);
        output << setw(ANCHO_REPORTE / N_COLUMNS) << setprecision(2) << monto << endl;
        c = input.get();
        if (c == '\n')break;
    }
    print_line(ANCHO_REPORTE, '=', output);
}

void imprime_header(int dni, ifstream &input, ofstream &output) {
    output << left << setw(ANCHO_REPORTE / N_COLUMNS) << "DNI";
    output << left << setw(ANCHO_REPORTE / N_COLUMNS) << "NOMBRE" << endl;
    output << setw(ANCHO_REPORTE / N_COLUMNS) << left << dni;
    leer_imprimir_nombre(input, output);
    output << endl;
    print_line(ANCHO_REPORTE, '*', output);
}

void lee_imprimr_datos_moviles(ifstream &input, ofstream &output) {
    int dni;
    char c;
    //DNI10218013 Escalona-Zurita-Estela 9
    while (true) {
        input >> c;
        if (input.eof())break;
        input.ignore(2);
        input >> dni;
        imprime_header(dni, input, output);
        leer_planes(input, output);
        //input.ignore(300, '\n');
        output << endl;
    }
}

void imprime_titulo(const char *titulo, ofstream &output) {
    output << setw((ANCHO_REPORTE + strlen(titulo)) / 2) << titulo<<endl;
    print_line(ANCHO_REPORTE, '*', output);
}

void leer_procesar_clientes_moviles(const char *file_name_entrada, const char *file_name_salida) {
    ifstream input;
    apertura_archivo_lectura(input, file_name_entrada);
    ofstream output;
    apertura_archivo_escritura(output, file_name_salida);
    //Codear sin problemas
    // Impresion Titulo
    imprime_titulo("REPORTE DE PLANES DE MOVILES", output);
    // Lectura e Impresion de datos
    lee_imprimr_datos_moviles(input, output);
    input.close();
    output.close();
}

void apertura_archivo_lectura(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "El archivo : " << file_name << " No se pudo abrir";
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "El archivo : " << file_name << " No se pudo abrir";
        exit(1);
    }
}
