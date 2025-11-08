//
// Created by Erasmo on 8/11/25.
//

#include "Funciones.hpp"

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

void linea(char ch, int width, ofstream &output) {
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

void cargar_pokemones(const char *file_name, Pokemon *&pokemones, int &n_pokemones) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    srand(time(nullptr));
    pokemones = new struct Pokemon[MAX_POKEMONES];
    //25,Pikachu,Electric,,320,35,55,40,50,50,90,1,False
    int indice;
    char buffer[20];
    while (true) {
        input >> indice;
        if (input.eof())break;
        input.get();//La coma;
        pokemones[n_pokemones].pokemon_index = indice;
        pokemones[n_pokemones].nombre = leer_cadena(input, ',', 20);
        pokemones[n_pokemones].tipo_1 = leer_cadena(input, ',', 20);
        pokemones[n_pokemones].tipo_2 = leer_cadena(input, ',', 20);
        pokemones[n_pokemones].stadisticas.total_stats = leer_entero(input);
        pokemones[n_pokemones].stadisticas.hp = leer_entero(input);
        pokemones[n_pokemones].stadisticas.ataque = leer_entero(input);
        pokemones[n_pokemones].stadisticas.defensa = leer_entero(input);
        pokemones[n_pokemones].stadisticas.ataque_special = leer_entero(input);
        pokemones[n_pokemones].stadisticas.defensa_special = leer_entero(input);
        pokemones[n_pokemones].stadisticas.velocidad = leer_entero(input);
        pokemones[n_pokemones].stadisticas.generation = leer_entero(input);
        pokemones[n_pokemones].nivel = rand() % 100 + 1; //Genera un numero aleatorio entre 1 y 100
        input.getline(buffer, 20, '\n');
        pokemones[n_pokemones]._es_legendario = (strcmp(buffer, "True") == 0);
        //pokemones[n_pokemones]._es_legendario = (strcasecmp(buffer, "true") == 0); //para compara con True o TRUE o true
        n_pokemones++;
    }
}

void imprimir_header_columna(ofstream &output, const char *header) {
    output << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << header;
}

void imprimir_header(ofstream &output, int i = 0) {
    if (i > 0)linea('-', ANCHO_REPORTE, output);
    output << left;
    imprimir_header_columna(output, "Idx");
    imprimir_header_columna(output, "Nombre");
    imprimir_header_columna(output, "Type 1");
    imprimir_header_columna(output, "Type 2");
    imprimir_header_columna(output, "Level");
    imprimir_header_columna(output, "Legendary");
    imprimir_header_columna(output, "HP");
    imprimir_header_columna(output, "Atk");
    imprimir_header_columna(output, "Def");
    imprimir_header_columna(output, "SpA");
    imprimir_header_columna(output, "SpD");
    imprimir_header_columna(output, "Spe");
    imprimir_header_columna(output, "Total");
    output << left << "\n";
    linea('-', ANCHO_REPORTE, output);
}

void imprimir_titulo(ofstream &output) {
    linea('=', ANCHO_REPORTE, output);
    output << right << setw(ANCHO_REPORTE / 2) << "REPORTE POKÉMON" << "\n";
    linea('=', ANCHO_REPORTE, output);
}

const char *safe(const char *s, const char *fallback = "N/A") {
    return (s && s[0] != '\0') ? s : fallback;
}

void imprime_pokemon(ofstream &output, struct Pokemon &p) {
    output << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.pokemon_index
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << safe(p.nombre)
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << safe(p.tipo_1)
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << safe(p.tipo_2)
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.nivel
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << (p._es_legendario ? "Si" : "No")
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.hp
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.ataque
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.defensa
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.ataque_special
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.defensa_special
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.velocidad
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.stadisticas.total_stats
           << left << "\n";
}

void generar_reporte_prueba(const char *file_name, struct Pokemon *pokemones, int n_pokemones) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    imprimir_titulo(output);
    //imprimir_header(output);
    for (int i = 0; i < n_pokemones; i++) {
        if (i % 25 == 0) imprimir_header(output, i);
        imprime_pokemon(output, pokemones[i]);
    }
}