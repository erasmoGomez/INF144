//
// Created by erasmo on 6/13/26.
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

int leer_entero(ifstream &input) {
    int i;
    input >> i;
    input.get(); //La coma
    return i;
}

double leer_double(ifstream &input) {
    double d;
    input >> d;
    input.get();
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

void cargar_videojuegos(const char *nombre_archivo,
                        VideoJuego *videojuegos,
                        int &cantidad_videojuegos) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    int id;
    while (true) {
        input>>id;
        if (input.eof()) break;
        input.ignore();
        videojuegos[cantidad_videojuegos].id = id;
        videojuegos[cantidad_videojuegos].precio = leer_double(input);
        videojuegos[cantidad_videojuegos].titulo = leer_cadena(input, ',', 30);
        videojuegos[cantidad_videojuegos].multijugador = leer_boolean(input);
        videojuegos[cantidad_videojuegos].clasificacion = leer_char(input);
        cantidad_videojuegos++;
    }
}

void ordenar_videojuegos(VideoJuego *videojuegos,
                         int cantidad_videojuegos) {
}

void mostrar_videojuegos(const VideoJuego *videojuegos,
                         int cantidad_videojuegos) {
}
