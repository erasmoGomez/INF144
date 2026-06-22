//
// Created by erasmo on 6/22/26.
//

#include "FuncionesAuxiliares.hpp"

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void imprimir_linea(char ch, int width, ofstream &output) {
    output << setfill(ch) << setw(width) << "" << setfill(' ') << "\n";
}

int leer_entero(ifstream &input, bool leer_char) {
    int i;
    input >> i;
    if (leer_char) input.get();
    return i;
}

double leer_double(ifstream &input, bool leer_char) {
    double d;
    input >> d;
    if (leer_char) input.get();
    return d;
}

char *leer_cadena(ifstream &input, char delim, int n) {
    char *cadena, buffer[n];
    input.getline(buffer, n, delim);
    if (input.eof()) return nullptr;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void leer_cadena_estatica(ifstream& input, char* cadena, char delim, int n) {
    char buffer[n];
    input.getline(buffer, n, delim);
    strcpy(cadena, buffer);
}

bool leer_boolean(ifstream &input) {
    bool booleano;
    input >> std::boolalpha >> booleano;
    input.ignore();
    return booleano;
}

char leer_char(ifstream& input) {
    char c;
    input >> c;
    input.ignore();
    return c;
}

char* asignar_cadena(char* origen) {
    char* destino;
    destino = new char[strlen(origen) + 1];
    strcpy(destino, origen);
    return destino;
}
