/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 24, 2025, 5:09 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    int arr_codigos[10];
//    ifstream input;
//    ofstream output;
//    apertura_archivo_lectura(input, "codigos.txt");
//    apertura_archivo_escritura(output, "reporte.txt");
//    //Llenado de arreglo
//    int n_datos = 0;
//    while(true){
//        input>>arr_codigos[n_datos];
//        if(input.eof())break;
//        n_datos++;
//    }
//    //Imprimir los datos del arreglo
//    for(int i=0; i<n_datos;i++)
//        output<<"Codigo: "<<arr_codigos[i]<<endl;
    
    int arr_codigos[MAX_ALUMNOS];
    double arr_notas[MAX_ALUMNOS];
    ifstream input;
    ofstream output;
    apertura_archivo_lectura(input, "alumnos.csv");
    apertura_archivo_escritura(output, "reporte_2.txt");
    
    int n_alumnos = 0;
    int codigo;
    double nota;
    while(true){
        //20082060, 18.0
        input>>codigo;
        if(input.eof())break;
        input.get(); // Lee la coma
        input>>nota;
        //Guardar en arreglos
        arr_codigos[n_alumnos] = codigo;
        arr_notas[n_alumnos] = nota;
        n_alumnos++;
    }
    //06.35
    for(int i = 0 ; i<n_alumnos;i++){
        output<<setw(10)<<arr_codigos[i];
        output<<setw(10)<<arr_notas[i]<<endl;
    }
    return 0;
}

