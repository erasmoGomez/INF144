/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 28, 2025, 3:43 PM
 */

#include "Funciones.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    char oracion[50] = "Hola me llamo erasmo!";
    char oracion_cpy[50];
    //1. strcpy
    my_strcpy(oracion_cpy, oracion);
    my_strncpy(oracion_cpy, oracion, 4);
    //strncpy(oracion_cpy, oracion,4);
    //2. strcat
    my_strcat(oracion_cpy, " mundo");
    cout << oracion << endl;
    cout << oracion_cpy << endl;
    //3. strcmp
    int iguales = my_strcmp("Hola ", "Hola");
    cout << iguales << endl;
    iguales = strcmp("Hola ", "Hola");
    cout << iguales << endl;
    iguales = my_strncmp("Hola ", "Hola", 4);
    cout << iguales << endl;
    iguales = strncmp("Hola ", "Hola", 4);
    cout << iguales << endl;
    //4. strchr
    int pos = my_strchr("Hola mundo", 'o');
    cout << pos << endl;
    char *texto;
    texto = new char[50];
    my_strncpy(texto, "Hola mundo", 50);
    char *pos_ptr;
    pos_ptr = strchr(texto, 'o');
    cout << pos_ptr << endl;
    //5. strstr
    int start, end;
    my_strstr("Hola mundo que tal", "mundo", start, end);

    if (start != -1)
        cout << "Subcadena encontrada de " << start << " a " << end << "\n";
    else
        cout << "Subcadena no encontrada\n";

    const char *sub = strstr("Hola mundo que tal", "mundo");
    if (sub != nullptr)
        cout << sub << endl;
    else cout << "No se encontro sub cadena" << endl;


    return 0;
}

