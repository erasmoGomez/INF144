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

int leer_entero(ifstream &input) {
    int entero;
    input >> entero;
    input.ignore();
    return entero;
}

void linea(char ch, int width, ofstream &output) {
    output << setfill(ch) << setw(width) << "" << setfill(' ') << "\n";
}

void imprimir_header_columna(ofstream &output, const char *header, bool imprime_movimientos) {
    output << setw(ANCHO_REPORTE / (imprime_movimientos?N_COLUMNS_MOVIMIENTOS:N_COLUMNS_PRUEBA)) << header;
}

void imprimir_header(ofstream &output, int i, bool imprime_movimientos) {
    if (i > 0)linea('-', ANCHO_REPORTE, output);
    output << left;
    imprimir_header_columna(output, "Idx", imprime_movimientos);
    imprimir_header_columna(output, "Nombre", imprime_movimientos);
    imprimir_header_columna(output, "Type 1", imprime_movimientos);
    imprimir_header_columna(output, "Type 2", imprime_movimientos);
    imprimir_header_columna(output, "Level", imprime_movimientos);
    if (not imprime_movimientos) {
        imprimir_header_columna(output, "Legendary", false);
        imprimir_header_columna(output, "HP", false);
        imprimir_header_columna(output, "Atk", false);
        imprimir_header_columna(output, "Def", false);
        imprimir_header_columna(output, "SpA", false);
        imprimir_header_columna(output, "SpD", false);
        imprimir_header_columna(output, "Spe", false);
        imprimir_header_columna(output, "Total", false);
    } else {
        imprimir_header_columna(output, "Movimiento 1", true);
        imprimir_header_columna(output, "Movimiento 2", true);
        imprimir_header_columna(output, "Movimiento 3", true);
        imprimir_header_columna(output, "Movimiento 4", true);
    }

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


bool leer_boolean(ifstream &input) {
    bool booleano;
    input >> std::boolalpha >> booleano;
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

void llenar_movimientos_pokemon(int id_pokemon, MoveSet &moveset, ifstream &input_moves) {
    int id_leido = 0;
    moveset.cantidad_movimientos = 0;
    while (true) {
        input_moves >> id_leido;
        if (input_moves.eof())break;
        if (id_leido == id_pokemon) {
            input_moves.get();
            moveset.ids_movimientos[moveset.cantidad_movimientos] = leer_entero(input_moves);
            moveset.niveles_movimientos[moveset.cantidad_movimientos] = leer_entero(input_moves);
            moveset.cantidad_movimientos++;
        } else {
            if (id_leido > id_pokemon) {
                if (id_leido < 10) input_moves.unget();
                if (id_leido >= 10 and id_leido <= 99) {
                    input_moves.unget();
                    input_moves.unget();
                }
                if (id_leido > 99) {
                    input_moves.unget();
                    input_moves.unget();
                    input_moves.unget();
                }
                break;
            }
            input_moves.ignore(20, '\n');
        }
    }
}

void cargar_pokemones(const char *nombre_archivo,
                      Pokemon *&pokemones,
                      int &cantidad_pokemones) { //Dinamico
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    //Aperturar archivo pokemon_moves.csv
    ifstream input_moveset;
    apertura_archivo_lectura(input_moveset, "ArchivosDeDatos/pokemon_moves.csv");

    //RESERVAR MEMORIA
    pokemones = new Pokemon[MAX_POKEMONES]{};

    int id_pokemon = 0;

    while (true) {
        input >> id_pokemon;
        if (input.eof())break;
        input.ignore(); // input.get()
        pokemones[cantidad_pokemones].numero = id_pokemon;
        pokemones[cantidad_pokemones].nombre = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].tipo1 = leer_cadena_exacta(input, ',');
        pokemones[cantidad_pokemones].tipo2 = leer_cadena_exacta(input, ',');;
        pokemones[cantidad_pokemones].estadisticas = leer_estadisticas(input);
        pokemones[cantidad_pokemones].generacion = leer_entero(input);
        pokemones[cantidad_pokemones].es_legendario = leer_boolean(input);
        pokemones[cantidad_pokemones].nivel = rand() % 100 + 1; //Genera un numero aleatorio entre 1 y 100
        llenar_movimientos_pokemon(id_pokemon, pokemones[cantidad_pokemones].movimientos_disponibles,
                                   input_moveset);
        ordenar_movimientos_disponibles(pokemones[cantidad_pokemones].movimientos_disponibles);

        cantidad_pokemones++;
    }
}

void imprime_pokemon(ofstream &output, struct Pokemon &p, bool imprime_movimientos) {
    output << setw(ANCHO_REPORTE / (imprime_movimientos?N_COLUMNS_MOVIMIENTOS:N_COLUMNS_PRUEBA)) << p.numero
            << setw(ANCHO_REPORTE / (imprime_movimientos?N_COLUMNS_MOVIMIENTOS:N_COLUMNS_PRUEBA)) << safe(p.nombre)
            << setw(ANCHO_REPORTE / (imprime_movimientos?N_COLUMNS_MOVIMIENTOS:N_COLUMNS_PRUEBA)) << safe(p.tipo1)
            << setw(ANCHO_REPORTE / (imprime_movimientos?N_COLUMNS_MOVIMIENTOS:N_COLUMNS_PRUEBA)) << safe(p.tipo2)
            << setw(ANCHO_REPORTE / (imprime_movimientos?N_COLUMNS_MOVIMIENTOS:N_COLUMNS_PRUEBA)) << p.nivel;
    if (not imprime_movimientos) {
        output << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << (p.es_legendario ? "Si" : "No")
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.hp
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.ataque
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.defensa
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.ataque_especial
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.defensa_special
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.velocidad
            << setw(ANCHO_REPORTE / N_COLUMNS_PRUEBA) << p.estadisticas.total
            << left << "\n";
    }

}

void generar_reporte_prueba(const char *file_name,
                            struct Pokemon *pokemones,
                            int n_pokemones) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    imprimir_titulo(output);
    for (int i = 0; i < n_pokemones; i++) {
        if (i % 25 == 0) imprimir_header(output, i, false);
        imprime_pokemon(output, pokemones[i], false);
    }
}

void leer_pokemon(struct Pokemon &p, ifstream &input, int numero_pokemon) {
    p.numero = numero_pokemon;
    p.nombre = leer_cadena_exacta(input, ',');
    p.tipo1 = leer_cadena_exacta(input, ',');
    p.tipo2 = leer_cadena_exacta(input, ',');;
    p.estadisticas = leer_estadisticas(input);
    p.generacion = leer_entero(input);
    p.nivel = rand() % 100 + 1; //Genera un numero aleatorio entre 1 y 100
    p.es_legendario = leer_boolean(input);
}

void swap_int(int &a, int &b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}


void ordenar_movimientos_disponibles(MoveSet &moveset) {
    for (int i = 0; i < moveset.cantidad_movimientos - 1; i++)
        for (int j = i + 1; j < moveset.cantidad_movimientos; j++)
            if (moveset.niveles_movimientos[i] < moveset.niveles_movimientos[j]) {
                swap_int(moveset.niveles_movimientos[i], moveset.niveles_movimientos[j]);
                swap_int(moveset.ids_movimientos[i], moveset.ids_movimientos[j]);
            }
}

void imprimir_reporte_pokemones(Pokemon *pokemones, int cantidad_pokemones) {
    ofstream output;
    apertura_archivo_escritura(output, "ArchivosDeReporte/reporte_pokemones_inicial.txt");
    imprimir_titulo(output);
    for (int i = 0; i < cantidad_pokemones; i++) {
        if (i % 25 == 0) imprimir_header(output, i, true);
        imprime_pokemon(output, pokemones[i], true);
        if (pokemones[i].movimientos_activados)
            for (int j = 0; j < 4; j++)
                output << setw(ANCHO_REPORTE/N_COLUMNS_MOVIMIENTOS) << pokemones[i].movimientos_activados[j].nombre;
        output << endl;
    }
}

void cargar_pokemones_estatico(const char *nombre_archivo,
                               Pokemon *pokemones,
                               int &cantidad_pokemones_estatico) { //Estatico
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    //Aperturar archivo pokemon_moves.csv
    ifstream input_moveset;
    apertura_archivo_lectura(input_moveset, "ArchivosDeDatos/pokemon_moves.csv");

    //Sembrar la semilla
    srand(time(nullptr));

    int id_pokemon = 0;
    while (true) {
        input >> id_pokemon;
        if (input.eof())break;
        input.ignore(); // input.get()
        leer_pokemon(pokemones[cantidad_pokemones_estatico], input, id_pokemon);
        llenar_movimientos_pokemon(id_pokemon, pokemones[cantidad_pokemones_estatico].movimientos_disponibles,
                                   input_moveset);
        ordenar_movimientos_disponibles(pokemones[cantidad_pokemones_estatico].movimientos_disponibles);
        cantidad_pokemones_estatico++;
    }
}

void leer_movimiento(struct Movimiento &m,
                     ifstream &input,
                     int id) {
    //720,Mind Blown,Fire,Special,???,5,150,100,7
    char buffer[30];
    m.id = id;
    m.nombre = leer_cadena_exacta(input, ',');
    m.tipo = leer_cadena_exacta(input, ',');
    m.categoria = leer_cadena_exacta(input, ',');
    input.getline(buffer, 30, ',');
    m.pp = leer_entero(input);
    m.poder = leer_entero(input);
    m.precision = leer_entero(input);
    if (m.precision == 0) m.precision = 100;
    m.generacion = leer_entero(input);
}

void cargar_movimientos(const char *nombre_archivo,
                        Movimiento *&movimientos,
                        int &n_movimientos) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    movimientos = new Movimiento[MAX_MOVIMIENTOS]{};
    //720,Mind Blown,Fire,Special,???,5,150,100,7
    int id = 0;
    while (true) {
        input >> id;
        if (input.eof())break;
        input.ignore(); //Ignoramos la coma input.get()
        leer_movimiento(movimientos[n_movimientos], input, id);
        n_movimientos++;
    }
}

int buscar_movimiento(int id, Movimiento *movimientos, int n_movimientos) {
    for (int i = 0; i < n_movimientos; i++)
        if (movimientos[i].id == id) return i;
    return NO_ENCONTRADO;
}

void conseguir_llenar_movimientos(Pokemon &p,
                                  Movimiento *movimientos,
                                  int n_movimientos) {
    int cantidad_movimientos = 0;
    for (int nivel = p.nivel; (nivel >= 0 and cantidad_movimientos < 4); --nivel) {
        for (int i = 0; i < p.movimientos_disponibles.cantidad_movimientos; i++) {
            if (p.movimientos_disponibles.niveles_movimientos[i] <= nivel) {
                int pos = buscar_movimiento(p.movimientos_disponibles.ids_movimientos[i], movimientos, n_movimientos);
                if (pos != NO_ENCONTRADO) {
                    p.movimientos_activados[cantidad_movimientos] = movimientos[pos];
                    cantidad_movimientos++;
                    if (cantidad_movimientos == 4) break;
                }
            }
        }
    }
}

void completar_info_pokemones(Pokemon *&pokemones,
                              int cantidad_pokemones,
                              Movimiento *movimientos,
                              int n_movimientos) {
    // Reservar Memoria a todos los pokemones pero con 4 espacios
    // movimientos_activados
    for (int i = 0; i < cantidad_pokemones; i++) {
        pokemones[i].movimientos_activados = new struct Movimiento[4];
        // conseguir_llenar_movimientos(pokemones[i].movimientos_activados,
        //                              pokemones[i].movimientos_disponibles,
        //                              movimientos,
        //                              pokemones[i].nivel,
        //                              n_movimientos);
        conseguir_llenar_movimientos(pokemones[i],
                                     movimientos,
                                     n_movimientos);
    }
}
