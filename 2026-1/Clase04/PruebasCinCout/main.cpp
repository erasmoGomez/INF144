#include <iostream>
using namespace std;
int main() {
    int age = 0; // Inicializamos
    int parte_entera = 0, parte_decimal = 0;
    long long numero_grande = 0;
    // cin >> parte_entera;
    // // cout << "La edad ingresada es : "<< age<< endl;
    // cout << "La parte entera es ingresada es : "<< parte_entera<< endl;
    //
    // // Completar la lectura
    // char punto;
    // cin >> punto; // Lee el .
    // cin >> parte_decimal; // Lee la parte_decimal
    // cout << "La parte decimal es : "<< parte_decimal<< endl;
    // cin >> numero_grande; // Cae en error luego del .
    // cout << "El numero muy grande es : "<< numero_grande<< endl;
    // int entero_siguiente = 10; // Intentemos leer un CHAR
    // cin >> entero_siguiente;
    // cout <<"el entero siguiente es : " << entero_siguiente << endl;
    // Error LÓGICO

    //LEER DOUBLES
    // double peso = 0.0; // Default value
    // cin >> peso;
    // cout << "El peso es : " << peso << endl;

    // LEER CHAR
    // char grade;
    // char next;
    // char whitespace;
    // cout << "Enter grade (A-F): ";
    // cin >> grade;
    // //cin >> whitespace; // No puede ser leido con CIN
    // cin.get(whitespace); // Lee un caracter. Es la unica opcion para leer un caracter invisible
    // cin >> next;
    // cout << grade; // 1
    // cout << whitespace; //
    // cout << next << endl; // 9

    // Leer BOOLEAN
    //
    // bool active;
    // cout << "Enter 1 (true) or 0 (false): ";
    // cin >> active;
    // cout << "Active: " << active << endl;

    // Leer valores consecutivos
    // int x, y;
    // cout << "Enter two integers: ";
    // cin >> x >> y;
    // cout << "x=" << x << ", y=" << y << endl;
        // Leer una fecha
    // 04/04/2026
    // int dd, mm, aa, date;
    // char slash;
    // cin >> dd >> slash >> mm >> slash >> aa;
    // cout << "dd=" << dd << ", mm=" << mm << ", aa=" << aa << endl;
    // date = aa * 10000 + mm * 100 + dd;
    // cout<<"date = " << date<< endl;
    int entero;
    // cin.fail() SI ES 1 TRUE, ES X Q HAY UN FALLO EN LA LECTURA
    cout<< "Valor inicial de la bandera: "<< cin.fail()<<endl;
    cin >> entero;
    cout<< "Valor final de la bandera: " << cin.fail()<<endl;
    cin.clear();
    cout<< "Valor final final de la bandera: " << cin.fail()<<endl;

    return 0;
}