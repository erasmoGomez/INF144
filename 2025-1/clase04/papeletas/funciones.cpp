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

int leer_fecha() {
    int fecha, dd, mm, aa;
    char slash;
    //07/05/2024
    cin >> dd >> slash >> mm >> slash>>aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

void imprime_fecha(int fecha) {
    //    int dd,mm,aa;
    //    int res;
    //    aa = fecha/10000;
    //    res = fecha%10000;
    //    mm = res/100;
    //    dd = res%100;
    //    cout<<"Fecha: "<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/';
    //    cout<<setfill(' ')<<setw(4)<<aa<<endl;
    cout << "Fecha: "
            << setfill('0') << setw(2) << (fecha % 100) << '/'
            << setw(2) << (fecha / 100 % 100) << '/'
            << setfill(' ') << (fecha / 10000) << endl;
    cout << setfill(' ');
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
    cout << "Hora: "
            << setfill('0') << setw(2) << s / 3600 << ':'
            << setw(2) << (s / 60) % 60 << ':'
            << setw(2) << s % 60 << endl;
    cout<<setfill(' ');
}

void ignorar_nombre() {
    char c;
    cin>>ws; // lee todos los espacion NO visibles del buffer
    while (true) {
        c = cin.get();
        if (c == ' ')break;
    }
}

void leer_imprimir_location(const char* tipo) {
    int h_loc = 0, m_loc = 0, s_loc = 0;
    char car;
    //-88°21'19"
    //38°25'5"
    cout << tipo << ": " << endl;

    cin >> h_loc>>car;
    cin >> m_loc>>car;
    cin >> s_loc>>car;
    cout << setw(15) << right << "Horas: " << setw(4) << h_loc;
    cout << setw(15) << right << "Minutos: " << setw(4) << m_loc;
    cout << setw(15) << right << "Segundos: " << setw(4) << s_loc << endl;

    //cout<<right<<setw(10)<<"Horas: "<<h_loc<<" Minutos: "<<m_loc<<" Segundos: "<<s_loc<<endl;
}

void leer_y_procesar_papeletas() {
    //07/05/2024 64432010 Gomez/Lopez/Luisa 23:25:17 3 -88°21'19" 38°25'5" 785.85 2 0
    int fecha, dni, hora, tipo_falta, puntos;
    double monto;
    bool estado;
    cout<<setprecision(3);
    cout<<fixed;
    while (true) {
        fecha = leer_fecha();
        if (cin.eof()) break;
        cin>>dni;
        ignorar_nombre();
        hora = leer_hora();
        cin>>tipo_falta;
        imprime_fecha(fecha);
        cout << "DNI: " << dni << endl;
        imprime_hora(hora);
        leer_imprimir_location("Latitud");
        leer_imprimir_location("Longitud");
        cin>>monto;
        cin>>puntos;
        cin>>estado;
        cout << "Monto: " << monto << endl;
        cout << "Puntos: " << puntos << endl;
        cout << "Estado: " << estado << endl;
        cout << endl;
    }
}