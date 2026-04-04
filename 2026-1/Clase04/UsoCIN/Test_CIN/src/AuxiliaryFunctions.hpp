//
// Created by Erasmo on 4/09/25.
//

#ifndef TEST_CIN_AUXILIARYFUNCTIONS_HPP
#define TEST_CIN_AUXILIARYFUNCTIONS_HPP
#include "Utils.hpp"
// Lecturas básicas
void leerTresEnteros();

void leerEnteroDoubleChar();

// Fecha y hora
int leerFecha(int &dd, int &mm, int &aa);      // dd/mm/aaaa
int leerHora(int &HH, int &MM, int &SS);       // HH:MM[:SS] (segundos opcional)

// Eco sin almacenar
void ecoTokenMayusSinAlmacenar();               // hasta espacio o salto
void ecoLineaMayusSinAlmacenar();               // hasta '\n'

// Patrones útiles con cin
void sumarEnterosHastaTope();                     // patrón correcto de Tope
void demoPeekGetPutIgnore();                     // muestra peek, get, put, ignore, ws

// Utilitario para limpiar línea en caso de error
void limpiarLinea();

#endif //TEST_CIN_AUXILIARYFUNCTIONS_HPP
