/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 9, 2025, 3:45 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void fecha_dd_mm_aa(int f, int &dd, int &mm, int &aa) {
    //Fecha: 20240926
    aa = f / 10000; //2024
    f %= 10000; //0926
    mm = f / 100; //9
    dd = f % 100; //26
}

void imprimir_linea(ofstream &output, char c) {
    output << setfill(c) << setw(TAM_REPORTE - 1) << c << endl;
    output << setfill(' ');
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void ignorar_cadena(ifstream& input, char del) {
    input>>ws;
    while (input.get() != del);
}

int leer_fecha(ifstream& input) {
    int fecha, dd, mm, aa;
    char c;
    input >> dd >> c >> mm >> c >> aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

int leer_int(ifstream& input) {
    int i;
    input >> i;
    return i;
}

char leer_char(ifstream& input) {
    char c;
    input >> c;
    return c;
}

double leer_double(ifstream& input) {
    double d;
    input >> d;
    return d;
}

void intercambiarI(int &a, int &b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiarD(double &a, double &b) {
    double aux;
    aux = a;
    a = b;
    b = aux;
}

void intercambiarC(char &a, char &b) {
    char aux;
    aux = a;
    a = b;
    b = aux;
}

void cargar_datos_videos(const char* nombre_archivo, char* tipos_videos, 
                         int* codigos_videos, double* duraciones_videos, 
                         int& cantidad_videos){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    
    //P001	3.32	feather/sabrina-carpenter
    char tipo;
    while(true){
        tipo = input.get();
        //input>>tipo;
        if(input.eof())break;
        tipos_videos[cantidad_videos] = tipo;
        codigos_videos[cantidad_videos] = leer_int(input);
        duraciones_videos[cantidad_videos] = leer_double(input);
        ignorar_cadena(input, '\n');
        cantidad_videos++;
    }
}

void cargar_datos_dispositivos(const char* nombre_archivo, int* dnis_dispositivos, 
                         char* tipos_dispositivos, int* codigo_dispositivos, 
                         int& cantidad_dispostivos){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    
    //78450044	MOB-015
    int dni;
    while(true){
        input>>dni;
        if(input.eof())break;
        dnis_dispositivos[cantidad_dispostivos] = dni;
        tipos_dispositivos[cantidad_dispostivos] = leer_char(input);
        ignorar_cadena(input,'-');
        codigo_dispositivos[cantidad_dispostivos] = leer_int(input);
        cantidad_dispostivos++;
    }
}

void cargar_datos_usuarios(ifstream& input, int*dnis_registrados, int& cantidad_usuarios){
    
    //78450000	lopez/ana-maria
    int dni;
    while(true){
        input>>dni;
        if(input.eof())break;
        dnis_registrados[cantidad_usuarios] = dni;
        ignorar_cadena(input,'\n');
        cantidad_usuarios++;
    }
}

void ordenar_usuarios_registrados(int*dnis_registrados, int cantidad_usuarios){
    for(int i=0; i<cantidad_usuarios-1; i++)
        for(int k = i+1; k<cantidad_usuarios; k++)
            if(dnis_registrados[i] > dnis_registrados[k])
                intercambiarI(dnis_registrados[i], dnis_registrados[k]);
}

int buscar_dni_usuario_registrado(char tipo_dispositivo, int codigo_dispositivo,
                                  char* tipos_dispositivos, int* codigo_dispositivos,
                                  int* dnis_dispositivos,
                                  int* dnis_registrados, int cantidad_registrados,
                                  int cantidad_dispostivos){
    int i=0, dni;
    for(i=0; i<cantidad_dispostivos;i++)
        if(tipo_dispositivo == tipos_dispositivos[i] and 
           codigo_dispositivo == codigo_dispositivos[i]) break;
    dni = dnis_dispositivos[i];
    
    for(int j = 0; j<cantidad_registrados; j++)
        if(dnis_registrados[j] == dni) return j;
    return NO_ENCONTRADO;
}

double buscar_tiempo_video(char tipo_video, int codigo_video, 
                           char* tipos_videos, int* codigos_videos, 
                           int cantidad_videos){
    for(int i=0; i<cantidad_videos;i++)
        if(tipo_video == tipos_videos[i] and 
           codigo_video == codigos_videos[i]) return i;
    return NO_ENCONTRADO;
}

void leer_procesar_usuarios(const char* nombre_archivo, int* dnis_registrados, int cantidad_registrados,
                            char* tipos_videos, int* codigos_videos, double* duraciones_videos, int cantidad_videos,
                            int * dnis_dispositivos, char* tipos_dispositivos, int* codigo_dispositivos, int cantidad_dispostivos,
                            int *total_videos_usuarios, double* duracion_videos_usuarios,
                            int& total_videos_estadistica, double &duracion_videos_estadistica){
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //01/02/2025	PC-080	V133
    int fecha, codigo_dispositivo, codigo_video;
    char tipo_dispositivo, tipo_video;
    int total_videos=0, pos_dni_usuario_registrado, pos_tiempo_video_registrado; 
    double duracion_videos=0;
    while(true){
        fecha = leer_fecha(input);
        if(input.eof())break;
        tipo_dispositivo = leer_char(input);
        ignorar_cadena(input, '-');
        codigo_dispositivo = leer_int(input);
        tipo_video = leer_char(input);
        codigo_video = leer_int(input);
        pos_dni_usuario_registrado = buscar_dni_usuario_registrado(tipo_dispositivo, codigo_dispositivo,
                                                               tipos_dispositivos, codigo_dispositivos,
                                                               dnis_dispositivos,dnis_registrados,cantidad_registrados, 
                                                               cantidad_dispostivos);
        
        pos_tiempo_video_registrado = buscar_tiempo_video(tipo_video, codigo_video, 
                                                      tipos_videos, codigos_videos, 
                                                      cantidad_videos);
        if(pos_dni_usuario_registrado!=NO_ENCONTRADO){
            total_videos_usuarios[3*pos_dni_usuario_registrado] += tipo_video == 'P' ? 1:0;
            total_videos_usuarios[3*pos_dni_usuario_registrado+1] += tipo_video == 'R' ? 1:0;
            total_videos_usuarios[3*pos_dni_usuario_registrado+2]++;
        }
        else
            cout<<"El DNI de usuario No se pudo encontrar"<<endl;
        if(pos_tiempo_video_registrado!=NO_ENCONTRADO){
            duracion_videos_usuarios[3*pos_dni_usuario_registrado] += tipo_video == 'P' ? duraciones_videos[pos_tiempo_video_registrado]:0;
            duracion_videos_usuarios[3*pos_dni_usuario_registrado+1] += tipo_video == 'R' ? duraciones_videos[pos_tiempo_video_registrado]:0;
            duracion_videos_usuarios[3*pos_dni_usuario_registrado+2] += duraciones_videos[pos_tiempo_video_registrado];
        }
        else
            cout<<"El tiempo de video No se pudo encontrar"<<endl;
        total_videos_estadistica+=total_videos_usuarios[3*pos_dni_usuario_registrado+2];
        duracion_videos_estadistica+=duracion_videos_usuarios[3*pos_dni_usuario_registrado+2];
    }
}

void imprimir_cadena(int dni, ifstream& input, ofstream& output){
    imprimir_linea(output, '=');
    output << "DNI: " << dni << " - " << "NOMBRE: ";
    input>>ws;
    char c;
    while (true) {
        c = input.get();
        if (c == '\n') break;
        if (c == '/' or c == '-') c = ' ';
        output.put(c);
    }
    output << endl;
    imprimir_linea(output, '=');
}


void buscar_imprimir_nombre(int dni, ifstream&input, ofstream& output){
    input.clear();
    input.seekg(0, ios::beg);
    //78450000	lopez/ana-maria
    int dni_leido;
    while(true){
        input>>dni_leido;
        if(input.eof())break;
        if(dni_leido == dni)
            imprimir_cadena(dni, input, output);
        else
            ignorar_cadena(input, '\n');
    }
}

void imprimir_reporte(const char* nombre_reporte, 
                      int* dnis_registrados, int cantidad_registrados,
                      ifstream& input_usuarios_registrados,
                      int* cantidades_videos_usuarios,
                      double* duraciones_videos_usuarios,
                      int total_videos_estadistica,
                      double duracion_videos_estadistica){
    ofstream output;
    apertura_archivo_escritura(output, nombre_reporte);
    for(int i = 0; i<cantidad_registrados; i++){
        imprimir_linea(output,'=');
        buscar_imprimir_nombre(dnis_registrados[i], input_usuarios_registrados, output);
        imprimir_linea(output,'-');
        output<<"POP: "<<cantidades_videos_usuarios[3*i]<<endl;
        output<<"ROCK: "<<cantidades_videos_usuarios[3*i+1]<<endl;
        output<<"TOTAL_CANTIDADES: "<<cantidades_videos_usuarios[3*i+2]<<endl;
        imprimir_linea(output,'-');
        output<<"POP: "<<duraciones_videos_usuarios[3*i]<<endl;
        output<<"ROCK: "<<duraciones_videos_usuarios[3*i+1]<<endl;
        output<<"TOTAL_DURACIONES: "<<duraciones_videos_usuarios[3*i+2]<<endl;
        imprimir_linea(output,'=');
    }
    output<<"Resumen Final:"<<endl;
    output<<"total_videos_estadistica: "<<total_videos_estadistica<<endl;
    output<<"duracion_videos_estadistica: "<<duracion_videos_estadistica<<endl;
    imprimir_linea(output,'=');
    
}
