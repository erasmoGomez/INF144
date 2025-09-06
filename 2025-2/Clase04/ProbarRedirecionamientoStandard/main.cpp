#include "src/AuxiliaryFunctions.hpp"

int main() {
    // Vamos a leer desde la entrada standard 3 datos
    int entero;
    double real;
    // "Ingrese un numero entero, un numero real y un nombre separada por ."
    // 123 3.5 erasmo.gomez -> coloque esta linea en un archivo de textos
    // No olvide que el archivo de texto creado debe tener un enter al final de la linea
    cin >> entero >> real;

    // Vamos a escribir en la salida standard los 3 datos
    cout << fixed;
    cout << setprecision(2);
    cout << setw(5) << entero << setw(5) << real;
    read_print_str();
    return 0;
}
