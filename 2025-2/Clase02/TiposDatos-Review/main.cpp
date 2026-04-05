

#include "src/AuxiliaryFunctions.hpp"

int main() {
    // ===== Declaración de variables básicas =====
    int dia = 25, mes = 8, anio = 2025;
    int fecha = anio*10000+mes*100+dia;

    double rating = 0.78; //Valores entre 0 a 1.

    double latitud  = -12.0464;
    double longitud = -77.0428; // Lima, Perú

    bool recomendado = true;

    //cout<<"erasmo";

    // the standard output device
    // CONSOLE
    // Otras salidas pueden ser: txt, dat, csv, bin

    int age = 21;
    cout<<"La edad es: "<<age<<endl;

    cout<<"La edad es: "<<setw(15)<<1234567890<<setw(5)<<"hola"<<endl;

    cout<<"La edad es: "<<setw(5)<<1234567890<<setw(5)<<"hola"<<endl;

    cout << left << setw(10) << "Hello"<<endl;

    cout << right << setw(10) << "Hello"<<endl;
    cout << left;
    cout << setw(10) << "Hello"<<endl;

    cout << setfill('X') << setw(10) << 5<<endl;

    cout << setfill(' ');
    cout << setw(10) << "Hello"<<endl;

    cout << latitud << endl;
    cout << longitud << endl;

    // Queremos formatear los valores de punto flotante.
    // Queremos que solo usen 2 decimales.

    cout << fixed; //Una sola vez
    cout << setprecision(2)<<latitud << endl; //Cada vez que quieran mostrar valores de punto flotante formateados.
    cout << setprecision(2)<<longitud << endl;

    cout << left << setw(10) << "Name"
         << right << setw(8) << "Score" << endl;

    print_line(18, '-');

    print_line_2(18, '-');

    cout << left << setw(10) << "Ana"
         << right << setw(8) << 95 << endl;

    cout << left << setw(10) << "Luis"
         << right << setw(8) << 100 << endl;

    int edad;
    cout << "Enter your age: ";
    cin >> edad;
    cout << "You entered: " << edad - 1;
    return 0;
}

