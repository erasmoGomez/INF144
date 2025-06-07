/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 8, 2025, 12:15 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void fecha_dd_mm_aa(int f, int &dd, int &mm, int &aa) {
    //Fecha: 20240926
    aa = f / 10000; //2024
    f %= 10000; //0926
    mm = f / 100; //9
    dd = f % 100; //26
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void ignorar_cadena(ifstream& input) {
    input>>ws;
    while (input.get() != ' ');
}

int leer_fecha(ifstream& input) {
    int fecha, dd, mm, aa;
    char c;
    input >> dd >> c >> mm >> c >> aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

char leer_char(ifstream& input) {
    char c;
    input >> c;
    return c;
}


double leer_double(ifstream& input) {
    double d;
    input >> d;
    return d;
}

void leer_datos(const char *nombre_archivo, int *codigos, int *fechas, char*pg13s,
        double *precios, int &cantidad_videojuegos) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int codigo;

    while (true) {
        input>>codigo;
        if (input.eof())break;
        ignorar_cadena(input);
        codigos[cantidad_videojuegos] = codigo;
        fechas[cantidad_videojuegos] = leer_fecha(input);
        pg13s[cantidad_videojuegos] = leer_char(input);
        precios[cantidad_videojuegos] = leer_double(input);
        cantidad_videojuegos++;
    }
}

void imprimir_datos(const char *nombre_archivo, int *codigos, int *fechas, char*pg13s,
        double *precios, int cantidad_videojuegos) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    int dd, mm, aa;
    for (int i = 0; i < cantidad_videojuegos; i++) {
        fecha_dd_mm_aa(fechas[i], dd, mm, aa);
        output << setw(3) << i + 1 << ") " << setw(10) << codigos[i] << " "
                << setfill('0') << setw(2) << dd << '/' << setw(2) << mm << '/'
                << setw(4) << aa << setfill(' ')
                << setw(3) << pg13s[i] << setw(10) << precios[i] << endl;
    }
}

void insertar_dato(int pos, int codigo, int fecha, char pg13, double precio,
        int* codigos, int* fechas, char* pg13s, double* precios,
        int& cantidad_videojuegos) {
    pos--;
    for (int i = cantidad_videojuegos - 1; i >= pos; i--) {
        codigos[i + 1] = codigos[i];
        fechas[i + 1] = fechas[i];
        pg13s[i + 1] = pg13s[i];
        precios[i + 1] = precios[i];
    }
    codigos[pos] = codigo;
    fechas[pos] = fecha;
    pg13s[pos] = pg13;
    precios[pos] = precio;
    cantidad_videojuegos++;
}

void eliminar_dato(int pos, int *codigos, int *fechas, char*pg13s,
        double *precios, int &cantidad_videojuegos) {
    pos--;
    for (int i = pos; i < cantidad_videojuegos - 1; i++) {
        codigos[i] = codigos[i + 1];
        fechas[i] = fechas[i + 1];
        pg13s[i] = pg13s[i + 1];
        precios[i] = precios[i + 1];
    }
    cantidad_videojuegos--;
}

void intercambiarI(int &a, int &b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiarD(double &a, double &b) {
    double aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiarC(char &a, char &b) {
    char aux;
    aux = a;
    a = b;
    b = aux;
}

void ordenar_datos(int*codigos, int*fechas, char*pg13s, double*precios,
        int cantidad_videojuegos) {
    for (int i = 0; i < cantidad_videojuegos - 1; i++)
        for (int k = i + 1; k < cantidad_videojuegos; k++)
            // if(codigos[i]> codigos[k]){
            // if(fechas[i]< fechas[k]){
            if (pg13s[i] > pg13s[k] or (pg13s[i] == pg13s[k]
                    and codigos[i] > codigos[k])) {
                intercambiarI(codigos[i], codigos[k]);
                intercambiarI(fechas[i], fechas[k]);
                intercambiarC(pg13s[i], pg13s[k]);
                intercambiarD(precios[i], precios[k]);
            }
}

void insertar_ordenado(int codigo, int fecha, char pg13, double precio,
                       int* codigos, int* fechas, char* pg13s, double* precios,
                       int& cantidad_videojuegos) {
    
    int i = cantidad_videojuegos - 1; // Cuando cantidad_videojuegos = 0; i-> -1;
    //El bucle se ejecuta cuando el arreglo tiene datos
    while (i >= 0 and codigos[i] > codigo) {
        //cout<<"Hola soy un bucle de comparacion"<<endl;
        codigos[i + 1] = codigos[i];
        fechas[i + 1] = fechas[i];
        pg13s[i + 1] = pg13s[i];
        precios[i + 1] = precios[i];
        i--;
    }
    //Si no tuviera datos el arreglo ejecuta el siguiente codigo;
    //Cuando i>=0 se guara en el espacio q se ha abierto el valor nuevo
    codigos[i + 1] = codigo;
    fechas[i + 1] = fecha;
    pg13s[i + 1] = pg13;
    precios[i + 1] = precio;
    cantidad_videojuegos++;
}

void leer_insertar_ordenado(const char*nombre_archivo, int*codigos, int*fechas,
        char* pg13s, double*precios, int& cantidad_videojuegos) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int codigo, fecha;
    char pg13;
    double precio;
    while (true) {
        input>>codigo;
        if (input.eof())break;
        ignorar_cadena(input);
        fecha = leer_fecha(input);
        pg13 = leer_char(input);
        precio = leer_double(input);
        insertar_ordenado(codigo, fecha, pg13, precio,
                codigos, fechas, pg13s, precios, cantidad_videojuegos); //cantidad_videojuegos -> se actualizaconstantemente

    }
}


