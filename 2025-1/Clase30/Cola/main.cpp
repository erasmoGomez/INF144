/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on July 4, 2025, 2:05 PM
 */

#include "Cola.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    struct Cola c;
    inicializa(c);
    encolar(c, 18);
    encolar(c, 15);
    encolar(c, 20);
    
    int d;
    desencolar(c, d);
    cout<<d<<endl;
    desencolar(c, d);
    cout<<d<<endl;
    
    cout<<c.inicio->dato<<endl;
    return 0;
}

