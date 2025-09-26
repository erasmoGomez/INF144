#include "src/FuncionesAuxiliares.hpp"

int main() {
//    int size = 5;
//    int codigos[5] = {20082060, 20082131, 20082062, 20082096, 20082101};
//    printArray(codigos, size);
    int codigos[MAX_CODIGOS]{};
    int n = 0;
    leer_codigos(codigos, n, "Data/codigos.txt");
    cout << "La Cantidad de codigos es: " << n << endl;
    printArray(codigos, n);
    int pos = linearSearch(codigos, n, 19952096);
    if (pos != -1) {
        cout << "Codigo Encontrado: " << codigos[pos] << endl;
        cout << pos << endl;
    } else
        cout << "Codigo no Encontrado" << endl;
    cout << "Arreglo de codigos invertido: "<<endl;
    reverseArray(codigos, n);
    printArray(codigos, n);

    cout << "Arreglo de codigos ordenado por Burbuja: "<<endl;
    bubbleSort(codigos, n);
    printArray(codigos, n);

    cout << "Arreglo de codigos ordenado por Seleccion: "<<endl;
    selectionSort(codigos, n);
    printArray(codigos, n);
    return 0;
}
