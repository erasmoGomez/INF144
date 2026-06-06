//
// Created by erasmo on 6/5/26.
//

#ifndef SNIPPETS_FUNCIONESAUXILIARES_HPP
#define SNIPPETS_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"

// Búsquedas
int buscar_caracter(char *cad, char c);
int contar_caracter(char *cad, char c);
int contar_ocurrencias(char *cad, char *subcadena);

// Extracciones
void extraer_subcadena(char *origen,
                       int inicio,
                       int longitud,
                       char *destino);

void obtener_primer_nombre(char *nombre_completo,
                           char *nombre);

void obtener_primer_apellido(char *nombre_completo,
                             char *apellido);

// Reemplazos
void reemplazar_caracter(char *cad,
                         char original,
                         char nuevo);

void eliminar_caracter(char *cad,
                       char c);

// Inversiones
void invertir_cadena(char *cad);

// Comparaciones
bool empieza_con(char *cad,
                 char *prefijo);

bool termina_con(char *cad,
                 char *sufijo);

// Formatos
void capitalizar(char *cad);
void snake_case(char *cad);
void kebab_case(char *cad);

// Archivos
void generar_nombre_backup(char *archivo,
                           char *resultado);

void generar_nombre_log(char *base,
                        int dia,
                        int mes,
                        int anio,
                        char *resultado);

// Validaciones de caracteres
int es_mayuscula(char c);
int es_minuscula(char c);
int es_letra(char c);
int es_digito(char c);
int es_alfanumerico(char c);

// Transformaciones
void a_mayusculas(char *cad);
void a_minusculas(char *cad);
void remover_no_alfanumericos(char *cad);
void espacios_a_guion_bajo(char *cad);
void camelizar(char *cad);

// Estadísticas
int contar_palabras(char *cad);

// Generación de nombres y códigos
void generar_nombre_corto(char *nombre_largo,
                          char *resultado);

void generar_codigo(const char *nombre,
                    const char *apellido,
                    char *codigo);

// Manejo de paths y archivos
void formar_path(const char *carpeta,
                 const char *nombre,
                 char *path);

void generar_archivo(const char *base,
                     int numero,
                     const char *extension,
                     char *resultado);

void abrir_archivos_multiples();

#endif //SNIPPETS_FUNCIONESAUXILIARES_HPP