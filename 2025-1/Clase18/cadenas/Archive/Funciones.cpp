//
// Created by Erasmo on 26/05/25.
//

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
    int new_len = my_strlen(original) + my_strlen(add);
//    for (int i = my_strlen(original) - 1; i >= 0; i--) {
//        original[i + 1] = original[i];
//    }
    char aux[new_len + 1];
    my_strcpy(aux, add);
    my_strcat(aux, original);
    aux[new_len] = 0;
    my_strcpy(original, aux);
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


void leer_archivo_imprimir_tiktokers(const char *nombre_archivo) {
    ifstream input(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "No se pudo abrir este archivo: " << nombre_archivo << endl;
        exit(0);
    }
    //dream_102	CLAY_SANDERSON	26	6.43
    char usuario[20]{}, nombre[40]{};
    int seguidores;
    double engagement;
    cout << fixed;
    cout << setprecision(2);
    while (true) {
        input >> usuario;
        if (input.eof())break;
        input >> nombre >> seguidores >> engagement;
        prepend(usuario, "@");
        cambiar_nombre(nombre);
        cout << setw(ANCHO_REPORTE / N_COLUMNAS) << usuario;
        cout << setw(ANCHO_REPORTE / N_COLUMNAS) << nombre;
        cout << setw(ANCHO_REPORTE / N_COLUMNAS) << seguidores << "M";
        cout << setw(ANCHO_REPORTE / N_COLUMNAS) << engagement << endl;
    }
}

void remove_up_to(char* str, int pos) {
    int i = pos, j = 0;
    while (str[i] != '\0') {
        str[j++] = str[i++];
    }
    str[j] = '\0';
}

char* my_strtok(char* str, const char* delimiters) {
    if (str == nullptr or *str == '\0') return nullptr;

    // 1. Skip leading delimiters
    int start = 0;
    while (str[start] != '\0' and my_strchr(delimiters, str[start]) != -1) {
        start++;
    }

    if (str[start] == '\0') return nullptr;

    // 2. Find end of token
    int end = start;
    while (str[end] != '\0' and my_strchr(delimiters, str[end]) == -1) {
        end++;
    }

    // 3. Allocate and copy token
    int len = end - start;
    char* token = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        token[i] = str[start + i];
    }
    token[len] = '\0';

    // 4. Skip delimiters after the token
    int next = end;
    while (str[next] != '\0' and my_strchr(delimiters, str[next]) != -1) {
        next++;
    }

    // 5. Remove token + delimiters from original string
    remove_up_to(str, next);

    return token;
}





