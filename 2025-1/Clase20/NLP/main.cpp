/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 29, 2025, 4:34 PM
 */

#include "funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
//    char tokens[50] = "pop/rock&roll/latin/metal";
//    cout << "Lista de Tokens Inicial : " << tokens << endl;
//    imprimir_tokens(tokens);
//    agregar_token(tokens, "jazz");
//    cout << "Lista de Tokens Modificada : " << tokens << endl;
//    imprimir_tokens(tokens);

    //Modificar texto 2023-2

    char nombre_completo[100] = "gomez_erasmo";
    char apellido_materno[] = "montoya";
    modificaTexto(nombre_completo, apellido_materno);
    cout<<"Modificar_Texto: 2023-2"<<endl;
    cout<<nombre_completo<<endl;
    return 0;
}

