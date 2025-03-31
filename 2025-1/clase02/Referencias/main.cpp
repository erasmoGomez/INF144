/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 28 de marzo de 2025, 05:12 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    int edad;
//    edad = 33;
//    int edad = 33;
//    modificar_v1(edad);
//    cout<<"Fuera de modificar_v1: "<<edad<<endl;
//    
//    modificar_v2(edad);
//    cout<<edad<<endl;
    
    int a = 30;
    cout<<a<<endl;
    cout<<&a<<endl; //direccion de memoria de a
    
    int * pt;
    //pt = nullptr;
    cout<<pt<<endl;
    
    pt = &a;
    cout<<"luego de apuntar: "<<pt<<endl;
    
    *pt = 24; //de referenciar
    cout<<"luego de asignar: "<<pt<<endl;
    cout<<"luego de asignar el valor de 24 a *pt: "<<*pt<<endl;
    cout<<"luego de asignar el valor de 24 la variable a: "<<a<<endl;
    return 0;
}

