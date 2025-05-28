/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 28, 2025, 3:50 PM
 */

#include "Funciones.hpp"
void cambiar_cadena(char *nombre) {
    int ini, pos = 0;
    for (int i = 0; nombre[i]; i++) {
        if (nombre[i] == '_') nombre[i] = ' ';
        if (i > 0 and nombre[i - 1] != ' ' and nombre[i] >= 'A' and nombre[i] <= 'Z') {
            nombre[i] += 'a' - 'A';
        }
    }
    for (ini = 0; nombre[ini] != ' '; ini++);
    ini++;
    for (pos = ini; nombre[pos] != ' '; pos++);
    pos++;
    for (; nombre[pos]; pos++, ini++) {
        nombre[ini] = nombre[pos];
    }
    nombre[ini] = 0;
}

void cambiar_nombre(char *nombre) {
    int i;
    for (i = 0; nombre[i]; i++) {
        if (nombre[i] == '_') nombre[i] = ' ';
        if (i > 0 and nombre[i - 1] != ' ' and nombre[i] >= 'A' and nombre[i] <= 'Z') {
            nombre[i] += 'a' - 'A';
        }
    }
    nombre[i] = 0;
}

void leer_archivo_imprimir_personas(const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir este archivo: " << nombre_archivo << endl;
        exit(0);
    }
    //54741983    LANDEO_SUELDO_ADOLFO    4837.835243
    int dni;
    char nombre[50]{};
    double sueldo;
    cout << fixed;
    cout << setprecision(2);
    while (true) {
        input >> dni;
        if (input.eof())break;
        input >> nombre >> sueldo;
        cambiar_cadena(nombre);
        cout << setw(10) << dni << setw(50) << nombre << setw(10) << sueldo << endl;
    }
}

void my_strcpy(char *destination, const char *source) {
    int i = 0;
    while (true) {
        destination[i] = source[i];
        if (not source[i]) break;
        i++;
    }
}

void my_strncpy(char *destination, const char *source, int n) {
    int i = 0;
    for (; i < n and source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
}

int my_strlen(const char *str) {
    int len_str;
    for (len_str = 0; str[len_str]; len_str++);
    return len_str;
}

void my_strcat(char *str1, const char *str2) {
    int pos = my_strlen(str1);
    my_strcpy(&str1[pos], str2);
}

int my_strcmp(const char *s1, const char *s2) {
    for (int i = 0;; ++i) {
        if (s1[i] != s2[i]) {
            return (s1[i] > s2[i]) ? 1 : -1;
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
}


int my_strncmp(const char *s1, const char *s2, int n) {
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return (s1[i] > s2[i]) ? 1 : -1;
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}


void prepend(char *original, const char *add) {

}

int my_strchr(const char* str, char c) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == c) return i;
    }
    return NO_ENCONTRADO;
}

void my_strstr(const char *haystack, const char *needle, int &start, int &end) {
    int haystack_len = my_strlen(haystack);
    int needle_len = my_strlen(needle);

    start = NO_ENCONTRADO;
    end = NO_ENCONTRADO;

    if (needle_len == 0) {
        start = 0;
        end = 0;
        return;
    }

    for (int i = 0; i <= haystack_len - needle_len; ++i) {
        if (my_strncmp(haystack + i, needle, needle_len) == 0) {
            start = i;
            end = i + needle_len - 1;
            return;
        }
    }
}