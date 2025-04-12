/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 9, 2025, 11:42 AM
 */

#include "funciones.hpp"

void imprimir_linea(char c) {
    cout << setfill(c) << setw(TAM_REPORTE) << "" << endl;
    cout << setfill(' ');
}

void imprimir_titulo(const char* titulo, const char* sub_titulo) {
    cout << setw((TAM_REPORTE + TITULO_TAM_CAR) / 2) << titulo << endl;
    imprimir_linea('=');
    cout << setw((TAM_REPORTE + SUB_TITULO_TAM_CAR) / 2) << sub_titulo << endl;
    imprimir_linea('=');
}

void imprimir_headers() {
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "DNI No.";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "Sexo";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "Categoria";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "Hora (P)";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "Hora (A)";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 5) << "Duracion (H:M:S)";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "Duracion (H)";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "Canales";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 5) << "Compania";
    cout << endl;
    imprimir_linea('-');
}

int transformar_seg(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

void calcular_duracion(int tiempo, int &hh_dur, int &mm_dur, int &ss_dur) {
    hh_dur = tiempo / 3600;
    mm_dur = (tiempo % 3600) / 60;
    ss_dur = (tiempo % 3600) % 60;
}

void imprimir_sexo(char sexo) {
    if (sexo == 'F')
        cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "Femenino";
    else
        cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "Masculino";
}

void imprimir_categoria(int anio) {
    if (anio > 2009)
        cout << setw(TAM_REPORTE / N_COLUMNAS) << "Menor";
    else
        if (anio > 1988)
        cout << setw(TAM_REPORTE / N_COLUMNAS) << "Joven";
    else
        cout << setw(TAM_REPORTE / N_COLUMNAS) << "Adulto";
}
//fija
// reservan 20 espacios y escriben hola
// ****************hola
//variable
// reservan 20 espacios y luego escriben hola
//********************hola
void imprimir_hora(int s, int espacios) {
    cout << setw(TAM_REPORTE / N_COLUMNAS - espacios) << ""
            << setfill('0') << setw(2) << s / 3600 << ':'
            << setw(2) << (s / 60) % 60 << ':'
            << setw(2) << s % 60;
    cout << setfill(' ');
}

void imprimir_hora(int hh, int mm, int ss) {
    cout << setfill('0') << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss
            << setfill(' ') << endl;
}

void imprimir_canales(int canal1, int canal2, int canal3) {
    cout << setw(TAM_REPORTE / N_COLUMNAS -5) << "";
    cout << canal1;
    if (canal2 > 0) {
        cout << '/' << setw(3) << canal2;
        if (canal3 > 0)
            cout << '/' << setw(3) << canal3; // 123/321/333
        else
            cout << setw(4) << ' '; // 123/321   
    } else
        cout << setw(8) << ' '; // 123       
}

void imprimir_compania(char cable) {
    if (cable == 'A')
        cout << setw(TAM_REPORTE / N_COLUMNAS + 4) << "TVPUCP";
    else
        if (cable == 'B')
        cout << setw(TAM_REPORTE / N_COLUMNAS + 4) << "CableMas";
    else
        cout << setw(TAM_REPORTE / N_COLUMNAS + 4) << "TPVision";
}

void imprimir_linea_televidente(char sexo, int fecha, int seg_ini, int seg_fin,
        int tiempo, int canal1, int canal2, int canal3,
        char cable, double &duracion_horas) {
    int aa = fecha / 10000;
    imprimir_sexo(sexo);
    imprimir_categoria(aa);
    imprimir_hora(seg_ini, 8);
    imprimir_hora(seg_fin, 8);
    imprimir_hora(tiempo, 8);
    duracion_horas = tiempo / (double) 3600; //Casteo
    cout << setw(TAM_REPORTE / N_COLUMNAS) << duracion_horas;
    imprimir_canales(canal1, canal2, canal3);
    imprimir_compania(cable);
    cout << endl;
}

int contar_menores(int anio, int segIni, int segFin) {
    return anio > 2009 and segIni >= 14 * 3600 and segFin >= 19 * 3600; //1 o 0 true o false
}

int contar_mujeres(int anio, char sexo, int segIni, int segFin) {
    return sexo == 'F' and anio < 1988 and segIni > 9 * 3600 + 30 * 60 and segFin <= 12 * 3600 + 45 * 60;
}

int contar_hombres(int anio, char sexo, double durHoras) {
//    cout<<endl;
//    cout<<"duracion horas ->: "<<durHoras<<endl;
    return sexo == 'M' and anio > 1988 and anio <= 2009 and durHoras > 1.5;
}

int esCanal770_312_577(int canal) {
    return canal == 770 or canal == 312 or canal == 577;
}

int noEsCanal314_555(int canal) {
    return canal != 314 and canal != 555;
}

int contar_personas_canales(int canal1, int canal2, int canal3) {
    return ((esCanal770_312_577(canal1) or
            esCanal770_312_577(canal2) or
            esCanal770_312_577(canal3)) and
            (noEsCanal314_555(canal1) and
            noEsCanal314_555(canal2) and
            noEsCanal314_555(canal3)));
}

void contar_tiempo_medio_menores_adutlos(int &cantidad, double &suma_tiempo,
        int aa, double tiempo_seg) {
    if (aa > 1988) {
        cantidad++;
        suma_tiempo += tiempo_seg;
    }
}

void actualizar_resumen(int &cantidad_televidentes,
        int &cantidad_menores_14_19, int &cantidad_mujeres_no_tv,
        int &cantidad_hombres_3_horas, int &cantidad_personas_canales,
        double &tiempo_promedio, double &porcentaje_mujeres_tvpucp,
        double &porcentaje_hombres_tvvision, double &porcentaje_adultos,
        double &promedio_canales, int fecha, int seg_ini, int seg_fin, char sexo,
        double dur_horas, int canal1, int canal2, int canal3,
        double &suma_tiempo, int &cantidad) {
    int aa = fecha / 10000;
    cantidad_menores_14_19 += contar_menores(aa, seg_ini, seg_fin);
    cantidad_mujeres_no_tv += contar_mujeres(aa, sexo, seg_ini, seg_fin);
    cantidad_hombres_3_horas += contar_hombres(aa, sexo, dur_horas);
    cantidad_personas_canales += contar_personas_canales(canal1, canal2, canal3);
    contar_tiempo_medio_menores_adutlos(cantidad, suma_tiempo, aa, seg_fin - seg_ini);
}

void procesar_televidente(int dni, int &cantidad_televidentes,
        int &cantidad_menores_14_19, int &cantidad_mujeres_no_tv,
        int &cantidad_hombres_3_horas, int &cantidad_personas_canales,
        double &tiempo_promedio, double &porcentaje_mujeres_tvpucp,
        double &porcentaje_hombres_tvvision, double &porcentaje_adultos,
        double &promedio_canales, double &suma_tiempo, int &cantidad) {
    int hora, tipo_falta, puntos, dd, mm, aa, hh_ini, hh_fin, mm_ini, mm_fin;
    int ss_ini, ss_fin, canal1, canal2, canal3, fecha;
    int hh_dur, mm_dur, ss_dur, seg_ini, seg_fin, tiempo_seg;
    char sexo, car, cable;
    double monto, distancia, duracion_horas = 0;
    bool estado;
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << dni;
    cantidad_televidentes++;
    cin >> sexo >> dd >> car >> mm >> car >> aa;
    cin >> hh_ini >> car >> mm_ini >> car >> ss_ini;
    cin >> hh_fin >> car >> mm_fin >> car >> ss_fin;
    cin >> canal1 >> canal2 >> canal3>> cable; //Hasta aqui hemos leido tooooda la linea
    fecha = aa * 10000 + mm * 100 + dd;
    seg_ini = transformar_seg(hh_ini, mm_ini, ss_ini);
    seg_fin = transformar_seg(hh_fin, mm_fin, ss_fin);
    tiempo_seg = seg_fin - seg_ini;
    calcular_duracion(tiempo_seg, hh_dur, mm_dur, ss_dur);
    imprimir_linea_televidente(sexo, fecha, seg_ini, seg_fin, tiempo_seg,
            canal1, canal2, canal3, cable, duracion_horas);
    actualizar_resumen(cantidad_televidentes,
            cantidad_menores_14_19, cantidad_mujeres_no_tv,
            cantidad_hombres_3_horas, cantidad_personas_canales,
            tiempo_promedio, porcentaje_mujeres_tvpucp,
            porcentaje_hombres_tvvision, porcentaje_adultos,
            promedio_canales, fecha, seg_ini, seg_fin, sexo,
            duracion_horas, canal1, canal2, canal3, suma_tiempo, cantidad);
}

void imprime_resumen(int cantDatos, int cantMen1419, int cantMujAd912,
        int cantHomJov3, int cantPersCan, int tiempoPromHor, int tiempoPromMin,
        int tiempoPromSeg) {
    imprimir_linea('=');
    cout << setw(5) << ' ' << "ESTADISTICAS OBTENIDAS" << endl;
    cout << setw(5) << ' ' << "Cantidad de televidentes registrados: " << setw(10)
            << cantDatos << endl;
    cout << setw(5) << ' ' << "Cantidad de menores que ven entre las 14:00:00 y " <<
            "las 19:00:00:" << setw(10) << cantMen1419 << endl;
    cout << setw(5) << ' ' << "Cantidad de mujeres adultas que no ven television entre " <<
            " las 9:30:00 y las 12:45:00 " << setw(10) << cantMujAd912 << endl;
    cout << setw(5) << ' ' << "Cantidad de hombres jovenes que ven mas de 3 horas y media:" <<
            setw(10) << cantHomJov3 << endl;
    cout << setw(5) << ' ' << "Cantidad de personas que ven los canales 770,312 y 577 " <<
            "pero no 314 ni 555 " << setw(10) << cantPersCan << endl;
    cout << setw(5) << ' ' << "Tiempo promedio que ven los menores y adulltos " <<
            setw(10) << ' ';
    imprimir_hora(tiempoPromHor, tiempoPromMin, tiempoPromSeg);
    imprimir_linea('=');
}

void leer_procesar_televidentes() {
    //69323674    M    31/03/2013  13:54:27     16:12:37   556    0    0     B
    cout << fixed << setprecision(2); // SIEMPRE AL INICIO DE MI PROGRAMA
    imprimir_titulo("EMPRESA DE OPINION DE MERCADO S.A.", "REGISTRO DE PREFERENCIAS DE LOSTELEVIDENTES");
    imprimir_headers();
    int dni, cantidad_televidentes = 0, cantidad_menores_14_19 = 0, cantidad_mujeres_no_tv = 0;
    int cantidad_hombres_3_horas = 0, cantidad_personas_canales = 0;
    double porcentaje_mujeres_tvpucp = 0;
    double porcentaje_hombres_tvvision = 0, porcentaje_adultos = 0, promedio_canales = 0;
    double suma_tiempo = 0, tiempo_promedio = 0;
    int cantidad = 0;
    int tiempo_promedio_hh = 0, tiempo_promedio_mm = 0, tiempo_promedio_ss = 0;
    while (true) {
        cin>>dni; //Primera lectura
        if (cin.eof()) break; // Luego de la primera lectura, se valida fin de archivo. Si se llego al final del archivo entonces salgo del bucle.
        procesar_televidente(dni, cantidad_televidentes,
                cantidad_menores_14_19, cantidad_mujeres_no_tv,
                cantidad_hombres_3_horas, cantidad_personas_canales,
                tiempo_promedio, porcentaje_mujeres_tvpucp,
                porcentaje_hombres_tvvision, porcentaje_adultos, promedio_canales,
                suma_tiempo, cantidad);
    }
    tiempo_promedio = suma_tiempo / cantidad;
    tiempo_promedio_hh = tiempo_promedio / 3600;
    tiempo_promedio_mm = ((int)tiempo_promedio % 3600) / 60;
    tiempo_promedio_ss = ((int)tiempo_promedio % 3600) % 60;
    imprime_resumen(cantidad_televidentes, cantidad_menores_14_19, cantidad_mujeres_no_tv, cantidad_hombres_3_horas,
            cantidad_personas_canales, tiempo_promedio_hh, tiempo_promedio_mm, tiempo_promedio_ss);

}