/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 2, 2025, 5:32 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void ignorar(ifstream& input, char delimitador) {
    input>>ws;
    while (input.get() != delimitador);
}

void cargar_datos_juegos(const char*nombre_archivo_input, int*codigos, double*precios, int&cantidad) {
    //Arbir archivos
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo_input);
    //Leer
    //93210 GALAXY_BATTLE 4.50 SHOOTER
    int codigo;
    while (true) {
        input>>codigo;
        if (input.eof())break;
        codigos[cantidad] = codigo;
        ignorar(input, ' ');
        input >> precios[cantidad];
        ignorar(input, '\n');
        cantidad++;
    }
}

void prueba_impresion(int*codigos, double*precios, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << setw(10) << codigos[i] << setw(10) << precios[i] << endl;
    }
}

void imprimir_linea(ofstream &output, char c) {
    output << setfill(c) << setw(TAM_REPORTE - 1) << c << endl;
    output << setfill(' ');
}

void imprimir_titulo(ofstream & output, const char* titulo) {
    imprimir_linea(output, '=');
    output << setw((TAM_REPORTE + TAM_TITULO) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

void imprime_nombre_dni(ifstream& input, ofstream& output, int dni) {
    imprimir_linea(output, '=');
    output << "JUGADOR: " << dni << " - ";
    input>>ws;
    char c;
    while (true) {
        c = input.get();
        if (c == ' ') break;
        output.put(c);
    }
    output << endl;
    imprimir_linea(output, '=');
}

int leer_hora(ifstream& input) {
    //21:16:18
    int hh, mm, ss;
    char c;
    input >> hh >> c >> mm >> c>>ss;
    return 3600 * hh + 60 * mm + ss;
}

double buscar_precio(int codigo_buscar, int*codigos, double*precios, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (codigos[i] == codigo_buscar) return precios[i];
    }
    return NO_ENCONTRADO;
}

int obtener_posicion(int codigo_buscar, int*codigos, double*precios, int cantidad) {
    for (int i = 0; i < cantidad; i++)
        if (codigos[i] == codigo_buscar) return i;
    return NO_ENCONTRADO;
}

void imprimir_header(ofstream &output) {
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << "CODIGO";
    output << setw(TAM_REPORTE / N_COLUMNAS) << "RONDAS";
    output << setw(TAM_REPORTE / N_COLUMNAS) << "PRECIO";
    output << setw(TAM_REPORTE / N_COLUMNAS) << "TOTAL PAGADO" << endl;
    imprimir_linea(output, '-');
}

void imprimir_linea_juego(ofstream& output, int codigo, int rondas, double precio, double precio_total) {
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << codigo;
    output << setw(TAM_REPORTE / N_COLUMNAS) << rondas;
    output << setw(TAM_REPORTE / N_COLUMNAS) << precio;
    output << setw(TAM_REPORTE / N_COLUMNAS) << precio_total << endl;
}

void imprime_estadistico(double precio, ofstream& output, const char* titulo, const char* mensaje) {
    imprimir_linea(output, '-');
    imprimir_titulo(output, titulo);
    output << mensaje << setw(6) << precio << endl;
    imprimir_linea(output, '-');
}

void calculo_por_jugador(const char*nombre_archivo_input, const char*nombre_archivo_output,
        int*codigos, double*precios, int cantidad) {
    ifstream input;
    ofstream output;
    apertura_archivo_lectura(input, nombre_archivo_input);
    apertura_archivo_escritura(output, nombre_archivo_output);
    imprimir_titulo(output, "SERVIDOR DE VIDEOJUEGOS 'PIXELFIRE'");
    output << fixed;
    output << setprecision(2);
    //54561053 Romero/Quispe/Felipe 21:16:18 4 12345 2 33120
    int dni, hora, cantidad_rondas, codigo_juego, indice_juego;
    double precio_ronda_juego;
    double precio_acumulado = 0;
    while (true) {
        //Parte Fija
        input>>dni;
        if (input.eof())break;
        imprime_nombre_dni(input, output, dni);
        hora = leer_hora(input);
        //Parte Variable
        imprimir_header(output);
        int precio_jugador = 0;
        while (true) {
            input>>cantidad_rondas;
            input>>codigo_juego;
            precio_ronda_juego = buscar_precio(codigo_juego, codigos, precios, cantidad);
            //indice_juego = obtener_posicion(codigo_juego, codigos, precios, cantidad);
            if (precio_ronda_juego != NO_ENCONTRADO) {
                imprimir_linea_juego(output, codigo_juego, cantidad_rondas, precio_ronda_juego, cantidad_rondas * precio_ronda_juego);
            } else
                cout << "El precio de juego: " << codigo_juego << " No se pudo encontrar" << endl;
            precio_jugador += cantidad_rondas * precio_ronda_juego;
            if (input.get() == '\n')break;
        }
        imprime_estadistico(precio_jugador, output, "Resumen Jugador", "Ganancia Total Por Jugador: ");
        precio_acumulado += precio_jugador;
    }
    imprime_estadistico(precio_acumulado, output, "Resumen General", "Total Ganancias: ");
}