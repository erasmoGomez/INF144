//
// Created by erasmo on 6/5/26.
//

#include "FuncionesAuxiliares.hpp"

/*-----------------------------------------*/
int es_mayuscula(char c) {
    return c >= 'A' and c <= 'Z';
}

int es_minuscula(char c) {
    return c >= 'a' and c <= 'z';
}

int es_letra(char c) {
    return es_mayuscula(c) or es_minuscula(c);
}

int es_digito(char c) {
    return c >= '0' and c <= '9';
}

int es_alfanumerico(char c) {
    return es_letra(c) or es_digito(c);
}

/*-----------------------------------------*/
// Pasar a mayúsculas
void a_mayusculas(char *cad) {
    for (int i = 0; cad[i] != '\0'; i++) {
        if (es_minuscula(cad[i])) {
            cad[i] = cad[i] - 'a' + 'A';
        }
    }
}

/*-----------------------------------------*/
// Pasar a minúsculas
void a_minusculas(char *cad) {
    for (int i = 0; cad[i] != '\0'; i++) {
        if (es_mayuscula(cad[i])) {
            cad[i] = cad[i] - 'A' + 'a';
        }
    }
}

/*-----------------------------------------*/
// Remover símbolos y puntuación
void remover_no_alfanumericos(char *cad) {
    int j = 0;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (es_alfanumerico(cad[i]) or cad[i] == ' ') {
            cad[j] = cad[i];
            j++;
        }
    }

    cad[j] = '\0';
}

/*-----------------------------------------*/
// Reemplazar espacios por guion bajo
void espacios_a_guion_bajo(char *cad) {
    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == ' ') {
            cad[i] = '_';
        }
    }
}

/*-----------------------------------------*/
// Contar palabras simples
int contar_palabras(char *cad) {
    int contador = 0;
    bool dentro = false;

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] != ' ' && !dentro) {
            contador++;
            dentro = true;
        } else if (cad[i] == ' ') {
            dentro = false;
        }
    }

    return contador;
}

/*-----------------------------------------*/
// Camelizar: "juan perez lopez" -> "Juan Perez Lopez"
void camelizar(char *cad) {
    char temp[MAX];
    int j = 0;
    bool nueva_palabra = true;

    a_minusculas(cad);

    for (int i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == ' ') {
            temp[j] = cad[i];
            nueva_palabra = true;
            j++;
        } else {
            if (nueva_palabra and es_minuscula(cad[i])) {
                temp[j] = cad[i] - 'a' + 'A';
            } else {
                temp[j] = cad[i];
            }

            j++;
            nueva_palabra = false;
        }
    }

    temp[j] = '\0';
    strcpy(cad, temp);
}

/*-----------------------------------------*/
// Extraer primer nombre y primer apellido
// Entrada: nombre1 nombre2 apellido1 apellido2
void generar_nombre_corto(char *nombre_largo, char *resultado) {
    char palabra[20];
    int k=0, n_palabra = 0;
    for (int i=0; i<strlen(nombre_largo)+1; i++) {
        if (nombre_largo[i] == ' ' or nombre_largo[i] == '\0') {
            palabra[k] = '\0';
            if (n_palabra == 0) {
                strcpy(resultado, palabra);
                strcat(resultado, " ");
            }
            if (n_palabra == 2) {
                strcat(resultado, palabra);
            }
            n_palabra++;
            k=0;
        }
        else {
            palabra[k] = nombre_largo[i];
            k++;
        }
    }
}

/*-----------------------------------------*/
// Generar código: primer nombre + primera letra del apellido
// Juan Perez -> JuanP
void generar_codigo(const char *nombre,
                    const char *apellido, char *codigo) {
    strcpy(codigo, nombre);

    int len = strlen(codigo);
    codigo[len] = apellido[0];
    codigo[len + 1] = '\0';
    camelizar(codigo);
}

/*-----------------------------------------*/
// Formar path de archivo
void formar_path(const char *carpeta, const char *nombre, char *path) {
    strcpy(path, carpeta);
    strcat(path, "/");
    strcat(path, nombre);
}
/*-----------------------------------------*/
// Convertir numero a cadena
void entero_a_cadena(int numero, char *cad) {
    int n = numero;
    int cant = 0;

    if (n == 0) {
        cad[0] = '0';
        cad[1] = '\0';
        return;
    }

    while (n > 0) {
        n /= 10;
        cant++;
    }

    cad[cant] = '\0';

    n = numero;
    for (int i = cant - 1; i >= 0; i--) {
        cad[i] = (n % 10) + '0';
        n /= 10;
    }
}

/*-----------------------------------------*/
// Generar varios nombres de archivo: data_1.txt, data_2.txt...
void generar_archivo(const char *base, int entero,
                    const char *extension, char *resultado) {
    char str_entero[10];
    entero_a_cadena(entero, str_entero);
    strcpy(resultado, base);
    strcat(resultado, "_");
    strcat(resultado,  str_entero);
    strcat(resultado, ".");
    strcat(resultado, extension);
}

/*-----------------------------------------*/
// Leer múltiples archivos generados
void abrir_archivos_multiples() {
    char nombre_archivo[MAX];
    char path[MAX];
    for (int i = 1; i <= 3; i++) {
        generar_archivo("data", i, "txt", nombre_archivo);
        formar_path("datos", nombre_archivo, path);
        ofstream output(path, ios::out);
        ifstream input(path, ios::in);

        if (input.is_open()) {
            cout << "Archivo abierto: " << nombre_archivo << endl;
            input.close();
        } else {
            cout << "No se pudo abrir: " << nombre_archivo << endl;
        }
    }
}
