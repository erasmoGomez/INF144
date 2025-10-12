//
// Created by Erasmo on 9/10/25.
//
#include "Funciones.hpp"
void apertura_archivo_lectura(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "El archivo " << file_name << " No puede ser abiero" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "El archivo " << file_name << " No puede ser abiero" << endl;
        exit(1);
    }
}

void swapInt(int &a, int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void print_date(ofstream &output, int date) { //20250904
    int anio = date / 10000;        // 2025
    int mes = (date / 100) % 100;  // 09
    int dia = date % 100;          // 04

    output << right;
    output << setw(2) << setfill('0') << dia;
    output << "/";
    output << setw(2) << setfill('0') << mes;
    output << "/";
    output << setw(4) << anio;

    output << setfill(' ');  // restaurar fill a espacio
}

void ignorar(ifstream &input, char c) {
    input >> ws;
    while (input.get() != c);
}

int read_time(ifstream &input){
    //1:22:25
    int hh, mm, ss;
    char c;
    input>>hh>>c>>mm>>c>>ss;
    return hh*3600+mm*60+ss;
}

void cargar_videos(const char *file_name, int *codigos,
                   int *duraciones, int *codigos_idioma, int &n_videos) {
    //316186    1:22:25    4003    C1072
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo;
    while(true){
        input>>codigo;
        if(input.eof())break;
        codigos[n_videos] = codigo;
        duraciones[n_videos] = read_time(input);
        input>>codigos_idioma[n_videos];
        ignorar(input, '\n');
        n_videos++;
    }
}

void llenar_arreglos_archivo(ifstream& input, int codigo_video, int i,
                             int* fechas_antiguas, int* fechas_recientes,
                             double * promedios_rating, double * tasas){
    input.clear();
    input.seekg(0, ios::beg);
    //4/11/2025       Evelone192    450161    28/7/2025    19:47:03    1.39    0.052    316186    20/8/2025    10:49:46    4.92    0.69    501133    26/7/2025    02:38:02    2.69    0.004
    int fecha, codigo_video_leido;
    char c;
    while(true){
        //Parte Estatica
        fecha = read_date(input);
        if(input.eof())break;
        ignorar(input, ' ');
        //Parte Dinamica
        int veces = 0;
        int fecha_leida, duracion_leida;
        double rating_leido, tasa;
        while(true){
            veces = 0;
            input>>codigo_video_leido;
            //28/7/2025    19:47:03    1.39    0.052
            if(codigo_video_leido == codigo_video){
                //hacer cosas cheveres
                fecha_leida = read_date(input);
                duracion_leida = read_time(input);
                input>>rating_leido>>tasa;
                c = input.get();
                if( fechas_antiguas[i] > fecha_leida){
                    fechas_antiguas[i] = fecha_leida;
                }
                if( fechas_recientes[i] < fecha_leida){
                    fechas_recientes[i] = fecha_leida;
                }
                promedios_rating[i] += rating_leido;
                veces++;
                if( tasas[i] > tasa){
                    tasas[i] = tasa;
                }
            }
            else{
                //De ir hasta el nuevo codigo en la linea
                fecha_leida = read_date(input);
                duracion_leida = read_time(input);
                input>>rating_leido>>tasa;
                c = input.get();
            };
            if(c == '\n') break;
        }
        promedios_rating[i] = promedios_rating[i]/(double)veces;
    }
}

void llenar_nuevos_arreglos(const char *file_name, int *codigos, int *fechas_antiguas, int *fechas_recientes,
                            double *promedios_rating, double *tasas, int n_videos) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo_video;
    for(int i= 0; i<n_videos; i++){
        codigo_video = codigos[i];
        llenar_arreglos_archivo(input, codigo_video, i, fechas_antiguas, fechas_recientes, promedios_rating, tasas);
    }
}

void ordenacion(int *codigos, int *duraciones, int *codigos_idioma, int *fechas_antiguas, int *fechas_recientes,
                double *promedios_rating, double *tasas, int n_videos) {
    for(int i = 0; i<n_videos-1; i++)
        for(int k = i+1; k<n_videos; k++){
            if(codigos_idioma[i]<codigos_idioma[k] or codigos_idioma[i] == codigos_idioma[k] and fechas_antiguas[i]>fechas_antiguas[k]){
                swapInt(codigos_idioma[i], codigos_idioma[k]);
            }
        }


}
