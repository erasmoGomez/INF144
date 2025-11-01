//
// Created by Erasmo on 31/10/25.
//

#include "Funciones.hpp"
void apertura_archivo_escritura(ofstream& output, const char* ruta){
    output.open(ruta, ios::out);
}