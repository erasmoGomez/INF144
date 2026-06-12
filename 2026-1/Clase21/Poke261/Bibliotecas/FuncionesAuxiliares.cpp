//
// Created by erasmo on 6/11/26.
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

int leer_entero(ifstream& input) {
    int entero;
    input>>entero;
    input.ignore();
    return entero;
}

void linea(char ch, int width, ofstream &output) {
    output << setfill(ch) << setw(width) << "" << setfill(' ') << "\n";
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
    output << right << setw(ANCHO_REPORTE / 2) << "REPORTE POKEMON" << "\n";
    linea('=', ANCHO_REPORTE, output);
}

const char *safe(const char *s, const char *fallback = "N/A") {
    return (s && s[0] != '\0') ? s : fallback;
}


bool leer_boolean(ifstream& input) {
    bool booleano;
    input>>std::boolalpha>>booleano;
    input.ignore();
    return booleano;
}

char *leer_cadena_exacta(ifstream &input, char delim) {
    char *str, buffer[30];
    input.getline(buffer, 30, delim);
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

Estadisticas leer_estadisticas(ifstream &input) {
    Estadisticas stats;
    input >> stats.total;
    input.ignore();
    input >> stats.hp;
    input.ignore();
    input >> stats.ataque;
    input.ignore();
    input >> stats.defensa;
    input.ignore();
    input >> stats.ataque_especial;
    input.ignore();
    input >> stats.defensa_special;
    input.ignore();
    input >> stats.velocidad;
    input.ignore();
    return stats;
}

void cargar_pokemones(const char *nombre_archivo,
                    Pokemon *&pokemones,
                    int &cantidad_pokemones) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    pokemones = new Pokemon[160]{};
    int numero_pokemon = 0;

    while (true) {
        input >> numero_pokemon;
        if (input.eof())break;
        input.ignore(); // input.get()
        pokemones[cantidad_pokemones].numero = numero_pokemon;
        pokemones[cantidad_pokemones].nombre = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].tipo1 = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].tipo2 = leer_cadena_exacta(input, ',');;
        pokemones[cantidad_pokemones].estadisticas = leer_estadisticas(input);
        pokemones[cantidad_pokemones].generacion = leer_entero(input);
        pokemones[cantidad_pokemones].es_legendario = leer_boolean(input);
        cantidad_pokemones++;
    }
}

void imprime_pokemon(ofstream &output, struct Pokemon &p) {
    output << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.numero
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << safe(p.nombre)
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << safe(p.tipo1)
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << safe(p.tipo2)
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << 1
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << (p.es_legendario ? "Si" : "No")
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.hp
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.ataque
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.defensa
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.ataque_especial
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.defensa_special
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.velocidad
           << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.total
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

void cargar_pokemones_estatico(const char* nombre_archivo,
                                Pokemon* pokemones,
                                int &cantidad_pokemones_estatico) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    int numero_pokemon = 0;
    while (true) {
        input >> numero_pokemon;
        if (input.eof())break;
        input.ignore(); // input.get()
        pokemones[cantidad_pokemones_estatico].numero = numero_pokemon;
        pokemones[cantidad_pokemones_estatico].nombre = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones_estatico].tipo1 = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones_estatico].tipo2 = leer_cadena_exacta(input, ',');;
        pokemones[cantidad_pokemones_estatico].estadisticas = leer_estadisticas(input);
        pokemones[cantidad_pokemones_estatico].generacion = leer_entero(input);
        pokemones[cantidad_pokemones_estatico].es_legendario = leer_boolean(input);
        cantidad_pokemones_estatico++;
    }
}