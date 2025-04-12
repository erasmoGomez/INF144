/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 10, 2025, 4:57 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    //Archivos para leer
//    ifstream input_notas("notas.txt", ios::in);
//    ifstream input_codigos("codigos.txt", ios::in);
//    //Archivo para escribir
//    ofstream output("reporte.txt", ios::out);
//    //Validacion de apertura de archivos
//    if(not input_notas.is_open()){
//        cout<<"Error: El archivo notas.txt NO se puede abrir"<<endl;
//        exit(1);
//    }
//    if(not input_codigos.is_open()){
//        cout<<"Error: El archivo codigos.txt NO se puede abrir"<<endl;
//        exit(1);
//    }
//    if(not output.is_open()){
//        cout<<"Error: El archivo reporte.txt NO se puede abrir"<<endl;
//        exit(1);
//    }
//    int nota, codigo;
//    input_notas>>nota;
//    input_codigos>>codigo;
//    output<<"El codigo del alumno es : "<<codigo<<endl;;
//    output<<"La nota del alumno es: "<<nota<<endl;
    lectura_datos_alumnos("codigos.txt", "notas.txt", "reporte.txt");
    return 0;
}

