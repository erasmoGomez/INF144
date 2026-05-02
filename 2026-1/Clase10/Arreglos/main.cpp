#include "src/FuncionesAuxiliares.hpp"

int main() {
    int codigos[MAX_CODIGOS]{};
    int n_codigos = 0;
    leer_codigos(codigos, n_codigos, "Data/codigos.txt");
    cout << "La Cantidad de codigos es: " << n_codigos << endl;
    printArray(codigos, n_codigos);
    int pos = linearSearch(codigos, n_codigos, 20242060);
    // Validar
    if (pos != -1) {
        cout << "Codigo Encontrado: " << codigos[pos] << endl;
        cout << pos << endl;
    } else
        cout << "Codigo no Encontrado" << endl;
    cout << "Arreglo de codigos invertido: " << endl;
    reverseArray(codigos, n_codigos);
    printArray(codigos, n_codigos);

    // cout << "Arreglo de codigos ordenado por Burbuja: "<<endl;
    // bubbleSort(codigos, n_codigos);
    // printArray(codigos, n_codigos);
    //
    // cout << "Arreglo de codigos ordenado por Seleccion: "<<endl;
    // selectionSort(codigos, n_codigos);
    // printArray(codigos, n_codigos);
    return 0;
}
