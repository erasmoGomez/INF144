/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: erasmo
 *
 * Created on March 27, 2025, 6:22 PM
 */

#include "utils.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //Declaracion de variables
    //dni, nombre, edad, peso, cantidad_cursos, estatura, casado?
    int dni_1;
    char nombre_1[MAX_NOMBRE];
    int edad_1;
    double peso_1;
    int cantidad_cursos_1;
    double estatura_1;
    bool casado_1;
    
    //Asignar un valor a las variables
    dni_1 = 12345678;
    strcpy(nombre_1, "Erasmo");
    edad_1 = 33;
    peso_1 = 100.25;
    cantidad_cursos_1 = 5;
    estatura_1 = 1.675;
    casado_1 = true;
    //Imprimir
    cout<<nombre_1<<endl<<dni_1<<endl<<peso_1<<endl<<casado_1<<endl;
    
    cout<<left<<setw(20)<<nombre_1<<"|"<<endl;
    cout<<right<<setw(50)<<nombre_1<<endl;
    cout<<left<<setw(10)<<nombre_1<<peso_1<<endl;
    
    cout<<right<<setw(MAX_COLUMN_SPACES)<<nombre_1;
    cout<<right<<setw(MAX_COLUMN_SPACES)<<dni_1;
    cout<<right<<setw(MAX_COLUMN_SPACES)<<peso_1;
    cout<<right<<setw(MAX_COLUMN_SPACES)<<casado_1<<endl;
    
    cout<<right<<setfill('*')<<setw(MAX_COLUMN_SPACES*2)<<"ESTO ES EL ESPACIO RESERVADO"<<endl;
    cout<<right<<setfill(' ')<<setw(MAX_COLUMN_SPACES*2)<<"ESTO ES EL ESPACIO RESERVADO"<<endl;
    
    cout<<setfill('*')<<setw(10)<<" "<<endl;
    cout<<setfill(' ')<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<left<<"*"<<right<<setw(8)<<"*"<<endl;
    cout<<setfill('*')<<setw(10)<<" "<<endl;
    //    //int a = 23;
//    int *pt;
//    pt = new int;
//    *pt = 23;
//    cout<<*pt<<endl;
    return 0;
}

