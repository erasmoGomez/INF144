#include "Bibliotecas/FuncionesAuxiliares.h"
int main(int argc, char **argv) {
    // Archivo Categorias.txt
    char *arrCodigoCateg[MAX_DATOS_CATEG], *arrCategoria[MAX_DATOS_CATEG];
    int numDatCat;
    // Archivo Reproducciones:txt
    int arrFecha[MAX_DATOS_REPRO], arrDuracion[MAX_DATOS_REPRO], numDatRep;
    char *arrNombCanal[MAX_DATOS_REPRO], *arrCodCatRep[MAX_DATOS_REPRO];
    double arrRating[MAX_DATOS_REPRO], arrDrop_off[MAX_DATOS_REPRO];
    // // Prueba función generaArchivoEnlace
    char categoria[60] = "xxx_yyyy_zzzz", nA[60], en[60];
    generaArchivoEnlace(categoria, nA, en);
    cout << categoria << endl;
    cout << nA << endl;
    cout << en << endl;
    // leerCategorias("ArchivosDeDatos/Categorias.txt", arrCodigoCateg,
    //                arrCategoria, numDatCat);
    // probarLecturaDeCategorias(
    //     "ArchivosDeReporte/ReporteDePruebaDeCategorias.txt",
    //     arrCodigoCateg, arrCategoria, numDatCat);
    // LeerReproducciones("ArchivosDeDatos/Reproducciones.txt", arrFecha,
    //                    arrNombCanal, arrCodCatRep, arrRating, arrDrop_off,
    //                    arrDuracion, numDatRep);
    // probarLecturaDeReproducciones(
    //     "ArchivosDeReporte/ReporteDePruebaDeReproducciones.txt",
    //     arrFecha, arrNombCanal, arrCodCatRep, arrRating,
    //     arrDrop_off, arrDuracion, numDatRep);
    // generaReportesDeCategorias(arrCodigoCateg, arrCategoria, numDatCat,
    //                            arrFecha, arrNombCanal, arrCodCatRep, arrRating,
    //                            arrDrop_off, arrDuracion, numDatRep);
}
