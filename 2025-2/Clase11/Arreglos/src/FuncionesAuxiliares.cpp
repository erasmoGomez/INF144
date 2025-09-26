//
// Created by Erasmo on 25/09/25.
//

#include "FuncionesAuxiliares.hpp"

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++)
        cout<<"El codigo "<<i+1<<")"<<" es: "<<arr[i]<<endl;
}

int linearSearch(int *arr, int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}

int findMax(int *arr, int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void swap_int(int &a, int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void bubbleSort(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap_int(arr[j], arr[j+1]);
            }
        }
    }
}

void reverseArray(int *arr, int size) {
    int start = 0;
    int end = size - 1;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap_int(arr[i], arr[j]);
            }
        }
    }
}

void apertura_archivo_lectura(ifstream& input, const char* file_name){
    input.open(file_name, ios::in);
    if(not input.is_open()){
        cout<<"El archivo " << file_name << " No puede ser abiero"<<endl;
        exit(1);
    }
}

void leer_codigos(int *codigos,int &n,const char* file_name){
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo;
    while(true){
        input>>codigo;
        if(input.eof())break;
        codigos[n] = codigo;
        n++;
    }
}

void leer_alumnos(int *codigos, double* promedios,int &n,const char* file_name){
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo;
    double promedio;
    while(true){
        input>>codigo;
        if(input.eof())break;
        input>>promedio;
        codigos[n] = codigo;
        promedios[n] = promedio;
        n++;
    }
}