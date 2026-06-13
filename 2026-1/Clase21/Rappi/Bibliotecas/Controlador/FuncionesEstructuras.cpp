//
// Created by erasmo on 6/13/26.
//

#include "FuncionesEstructuras.hpp"

void leer_conductor(ifstream &input,
                    Conductor &c) {
    //301,LIMA NORTE,7845,QUISPE ROJAS MARIO ALBERTO,35.50,6123,TORRES VEGA ANA LUCIA,42.80

    c.codigo = leer_entero(input);
    leer_cadena_estatica(input, c.nombre, ',', 100);
    c.tarifa = leer_double(input, false);
}

void cargar_conductores(const char *nombre_archivo,
                        Conductor *conductores,
                        int &cantidad_conductores) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    int codigo_ruta = 0;
    char ruta[80];
    //301,LIMA NORTE,7845,QUISPE ROJAS MARIO ALBERTO,35.50,6123,TORRES VEGA ANA LUCIA,42.80
    while (true) {
        input >> codigo_ruta;
        if (input.eof())break;
        input.ignore();
        input.getline(ruta, 80, ',');
        input.ignore();
        while (true) {
            leer_conductor(input, conductores[cantidad_conductores]);
            conductores[cantidad_conductores].codigo_ruta = codigo_ruta;
            strcpy(conductores[cantidad_conductores].ruta, ruta);
            char c = input.get();
            cantidad_conductores++;
            if (c == '\n') break;
        }
    }
}

void crear_reporte_simple(const char *nombre_archivo,
                          const Conductor *conductores,
                          int cantidad_conductores) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    for (int i = 0; i < cantidad_conductores; i++) {
        output << conductores[i].codigo << " ";
        output << conductores[i].nombre << " ";
        output << conductores[i].codigo_ruta << " ";
        output << conductores[i].ruta << " ";
        output << conductores[i].tarifa << " ";
        output << endl;
    }
}
