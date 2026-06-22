//
// Created by erasmo on 6/13/26.
//

#ifndef RAPPI_ENVIO_HPP
#define RAPPI_ENVIO_HPP
#include "Fecha.hpp"
#include "Hora.hpp"
#include "Codigo.hpp"

struct Envio {
    Fecha fecha;
    int codigoConductor;
    Hora duracion;
    Codigo cliente;
};

#endif //RAPPI_ENVIO_HPP
