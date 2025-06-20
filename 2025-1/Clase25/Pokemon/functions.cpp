/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Functions.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(0);
    }
}

int leer_entero(ifstream &input) {
    int i;
    input>>i;
    input.get();
    return i;
}

double leer_double(ifstream &input) {
    double d;
    input>>d;
    input.get();
    return d;
}

char* leer_cadena(ifstream& input, char delim, int n) {
    char* cadena, buffer[n];
    input.getline(buffer, n, delim);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void llenar_ataques(int index, struct MoveSet &moveset, ifstream& input_moves) {
    int index_read;
    //143,61,0
    while (true) {
        input_moves>>index_read;
        if (input_moves.eof())break;
        if (index_read == index) {
            input_moves.get(); //Leo la coma
            moveset.move_ids[moveset.n_moves] = leer_entero(input_moves);
            moveset.lvl_requirements[moveset.n_moves] = leer_entero(input_moves);
            moveset.n_moves++;
        } else {
            if (index_read > index) {
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
            } else input_moves.ignore(20, '\n');
        }

    }
}

void cargar_pokemones(struct Pokemon *&pokemones, int &n_pokemones) {
    ifstream input_pokemons;
    apertura_archivo_lectura(input_pokemons, "pokemon.csv");
    ifstream input_moves;
    apertura_archivo_lectura(input_moves, "pokemon_moves.csv");
    srand(time(NULL));
    char c, buffer[40];
    int index = 0, total, hp, atk, def, spAtk, spDef, speed, gen;
    bool legendary;
    pokemones = new struct Pokemon[200]; //Reserva Dinámica
    //3,Venusaur,Grass,Poison,525,80,82,83,100,100,80,1,False
    while (true) {
        input_pokemons >> index;
        if (index == 10) {
            cout << "holi" << endl;
        }
        if (input_pokemons.eof()) break;
        input_pokemons.get();
        pokemones[n_pokemones].name = leer_cadena(input_pokemons, ',');
        pokemones[n_pokemones].type_Primary = leer_cadena(input_pokemons, ',');
        pokemones[n_pokemones].type_Secondary = leer_cadena(input_pokemons, ',');

        input_pokemons >> total >> c >> hp >> c >> atk >> c >> def
                >> c >> spAtk >> c >> spDef >> c
                >> speed >> c >> gen >> c;
        input_pokemons.getline(buffer, 40);
        if (strcmp(buffer, "True") == 0) legendary = true;
        else legendary = false;
        pokemones[n_pokemones].isLegendary = legendary;
        pokemones[n_pokemones].pokedex_index = index;
        pokemones[n_pokemones].stats.totalStats = total;
        pokemones[n_pokemones].stats.health_points = hp;
        pokemones[n_pokemones].stats.attack = atk;
        pokemones[n_pokemones].stats.defense = def;
        pokemones[n_pokemones].stats.sp_attack = spAtk;
        pokemones[n_pokemones].stats.sp_defense = spDef;
        pokemones[n_pokemones].stats.speed = speed;
        pokemones[n_pokemones].stats.generation = gen;
        pokemones[n_pokemones].level = rand() % 100 + 1;
        //pokemones[n_pokemones].moveset = cargar_moveset();
        cout<<setw(10)<< n_pokemones<<setw(10)<<index<<"   "<<pokemones[n_pokemones].name<<endl;
        llenar_ataques(index, pokemones[n_pokemones].moveset, input_moves);
        n_pokemones++;
    }
}

void cargar_movimientos(struct Move *&movimientos, int &n_movimientos) {
    n_movimientos = 0;
    ifstream input_moveset;
    apertura_archivo_lectura(input_moveset, "move-data.csv");

    char c, buffer[600];
    int id, power, season, accuracy;
    movimientos = new Move[900];
    //93,Confusion,Psychic,Special,Clever,25,50,100,1
    while (true) {
        input_moveset >> id;
        if (input_moveset.eof()) break;
        input_moveset.get();
        movimientos[n_movimientos].id = id;
        movimientos[n_movimientos].name = leer_cadena(input_moveset, ',');
        movimientos[n_movimientos].type = leer_cadena(input_moveset, ',');
        movimientos[n_movimientos].kind = leer_cadena(input_moveset, ',');
        input_moveset.getline(buffer, 600, ','); //Contest
        movimientos[n_movimientos].powerpoints = leer_entero(input_moveset);
        movimientos[n_movimientos].power = leer_entero(input_moveset);
        movimientos[n_movimientos].accuracy = leer_entero(input_moveset);
        if (movimientos[n_movimientos].accuracy == 0)
            movimientos[n_movimientos].accuracy = 100;
        //        persona[n_personas].sexo = leer_cadena(input, ',');
        //        if(strcmp(persona[n_personas].sexo, "F")==0)
        //            persona[n_personas].sexo = asignar_cadena("FEMENINO"); 
        input_moveset >> season;
        n_movimientos++;
    }
}

int buscar_ataque(int id, struct Move* movimientos, int n_movimientos) {
    for (int i = 0; i < n_movimientos; i++)
        if (movimientos[i].id == id) return i;
    return NO_ENCONTRADO;
}

void conseguir_ataques(struct Move* ataques, struct MoveSet moveset, struct Move* movimientos, int level, int n_movimientos) {
    int j = 0;

    // Iteramos de nivel actual hacia abajo
    for (int lvl = level; lvl >= 0 and j < 4; --lvl) {
        for (int i = 0; i < moveset.n_moves; ++i) {
            if (moveset.lvl_requirements[i] <= lvl) {
                int pos = buscar_ataque(moveset.move_ids[i], movimientos, n_movimientos);
                if (pos != NO_ENCONTRADO) {
                    ataques[j++] = movimientos[pos];
                    if (j == 4) break;
                }
            }
        }
    }
}

void completar_info_pokemones(struct Pokemon *&pokemones, int n_pokemones, struct Move* movimientos, int n_movimientos) {
    //Reservar a todos 4 espacios
    for (int i = 0; i < n_pokemones; i++) {
        pokemones[i].attacks = new struct Move[4];
        if (i == 131)
            cout << i;
        conseguir_ataques(pokemones[i].attacks, pokemones[i].moveset, movimientos, pokemones[i].level, n_movimientos);
    }

}

void imprimir_reporte_pokemones(struct Pokemon *pokemones, int n_pokemones) {
    ofstream output;
    apertura_archivo_escritura(output, "reporte_pokemones_inicial.txt");
    for (int i = 0; i < n_pokemones; i++) {
        output << setw(5) << pokemones[i].pokedex_index << setw(20) << pokemones[i].name;
        output << setw(10) << pokemones[i].type_Primary << setw(10) << pokemones[i].type_Secondary;
        output << setw(5) << pokemones[i].level << endl;
                for (int j = 0; j < 4; j++)
                    output << setw(20) << pokemones[i].attacks[j].name;
        output << endl;
    }
}