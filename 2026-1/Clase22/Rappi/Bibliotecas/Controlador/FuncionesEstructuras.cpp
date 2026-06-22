//
// Created by erasmo on 6/13/26.
//

#include "FuncionesEstructuras.hpp"

Conductor leer_conductor(ifstream &input) {
    //301,LIMA NORTE,7845,QUISPE ROJAS MARIO ALBERTO,35.50,6123,TORRES VEGA ANA LUCIA,42.80
    Conductor c;
    c.codigo = leer_entero(input, true);
    c.nombre = leer_cadena(input, ',', 100);
    c.tarifa = leer_double(input, false);
    return c;
}

void cargar_conductores(const char *nombre_archivo,
                        Conductor *&conductores,
                        int &cantidad_conductores) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    int codigo_ruta = 0;
    char ruta[80];

    //RESERVA DE MEMORIA
    conductores = new Conductor[MAX_CONDUCTORES];
    //301,LIMA NORTE,7845,QUISPE ROJAS MARIO ALBERTO,35.50,6123,TORRES VEGA ANA LUCIA,42.80
    while (true) {
        /*
         * Si fuera una cadena al inicio, deberian leer con char buffer[50]
         * input.getline(buffer, 50, ',');
         */
        input >> codigo_ruta;
        if (input.eof())break;
        input.ignore();
        input.getline(ruta, 80, ',');
        while (true) {
            conductores[cantidad_conductores] = leer_conductor(input);
            conductores[cantidad_conductores].codigo_ruta = codigo_ruta;
            conductores[cantidad_conductores].ruta = asignar_cadena(ruta);
            char c = input.get();
            cantidad_conductores++;
            if (c == '\n') break;
        }
    }
}

void imprimir_encabezados_reporte_simple(ofstream &output) {
    output << fixed;
    output << setprecision(2);
    output << left;
    output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << "CODIGO";
    output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << "NOMBRE";
    output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << "CODIGO RUTA";
    output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << "RUTA";
    output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << "TARIFA" << endl;
    imprimir_linea('=', ANCHO_REPORTE, output);
}

void crear_reporte_simple(const char *nombre_archivo,
                          const Conductor *conductores,
                          int cantidad_conductores) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);
    char titulo[80] = "REPORTE SIMPLE CONDUCTORES";
    output << setw((ANCHO_REPORTE + strlen(titulo)) / 2) << titulo << endl;
    imprimir_linea('=', ANCHO_REPORTE, output);
    imprimir_encabezados_reporte_simple(output);
    for (int i = 0; i < cantidad_conductores; i++) {
        output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << conductores[i].codigo;
        output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << conductores[i].nombre;
        output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << conductores[i].codigo_ruta;
        output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << conductores[i].ruta;
        output << setw(ANCHO_REPORTE / N_COLUMNAS_SIMPLE) << conductores[i].tarifa;
        output << endl;
    }
}

void swap_struct(Conductor &a, Conductor &b) {
    Conductor aux = a;
    a = b;
    b = aux;
}

void ordenar_conductores(Conductor *conductores, int cantidad_conductores) {
    for (int i = 0; i < cantidad_conductores - 1; i++)
        for (int j = i + 1; j < cantidad_conductores; j++) {
            if ((strcmp(conductores[i].nombre, conductores[j].nombre) > 0))
                swap_struct(conductores[i], conductores[j]);
        }
}

Fecha leer_fecha(ifstream &input) {
    Fecha f;
    int dd;
    char c;
    input >> dd;
    if (input.eof()) return f;
    f.dia = dd;
    input >> c >> f.mes >> c >> f.anho;
    input.ignore();
    f.fecha_AAAAMMDD = 10000 * f.anho + 100 * f.mes + f.dia;
    return f;
}

Hora leer_hora(ifstream &input) {
    Hora h;
    char c;
    input >> h.horas >> c >> h.minutos >> c >> h.segundos;
    h.segundos_HHMMSS = h.horas * 3600 + h.minutos * 60 + h.segundos;
    input.ignore();
    return h;
}

Codigo leer_codigo(ifstream &input) {
    Codigo c;
    char guion;
    input >> c.valor1 >> guion >> c.valor2 >> guion >> c.valor3;
    input.ignore();
    return c;
}

Hora calcular_duracion(Hora &h_entrada, Hora &h_saida) {
    Hora h;
    h.segundos_HHMMSS = h_saida.segundos_HHMMSS - h_entrada.segundos_HHMMSS;
    h.segundos = h.segundos_HHMMSS / 3600;
    h.minutos = h.segundos_HHMMSS / 60;
    h.horas = h.segundos_HHMMSS % 3600;
    return h;
}

Envio leer_envio(ifstream &input) {
    struct Envio e;
    Hora h_entrada, h_salida;
    input.ignore(20, ','); // Ignoramos la sede
    h_entrada = leer_hora(input);
    e.cliente = leer_codigo(input);
    h_salida = leer_hora(input);
    e.codigoConductor = leer_entero(input, false);
    e.duracion = calcular_duracion(h_entrada, h_salida);
    return e;
}

void cargar_envios(const char *nombre_archivo, Envio *envios, int &cantidad_envios) {
    //1/04/2023,102,08:15:00,CLI-45-8912,10:30:20,7845,205,09:10:00,CLI-77-3401,11:05:45,6123
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //Reservamos Memoria
    envios = new Envio[MAX_ENVIOS];

    Fecha f;
    while (true) {
        f = leer_fecha(input);
        if (input.eof())break;
        while (true) {
            envios[cantidad_envios] = leer_envio(input);
            envios[cantidad_envios].fecha = f;
            cantidad_envios++;
            char c = input.get();
            if (c == '\n') break;
        }
    }
}

void swap_struct_envio(Envio &a, Envio &b) {
    Envio aux = a;
    a = b;
    b = aux;
}

void ordenar_envios(Envio *envios, int cantidad_envios) {
    for (int i = 0; i < cantidad_envios - 1; i++)
        for (int j = i + 1; j < cantidad_envios; j++)
            if (envios[i].codigoConductor < envios[j].codigoConductor)
                swap_struct_envio(envios[i], envios[j]);
}
