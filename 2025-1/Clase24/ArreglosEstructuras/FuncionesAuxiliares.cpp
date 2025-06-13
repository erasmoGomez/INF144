/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 13, 2025, 4:53 PM
 */

#include "FuncionesAuxiliares.hpp"
void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

double leer_double(ifstream &input){
    double d;
    input>>d;
    input.get();
    return d;
}

char* leer_cadena(ifstream& input, char delim){
    char* cadena, buffer[60];
    input.getline(buffer, 60, delim);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

void leer_bonos(ifstream& input, double* bonos, int& n){
    double bono;
    while(true){
        input>>bono;
        bonos[n++] = bono;
        if(input.get()=='\n')break;
    }
}

void leer_empleados(const char* nombre_archivo, struct Empleado *empleados, int &cantidad_empleados){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //378708,22/06/2022,SAENZ ARANDA WILMER,23455.63,243.66,609,498.38,141.32,842.32,839.7,819.8,876.49
    int codigo, aa, mm, dd;
    char c;
    while(true){
        input>>codigo;
        if(input.eof())break;
        input.get();
        //Leer fecha
        input>>dd>>c>>mm>>c>>aa;
        input.get();
        empleados[cantidad_empleados].codigo = codigo;
        empleados[cantidad_empleados].fecha_ingreso.fecha = aa*10000+mm*100+dd;
        empleados[cantidad_empleados].fecha_ingreso.dd = dd;
        empleados[cantidad_empleados].fecha_ingreso.mm = mm;
        empleados[cantidad_empleados].fecha_ingreso.aa = aa;
        //Leer Nombre
        empleados[cantidad_empleados].nombre = leer_cadena(input, ',');
        //Leer Sueldo
        empleados[cantidad_empleados].sueldo = leer_double(input);
        //Leer Bonos
        leer_bonos(input, empleados[cantidad_empleados].bonos, empleados[cantidad_empleados].n_bonos);
        cantidad_empleados++;
    }
}

void imprimir_bonos(ofstream& output, double* bonos,int n){
    for(int i=0; i<n; i++)
        output<<setw(20)<<bonos[i]<<endl;
    output<<endl;
}

void imprimir_empleados(const char* nombre_archivo, struct Empleado *empleados, int cantidad_empleados){
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    
    output<<fixed;
    output<<setprecision(2);
    
    for(int i=0; i<cantidad_empleados;i++){
        output<<left<<setw(10)<<empleados[i].codigo;
        output<<left<<setw(10)<<empleados[i].fecha_ingreso.fecha;
        output<<left<<setw(30)<<empleados[i].nombre;
        output<<left<<setw(10)<<empleados[i].sueldo;
        imprimir_bonos(output, empleados[i].bonos, empleados[i].n_bonos);
    }
}

void cambiar(struct Empleado &dato1, struct Empleado& dato2){
    struct Empleado aux = dato1;
    dato1 = dato2;
    dato2 = aux;
}

void ordernar_empleados(struct Empleado* empleados, int cantidad_empleados){
    for(int i = 0; i<cantidad_empleados-1; i++)
        for(int j = i+1; j<cantidad_empleados; j++){
            if(strcmp(empleados[i].nombre, empleados[j].nombre)>0)
                cambiar(empleados[i], empleados[j]);
        }
}

void cambiar_double(double& d1, double& d2){
    double aux = d1;
    d1 = d2;
    d2 = aux;
}

void ordenar_bonos(double* bonos, int n_bonos){
    for(int i = 0; i<n_bonos-1; i++)
        for(int j = i+1; j<n_bonos; j++)
            if(bonos[i]>bonos[j])
                cambiar_double(bonos[i], bonos[j]);
}
void ordenar_arr_bonos(struct Empleado *empleados, int cantidad_empleados ){
    for(int i = 0; i< cantidad_empleados; i++)
        ordenar_bonos(empleados[i].bonos, empleados[i].n_bonos);
}