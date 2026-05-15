#include "Biblioteca/FuncionesAuxiliares.hpp"

int main(int argc, char **argv) {
    emitirElReporteDeReproduccionesDeStreams("ArchivosDeDatos/Canales.txt",
        "ArchivosDeDatos/Streams.txt","ArchivosDeDatos/Idiomas.txt",
        "ArchivosDeDatos/Categorias.txt",
        "ArchivosDeReporte/ReporteDeReproduccioneDeStreams.txt");

    return 0;
}