/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 11, 2025, 12:30 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo){
    input.open(nombre_archivo, ios::in);
    if(not input.is_open()){
        cout<<"Error: el archivo: "<<nombre_archivo<<" No se puede abrir"<<endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo){
    output.open(nombre_archivo, ios::out);
    if(not output.is_open()){
        cout<<"Error: el archivo: "<<nombre_archivo<<" No se puede abrir"<<endl;
        exit(1);
    }
}

char to_mayus(char c){
    char mayus;
    mayus = c - ('a' - 'A');
    return mayus;
}

char to_minus(char c){
    char minus;
    minus = c + ('a' - 'A');
    return minus;
}

void imprimir_linea(ofstream &output, char c) {
    output << setfill(c) << setw(TAM_REPORTE - 1) << c << endl;
    output << setfill(' ');
}

void leer_imprimir_nombre(ifstream &input, ofstream & output, int n_cliente, int dni) {
    int n_caracteres = 0;
    char c;
    //CLIENTE No. 1
    //NOMBRE: ESCALONA ZURITA, ESTELA  DNI: 10218013
    output<<"CLIENTE No. "<<n_cliente<<endl;
    output<<"NOMBRE: ";
    input >> ws; //Leer todos los espacios en blanco
    while (true) {
        c = input.get(); //Lee un caracter
        if (c == ' ') break;
//        if (c == '-') and bandera_coma c = ' '
//        else c = ', ';
        if (c == '-') c = ' ';
        //c = transforma_mayuscula(c);
        output.put(c); //Imprime un caracter
        n_caracteres++;
    }
    int tam = TAM_REPORTE/2;
    for (int i = 0; i < tam - n_caracteres; i++) output.put(' ');
    output<<"DNI: "<<dni<<endl;
    imprimir_linea(output, '-');
}

void leer_imprimir_plan(ifstream &input, ofstream & output) {
    int n_caracteres = 0;
    char c;
    input >> ws; //Leer todos los espacios en blanco
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << "";
    while (true) {
        c = input.get(); //Lee un caracter
        if (c == ' ') break;
        output.put(c); //Imprime un caracter
        n_caracteres++;
    }
    int tam = TAM_REPORTE / N_COLUMNAS;
    for (int i = 0; i < tam - n_caracteres; i++) output.put(' ');
}

int leer_fecha(ifstream &input) {
    int fecha, dd, mm, aa;
    char slash;
    input >> dd >> slash >> mm >> slash >> aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

void procesar_linea_clientes_moviles(ifstream &input, ofstream & output, double &monto_total){
    int dni, telefono, fecha_inicio_plan, fecha_fin_plan;
    int n_clientes = 0;
    char c;
    double monto_plan;
    //DNI10218013	Escalona-Zurita-Estela	984685245	PostpagoBasico	2025-06-18	2026-03-28	20.84	907288943	PostpagoPlus	2025-08-03	2026-07-15	78.56
    while(true){
        //Parte Fija
        input>>c>>c>>c>>dni;
        if(input.eof())break; //FIN DE ARCHIVO
        n_clientes++;
        leer_imprimir_nombre(input, output, n_clientes, dni);
        //Parte Variable
        while(true){
            input>>telefono;
            output<<setw(TAM_REPORTE/N_COLUMNAS)<<telefono;
            leer_imprimir_plan(input, output);
            fecha_inicio_plan = leer_fecha(input);
            fecha_fin_plan = leer_fecha(input);
            input>>monto_plan;
            monto_total += monto_plan;
            output<<setw(TAM_REPORTE/N_COLUMNAS)<<fecha_inicio_plan;
            output<<setw(TAM_REPORTE/N_COLUMNAS)<<fecha_fin_plan;
            output<<setw(TAM_REPORTE/N_COLUMNAS)<<monto_plan;
            //Verificacion de fin de linea
            c = input.get();
            if (c == '\n') {
                output<<endl;
                break;
            }
        }
    }
}

void imprimir_titulo(ofstream & output, const char* titulo){
    imprimir_linea(output, '=');
    output<<setw((TAM_REPORTE + TAM_TITULO_CAR)/2)<<titulo<<endl;
    imprimir_linea(output, '=');
}

void leer_procesar_clientes_moviles(const char* nombre_archivo_moviles, 
                                    const char* nombre_archivo_reporte){
    ifstream input_clientes_moviles;
    ofstream output_reporte;
    apertura_archivo_lectura(input_clientes_moviles, nombre_archivo_moviles);
    apertura_archivo_escritura(output_reporte, nombre_archivo_reporte);
    double pago_total = 0;
    imprimir_titulo(output_reporte, "CLIENTES MOVILES 2025");
    procesar_linea_clientes_moviles(input_clientes_moviles, output_reporte, pago_total);
    
}