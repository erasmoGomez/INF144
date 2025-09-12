//
// Created by Erasmo on 11/09/25.
//

#ifndef CLIENTESMOVILES_FUNCIONESAUXILIARES_HPP
#define CLIENTESMOVILES_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
void leer_procesar_clientes_moviles(const char* file_name_entrada, const char* file_name_salida);
void apertura_archivo_lectura(ifstream &input, const char* file_name);
void apertura_archivo_escritura(ofstream &output, const char *file_name);
#endif //CLIENTESMOVILES_FUNCIONESAUXILIARES_HPP
