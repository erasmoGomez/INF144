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

void imprimir_fecha(int fecha, ofstream &output) {
    output << setw(TAM_REPORTE / N_COLUMNAS - 13) << ""
            << setfill('0') << setw(2) << (fecha % 100) << '/'
            << setw(2) << (fecha / 100 % 100) << '/'
            << setfill(' ') << (fecha / 10000);
}

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

char to_mayus(char c) {
    char mayus;
    mayus = c - ('a' - 'A');
    return mayus;
}

char to_minus(char c) {
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
    output << "CLIENTE No. " << n_cliente << endl;
    output << "NOMBRE: ";
    input >> ws; //Leer todos los espacios en blanco
    while (true) {
        c = input.get(); //Lee un caracter
        if (c == ' ') break;
        //        if (c == '-') and bandera_coma c = ' '
        //        else c = ', ';
        if (c == '-') c = ' ';
        if (c >= 'a' and c <= 'z') c -= 'a' - 'A';
        //c = transforma_mayuscula(c);
        output.put(c); //Imprime un caracter
        n_caracteres++;
    }
    int tam = TAM_REPORTE / 2;
    for (int i = 0; i < tam - n_caracteres; i++) output.put(' ');
    output << "DNI: " << dni << endl;
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
        if (c == '_') c = ' ';
        if (c >= 'a' and c <= 'z') c -= 'a' - 'A';
        output.put(c); //Imprime un caracter
        n_caracteres++;
    }
    int tam = TAM_REPORTE / N_COLUMNAS;
    for (int i = 0; i < tam - n_caracteres; i++) output.put(' ');
}

int leer_fecha(ifstream &input) {
    int fecha, dd, mm, aa;
    char guion;
    input >> aa >> guion >> mm >> guion >> dd;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

int leer_codigo_plan(ifstream& input) {
    int codigo;
    char c;
    //PB101
    //PP102
    input >> c >> c>>codigo;
    return codigo;
}

double buscar_precio_base_plan(int codigo_plan, ifstream &input_planes, ofstream& output) {
    double precio_base = 0;
    //setear y limpiar el buffer
    input_planes.clear(); //Libera el buffer del archivo y limpia las banderas levantadas
    input_planes.seekg(0, ios::beg); //Devuelve el puntero al inicio del archivo
    int codigo_plan_leido;
    while (true) {
        codigo_plan_leido = leer_codigo_plan(input_planes);
        if (input_planes.eof()) break;
        if (codigo_plan_leido == codigo_plan) {
            leer_imprimir_plan(input_planes, output);
            input_planes>>precio_base;
            return precio_base;
        } else {
            //ignorar
            input_planes.ignore(50, '\n');
            continue;
        }
    }
    return precio_base;
}

void procesar_clientes_moviles(ifstream &input_moviles, ifstream &input_planes, ofstream & output, double &monto_total) {
    int dni, telefono, fecha_inicio_plan, fecha_fin_plan;
    int n_clientes = 0, codigo_plan;
    char c;
    double monto_plan, precio_base_plan, monto_real_plan, monto_cliente = 0;
    // DNI10218013 Escalona-Zurita-Estela 984685245 PB101 2025-06-18 2026-03-28 20.84 907288943 PP102 2025-08-03 2026-07-15 78.56
    while (true) {
        //Parte Fija
        input_moviles >> c >> c >> c>>dni;
        if (input_moviles.eof())break; //FIN DE ARCHIVO
        n_clientes++;
        leer_imprimir_nombre(input_moviles, output, n_clientes, dni);
        //Parte Variable
        monto_cliente = 0;
        while (true) {
            //984685245 PB101 2025-06-18 2026-03-28 20.84
            input_moviles>>telefono;
            output << setw(TAM_REPORTE / N_COLUMNAS - 15) << telefono;
            //leer codigo_plan
            codigo_plan = leer_codigo_plan(input_moviles); //101 102 103 o 104
            precio_base_plan = buscar_precio_base_plan(codigo_plan, input_planes, output);
            fecha_inicio_plan = leer_fecha(input_moviles);
            fecha_fin_plan = leer_fecha(input_moviles);
            input_moviles>>monto_plan;
            monto_real_plan = monto_plan + precio_base_plan;
            monto_cliente += monto_real_plan;
            monto_total += monto_real_plan;
            imprimir_fecha(fecha_inicio_plan, output);
            imprimir_fecha(fecha_fin_plan, output);
            output << setw(TAM_REPORTE / N_COLUMNAS) << monto_real_plan << endl;
            //Verificacion de fin de linea
            c = input_moviles.get();
            if (c == '\n') {
                output << endl;
                break;
            }
        }
        //Imprimir resumen x Cliente
        imprimir_titulo(output, "RESUME X CLIENTE");
        output<<"El monto parcial por cliente es :" << monto_cliente <<endl;
        imprimir_linea(output, '-');
    }
}

void imprimir_titulo(ofstream & output, const char* titulo) {
    imprimir_linea(output, '=');
    output << setw((TAM_REPORTE + TAM_TITULO_CAR) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

void imprimir_resumen_final(ofstream & output_reporte, double pago_total){
    imprimir_titulo(output_reporte, "RESUMEN FINAL");
    output_reporte<<"El pago total de 2025 es: "<< pago_total<<endl;
    imprimir_linea(output_reporte, '-');
}

void leer_procesar_clientes_moviles(const char* nombre_archivo_moviles,
                                    const char* nombre_archivo_planes,
                                    const char* nombre_archivo_reporte) {
    ifstream input_clientes_moviles, input_clientes_planes;
    ofstream output_reporte;
    apertura_archivo_lectura(input_clientes_moviles, nombre_archivo_moviles);
    apertura_archivo_lectura(input_clientes_planes, nombre_archivo_planes);
    apertura_archivo_escritura(output_reporte, nombre_archivo_reporte);
    double pago_total = 0;
    imprimir_titulo(output_reporte, "CLIENTES MOVILES 2025");
    procesar_clientes_moviles(input_clientes_moviles, input_clientes_planes, output_reporte, pago_total);
    imprimir_resumen_final(output_reporte, pago_total);
}