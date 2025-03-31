/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "funciones.hpp"

void modificar_v1(int edad){
    edad +=10;
    cout<<"Edad dentro de modificar_v1 :"<<edad<<endl;
}

void modificar_v2(int & edad){
    edad +=10;
}