/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 5, 2025, 3:11 PM
 */

#include "Funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    //Lectura
    char cadena[100];
//    while(true){
//        cin.getline(cadena, 100, '*');
//        cout<<cadena<<endl;
//        if(cin.get()=='\n') break;
//        else
//            cin.unget();
//    }
    char c;
    int numero;
    //erasmo,1234,montoya
    char buffer1[20], buffer2[20];
    cin.getline(buffer1, 20, ',');
    cin>>numero;
    cin.get();
    cin.getline(buffer2, 20, '\n');
    
    cout<<setw(20)<<buffer1<<setw(5)<<numero<<setw(20)<<buffer2<<endl;
    return 0;
}

