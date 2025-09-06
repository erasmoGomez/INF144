// Nombre: Erasmo Gómez Montoya Codigo: 20082060
// Descripción Problema:
// El siguiente programa permite realizar un reporte con la información de las reproducciones musicales
// de usuarios en un determinado tiempo en la plataforma Spotify, este reporte presenta
// Por cada usuario, la cantidad de tiempo que el usuario ha reproducido diferentes periodos musicales
// También muestra el número total de reproducciones asi como las fechas donde fueron realizadas las reproducciones.

#include "src/AuxiliaryFunctions.hpp"

int main() {
    int start_date = 20000101, end_date = 20101231;
    calculate_report(start_date, end_date);
    return 0;
}
