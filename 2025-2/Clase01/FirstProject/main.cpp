#include "src/MathFunctions.hpp"

int main() {
    int sum = 0;
    sum = adding_numbers(2, 3);
    cout << "El valor de sum es: ";
    cout << sum << endl; // Tal como estaba
    cout << "El valor de sum es: ";
    cout << setw(20) << sum << endl; //Usando iomanip
    return 0;
}
