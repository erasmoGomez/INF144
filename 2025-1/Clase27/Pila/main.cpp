/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on June 26, 2025, 4:38 PM
 */

#include "Pila.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    Pila p;
    inicializa(p);
    push(p, 5);
    push(p, 10);
    push(p, 15);
    int d = 0;
    pop(p,d);
    cout<<d<<endl;
    pop(p,d);
    cout<<d<<endl;
    return 0;
}

