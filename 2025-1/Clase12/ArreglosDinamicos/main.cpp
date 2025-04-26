/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 25, 2025, 6:39 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int codigos[10]{20082060, 20212060};
    int indice = 0;
    cout<<codigos[indice]<<endl;
    //codigos es un puntero a enteros
    cout<<codigos<<endl;
    cout<<codigos[indice+1]<<endl; //de-referencia
    cout<<*codigos<<endl; //de-referencia pero del primer elemento del arreglo
    
    int *arr; //arreglo enteros dinamico
    arr = new int [10]; //reservar memoria
    arr[0] = 20082060;
    cout<<"Arreglo Dinamico: "<<arr[0]<<endl;
    cout<<arr<<endl;
    cout<<*arr<<endl;
    return 0;
}

