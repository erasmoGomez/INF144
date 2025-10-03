//
// Created by Erasmo on 2/10/25.
//

#include "Funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << file_name << " No puede ser abiero" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "El archivo " << file_name << " No puede ser abiero" << endl;
        exit(1);
    }
}

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void print_date(ofstream &output, int date) { //20250904
    int anio = date / 10000;        // 2025
    int mes = (date / 100) % 100;  // 09
    int dia = date % 100;          // 04

    output << right;
    output << setw(2) << setfill('0') << dia;
    output << "/";
    output << setw(2) << setfill('0') << mes;
    output << "/";
    output << setw(4) << anio;

    output << setfill(' ');  // restaurar fill a espacio
}

void ignorar(ifstream &input, char c) {
    input >> ws;
    while (input.get() != c);
}

void leer_empleados(const char *nombArch, int *dnis, int *fechasIng, char *sexos,
                    int *telefonos, double *sueldos, int &numDat) {
    ifstream input;
    apertura_archivo_lectura(input, nombArch);

    int dni;
    //17000095 Hijar 5/07/2020 F 39827505 2001.21
    while (true) {
        input >> dni;
        if (input.eof()) break;
        ignorar(input, ' ');
        dnis[numDat] = dni;
        fechasIng[numDat] = read_date(input);
        input >> sexos[numDat];
        input >> telefonos[numDat];
        input >> sueldos[numDat];
        numDat++;
    }
}

void swapInt(int &a, int &b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void swapChar(char &a, char &b) {
    char aux;
    aux = a;
    a = b;
    b = aux;
}

void swapDouble(double &a, double &b) {
    double aux;
    aux = a;
    a = b;
    b = aux;
}

void ordenar_por_dni(int *dnis, int *fechasIng, char *sexos, int *telefonos, double *sueldos, int numDat) {
    //Aplicar el selection sort 2
    for (int i = 0; i < numDat - 1; i++)
        for (int k = i + 1; k < numDat; k++)
//            if (sexos[i] > sexos[k] or
//                sexos[i]==sexos[k] and
//                dnis[i]>dnis[k]) { //Condicion de ordenamiento
            if(dnis[i]>dnis[k]){
                swapInt(dnis[i], dnis[k]);
                swapInt(fechasIng[i], fechasIng[k]);
                swapInt(telefonos[i], telefonos[k]);
                swapChar(sexos[i], sexos[k]);
                swapDouble(sueldos[i], sueldos[k]);
            }
}


void imprimir_empleados(const char *nombArch, int *dnis, int *fechasIng, char *sexos,
                        int *telefonos, double *sueldos, int numDat) {
    ofstream output;
    apertura_archivo_escritura(output, nombArch);
    output.precision(2);
    output << fixed;
    for (int i = 0; i < numDat; i++) {
        print_date(output, fechasIng[i]);
        output << setw(3) << i + 1 << ") " << setw(10) << dnis[i] << " "
               << setw(5) << sexos[i]
               << setw(10) << telefonos[i] << setw(10) << sueldos[i] << endl;
    }
}

void insertar_ordenado(int dni, int fechaIngreso, char sexo, int telefono, double sueldo,
                       int *dnis, int *fechasIngreso, char *sexos,
                       int *telefonos, double *sueldos, int &numDat) {

    int i = numDat - 1;
    while (i >= 0 and fechasIngreso[i] > fechaIngreso) {
        dnis[i + 1] = dnis[i];
        fechasIngreso[i + 1] = fechasIngreso[i];
        sexos[i + 1] = sexos[i];
        telefonos[i + 1] = telefonos[i];
        sueldos[i + 1] = sueldos[i];
        i--;
    }
    dnis[i + 1] = dni;
    fechasIngreso[i + 1] = fechaIngreso;
    sexos[i + 1] = sexo;
    telefonos[i + 1] = telefono;
    sueldos[i + 1] = sueldo;
    numDat++;
}

void leer_insertar_ordenado(const char *nombArch, int *dnis, int *fechasIngreso, char *sexos, int *telefonos,
                            double *sueldos, int &numDat) {
    ifstream input;
    apertura_archivo_lectura(input, nombArch);

    int dni, fechaIngreso, telefono;
    char sexo;
    double sueldo;
    //17000095 Hijar 5/07/2020 F 39827505 2001.21
    while (true) {
        input >> dni;
        if (input.eof()) break;
        ignorar(input, ' ');
        fechaIngreso = read_date(input);
        input >> sexo >> telefono >> sueldo;
        insertar_ordenado(dni, fechaIngreso, sexo, telefono, sueldo,
                          dnis, fechasIngreso, sexos, telefonos,
                          sueldos, numDat);
    }
}

void imprime_datos(int *datos, int n) {
    for (int i = 0; i < n; i++)
        cout << setw(3) << datos[i];
    cout << endl;
}

void insertion_sort(int *datos, int n) {
    // [5, 3, 4, 1, 2]
    // [5] | [3, 4, 1, 2]
    // [3, 5] | [4, 1, 2]
    // [3, 4, 5] | [1, 2]
    // [1, 3, 4, 5] | [2]
    for (int i = 1; i < n; i++) {
        int key = datos[i];       // elemento actual a insertar
        int j = i - 1;
        // cout << "KEY: " << key << endl;
        // Mover los elementos mayores que key una posición adelante
        while (j >= 0 and datos[j] > key) {
            datos[j + 1] = datos[j];
            j--;
        }
        // imprime_datos(datos, n);
        // Insertar el elemento en la posición correcta
        datos[j + 1] = key;
        // imprime_datos(datos, n);
    }
}

void selection_sort(int *datos, int n) {
    // int n_swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // asumimos que el menor está en i

        // buscar el menor en la parte desordenada
        for (int j = i + 1; j < n; j++) {
            if (datos[j] < datos[min_idx]) {
                min_idx = j;  // actualizamos índice del mínimo
            }
        }

        // intercambiar el menor encontrado con la posición i
        if (min_idx != i) {
            // n_swaps++;
            swapInt(datos[i], datos[min_idx]);
        }

    }
    // cout<<"Cantidad de swaps: "<< n_swaps<<endl;
}

void selection_sort_not_efficient(int *datos, int n) {
    //int n_swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (datos[j] < datos[i]) {
                //n_swaps++;
                swapInt(datos[i], datos[j]);
            }
        }
    }
    //cout<<"Cantidad de swaps: "<< n_swaps<<endl;
}

void bubble_sort(int *datos, int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // última i posiciones ya están en su lugar
        //¿Por qué j < n - i - 1?
        //n → tamaño total del arreglo.
        //i → número de la pasada actual (0, 1, 2, …).
        //n - i - 1 → última posición que aún no está ordenada.
        for (int j = 0; j < n - i - 1; j++) {
            if (datos[j] > datos[j + 1]) {
                // intercambiar
                swapInt(datos[j], datos[j + 1]);
                swapped = true;
            }
        }
        // si no hubo intercambios, ya está ordenado
        if (!swapped) break;
    }
}

void insert_in_order(int *arr, int value,  int &n) {

    // Find insertion position
    int i = n - 1; // [][][][][]
    // value [3]
    // Shift elements right
    // [1][2][4][5][6][6] i = 4
    // [1][2][4][5][5][6]  i = 3
    // [1][2][4][4][5][6]   i = 2
    // [1][2][4][4][5][6]    i = 1

    while (i >= 0 and arr[i] > value) { //Abrir espacios para recibir nuevos datos
        // [1][2][4][4][5][6]
        arr[i + 1] = arr[i]; //Chancar las posiciones previas
        i--;
    }
    // Insert the value
    // [1][2][4][4][5][6]    i = 1
    arr[i + 1] = value;
    // [1][2][3][4][5][6]
    n++;
}