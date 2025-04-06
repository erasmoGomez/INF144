/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: hecto
 * 
 * Created on April 3, 2025, 4:46 PM
 */

#include "funciones.hpp"

const char* nombreMes(int mes) {
    switch (mes) {
        case 1: return "Enero";
        case 2: return "Febrero";
        case 3: return "Marzo";
        case 4: return "Abril";
        case 5: return "Mayo";
        case 6: return "Junio";
        case 7: return "Julio";
        case 8: return "Agosto";
        case 9: return "Setiembre";
        case 10: return "Octubre";
        case 11: return "Noviembre";
        case 12: return "Diciembre";
        default: return "";
    }
}

void imprimir_rango_meses(int inicio, int fin) {
    //5 a 7
    for (int i = inicio; i <= fin; ++i) {
        cout << nombreMes(i);
        if (i < fin - 1) {
            cout << ", ";
        } else if (i == fin - 1) {
            cout << " y ";
        }
    }
    cout << endl;
}

int leer_fecha() {
    int fecha, dd, mm, aa;
    char slash;
    //07/05/2024
    cin >> dd >> slash >> mm >> slash>>aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

void imprime_fecha(int fecha) {
    //        int dd,mm,aa;
    //        int res;
    //        aa = fecha/10000;
    //        res = fecha%10000;
    //        mm = res/100;
    //        dd = res%100;
    //        cout<<"Fecha: "<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/';
    //        cout<<setfill(' ')<<setw(4)<<aa<<endl;
    cout << setw(TAM_REPORTE/N_COLUMNAS-13)<<""
            << setfill('0') << setw(2) << (fecha % 100) << '/'
            << setw(2) << (fecha / 100 % 100) << '/'
            << setfill(' ') << (fecha / 10000);
}

int leer_hora() {
    int hora, hh, mm, ss;
    char dospuntos;
    //23:25:17
    cin >> hh >> dospuntos >> mm >> dospuntos>>ss;
    hora = hh * 3600 + mm * 60 + ss;
    return hora;
}

void imprime_hora(int s) {
    cout << setw(TAM_REPORTE/N_COLUMNAS-15)<<""
            << setfill('0') << setw(2) << s / 3600 << ':'
            << setw(2) << (s / 60) % 60 << ':'
            << setw(2) << s % 60 << endl;
    cout << setfill(' ');
}

void ignorar_nombre() {
    char c;
    cin>>ws; // lee todos los espacion NO visibles del buffer
    while (true) {
        c = cin.get();
        if (c == ' ')break;
    }
}

void lee_imprime_nombre() {
    int n=0;
    char c;
    cin>>ws; // lee todos los espacion NO visibles del buffer
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5)<<"";
    while (true) {
        c = cin.get();
        if (c == ' ')break;
        if (c == '/')c = ' ';
        cout.put(c);
        n++;
    }
    int tam = TAM_REPORTE/N_COLUMNAS;
    //Imprimir espacios en blanco.
    for(int i=0; i<tam-n; i++)cout.put(' ');
}

void leer_imprimir_location(const char* tipo) {
    int h_loc = 0, m_loc = 0, s_loc = 0;
    char car;
    //-88°21'19"
    //38°25'5"
    //cout << tipo << ": " << endl;

    cin >> h_loc >> car >> m_loc >> car >> s_loc>>car;

//    cout << setw(15) << right << "Horas: " << setw(4) << h_loc;
//    cout << setw(15) << right << "Minutos: " << setw(4) << m_loc;
//    cout << setw(15) << right << "Segundos: " << setw(4) << s_loc << endl;

    //cout<<right<<setw(10)<<"Horas: "<<h_loc<<" Minutos: "<<m_loc<<" Segundos: "<<s_loc<<endl;
}

void imprimir_linea(char c) {
    //for(int i=0; i<TAM_REPORTE; i++) cout.put(c);
    cout << setfill(c) << setw(TAM_REPORTE - 1) << c << endl;
    cout << setfill(' ');
}

void imprimir_titulo(const char* titulo, int mes_inicio, int mes_final) {
    imprimir_linea('*');
    //Impresion FIJA!
    cout << setw((TAM_REPORTE + TITULO_TAM_CAR) / 2) << titulo << endl;
    //Impresion VARIABLE
    cout << setw((TAM_REPORTE - SUB_TITULO_TAM_CAR) / 2) << "";
    imprimir_rango_meses(mes_inicio, mes_final);
    imprimir_linea('*');
}

void imprimir_headers() {
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "FECHA";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "DNI";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 10) << "NOMBRE";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "HORA";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "TIPO";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "DISTANCIA";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "MONTO";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "ESTADO";
    cout << endl;
    imprimir_linea('*');
}

void leer_y_procesar_papeletas() {
    //07/05/2024 64432010 Gomez/Lopez/Luisa 23:25:17 3 -88°21'19" 38°25'5" 785.85 2 0
    int fecha, dni, hora, tipo_falta, puntos;
    double monto;
    bool estado;
    cout << fixed;
    cout << setprecision(3);

    imprimir_titulo("REPORTE DE PAPELETAS DE LOS MESES", 5, 7);
    imprimir_headers();
    while (true) {
        fecha = leer_fecha();
        if (cin.eof())break;
        cin>>dni;
        imprime_fecha(fecha);
        cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << dni;
        //ignorar_nombre();
        lee_imprime_nombre();
        hora = leer_hora();
        cin>>tipo_falta;
        
        imprime_hora(hora);
        leer_imprimir_location("Latitud");
        leer_imprimir_location("Longitud");
        cin>>monto;
        cin>>puntos;
        cin>>estado;
//        cout << "Monto: " << monto << endl;
//        cout << "Puntos: " << puntos << endl;
//        cout << "Estado: " << estado << endl;
        cout << endl;
    }
}