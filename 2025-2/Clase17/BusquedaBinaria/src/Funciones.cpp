//
// Created by Erasmo on 23/10/25.
//

#include "Funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << file_name << " No puede ser abiero" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "El archivo " << file_name << " No puede ser abiero" << endl;
        exit(1);
    }
}

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
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

void ignorar(ifstream &input, char c) {
    input >> ws;
    while (input.get() != c);
}

char *leer_cadena_exacta(ifstream &input) {
    char buffer[MAX_CARACTERES], *cadena;
    input >> buffer; //Para archivos .txt
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void imprimir_empleados(const char *nombArch, int *dnis, int *fechasIng, char *sexos,
                        int *telefonos, double *sueldos, char **nombres, int numDat) {
    ofstream output;
    apertura_archivo_escritura(output, nombArch);
    output.precision(2);
    output << fixed;
    for (int i = 0; i < numDat; i++) {
        print_date(output, fechasIng[i]);
        output << setw(3) << i + 1 << ") " << setw(10) << dnis[i] << " "
               << setw(40) << nombres[i]
               << setw(5) << sexos[i]
               << setw(10) << telefonos[i] << setw(10) << sueldos[i] << endl;
    }
}

void insertar_ordenado(int dni, int fechaIngreso, char sexo, int telefono, double sueldo, char *nombre,
                       int *dnis, int *fechasIngreso, char *sexos,
                       int *telefonos, double *sueldos, char **nombres, int &numDat) {
    // [12][][][][]
    // numDat = 1
    // 10
    // [10][12][][][]
    int i = numDat - 1; //Me ubico al final de mi arreglo
    //Para el primer dato el i es -1
    while (i >= 0 and dnis[i] > dni) { //Q se mantenga ordenado por dni
        dnis[i + 1] = dnis[i];
        fechasIngreso[i + 1] = fechasIngreso[i];
        sexos[i + 1] = sexos[i];
        telefonos[i + 1] = telefonos[i];
        sueldos[i + 1] = sueldos[i];
        nombres[i + 1] = nombres[i];
        i--;
    }
    dnis[i + 1] = dni;
    fechasIngreso[i + 1] = fechaIngreso;
    sexos[i + 1] = sexo;
    telefonos[i + 1] = telefono;
    sueldos[i + 1] = sueldo;
    nombres[i + 1] = nombre;
    numDat++;
}

void leer_insertar_ordenado(const char *nombArch, int *dnis, int *fechasIngreso, char *sexos, int *telefonos,
                            double *sueldos, char **nombres, int &numDat) {
    ifstream input;
    apertura_archivo_lectura(input, nombArch);
    // [][][][][][][][][][][][]
    // int arr[12]
    int dni, fechaIngreso, telefono;
    char sexo;
    double sueldo;
    char *nombre;
    //17000095 Hijar 5/07/2020 F 39827505 2001.21
    while (true) {
        input >> dni;
        if (input.eof()) break;
        //ignorar(input, ' ');
        nombre = leer_cadena_exacta(input);
        fechaIngreso = read_date(input);
        input >> sexo >> telefono >> sueldo;
        insertar_ordenado(dni, fechaIngreso, sexo, telefono, sueldo, nombre,
                          dnis, fechasIngreso, sexos, telefonos,
                          sueldos, nombres, numDat);
    }
}

int busqueda_binaria(int dato_buscar, const int *arr, int n) {
    int limite_inferior = 0, limite_superior = n - 1;
    int punto_medio;
    while (true) {
        if (limite_inferior > limite_superior) return -1; //Caso Base
        punto_medio = (limite_inferior + limite_superior) / 2; //Punto Medio
        if (dato_buscar == arr[punto_medio]) return punto_medio; //Comparacion
        if (dato_buscar> arr[punto_medio])
            limite_inferior = punto_medio + 1; //Derecha
        else
            limite_superior = punto_medio - 1; //Izquierda
    }
}