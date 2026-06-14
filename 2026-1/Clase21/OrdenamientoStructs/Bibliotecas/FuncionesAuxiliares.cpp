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

void swap_struct(VideoJuego&a, VideoJuego&b) {
    VideoJuego aux;
    aux = a;
    a = b;
    b = aux;
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
    for (int i = 0; i < cantidad_videojuegos-1; i++) {
        for (int j = i+1; j < cantidad_videojuegos; j++) {
            if (strcmp(videojuegos[i].titulo, videojuegos[j].titulo)>0) { //Alfabeticamente o Ascendente
                swap_struct(videojuegos[i], videojuegos[j]);
            }
        }
    }
}

void imprimir_titulo(ofstream & output, const char * titulo) {
    imprimir_linea('=', ANCHO_REPORTE,output);
    output<<setw((ANCHO_REPORTE+strlen(titulo))/2)<<titulo<<endl;
    imprimir_linea('=', ANCHO_REPORTE,output);
}

void imprimir_encabezado_columna(ofstream& output, const char * encabezado) {
    output<<setw(ANCHO_REPORTE/N_COLUMNAS)<<encabezado;
}

void imprimir_encabezados(ofstream& output) {
    output<<left;
    imprimir_encabezado_columna(output, "ID");
    imprimir_encabezado_columna(output, "PRECIO");
    imprimir_encabezado_columna(output, "TITULO");
    imprimir_encabezado_columna(output, "MULTIJUGADOR?");
    imprimir_encabezado_columna(output, "CLASIFICACION");
    output<<endl;
    imprimir_linea('-',ANCHO_REPORTE,output );
}

void mostrar_videojuegos(const char* nombre_archivo,
                         const VideoJuego *videojuegos,
                         int cantidad_videojuegos) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    imprimir_titulo(output, "Reporte Videojuegos");
    imprimir_encabezados(output);
    output<<left;
    output<<fixed;
    output<<setprecision(2);
    for (int i = 0; i < cantidad_videojuegos; i++) {
        output<<setw(ANCHO_REPORTE/N_COLUMNAS)<<videojuegos[i].id;
        output<<setw(ANCHO_REPORTE/N_COLUMNAS)<<videojuegos[i].precio;
        output<<setw(ANCHO_REPORTE/N_COLUMNAS)<<videojuegos[i].titulo;
        output<<setw(ANCHO_REPORTE/N_COLUMNAS)<<(videojuegos[i].multijugador?"Si":"No");
        output<<setw(ANCHO_REPORTE/N_COLUMNAS)<<videojuegos[i].clasificacion;
        output<<endl;
    }
    imprimir_linea('-',ANCHO_REPORTE,output );
}
