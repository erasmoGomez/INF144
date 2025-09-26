//
// Created by Erasmo on 25/09/25.
//

#ifndef ARREGLOS_FUNCIONESAUXILIARES_HPP
#define ARREGLOS_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
void printArray(int* arr, int size);
int linearSearch(int *arr, int size, int target);
int findMax(int *arr, int size);
void bubbleSort(int *arr, int size) ;
void reverseArray(int *arr, int size) ;
void selectionSort(int *arr, int n) ;
void apertura_archivo_lectura(ifstream& input, const char* file_name);
void leer_codigos(int *codigos,int &n,const char* file_name);
#endif //ARREGLOS_FUNCIONESAUXILIARES_HPP
