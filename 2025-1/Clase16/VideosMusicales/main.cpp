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
    
    cargar_datos_videos("Videos.txt", tipos_videos, codigos_videos, duraciones_videos, cantidad_videos);
    cargar_datos_dispositivos("DispositivosRegistrados.txt", dnis_dispositivos, tipos_dispositivos, codigo_dispositivos, cantidad_dispostivos);
    cout<<cantidad_videos<<endl;
    cout<<cantidad_dispostivos<<endl;
    return 0;
}

