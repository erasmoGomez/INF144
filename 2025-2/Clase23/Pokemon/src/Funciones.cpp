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

void leer_pokemon(struct Pokemon &p, ifstream& input, int indice){
    char buffer[20];
    p.pokemon_index = indice;
    p.nombre = leer_cadena(input, ',', 20);
    p.tipo_1 = leer_cadena(input, ',', 20);
    p.tipo_2 = leer_cadena(input, ',', 20);
    p.stadisticas.total_stats = leer_entero(input);
    p.stadisticas.hp = leer_entero(input);
    p.stadisticas.ataque = leer_entero(input);
    p.stadisticas.defensa = leer_entero(input);
    p.stadisticas.ataque_special = leer_entero(input);
    p.stadisticas.defensa_special = leer_entero(input);
    p.stadisticas.velocidad = leer_entero(input);
    p.stadisticas.generation = leer_entero(input);
    p.nivel = rand() % 100 + 1; //Genera un numero aleatorio entre 1 y 100
    input.getline(buffer, 20, '\n');
    p._es_legendario = (strcmp(buffer, "True") == 0);
}

void llenar_ataques(int index, struct MoveSet &moveset, ifstream& input_moves){
    int index_read;
    //143, 61, 0
    moveset.cantidad_movimientos = 0;
    while(true){
        input_moves>>index_read;
        if(input_moves.eof())break;
        if(index_read == index){
            input_moves.get();
            moveset.ids_movimiento[moveset.cantidad_movimientos] = leer_entero(input_moves);
            moveset.niveles_movimento[moveset.cantidad_movimientos] = leer_entero(input_moves);
            moveset.cantidad_movimientos++;
        } else{
            if(index_read>index){
                if(index_read<10) input_moves.unget();
                if(index_read>=10 and index_read<=99){
                    input_moves.unget();
                    input_moves.unget();
                }
                if(index_read>99){
                    input_moves.unget();
                    input_moves.unget();
                    input_moves.unget();
                }
                break;
            }else input_moves.ignore(20, '\n');
        }
    }
}

void cargar_pokemones(const char *file_name, Pokemon *&pokemones, int &n_pokemones) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    ifstream input_moveset;
    apertura_archivo_lectura(input_moveset, "Data/pokemon_moves.csv");
    //Sembrar la semilla
    srand(time(nullptr));
    //Reserva de Memoria para arreglo dinámico
    pokemones = new struct Pokemon[MAX_POKEMONES];
    //25,Pikachu,Electric,,320,35,55,40,50,50,90,1,False
    int indice;
    char buffer[20];
    while (true) {
        input >> indice;
        if (input.eof())break;
        input.get();//La coma;
        // rand() -> [0 - 1000000] % 100 -> [0 - 99] + 1 -> [1 - 100]
//        pokemones[n_pokemones].pokemon_index = indice;
//        pokemones[n_pokemones].nombre = leer_cadena(input, ',', 20);
//        pokemones[n_pokemones].tipo_1 = leer_cadena(input, ',', 20);
//        pokemones[n_pokemones].tipo_2 = leer_cadena(input, ',', 20);
//        pokemones[n_pokemones].stadisticas.total_stats = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.hp = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.ataque = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.defensa = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.ataque_special = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.defensa_special = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.velocidad = leer_entero(input);
//        pokemones[n_pokemones].stadisticas.generation = leer_entero(input);
//        pokemones[n_pokemones].nivel = rand() % 100 + 1; //Genera un numero aleatorio entre 1 y 100
//        input.getline(buffer, 20, '\n');
//        pokemones[n_pokemones]._es_legendario = (strcmp(buffer, "True") == 0);
        leer_pokemon(pokemones[n_pokemones], input, indice);
        //pokemones[n_pokemones]._es_legendario = (strcasecmp(buffer, "true") == 0); //para compara con True o TRUE o true
        llenar_ataques(indice, pokemones[n_pokemones].moveset, input_moveset);
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

void cargar_movimientos(const char *file_name, struct Movimiento *&movimientos, int &n_movimientos) {

    //93,Confusion,Psychic,Special,Clever,25,50,100,1
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    movimientos = new struct Movimiento[750];
    char buffer[30];
    int id;
    while(true){
        input>>id;
        if(input.eof())break;
        input.get(); // Lee la coma
        movimientos[n_movimientos].id = id;
        movimientos[n_movimientos].nombre = leer_cadena(input, ',', 30);
        movimientos[n_movimientos].tipo = leer_cadena(input, ',', 30);
        movimientos[n_movimientos].categoria = leer_cadena(input, ',', 30);
        input.getline(buffer, 30, ','); //Ignorar contest
        movimientos[n_movimientos].pp = leer_entero(input);
        movimientos[n_movimientos].poder = leer_entero(input);
        movimientos[n_movimientos].precision = leer_entero(input);
        if(movimientos[n_movimientos].precision == 0)
            movimientos[n_movimientos].precision = 100;
        movimientos[n_movimientos].generacion = leer_entero(input);
        n_movimientos++;
    }
}

int buscar_ataque(int id, struct Movimiento* movimientos, int n_movimientos) {
    for (int i = 0; i < n_movimientos; i++)
        if (movimientos[i].id == id) return i;
    return NO_ENCONTRADO;
}

void conseguir_ataques(struct Movimiento* ataques, struct MoveSet moveset, struct Movimiento* movimientos, int level, int n_movimientos) {
    int j = 0;

    // Iteramos de nivel actual hacia abajo
    for (int lvl = level; lvl >= 0 and j < 4; --lvl) {
        for (int i = 0; i < moveset.cantidad_movimientos; ++i) {
            if (moveset.niveles_movimento[i] <= lvl) {
                int pos = buscar_ataque(moveset.ids_movimiento[i], movimientos, n_movimientos);
                if (pos != NO_ENCONTRADO) {
                    ataques[j] = movimientos[pos];
                    j++;
                    if (j == 4) break;
                }
            }
        }
    }
}

void completar_info_pokemones(Pokemon *&pokemones, int n_pokemones, struct Movimiento *movimientos, int n_movimientos) {
    //Reservar a todos 4 espacios
    for (int i = 0; i < n_pokemones; i++) {
        pokemones[i].ataques = new struct Movimiento[4];
        conseguir_ataques(pokemones[i].ataques, pokemones[i].moveset, movimientos, pokemones[i].nivel, n_movimientos);
    }
}

void imprimir_reporte_pokemones(struct Pokemon *pokemones, int n_pokemones) {
    ofstream output;
    apertura_archivo_escritura(output, "Reports/reporte_pokemones_inicial.txt");
    for (int i = 0; i < n_pokemones; i++) {
        output << setw(5) << pokemones[i].pokemon_index << setw(20) << pokemones[i].nombre;
        output << setw(10) << pokemones[i].tipo_1 << setw(10) << pokemones[i].tipo_2;
        output << setw(5) << pokemones[i].nivel << endl;
        for (int j = 0; j < 4; j++)
            output << setw(20) << pokemones[i].ataques[j].nombre;
        output << endl;
    }
}