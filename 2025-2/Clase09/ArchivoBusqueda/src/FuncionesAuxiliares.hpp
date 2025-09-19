//
// Created by Erasmo on 18/09/25.
//

#ifndef ARCHIVOBUSQUEDA_FUNCIONESAUXILIARES_HPP
#define ARCHIVOBUSQUEDA_FUNCIONESAUXILIARES_HPP

#include "Utils.hpp"

void apertura_archivo_lectura(ifstream &, const char *);

void apertura_archivo_escritura(ofstream &, const char *);

void imprimir_titulo(ofstream &, const char *);

void leer_procesar_clientes_moviles(const char *, const char *, const char *);

#endif //ARCHIVOBUSQUEDA_FUNCIONESAUXILIARES_HPP
