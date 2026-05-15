#ifndef SOLUCIONEXAMENPARCIALPREGUNTA01_2025_2_FUNCIONESAUXILIARES_H
#define SOLUCIONEXAMENPARCIALPREGUNTA01_2025_2_FUNCIONESAUXILIARES_H
#include "Utils.hpp"

void emitirElReporteDeReproduccionesDeStreams(const char *archCanales,
        const char *archStreams,const char *archIdiomas,
        const char *archCategoria,const char *archReporte);
void imprimeTitulos(ofstream &archReporte);
void imprimeLinea(ofstream &archReporte,char car,int cant);
void leeImprimeCategoria(char letraCateg,int codigoCateg,
                        ifstream &archCategoria, ofstream &archReporte,
                        int numCar);
void leeImprimeIdioma(int codigoIdioma, ifstream &archIdiomas,
                      ofstream &archReporte, int numCar);
void leeImprimeTexto(ifstream&archCategoria,ofstream &archReporte,int numCar,
                     bool enMayuscula);
void imprimeCanales(int codigoStream,int duracion,ifstream &archCanales,
                    ofstream &archReporte);
void leeImprimeStreams(int &nCanal,char letraCanal,int codigoCanal,
                       int duracion,int &duracionTotal,int codigoStream,ifstream &archCanales,
                       ofstream &archReporte, double &tasaDropMayor, double& tasaDropMenor,
                       char &letraCanalMay,int &codigoCanalMay,char &letraCanalMen,
                       int &codigoCanalMen);
void imprimeHora(int horaIni, ofstream &archReporte);

#endif //SOLUCIONEXAMENPARCIALPREGUNTA01_2025_2_FUNCIONESAUXILIARES_H