/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 10, 2025, 6:07 PM
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

void lectura_datos_alumnos(const char* nombre_archivo_codigos, 
                           const char* nombre_archivo_notas, 
                           const char* nombre_archivo_reporte){
    ifstream input_codigos;
    ifstream input_notas;
    ofstream output_reporte;
    apertura_archivo_lectura(input_codigos, nombre_archivo_codigos);
    apertura_archivo_lectura(input_notas, nombre_archivo_notas);
    apertura_archivo_escritura(output_reporte, nombre_archivo_reporte);
    //Lectura
    int codigo, nota;
    output_reporte<<setw(20)<<"Notas LAB 1 2025-1"<<endl;
    output_reporte<<setw(10)<<"CODIGOS"<<setw(10)<<"NOTAS"<<endl;
    while(true){
        input_codigos>>codigo;
        input_notas>>nota;
        if(input_codigos.eof())break;
        //if(input_notas.eof())break;
        output_reporte<<setw(12)<<left<<codigo<<setw(2)<<setfill('0')<<nota<<endl;
        output_reporte<<setfill(' ');
    }
}