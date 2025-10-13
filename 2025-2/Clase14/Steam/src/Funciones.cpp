//
// Created by Erasmo on 4/10/25.
//

#include "Funciones.hpp"

int buscar_pos(int* codigos_logros, int codigo_logro, int n_logros){
    for(int i=0; i<n_logros; i++)
        if(codigos_logros[i]==codigo_logro) return i;
    return -1;
}

void cargar_logros_juegos(const char *file_name, char *codigos_char_juegos_logros, int *codigos_int_juegos_logros,
                          int *codigos_logros_juegos_logros, int *cantidad_juegos_logros, int *codigos_logros,
                          int &n_logros_juegos, int n_logros) {
    ifstream input;
    open_file_read(input, file_name);
    //G4812   501201
    char codigo_char_juego;
    int codigo_int_juego, codigo_logro, pos;
    while(true){
        input>>codigo_char_juego;
        if(input.eof())break;
        input>>codigo_int_juego;
        input>>codigo_logro;
        codigos_char_juegos_logros[n_logros_juegos] = codigo_char_juego;
        codigos_int_juegos_logros[n_logros_juegos] = codigo_int_juego;
        codigos_logros_juegos_logros[n_logros_juegos] = codigo_logro;

        pos = buscar_pos(codigos_logros, codigo_logro, n_logros);
        if(pos!=-1)
            cantidad_juegos_logros[pos] = cantidad_juegos_logros[pos] + 1 ;
        else
            cout<<"NO se ha encontrado el codigo del logro"<<endl;

    }
}

void swapInt(int &dato_k, int &dato_i){
    int aux;
    aux = dato_k;
    dato_k = dato_i;
    dato_i = aux;
}

void swapDouble(double &dato_k, double &dato_i){
    double aux;
    aux = dato_k;
    dato_k = dato_i;
    dato_i = aux;
}

void ordenar_arreglos_logros(int * codigos_logros, double* tiempos_logros, int* cantidad_juegos_logros, int n_logros){
    for(int i=0; i<n_logros-1; i++)
        for(int k=i+1; k<n_logros; k++)
            if(tiempos_logros[k]< tiempos_logros[i]){
                //intercarmbios
                swapInt(codigos_logros[k], codigos_logros[i]);
                swapDouble(tiempos_logros[k], tiempos_logros[i]);
                swapInt(cantidad_juegos_logros[k], cantidad_juegos_logros[i]);
            }
}

int buscar_codigo(int* codigos_no_repetidos, int codigo, int cantidad_codigos_no_repetidos){
    for(int i=0; i<cantidad_codigos_no_repetidos;i++)
        if(codigos_no_repetidos[i]==codigo) return i;
    return -1; // NO ENCONTRE EL CODIGO EN EL ARREGLO
}

void cargar_codigos_frecuencia(const char* file_name,
                               int* codigos_no_repetidos,
                               int* frecuencias,
                               int& cantidad_codigos_no_repetidos){
    ifstream input;
    open_file_read(input, file_name);
    int codigo, codigo_juego, pos;
    while(true){
        input>>codigo;
        if(input.eof())break;
        input>>codigo_juego;
        pos = buscar_codigo(codigos_no_repetidos, codigo, cantidad_codigos_no_repetidos);
        if( pos != -1){ //SI ENCONTRE
            // Aqui ya existe en el arreglo el dato, por lo tanto NO voy a insertar
            // Solamente actualizo mis acumuladores
            // codigos_no_repetidos[pos] = codigo;
            frecuencias[pos]++;
        }
        else{ // NO ENCONTRE
            // Aqui no existe el elemento en el arreglo, por lo tanto SI voy a insertar
            codigos_no_repetidos[cantidad_codigos_no_repetidos] = codigo;
            frecuencias[cantidad_codigos_no_repetidos]++;
            cantidad_codigos_no_repetidos++;
        }
    }
}