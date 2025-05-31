/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 29, 2025, 4:41 PM
 */

#include "Funciones.hpp"

int my_strchr(const char* str, char c) {
    for (int i = 0; str[i]; i++)
        if (str[i] == c)return i;
    return -1;
}

void remove_up_to(char* str, int pos) {
    int i = pos, j = 0;
    while (str[i] != '\0') {
        str[j] = str[i];
        i++;
        j++;
    }
    str[j] = '\0';
}

int my_strlen(const char* str) {
    int len;
    for (len = 0; str[len]; len++);
    return len;
}

void my_strcpy(char* destination, const char *source) {
    int i = 0;
    while (true) {
        destination[i] = source[i];
        if (not source[i]) break;
        i++;
    }
}

void my_strcat(char* str1, const char* str2) {
    int pos = my_strlen(str1);
    my_strcpy(&str1[pos], str2);
}

int my_strcmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' and b[i] != '\0') {
        if (a[i] != b[i]) return a[i] - b[i];
        i++;
    }
    return a[i] - b[i]; // Si una terminó antes
}

void prepend(char*origin, const char* add) {
    //int new_len = strlen(origin)+strlen(add);
    char aux[100]{};
    my_strcpy(aux, add);
    my_strcat(aux, origin);
    my_strcpy(origin, aux);
}

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

void camelizar(char* nombre) {
    int i;
    for (i = 0; nombre[i]; i++) {
        if (nombre[i] == '_') nombre[i] = ' ';
        if (i > 0 and nombre[i - 1] != ' ' and nombre[i] >= 'A' and nombre[i] <= 'Z') {
            nombre[i] += 'a' - 'A';
        }
    }
    nombre[i] = 0;
}

void imprimir_linea(ofstream &output, char c) {
    for (int i = 0; i < ANCHO_REPORTE; i++)
        output.put(c);
    output << endl;
}

void intercambiar_int(int& a, int& b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiar_double(double& a, double& b) {
    double aux;
    aux = a;
    a = b;
    b = aux;
}

void ordenar_seguidores(int *seguidores, double* engagements, int n_tiktokers) {
    for (int i = 0; i < n_tiktokers - 1; i++)
        for (int j = i + 1; j < n_tiktokers; j++)
            if (seguidores[i] > seguidores[j]) {
                intercambiar_int(seguidores[i], seguidores[j]);
                intercambiar_double(engagements[i], engagements[j]);
            }
}

void impresion_titulo(ofstream& output, const char*titulo) {
    output << setw((ANCHO_REPORTE + my_strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

void leer_archivo_imprimir_tiktokers(const char*nombre_archivo,
        int*arr_seguidores, double* engagements,
        int&n_tiktokers) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    ofstream output;
    apertura_archivo_escritura(output, "reporte.txt");

    char usuario[MAX_CADENA]{}, nombre[MAX_CADENA]{};
    int seguidores;
    double engagement;
    //dream_102	CLAY_SANDERSON	26	6.43
    impresion_titulo(output, "Lista de Influencers");
    while (true) {
        input>>usuario;
        if (input.eof())break;
        input >> nombre >> seguidores>>engagement;
        arr_seguidores[n_tiktokers] = seguidores;
        engagements[n_tiktokers] = engagement;
        prepend(usuario, "@");
        camelizar(nombre);
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << usuario;
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << nombre;
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << seguidores;
        output << setw(ANCHO_REPORTE / N_COLUMNAS) << engagement << endl;
        n_tiktokers++;
    }
}

int busqueda_binaria(int* arr, int n, int solicitado) {
    int lim_inf, lim_sup, punto_medio;
    lim_inf = 0;
    lim_sup = n - 1;

    while (true) {
        if (lim_inf > lim_sup) return NO_ENCONTRADO;
        punto_medio = (lim_inf + lim_sup) / 2;
        if (solicitado == arr[punto_medio]) return punto_medio;
        if (solicitado < arr[punto_medio])
            lim_sup = punto_medio - 1;
        else
            lim_inf = punto_medio + 1;
    }
}

int contar_tokens(const char* cadena) {
    if (cadena[0] == '\0') return 0;

    int i = 0, count = 1; // empezamos en 1 porque hay al menos un token si la cadena no está vacía

    while (cadena[i] != '\0') {
        if (cadena[i] == '/') count++;
        i++;
    }

    return count;
}

int buscar_inicio_token(const char* tokens, int n) {
    if (n < 1) return -1;

    int current = 1;
    for (int i = 0; tokens[i]; i++) {
        if (current == n) return i;
        if (tokens[i] == '/') current++;
    }

    return -1; // No se encontró el token
}

int buscar_fin_token(const char* tokens, int start) {
    int i = start;
    while (tokens[i] != '/' and tokens[i] != '\0') i++;
    return i;
}

void copiar_token(const char* origen, int inicio, int fin, char* destino) {
    int j = 0;
    for (int i = inicio; i < fin; i++)
        destino[j++] = origen[i];
    destino[j] = '\0';
}

void sacar_token(const char* tokens, int n, char* token) {
    int start = buscar_inicio_token(tokens, n);
    if (start == -1) return;
    int end = buscar_fin_token(tokens, start);
    copiar_token(tokens, start, end, token);
}

bool existe_token(const char* tokens, const char* token) {
    int total = contar_tokens(tokens);
    char temporal[100];

    for (int i = 1; i <= total; i++) {
        sacar_token(tokens, i, temporal);
        if (my_strcmp(temporal, token) == 0) return true;
    }
    return false;
}

void agregar_token(char* tokens, const char* token) {
    if (existe_token(tokens, token)) return;
    my_strcat(tokens, "/");
    my_strcat(tokens, token);
}

void imprimir_tokens(const char*tokens) {
    char token[10];
    for (int i = 0; i < contar_tokens(tokens); i++) {
        sacar_token(tokens, i + 1, token);
        cout << token << endl;
    }
}

char to_upper(char c) {
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}

void convertir_a_mayusculas(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = to_upper(str[i]);
        i++;
    }
}

void copiar_hasta(char* dest, const char* src, char delimitador) {
    int i = 0;
    while (src[i] != '\0' && src[i] != delimitador) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void copiar_desde(char* dest, const char* src, char delimitador) {
    int i = 0, j = 0;

    while (src[i] != '\0' && src[i] != delimitador) i++;
    if (src[i] == delimitador) i++; // saltar el delimitador

    while (src[i] != '\0') {
        dest[j++] = src[i++];
    }
    dest[j] = '\0';
}

void my_strcpy_upper(char* dest, const char* src) {
    my_strcpy(dest, src);
    //convertir_a_mayusculas(dest);
}

void my_strcat_upper(char* dest, const char* src) {
    int len = my_strlen(dest);
    my_strcpy(dest + len, src);
    //convertir_a_mayusculas(dest + len);
}

void modificaTexto(char* nombre_completo, const char* apellido_materno) {
    char apellido_paterno[50];
    char nombres[50];
    char resultado[150];
    
    copiar_hasta(apellido_paterno, nombre_completo, '_');
    copiar_desde(nombres, nombre_completo, '_');

    resultado[0] = '\0'; // inicializar cadena vacía

    my_strcpy(resultado, apellido_paterno);
    my_strcat(resultado, " ");
    my_strcat(resultado, apellido_materno);
    my_strcat(resultado, " ");
    my_strcat(resultado, nombres);
    convertir_a_mayusculas(resultado);
    my_strcpy(nombre_completo, resultado);
}

