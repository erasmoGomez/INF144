// Proyecto: SolucionLaboratorio06_2025_2
// Archivo:  FuncionesAuxiliares.cpp.cpp
//
// Autor:   J. Miguel Guanira E.
// Creado el sábado, 01 de Noviembre del 2025 a las 14:29:42.
//

#include <iostream>
#include <fstream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "FuncionesAuxiliares.h"

void generaArchivoEnlace(const char *categoria,char *nombArch, char *enlace) {
    char aMayusculas[100];
    strcpy(aMayusculas,categoria);
    for (int i=0; i<aMayusculas[i]; i++) {
        if (i==0 or aMayusculas[i-1]=='_')
            if (aMayusculas[i]>='a' && aMayusculas[i]<='z')
               aMayusculas[i] -= 'a'-'A';
        // else
        //     if (aMayusculas[i]>='A' && aMayusculas[i]<='Z')
        //         aMayusculas[i] +='a'-'A';
    }
    strcpy(nombArch,"ArchivosDeReporte/");
    strcat(nombArch,aMayusculas);
    strcat(nombArch,".txt");
    cout<<nombArch<<endl;
    strcpy(enlace,"https://Laboratorio06_2025_2/ArchivosDeReporte/");
    strcat(enlace,aMayusculas);
}

void leerCategorias(const char *nombArch,char **arrCodigoCateg,
                    char **arrCategoria, int &numDatCat) {
    ifstream arch(nombArch, ios::in);;
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    numDatCat = 0;
    while (true) {
        arrCodigoCateg[numDatCat] = leeCadenaExacta(arch);
        if (arch.eof())break;
        arrCategoria[numDatCat] = leeCadenaExacta(arch);
        numDatCat++;
    }
}

char *leeCadenaExacta(ifstream &arch) {
    char cadena[100], *cadenaPtr;
    arch>>cadena;
    if (arch.eof())return nullptr;
    cadenaPtr = new char[strlen(cadena)+1];
    strcpy(cadenaPtr,cadena);
    return cadenaPtr;
}

void probarLecturaDeCategorias(const char *nombArch,char **arrCodigoCateg,
                               char **arrCategoria, int &numDatCat) {
    ofstream arch(nombArch, ios::out);;
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<setw(10)<< "REPORTE DE PRUEBA DE CATEGORIAS"<<endl<<endl;
    arch<<left<<setw(10)<<"CODIGO"<<"CATEGORIA"<<endl;
    for (int i=0; i<numDatCat; i++)
        arch<<left<<setw(10)<<arrCodigoCateg[i]<<arrCategoria[i]<<endl;
}

void LeerReproducciones(const char *nombArch,int *arrFecha,
                        char **arrNombCanal,char **arrCodCatRep,
                        double *arrRating,double *arrDrop_off,
                        int *arrDuracion,int &numDatRep) {
    ifstream arch(nombArch, ios::in);;
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int dia, mes, año,hora, minuto, segundo;
    char c;
    numDatRep = 0;
    while (true) {
        arch>>dia;
        if (arch.eof())break;
        arch>>c>>mes>>c>>año;
        arrFecha[numDatRep] = compactaFecha(dia, mes, año);
        arrNombCanal[numDatRep] = leeCadenaExacta(arch);
        arrCodCatRep[numDatRep] = leeCadenaExacta(arch);
        arch>>arrRating[numDatRep]>>arrDrop_off[numDatRep];
        arch>>hora>>c>>minuto>>c>>segundo;
        arrDuracion[numDatRep] = compactaHora(hora, minuto, segundo);
        numDatRep++;
    }
}

int compactaFecha(int dia, int mes, int año) {
    return dia + mes*100 + año*10000;

}

int compactaHora(int hora, int minuto, int segundo) {
    return hora*3600 + minuto*60 + segundo;
}

void probarLecturaDeReproducciones(const char *nombArch,int *arrFecha,
                            char **arrNombCanal,char **arrCodCatRep,
                            double *arrRating,double *arrDrop_off,
                            int *arrDuracion,int numDatRep) {
    ofstream arch(nombArch, ios::out);;
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int dia, mes, año, hora, minuto, segundo;
    arch.precision(2);
    arch<<fixed;
    arch<<setw(10)<< "REPORTE DE PRUEBA DE REPRODUCCIONES"<<endl<<endl;
    arch<<left<<setw(12)<<"CODIGO"<<setw(18)<<"CANAL"<<setw(15)<<"COD. CAT"
        <<setw(9)<<"RATING"<<setw(10)<<"DROP-OFF"<<"DURACION"<<endl;
    for (int i=0; i<numDatRep; i++) {
        expandeFecha(arrFecha[i],dia, mes, año);
        expandeHora(arrDuracion[i],hora, minuto, segundo);
        arch<<right<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'
            <<setw(4)<<año<<setfill(' ')<<"  ";
        arch<<left<<setw(18)<<arrNombCanal[i]<<setw(10)<<arrCodCatRep[i]
            <<right<<setw(10)<<arrRating[i]<<setw(10)<<arrDrop_off[i]<<"    ";
        arch<<setfill('0')<<setw(2)<<hora<<':'<<setw(2)<<minuto<<':'
            <<setw(2)<<segundo<<setfill(' ')<<endl;
    }
}

void expandeFecha(int fecha, int &dia, int &mes, int &año) {
    año = fecha/10000;
    fecha %= 10000;
    mes = fecha/100;
    dia = fecha%100;
}

void expandeHora(int duracion,int &hora, int &minuto, int &segundo) {
    hora = duracion/3600;
    duracion %= 3600;
    minuto = duracion/60;
    segundo = duracion%60;
}

void generaReportesDeCategorias(
                     char **arrCodigoCateg,char **arrCategoria,int numDatCat,
                     int *arrFecha,char **arrNombCanal,char **arrCodCatRep,
                     double *arrRating, double *arrDrop_off,int *arrDuracion,
                     int numDatRep) {
    char nombArch[100], enlace[100];

    // for (int cat=0; cat<numDatCat; cat++) {
    for (int cat=0; cat<numDatCat; cat++) {
        generaArchivoEnlace(arrCategoria[cat], nombArch,enlace);
        reporteDeCategoria(arrCodigoCateg[cat],arrCategoria[cat],
                           nombArch,enlace,arrFecha,
                           arrNombCanal,arrCodCatRep,arrRating,arrDrop_off,
                           arrDuracion,numDatRep);
    }
}

void reporteDeCategoria(char *codigoCateg,char *categoria,char *nombArch,
                     char *enlace,int *arrFecha,char **arrNombCanal,
                     char **arrCodCatRep,double *arrRating,
                     double *arrDrop_off,int *arrDuracion,int numDatRep) {
    ofstream arch(nombArch, ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    double sumaRating=0,sumaDrop_Off=0.0, sumaDuracion=0.0;
    int dia, mes, año, hora, minuto, segundo,numRep=0;
    arch.precision(2);
    arch<<fixed;
    arch<<"Codigo: "<<codigoCateg<<endl;
    arch<<"Nombre: "<<categoria<<endl;
    arch<<"Enlace: "<<enlace<<endl;
    arch<<"REPRODUCCIONES:: "<<endl;
    imprimeLinea(arch,'=',70);
    arch<<left<<setw(12)<<"CODIGO"<<setw(22)<<"CANAL"
        <<setw(9)<<"RATING"<<setw(10)<<"DROP-OFF"<<"DURACION"<<endl;
    for (int i=0; i<numDatRep; i++) {
        if (strcmp(codigoCateg,arrCodCatRep[i])==0) {
            sumaRating+=arrRating[i];
            sumaDrop_Off+=arrDrop_off[i];
            sumaDuracion+=arrDuracion[i];
            numRep++;
            expandeFecha(arrFecha[i],dia, mes, año);
            expandeHora(arrDuracion[i],hora, minuto, segundo);
            arch<<right<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'
                <<setw(4)<<año<<setfill(' ')<<"  "
                <<left<<setw(18)<<arrNombCanal[i]
                <<right<<setw(10)<<arrRating[i]<<setw(10)<<arrDrop_off[i]
                <<"   ";
            arch<<setfill('0')<<setw(2)<<hora<<':'<<setw(2)<<minuto<<':'
                <<setw(2)<<segundo<<setfill(' ')<<endl;
        }
    }
    imprimeLinea(arch,'=',70);
    expandeHora(sumaDuracion,hora, minuto, segundo);
    arch<<"PROMEDIO DE RATING:"<<setw(11)<< sumaRating/numRep<<endl;
    arch<<"PROMEDIO DE DROP-OFF:"<<setw(9)<<sumaDrop_Off/numRep<<endl;
    arch<<"DURACION TOTAL:     : "<<setfill('0')<<setw(2)<<hora<<':'
               <<setw(2)<<minuto<<':'<<setw(2)<<segundo<<setfill(' ')<<endl;

}

void imprimeLinea(ofstream &arch,char car, int n) {
    for (int i=0; i<n; i++) arch.put(car);
    arch<<endl;
}

void generaArchivoEnlace2(const char* categoria,
                          char* nombre_archivo,
                          char* enlace) {
    //categoria -> xxx_yyy_zzz
    char categoria_cpy[20];
    strcpy(categoria_cpy,categoria);
    // categoria_cpy -> Xxx_Yyy_Zzz Camelizacion
    modificar_categoria(categoria_cpy);

    //Nombre Archivo Reporte
    // char ruta_base[100];
    // strcpy(ruta_base,"ArchivosDeReporte/");
    // ArchivosDeReporte/Xxx_Yyy_Zzz.txt
    strcpy(nombre_archivo, "ArchivosDeReporte/");
    strcat(nombre_archivo, categoria_cpy);
    strcat(nombre_archivo, ".txt");
    //strcpy(nombre_archivo,ruta_base);
    //Enlace
    //https://laboratorio06_2025_2/ArchivosDeReporte/Xxx_Yyyy_Zzz
    strcpy(enlace, "https://laboratorio06_2025_2/ArchivosDeReporte/");
    strcat(enlace, categoria_cpy);
}
