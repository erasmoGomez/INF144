//
// Created by erasmo on 6/4/26.
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

void imprimir_linea(ofstream &output, char c) {
    for (int i = 0; i < ANCHO_REPORTE; i++)
        output.put(c);
    output << endl;
}

void impresion_titulo(ofstream &output, const char *titulo) {
    output << setw((ANCHO_REPORTE + strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

char *leer_cadena(ifstream &input, char del) {
    char buffer[MAX_TAM_CADENA], *cadena;
    input.getline(buffer, MAX_TAM_CADENA, del);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

int leer_entero(ifstream &input) {
    int dato;
    input >> dato;
    input.get(); //Leer la coma
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get();
    input.get(); //Solo para el profe x q usa MAC
    return dato;
}

void lectura_arch_canciones_csv(char **artistas,
                                char **titulos,
                                int *reproducciones,
                                char **generos,
                                double *bailables,
                                int &n_canciones,
                                const char *nombre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //Tyga,Taste,232959,hiphop-pop,0.884
    char *artista;
    while (true) {
        //Sisqo,Thong_Song,253733,hiphop-pop-R&B,0.706
        artista = leer_cadena(input, ',');
        if (input.eof()) {
            delete artista;
            break;
        }
        titulos[n_canciones] = leer_cadena(input, ',');
        reproducciones[n_canciones] = leer_entero(input);
        generos[n_canciones] = leer_cadena(input, ',');
        bailables[n_canciones] = leer_double(input);
        artistas[n_canciones] = artista;
        n_canciones++;
    }
}

void impresion_canciones(char **artistas,
                         char **titulos,
                         int *reproducciones,
                         char **generos,
                         double *bailables,
                         int n_canciones,
                         const char *nombre_archivo) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    for (int i = 0; i<n_canciones; i++) {
        output<<setw(ANCHO_REPORTE/5)<<artistas[i];
        output<<setw(ANCHO_REPORTE/5)<<titulos[i];
        output<<setw(ANCHO_REPORTE/5)<<reproducciones[i];
        output<<setw(ANCHO_REPORTE/5)<<generos[i];
        output<<setw(ANCHO_REPORTE/5)<<bailables[i];
        output<<endl;
    }
}
