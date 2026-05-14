//
// Created by erasmog on 8/10/2025.
//


#include "Bibliotecas/FuncionesAuxiliares.hpp"


int main() {
    // Streams.txt
    int arrStream[TAM_STREAMS];
    int arrDuracion[TAM_STREAMS];
    int arrIdioma[TAM_STREAMS];
    int arrNumCat[TAM_STREAMS];
    char arrCarCat[TAM_STREAMS];
    int cantStreams = 0;
    cargarStreams("ArchivosDeDatos/Streams.txt",
                    arrStream,
                    arrDuracion,
                    arrIdioma,
                    arrCarCat,
                    arrNumCat,
                    cantStreams);
    //LA VERIFICACION
    // Incluye Titulo, Encabezados/Headers
    mostrarStreams(arrStream, arrDuracion, arrIdioma, arrCarCat, arrNumCat, cantStreams);
    //Canales.txt
    int arrRepAntigua[TAM_STREAMS]{};
    int arrRepReciente[TAM_STREAMS]{};
    int arrNumReprod[TAM_STREAMS]{};
    int arrTotReprod[TAM_STREAMS]{};
    double arrPromRat[TAM_STREAMS]{};
    double arrPromTasa[TAM_STREAMS]{};
    completarCanales("ArchivosDeDatos/Canales.txt",
                    //Los que me van a ayudar a llenar
                    arrStream,
                    arrIdioma,
                    arrCarCat,
                    arrNumCat,
                    arrDuracion,
                    //Los que voy a llenar
                    arrRepAntigua,
                    arrRepReciente,
                    arrPromRat,
                    arrPromTasa,
                    arrNumReprod,
                    arrTotReprod,
                    cantStreams);
    emitirReporte("ArchivosDeReporte/Reproducciones-Streams.txt",
                  "DETALLE COMPLETO DE REPRODUCCION DE STREAMS",
                  true, arrStream, arrIdioma,
                  arrCarCat, arrNumCat, arrRepAntigua, arrRepReciente, arrPromRat, arrPromTasa,
                  arrDuracion, arrNumReprod, arrTotReprod, cantStreams);
    ordenarStreams(arrStream, arrIdioma, arrCarCat, arrNumCat, arrRepAntigua,
                   arrRepReciente, arrPromRat, arrPromTasa, arrDuracion, arrNumReprod, arrTotReprod,
                   cantStreams);
    emitirReporte("ArchivosDeReporte/Reproducciones-Streams-Ordenado.txt",
                  "DETALLE COMPLETO DE REPRODUCCION DE STREAMS ORDENADO POR IDIOMA Y TASA DROP-OFF",
                  false, arrStream, arrIdioma, arrCarCat, arrNumCat, arrRepAntigua, arrRepReciente,
                  arrPromRat, arrPromTasa, arrDuracion, arrNumReprod, arrTotReprod, cantStreams);
    return 0;
}
