// Proyecto: SolucionLaboratorio06_2025_2
// Archivo:  FuncionesAuxiliares.h.h
//
// Autor:   J. Miguel Guanira E.
// Creado el sábado, 01 de Noviembre del 2025 a las 14:29:42.
//

#ifndef SOLUCIONLABORATORIO06_2025_2_FUNCIONESAUXILIARES_H
#define SOLUCIONLABORATORIO06_2025_2_FUNCIONESAUXILIARES_H
#include "Utils.hpp"
void generaArchivoEnlace(const char *categoria,char *nombArch, char *enlace);
void leerCategorias(const char *nombArch,char **arrCodigoCateg,
                    char **arrCategoria,int &numDatCat);
char *leeCadenaExacta(ifstream &arch);
void probarLecturaDeCategorias(const char *nombArch,char **arrCodigoCateg,
                               char **arrCategoria, int &numDatCat);
void LeerReproducciones(const char *nombArch,int *arrFecha,
                        char **arrNombCanal,char **arrCodigoCateg,
                        double *arrRating,double *arrDrop_off,
                        int *arrDuracion,int &numDatRep);
int compactaFecha(int dia, int mes, int año);
int compactaHora(int hora, int minuto, int segundo);
void probarLecturaDeReproducciones(const char *nombArch,int *arrFecha,
                            char **arrNombCanal,char **arrCodCatRep,
                            double *arrRating,double *arrDrop_off,
                            int *arrDuracion,int numDatRep);
void expandeFecha(int fecha, int &dia, int &mes, int &año);
void expandeHora(int duracion,int &hora, int &minuto, int &segundo);
void generaReportesDeCategorias(
                     char **arrCodigoCateg,char **arrCategoria,int numDatCat,
                     int *arrFecha,char **arrNombCanal,char **arrCodCatRep,
                     double *arrRating, double *arrDrop_off,int *arrDuracion,
                     int numDatRep);
void reporteDeCategoria(char *codigoCateg,char *categoria,char *nombArch,
                     char *enlace,int *arrFecha,char **arrNombCanal,
                     char **arrCodCatRep,double *arrRating, double *arrDrop_off,int *arrDuracion,
                     int numDatRep);
void imprimeLinea(ofstream &arch,char car, int n);

#endif //SOLUCIONLABORATORIO06_2025_2_FUNCIONESAUXILIARES_H