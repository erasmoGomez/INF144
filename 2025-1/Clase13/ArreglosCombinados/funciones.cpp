/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 30, 2025, 8:29 PM
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

// un arreglo estático se recibe comopuntero al tipo de dato

void leer_datos_enteros(ifstream& input, int* arreglo, int &cantidad_datos) {
    int numero = 0;
    while (true) {
        input>>numero;
        if (input.eof())break;
        arreglo[cantidad_datos] = numero;
        cantidad_datos++;
    }
}

void imprime_titulo(ofstream& output, const char* titulo) {
    output << setw((TAM_REPORTE + TAM_TITULO) / 2) << titulo << endl;
}

void imprimir_arreglo(ofstream& output, int*arreglo, int cantidad_datos, const char* titulo) {
    imprime_titulo(output, titulo);
    for (int i = 0; i < cantidad_datos; i++) {
        output << setw(5) << arreglo[i];
    }
    output << endl;
}

void combinar_arreglos(int* arreglo_enteros_1,
        int* arreglo_enteros_2,
        int* arreglo_enteros_final,
        int cantidad_datos_1, int cantidad_datos_2,
        int &cantidad_datos_final) {
    //[2][3][4][8][10]  Arreglo1
    //[1][5][7]         Arreglo2
    //[1][2][3][4][5][7][][]  ArregloFinal
    //[0][1][2] -> indice 3 se valida
    int indice_1 = 0, indice_2 = 0;
    while (true) {
        if (arreglo_enteros_1[indice_1] == arreglo_enteros_2[indice_2]) {
            arreglo_enteros_final[cantidad_datos_final] = arreglo_enteros_1[indice_1];
            indice_1++;
            indice_2++;
        } else
            if (arreglo_enteros_1[indice_1] < arreglo_enteros_2[indice_2]) {
            arreglo_enteros_final[cantidad_datos_final] = arreglo_enteros_1[indice_1];
            indice_1++;
        } else {
            arreglo_enteros_final[cantidad_datos_final] = arreglo_enteros_2[indice_2];
            indice_2++;
        }
        cantidad_datos_final++;
        if (indice_1 >= cantidad_datos_1 or indice_2 >= cantidad_datos_2)
            break;


        //        if (indice_1 > cantidad_datos_1 or indice_2 > cantidad_datos_2)
        //            break;
        //        cantidad_datos_final++;
    }

    while (indice_1 < cantidad_datos_1) {
        arreglo_enteros_final[cantidad_datos_final] = arreglo_enteros_1[indice_1];
        indice_1++;
        cantidad_datos_final++;
    }

    while (indice_2 < cantidad_datos_2) {
        arreglo_enteros_final[cantidad_datos_final] = arreglo_enteros_2[indice_2];
        indice_2++;
        cantidad_datos_final++;
    }
}

void calcular_arreglo_combinado(const char*nombre_archivo_numeros_1,
        const char*nombre_archivo_numeros_2,
        const char*nombre_archivo_reporte) {
    ifstream input_numeros_1, input_numeros_2, input_numeros_3;
    ofstream output;
    apertura_archivo_lectura(input_numeros_1, nombre_archivo_numeros_1);
    apertura_archivo_lectura(input_numeros_2, nombre_archivo_numeros_2);
    apertura_archivo_lectura(input_numeros_3, "numeros.txt");
    apertura_archivo_escritura(output, nombre_archivo_reporte);

    int arreglo_enteros_1[MAX_NUMEROS]{}, arreglo_enteros_2[MAX_NUMEROS]{};
    int arreglo_enteros_3[MAX_NUMEROS]{};
    int arreglo_enteros_final[MAX_NUMEROS]{};
    int cantidad_datos_1 = 0, cantidad_datos_2 = 0, cantidad_datos_final = 0;
    int cantidad_datos_3 = 0;

    //[12][15][-5][10][2][0][0][0][0][0].....[0] -> MAX_NUMEROS 30
    //                                           -> cantidad_datos 5

    leer_datos_enteros(input_numeros_1, arreglo_enteros_1, cantidad_datos_1);
    leer_datos_enteros(input_numeros_2, arreglo_enteros_2, cantidad_datos_2);
    imprimir_arreglo(output, arreglo_enteros_1, cantidad_datos_1, "Arreglo Enteros 1");
    imprimir_arreglo(output, arreglo_enteros_2, cantidad_datos_2, "Arreglo Enteros 2");
    combinar_arreglos(arreglo_enteros_1, arreglo_enteros_2, arreglo_enteros_final,
            cantidad_datos_1, cantidad_datos_2, cantidad_datos_final);
    imprimir_arreglo(output, arreglo_enteros_final, cantidad_datos_final, "Arreglo Enteros Combinado");

    leer_datos_enteros(input_numeros_3, arreglo_enteros_3, cantidad_datos_3);
    
    //impriman al reves
    imprime_titulo(output, "Imprimir al revez");
    for (int i = cantidad_datos_3 - 1; i >= 0; i--) {
        output << setw(5) << arreglo_enteros_3[i];
    }
    output << endl;
}