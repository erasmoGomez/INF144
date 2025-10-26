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

void swapInt(int &a, int &b) {
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void swapDouble(double &a, double &b) {
    double aux;
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

int read_time(ifstream &input) {
    //1:22:25
    int hh, mm, ss;
    char c;
    input >> hh >> c >> mm >> c >> ss;
    return hh * 3600 + mm * 60 + ss;
}

void cargar_videos(const char *file_name, int *codigos,
                   int *duraciones, int *codigos_idioma, int &n_videos) {
    //316186    1:22:25    4003    C1072
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo;
    while (true) {
        input >> codigo;
        if (input.eof())break;
        codigos[n_videos] = codigo;
        duraciones[n_videos] = read_time(input);
        input >> codigos_idioma[n_videos];
        ignorar(input, '\n');
        n_videos++;
    }
}

void llenar_arreglos_archivo(ifstream &input, int codigo_video, int i,
                             int *fechas_antiguas, int *fechas_recientes,
                             double *promedios_rating, double *tasas) {
    input.clear();
    input.seekg(0, ios::beg);
    //4/11/2025       Evelone192    450161    28/7/2025    19:47:03    1.39    0.052    316186    20/8/2025    10:49:46    4.92    0.69    501133    26/7/2025    02:38:02    2.69    0.004
    int fecha, codigo_video_leido;
    char c;
    while (true) {
        //Parte Estatica
        fecha = read_date(input);
        if (input.eof())break;
        ignorar(input, ' ');
        //Parte Dinamica
        int veces = 0;
        int fecha_leida, duracion_leida;
        double rating_leido, tasa;
        while (true) {
            veces = 0;
            input >> codigo_video_leido;
            //28/7/2025    19:47:03    1.39    0.052
            if (codigo_video_leido == codigo_video) {
                //hacer cosas cheveres
                fecha_leida = read_date(input);
                duracion_leida = read_time(input);
                input >> rating_leido >> tasa;
                c = input.get();
                if (fechas_antiguas[i] > fecha_leida) {
                    fechas_antiguas[i] = fecha_leida;
                }
                if (fechas_recientes[i] < fecha_leida) {
                    fechas_recientes[i] = fecha_leida;
                }
                promedios_rating[i] += rating_leido;
                veces++;
                if (tasas[i] > tasa) {
                    tasas[i] = tasa;
                }
            } else {
                //De ir hasta el nuevo codigo en la linea
                fecha_leida = read_date(input);
                duracion_leida = read_time(input);
                input >> rating_leido >> tasa;
                c = input.get();
            };
            if (c == '\n') break;
        }
        promedios_rating[i] = promedios_rating[i] / (double) veces;
    }
}

void llenar_nuevos_arreglos(const char *file_name, int *codigos, int *fechas_antiguas, int *fechas_recientes,
                            double *promedios_rating, double *tasas, int n_videos) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo_video;
    for (int i = 0; i < n_videos; i++) {
        codigo_video = codigos[i];
        llenar_arreglos_archivo(input, codigo_video, i, fechas_antiguas, fechas_recientes, promedios_rating, tasas);
    }
}

void ordenacion(int *codigos, int *duraciones, int *codigos_idioma, int *fechas_antiguas, int *fechas_recientes,
                double *promedios_rating, double *tasas, int n_videos) {
    for (int i = 0; i < n_videos - 1; i++)
        for (int k = i + 1; k < n_videos; k++) {
            if (codigos_idioma[k] > codigos_idioma[i] or codigos_idioma[k] == codigos_idioma[i] and
                duraciones[k] < duraciones[i]) {
                swapInt(codigos[i], codigos[k]);
                swapInt(duraciones[i], duraciones[k]);
                swapInt(codigos_idioma[i], codigos_idioma[k]);
                swapInt(fechas_antiguas[i], fechas_antiguas[k]);
                swapInt(fechas_recientes[i], fechas_recientes[k]);
                swapDouble(promedios_rating[i], promedios_rating[k]);
                swapDouble(tasas[i], tasas[k]);
            }
        }


}

void imprimir_datos(const char *file_name, int *codigos, int *duraciones, int *codigos_idioma, int *fechas_antiguas,
                    int *fechas_recientes, double *promedios_rating, double *tasas, int n_videos) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    output << fixed;
    output << setprecision(2);
    for (int i = 0; i < n_videos; i++) {
        output << setw(15) << codigos[i];
        output << setw(15) << duraciones[i];
        output << setw(15) << codigos_idioma[i];
        if (fechas_antiguas[i])
            output << setw(40) << fechas_antiguas[i];
        else
            output << setw(40) << "No hay fechas para este video";
        if (fechas_recientes[i])
            output << setw(40) << fechas_recientes[i];
        else
            output << setw(40) << "No hay fechas para este video";
        output << setw(15) << promedios_rating[i];
        output << setw(15) << tasas[i] << endl;
    }

}

int buscar_codigo_video(int *codigos, int codigo_video_leido, int n_videos) {
    for (int i = 0; i < n_videos; i++)
        if (codigo_video_leido == codigos[i]) return i;
    return -1;
}

void llenar_nuevos_arreglos_caso_2(const char *file_name,
                                   int *codigos, int *duraciones, int *codigos_idioma,
                                   int *fechas_antiguas, int *fechas_recientes,
                                   double *promedios_rating, double *tasas,
                                   int n_videos) {

    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int n_canales = 0, pos;
    int fecha, fecha_video_leido, codigo_video_leido, hora_video_leido;
    double rating_leido, tasa_leido;
    // 4/11/2025       Evelone192
    // 450161  28/7/2025    19:47:03    1.39    0.052
    // 316186  20/8/2025    10:49:46    4.92    0.69
    // 501133  26/7/2025    02:38:02    2.69    0.004
    while (true) {
        fecha = read_date(input);
        if (input.eof()) break;
        ignorar(input, ' ');
        n_canales++;
        while (true) {
            input >> codigo_video_leido;
            fecha_video_leido = read_date(input);
            hora_video_leido = read_time(input);
            input >> rating_leido >> tasa_leido;
            pos = buscar_codigo_video(codigos, codigo_video_leido, n_videos);
            // Este pos es el indice donde voy a actualizar o completar mis nuevos arreglos
            if (pos != -1) {
                promedios_rating[pos] += rating_leido;
                tasas[pos] += tasa_leido;
                if (fechas_antiguas[pos] == 0 or fecha < fechas_antiguas[pos])
                    fechas_antiguas[pos] = fecha;
                if (fechas_recientes[pos] == 0 or fecha > fechas_recientes[pos])
                    fechas_recientes[pos] = fecha;
            }
            if (input.get() == '\n') break;
        }
    }

}

void insertar_ordenado(int codigo, int duracion, int codigo_idioma,
                       int *codigos, int *duraciones, int *codigos_idioma, int &n_videos) {
    int i = n_videos - 1;
    while (i >= 0 && (codigos[i] > codigo or
                      (codigos[i] == codigo and duraciones[i] > duracion)))  {
        codigos[i + 1] = codigos[i];
        duraciones[i + 1] = duraciones[i];
        codigos_idioma[i + 1] = codigos_idioma[i];
        i--;
    }
    codigos[i + 1] = codigo;
    duraciones[i + 1] = duracion;
    codigos_idioma[i + 1] = codigo_idioma;
    n_videos++;
}

void cargar_videos_ordenados(const char *file_name, int *codigos,
                             int *duraciones, int *codigos_idioma, int &n_videos) {
    //316186    1:22:25    4003    C1072
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int codigo, codigo_idioma;
    int duracion;
    while (true) {
        input >> codigo;
        if (input.eof())break;
        duracion = read_time(input);
        input >> codigo_idioma;
        ignorar(input, '\n');
        insertar_ordenado(codigo, duracion, codigo_idioma,
                          codigos, duraciones, codigos_idioma, n_videos);
    }
}

int busqueda_binaria(int dato_buscar, const int *arr, int n) {
    int limite_inferior = 0, limite_superior = n - 1;
    int punto_medio;
    while (true) {
        if (limite_inferior > limite_superior) return -1;
        punto_medio = (limite_inferior + limite_superior) / 2;
        if (dato_buscar == arr[punto_medio]) return punto_medio;
        if (dato_buscar> arr[punto_medio])
            limite_inferior = punto_medio + 1;
        else
            limite_superior = punto_medio - 1;
    }
}

void llenar_nuevos_arreglos_caso_3(const char *file_name,
                                   int *codigos, int *duraciones, int *codigos_idioma,
                                   int *fechas_antiguas, int *fechas_recientes,
                                   double *promedios_rating, double *tasas,
                                   int n_videos) {

    ifstream input;
    apertura_archivo_lectura(input, file_name);
    int n_canales = 0, pos;
    int fecha, fecha_video_leido, codigo_video_leido, hora_video_leido;
    double rating_leido, tasa_leido;
    // 4/11/2025       Evelone192
    // 450161  28/7/2025    19:47:03    1.39    0.052
    // 316186  20/8/2025    10:49:46    4.92    0.69
    // 501133  26/7/2025    02:38:02    2.69    0.004
    while (true) {
        fecha = read_date(input);
        if (input.eof()) break;
        ignorar(input, ' ');
        n_canales++;
        while (true) {
            input >> codigo_video_leido;
            fecha_video_leido = read_date(input);
            hora_video_leido = read_time(input);
            input >> rating_leido >> tasa_leido;
            pos = busqueda_binaria(codigo_video_leido, codigos, n_videos);
            // Este pos es el indice donde voy a actualizar o completar mis nuevos arreglos
            if (pos != -1) {
                promedios_rating[pos] += rating_leido;
                tasas[pos] += tasa_leido;
                if (fechas_antiguas[pos] == 0 or fecha < fechas_antiguas[pos])
                    fechas_antiguas[pos] = fecha;
                if (fechas_recientes[pos] == 0 or fecha > fechas_recientes[pos])
                    fechas_recientes[pos] = fecha;
            }
            if (input.get() == '\n') break;
        }
    }

}