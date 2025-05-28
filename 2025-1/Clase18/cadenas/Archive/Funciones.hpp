//
// Created by Erasmo on 26/05/25.
//

#ifndef CADENAS_FUNCIONES_HPP
#define CADENAS_FUNCIONES_HPP

#include "Utils.hpp"

void leer_archivo_imprimir_personas(const char *);

void leer_archivo_imprimir_tiktokers(const char *);

void cambiar_cadena(char *);

void concatenar(char *, const char *);

void my_strncpy(char *, const char *, int n);

void my_strcat(char *, const char *);

int my_strcmp(const char *, const char *);

int my_strncmp(const char *, const char *, int);

int my_strchr(const char *, char);

void my_strstr(const char *, const char *, int &, int &);

char* my_strtok(char* str, const char* delimitadores);

void remove_up_to(char* str, int pos);

int my_strlen(const char *str);

void prepend(char *original, const char *add);

#endif //CADENAS_FUNCIONES_HPP
