/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funciones.cpp
 * Author: Erasmo Gomez
 * Description: 
 * Created on April 25, 2025, 2:49 PM
 */

#include "funciones.hpp"

void apertura_archivo_lectura(ifstream &input, const char* nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (not input.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char* nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (not output.is_open()) {
        cout << "Error: el archivo: " << nombre_archivo << " No se puede abrir" << endl;
        exit(1);
    }
}

void imprimir_fecha(int fecha, ofstream &output) {
    output << setw(TAM_REPORTE / N_COLUMNAS - 13) << ""
            << setfill('0') << setw(2) << (fecha % 100) << '/'
            << setw(2) << (fecha / 100 % 100) << '/'
            << setfill(' ') << (fecha / 10000);
}

void imprimir_linea(ofstream &output, char c) {
    output << setfill(c) << setw(TAM_REPORTE - 1) << c << endl;
    output << setfill(' ');
}

void imprimir_titulo(ofstream & output, const char* titulo) {
    imprimir_linea(output, '=');
    output << setw((TAM_REPORTE + TAM_TITULO_CAR) / 2) << titulo << endl;
    imprimir_linea(output, '=');
}

int leer_dni_plan(ifstream &input) {
    int dni;
    char c;
    input >> c >> c >> c>>dni;
    return dni;
}

int leer_codigo_plan(ifstream& input) {
    int codigo;
    char c;
    input >> c >> c>>codigo;
    return codigo;
}

int leer_fecha(ifstream &input) {
    int fecha, dd, mm, aa;
    char guion;
    input >> aa >> guion >> mm >> guion >> dd;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

void busca_imprime_nombre(ifstream &input, ofstream & output, int n_cliente, int dni) {
    input.clear();
    input.seekg(0, ios::beg);
    //DNI93466845 Peral-Olmedo-Adriana
    int dni_leido = 0;
    char c;
    while (true) {
        dni_leido = leer_dni_plan(input);
        if (input.eof())break;
        if (dni_leido == dni)break;
        else {
            input.ignore(50, '\n');
        }
    }
    if (not dni_leido) {
        output << "NO SE ENCONTRO NOMBRE" << endl;
        return;
    } else {
        int n_caracteres = 0;
        char c;
        output << "CLIENTE No. " << n_cliente << endl;
        output << "NOMBRE: ";
        input >> ws; //Leer todos los espacios en blanco
        while (true) {
            c = input.get(); //Lee un caracter
            if (c == '\n') break; //OJO
            if (c == '-') c = ' ';
            if (c >= 'a' and c <= 'z') c -= 'a' - 'A';
            //c = transforma_mayuscula(c);
            output.put(c); //Imprime un caracter
            n_caracteres++;
        }
        int tam = TAM_REPORTE / 2;
        for (int i = 0; i < tam - n_caracteres; i++) output.put(' ');
        output << "DNI: " << dni << endl;
        imprimir_linea(output, '-');
    }
}

void leer_imprimir_plan(ifstream &input, ofstream & output) {
    int n_caracteres = 0;
    char c;
    input >> ws; //Leer todos los espacios en blanco
    output << setw(TAM_REPORTE / N_COLUMNAS - 5) << "";
    while (true) {
        c = input.get(); //Lee un caracter
        if (c == ' ') break;
        if (c == '_') c = ' ';
        if (c >= 'a' and c <= 'z') c -= 'a' - 'A';
        output.put(c); //Imprime un caracter
        n_caracteres++;
    }
    int tam = TAM_REPORTE / N_COLUMNAS;
    for (int i = 0; i < tam - n_caracteres; i++) output.put(' ');
}

double buscar_precio_base_plan(ifstream &input_planes, ofstream& output, int codigo_plan) {
    double precio_base = 0;
    //setear y limpiar el buffer
    input_planes.clear(); //Libera el buffer del archivo y limpia las banderas levantadas
    input_planes.seekg(0, ios::beg); //Devuelve el puntero al inicio del archivo
    int codigo_plan_leido;
    while (true) {
        codigo_plan_leido = leer_codigo_plan(input_planes);
        if (input_planes.eof()) break;
        if (codigo_plan_leido == codigo_plan) {
            leer_imprimir_plan(input_planes, output);
            input_planes>>precio_base;
            return precio_base;
        } else {
            //ignorar
            input_planes.ignore(50, '\n');
            continue;
        }
    }
    return precio_base;
}

void busca_imprime_plan_telefono(ifstream &input_planes, ifstream &input_telefonos,
        ofstream &output, int dni, int codigo_plan, double &monto_cliente, double &monto_total) {
    input_telefonos.clear();
    input_telefonos.seekg(0, ios::beg);
    
    int dni_leido = 0, codigo_plan_leido = 0, telefono, fecha_inicial, fecha_final;
    double monto_plan = 0, precio_base_plan = 0, monto_real_plan = 0;
    //DNI57765977 PB101 930254571 2025-12-18 2026-03-05 86.77
    while (true) {
        dni_leido = leer_dni_plan(input_telefonos);
        if (input_telefonos.eof())break; //Validar fin de archivo
        codigo_plan_leido = leer_codigo_plan(input_telefonos);
        if (dni_leido == dni and codigo_plan_leido == codigo_plan) break;
        else
            input_telefonos.ignore(60, '\n');
    }

    input_telefonos>>telefono;
    fecha_inicial = leer_fecha(input_telefonos);
    fecha_final = leer_fecha(input_telefonos);
    input_telefonos>>monto_plan;
    
    output << setw(TAM_REPORTE / N_COLUMNAS - 15) << telefono;
    
    precio_base_plan = buscar_precio_base_plan(input_planes, output, codigo_plan);

    monto_real_plan = monto_plan + precio_base_plan;
    monto_cliente += monto_real_plan;
    monto_total += monto_real_plan;

    imprimir_fecha(fecha_inicial, output);
    imprimir_fecha(fecha_final, output);
    output << setw(TAM_REPORTE / N_COLUMNAS) << monto_real_plan << endl;

}

void actualiza_estadisticos(int dni, double monto_cliente, 
                            int &dni_cliente_mayor_pago, 
                            double &monto_cliente_mayor_pago, 
                            int &dni_cliente_menor_pago, 
                            double &monto_cliente_menor_pago){
    if(monto_cliente>monto_cliente_mayor_pago){
        monto_cliente_mayor_pago = monto_cliente;
        dni_cliente_mayor_pago = dni;
    }
    if(monto_cliente<monto_cliente_menor_pago){
        monto_cliente_menor_pago = monto_cliente;
        dni_cliente_menor_pago = dni;
    }
}

void procesar_clientes_moviles(ifstream &input_clientes, ifstream &input_planes,
                               ifstream &input_telefonos, ifstream &input_contratos,
                               ofstream & output, double &monto_total, 
                               int &dni_cliente_mayor_pago, double &monto_cliente_mayor_pago,
                               int &dni_cliente_menor_pago, double &monto_cliente_menor_pago) {
    int dni, n_clientes = 0, codigo_plan;
    double monto_cliente = 0;
    char c;
    //DNI51086918 PP103 PP102
    while (true) {
        //Parte Fija
        //input_contratos >> c >> c >> c>>dni;
        dni = leer_dni_plan(input_contratos);
        if (input_contratos.eof())break; //FIN DE ARCHIVO
        n_clientes++;
        busca_imprime_nombre(input_clientes, output, n_clientes, dni);
        //Parte Variable
        monto_cliente = 0;
        while (true) {
            codigo_plan = leer_codigo_plan(input_contratos);
            busca_imprime_plan_telefono(input_planes, input_telefonos, output, dni, codigo_plan, monto_cliente, monto_total);
            //Verificacion de fin de linea
            c = input_contratos.get();
            if (c == '\n') {
                output << endl;
                break; //FIN DE LINEA
            }
        }
        actualiza_estadisticos(dni, monto_cliente, dni_cliente_mayor_pago, 
                               monto_cliente_mayor_pago, dni_cliente_menor_pago, 
                               monto_cliente_menor_pago);
        //Imprimir resumen x Cliente
        imprimir_titulo(output, "RESUME X CLIENTE");
        output << "El monto parcial por cliente es :" << monto_cliente << endl;
        imprimir_linea(output, '-');
    }
}

void imprimir_resumen_pago_lineas(ofstream &output, int dni_mayor, double total_mayor, int dni_menor, double total_menor) {
    output << setfill('+') << setw(TAM_REPORTE/3) << "+" << endl << setfill(' ');
    output << "+ PERSONA CON MAYOR PAGO POR LINEAS:   +" << endl;

    output << "+ DNI: " << left << setw(TAM_REPORTE/3 - 8) << dni_mayor << "+" << endl;
    output << "+ TOTAL PAGADO: " << left << setw(TAM_REPORTE/3 - 17) << fixed << setprecision(2) << total_mayor << "+" << endl;

    output << setfill('+') << setw(TAM_REPORTE/3) << "+" << endl << setfill(' ');
    output << "+ PERSONA CON MENOR PAGO POR LINEAS:   +" << endl;

    output << "+ DNI: " << left << setw(TAM_REPORTE/3 - 8) << dni_menor << "+" << endl;
    output << "+ TOTAL PAGADO: " << left << setw(TAM_REPORTE/3 - 17) << fixed << setprecision(2) << total_menor << "+" << endl;

    output << setfill('+') << setw(TAM_REPORTE/3) << "+" << endl << setfill(' ');
}

void imprimir_resumen_final(ofstream& output, double monto_total, 
                            int dni_mayor, 
                            double monto_mayor,
                            int dni_menor,
                            double monto_menor) {
    imprimir_titulo(output, "RESUMEN FINAL");
    output << "El pago total de 2025 es: " << monto_total << endl;
    imprimir_linea(output, '-');
    
    imprimir_resumen_pago_lineas(output, dni_mayor, monto_mayor, dni_menor, monto_menor);
}

void leer_procesar_clientes_moviles(const char* nombre_archivo_clientes_moviles,
                                    const char* nombre_archivo_planes_moviles,
                                    const char* nombre_archivo_telefonos_moviles,
                                    const char* nombre_archivo_contratos_moviles,
                                    const char* nombre_archivo_reporte) {
    ifstream input_clientes, input_planes, input_telefonos, input_contratos;
    ofstream output;
    apertura_archivo_lectura(input_clientes, nombre_archivo_clientes_moviles);
    apertura_archivo_lectura(input_planes, nombre_archivo_planes_moviles);
    apertura_archivo_lectura(input_telefonos, nombre_archivo_telefonos_moviles);
    apertura_archivo_lectura(input_contratos, nombre_archivo_contratos_moviles);
    apertura_archivo_escritura(output, nombre_archivo_reporte);
    int dni_cliente_mayor_pago = 0, dni_cliente_menor_pago  = 0;
    double monto_cliente_mayor_pago = 0, monto_cliente_menor_pago = 1e09 ;
    double monto_total = 0;
    imprimir_titulo(output, "REPORTE DE PLANES LINEAS MOVILES");
    procesar_clientes_moviles(input_clientes, 
                              input_planes, 
                              input_telefonos, 
                              input_contratos, 
                              output, 
                              monto_total,
                              dni_cliente_mayor_pago, monto_cliente_mayor_pago,
                              dni_cliente_menor_pago, monto_cliente_menor_pago);
    imprimir_resumen_final(output, monto_total, dni_cliente_mayor_pago, monto_cliente_mayor_pago,
                           dni_cliente_menor_pago, monto_cliente_menor_pago);
}