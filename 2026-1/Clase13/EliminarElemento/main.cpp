#include <iostream>
#include <iomanip>
using namespace std;

void eliminar_elemento(int* arreglo, int &n, int pos) {
    for (int i = pos; i < n -1; i++) {
        arreglo[i] = arreglo[i + 1];
    }
    n--;
}

void imprimir(int *arreglo, int n) {
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }
    cout<<endl;
}

void eliminar_pares(int * arreglo, int &n) {
    int index = 0;
    while (index < n) {
        if (arreglo[index] % 2 == 0) {
            eliminar_elemento(arreglo, n, index);
        }
        else
            index++;
    }
}

int main() {
    int arreglo[10] = {10, 15, 20, 7, 8, 11, 14};
    int n = 7;
    int pos = 2;
    imprimir(arreglo, n);
    // eliminar_elemento(arreglo, n, pos);
    eliminar_pares(arreglo, n);
    imprimir(arreglo, n);
    return 0;
}