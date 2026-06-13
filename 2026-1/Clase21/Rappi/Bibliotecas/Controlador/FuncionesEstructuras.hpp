//
// Created by erasmo on 6/13/26.
//

#ifndef RAPPI_FUNCIONESESTRUCTURAS_HPP
#define RAPPI_FUNCIONESESTRUCTURAS_HPP

#include "../Modelo/Estructuras/Conductor.hpp"
#include "../Modelo/Estructuras/Envio.hpp"
#include "../Auxiliares/FuncionesAuxiliares.hpp"

void cargar_conductores(const char *nombre_archivo, Conductor *conductores, int &cantidad_conductores);

void crear_reporte_simple(const char *nombre_archivo,
                          const Conductor *conductores,
                          int cantidad_conductores);

void ordenar_conductores(Conductor *conductores,
                         int cantidad_conductores);

void cargar_envios(const char *nombre_archivo, Envio *envios, int &cantidad_envios);
#endif //RAPPI_FUNCIONESESTRUCTURAS_HPP
