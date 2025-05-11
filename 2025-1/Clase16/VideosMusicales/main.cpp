/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on May 9, 2025, 3:45 PM
 */

#include "funciones.hpp"    

/*
 * 
 */
int main(int argc, char** argv) {
    //Videos.txt
    char tipos_videos[MAX_VIDEOS]{};
    int codigos_videos[MAX_VIDEOS]{};
    double duraciones_videos[MAX_VIDEOS]{};
    //UsuariosRegistrados.txt
    int dnis_registrados[MAX_USUARIOS_REGISTRADOS]{};
    //DispositivosRegistrados.txt
    int dnis_dispositivos[MAX_DISPOSITIVOS_REGISTRADOS]{};
    char tipos_dispositivos[MAX_DISPOSITIVOS_REGISTRADOS]{};
    int codigo_dispositivos[MAX_DISPOSITIVOS_REGISTRADOS]{};
    
    //Cantidades
    int cantidad_videos = 0, cantidad_registrados = 0, cantidad_dispostivos = 0;
    
    //Calculos intermedios en arreglos Auxiliares //POP, ROCK, TOTAL
    int cantidades_videos_usuarios[3*MAX_USUARIOS_REGISTRADOS]{};
    double duraciones_videos_usuarios[3*MAX_USUARIOS_REGISTRADOS]{};
    int total_videos_estadistica = 0;
    double duracion_videos_estadistica = 0;
    
    //Archivos Reutilizables
    ifstream input_usuarios_registrados;
    apertura_archivo_lectura(input_usuarios_registrados, "UsuariosRegistrados.txt");
    
    //Carga de datos
    cargar_datos_videos("Videos.txt", tipos_videos, codigos_videos, duraciones_videos, cantidad_videos);
    cargar_datos_usuarios(input_usuarios_registrados, dnis_registrados, cantidad_registrados);
    cargar_datos_dispositivos("DispositivosRegistrados.txt", dnis_dispositivos, tipos_dispositivos, codigo_dispositivos, cantidad_dispostivos);
    //Ordenar usuarios
    ordenar_usuarios_registrados(dnis_registrados, cantidad_registrados);
    //Procesar datos
    leer_procesar_usuarios("Reproducciones.txt", dnis_registrados, cantidad_registrados,
                            tipos_videos, codigos_videos, duraciones_videos, cantidad_videos,
                            dnis_dispositivos, tipos_dispositivos, codigo_dispositivos, cantidad_dispostivos,
                            cantidades_videos_usuarios, duraciones_videos_usuarios,
                            total_videos_estadistica, duracion_videos_estadistica);

    imprimir_reporte("reporte.txt", dnis_registrados,
                     cantidad_registrados, input_usuarios_registrados,
                     cantidades_videos_usuarios,
                     duraciones_videos_usuarios,
                     total_videos_estadistica,
                     duracion_videos_estadistica);
    return 0;
}

