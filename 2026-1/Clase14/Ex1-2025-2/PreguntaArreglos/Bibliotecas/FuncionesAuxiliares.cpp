//
// Created by erasmog on 8/10/2025.
//

#include "FuncionesAuxiliares.hpp"

void apertura_archivo_lectura(ifstream &archivo, const char *nombre_archivo) {
    archivo.open(nombre_archivo, ios::in);
    if (not archivo.is_open()) {
        cout << "El archivo Archivo lectura: " << nombre_archivo << " no existe" << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &archivo, const char *nombre_archivo) {
    archivo.open(nombre_archivo, ios::out);
    if (not archivo.is_open()) {
        cout << "El archivo Archivo lectura: " << nombre_archivo << " no existe" << endl;
        exit(1);
    }
}

void cargarStreams(const char *nombre_archivo, int *arrStream, int *arrDuracion, int *arrIdioma, char *arrCarCat,
                   int *arrNumCat, int &cantStreams) {
    ifstream archRepro;
    apertura_archivo_lectura(archRepro, nombre_archivo);
    int stream, h, m, s, idioma, numCat, segundos;
    char carCat, c;
    //28/02/1995
    // while (true) {
    //     input>>dia;
    //     if (input.eof())break;
    //     input>>c>>mes>>c>>anio;
    // }
    //532197    1:7:30    4013    W1033
    //INSERTAR ORDENADO
    // 1. Leer todo en variables
    // 2. Llamar a una funcion que inserte ordenado
    //      * Todo lo que se leyo
    //      * Todos los arreglos donde se van a insertar
    //      * Numero de datos
    while (true) {
        archRepro >> stream;
        if (archRepro.eof()) break;
        archRepro >> h >> c >> m >> c >> s >> idioma >> carCat >> numCat;
        segundos = convertirSegundos(h, m, s);
        insertarOrdenado(stream, segundos, idioma, carCat, numCat, arrStream, arrDuracion,
                         arrIdioma, arrCarCat, arrNumCat, cantStreams);
        cantStreams++;
    }
}

int convertirSegundos(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

void insertarOrdenado(int stream, int segundos, int idioma, char carCat, int numCat,
                      int *arrStream, int *arrDuracion, int *arrIdioma, char *arrCarCat, int *arrNumCat,
                      int cantStreams) {
    int i;
    for (i = cantStreams - 1; i >= 0; i--) {
        if (segundos <= arrDuracion[i]) {
            arrStream[i + 1] = arrStream[i];
            arrDuracion[i + 1] = arrDuracion[i];
            arrIdioma[i + 1] = arrIdioma[i];
            arrCarCat[i + 1] = arrCarCat[i];
            arrNumCat[i + 1] = arrNumCat[i];
        } else
            break;
    }
    arrStream[i + 1] = stream;
    arrDuracion[i + 1] = segundos;
    arrIdioma[i + 1] = idioma;
    arrCarCat[i + 1] = carCat;
    arrNumCat[i + 1] = numCat;
}

void mostrarStreams(int *arrStream, int *arrDuracion, int *arrIdioma, char *arrCarCat,
                    int *arrNumCat, int cantStreams) {
    ofstream archRep;
    apertura_archivo_escritura(archRep, "ArchivosDeReporte/Reproducciones-Streams.txt");
    archRep << "LISTA DE STREAMS" << endl;
    archRep << setw(8) << "CODIGO" << setw(13) << "DURACION" << setw(8) << "IDIOMA" << setw(15)
            << "CATEGORIA" << endl;
    for (int i = 0; i < cantStreams; i++)
        archRep << setw(8) << arrStream[i] << setw(10) << arrDuracion[i]
                << setw(10) << arrIdioma[i] << setw(10) << arrCarCat[i] << arrNumCat[i] << endl;
}

void ignorar(ifstream& archivo, char del) {
    archivo>>ws;
    char c;
    while (true) {
        c = archivo.get();
        if (c == del) break;
    }
}
/*
*"ArchivosDeDatos/Canales.txt",
                    //Los que me van a ayudar a llenar
                    arrStream,
                    arrIdioma,
                    arrCarCat,
                    arrNumCat,
                    arrDuracion,
                    //Los que voy a llenar
                    arrRepAntigua,
                    arrRepReciente,
                    arrPromRat,
                    arrPromTasa,
                    arrNumReprod,
                    arrTotReprod,
                    cantStreams);
 */
void completarCanales(const char* nombre_archivo, int *arrStream, int *arrIdioma, char *arrCarCat, int *arrNumCat,
                      int *arrDuracion, int *arrRepAntigua, int *arrRepReciente, double *arrPromRat, double *arrPromTasa,
                      int *arrNumReprod, int *arrTotReprod,
                      int cantStreams) {
    ifstream archCanal;
    apertura_archivo_lectura(archCanal, nombre_archivo);
    int d, stream, m, a, hh, mm, ss, idStream, fecha, numCanal = 0;
    double rating, tasa;
    char c;
    //3/12/2021      E5929      Evelone192    450161    28/7/2025    19:47:03    1.39    0.052    316186    20/8/2025    10:49:46    4.92    0.69    501133    26/7/2025    02:38:02    2.69    0.004
    while (true) {
        archCanal >> d;
        if (archCanal.eof()) break;
        ignorar(archCanal, ' '); // Resto Fecha
        ignorar(archCanal, ' '); // Codigo Canal
        ignorar(archCanal, ' '); // Nombre Canal
        numCanal++;
        while (true) {
            // 450161    28/7/2025    19:47:03    1.39    0.052
            archCanal >> stream
                       >> d >> c >> m >> c >> a
                       >> hh >> c >> mm >> c >> ss
                       >> rating >> tasa;
            idStream = buscarStream(stream, arrStream, cantStreams);
            if (idStream != NO_ENCONTRADO) {
                fecha = a * 10000 + m * 100 + d;
                arrPromRat[idStream] += rating;
                arrPromTasa[idStream] += tasa;
                arrNumReprod[idStream]++;
                if (arrRepAntigua[idStream] == 0 or fecha < arrRepAntigua[idStream])
                    arrRepAntigua[idStream] = fecha;
                if (arrRepReciente[idStream] == 0 or fecha > arrRepReciente[idStream])
                    arrRepReciente[idStream] = fecha;
                arrTotReprod[idStream] += arrDuracion[idStream];
            }
            if (archCanal.get() == '\n') break;
        }
    }
    calcularPromedios(arrPromRat, arrPromTasa, arrNumReprod, cantStreams);
}

int buscarStream(int stream, int *arrStream, int cantStreams) {
    for (int i = 0; i < cantStreams; i++)
        if (stream == arrStream[i]) return i;
    return NO_ENCONTRADO;
}

void calcularPromedios(double *arrPromRat, double *arrPromTasa, int *arrNumReprod,
                       int cantStreams) {
    for (int i = 0; i < cantStreams; i++) {
        if (arrNumReprod[i] > 0) {
            arrPromRat[i] /= arrNumReprod[i];
            arrPromTasa[i] /= arrNumReprod[i];
        }
    }
}

void emitirReporte(const char *nombArch, const char *titulo, bool resumen,
                   int *arrStream, int *arrIdioma, char *arrCarCat, int *arrNumCat, int *arrRepAntigua,
                   int *arrRepReciente, double *arrPromRat, double *arrPromTasa,
                   int *arrDuracion, int *arrNumReprod, int *arrTotReprod, int cantStreams) {
    ofstream archReporte(nombArch, ios::out);
    if (not archReporte.is_open()) {
        cout << "El archivo " << nombArch << " no se pudo abrir" << endl;
        exit(1);
    }
    archReporte << fixed << setprecision(2);
    imprimirLinea(archReporte, '=',TAM_LINEA);
    archReporte << setw(75) << "PLATAFORMA DE STREAMING TP" << endl;
    archReporte << setw(85) << titulo << endl;
    imprimirLinea(archReporte, '=',TAM_LINEA);
    archReporte << "STREAM" << setw(9) << "IDIOMA" << setw(11) << "CATEGORIA"
            << setw(13) << "REP.ANTIGUA" << setw(16) << "REP.RECIENTE"
            << setw(13) << "PROM.RAT.CAL" << setw(20) << "PROM.TASA.DROP-OFF"
            << setw(10) << "DURAC." << setw(8) << "#REPR." << setw(16) << "TOT.REPR." << endl;
    imprimirLinea(archReporte, '-',TAM_LINEA);
    for (int i = 0; i < cantStreams; i++) {
        archReporte << setw(5) << arrStream[i] << setw(8) << arrIdioma[i]
                << setw(6) << arrCarCat[i] << arrNumCat[i];
        if (arrNumReprod[i] > 0) {
            convertirImprimirFecha(archReporte, arrRepAntigua[i]);
            convertirImprimirFecha(archReporte, arrRepReciente[i]);
            archReporte << setw(10) << arrPromRat[i] << setw(18) << arrPromTasa[i];
        } else
            archReporte << setw(10) << '-' << setw(16) << '-' << setw(12) << '-'
                    << setw(20) << '-';
        convertirImprimirHora(archReporte, arrDuracion[i]);
        archReporte << setw(5) << arrNumReprod[i];
        convertirImprimirHora(archReporte, arrTotReprod[i]);
        archReporte << endl;
    }
    if (resumen) {
        imprimirLinea(archReporte, '-',TAM_LINEA);
        archReporte << "RESUMEN" << endl;
        archReporte << "STREAM CON MAYOR DURACION:" << setw(8) << arrStream[cantStreams - 1];
        convertirImprimirHora(archReporte, arrDuracion[cantStreams - 1]);
        archReporte << " hrs" << endl;
        archReporte << "STREAM CON MENOR DURACION:" << setw(8) << arrStream[0];
        convertirImprimirHora(archReporte, arrDuracion[0]);
        archReporte << " hrs" << endl;
        imprimirLinea(archReporte, '=',TAM_LINEA);
    }
}

void convertirImprimirFecha(ofstream &archReporte, int fecha) {
    int d, m, a;
    d = fecha % 100;
    a = fecha / 10000;
    m = (fecha % 10000) / 100;
    archReporte << setw(5) << ' ' << setfill('0') << setw(2) << d << '/'
            << setw(2) << m << '/' << setw(4) << a << setfill(' ');
}

void convertirImprimirHora(ofstream &archReporte, int segundos) {
    int h, m, s;
    h = segundos / 3600;
    m = (segundos % 3600) / 60;
    s = (segundos % 3600) % 60;
    archReporte << setw(9) << ' ' << setfill('0') << setw(2) << h << ':'
            << setw(2) << m << ':' << setw(2) << s << setfill(' ');
}

void ordenarStreams(int *arrStream, int *arrIdioma, char *arrCarCat, int *arrNumCat,
                    int *arrRepAntigua, int *arrRepReciente, double *arrPromRat, double *arrPromTasa,
                    int *arrDuracion, int *arrNumReprod, int *arrTotReprod, int cantStreams) {
    for (int i = 0; i < cantStreams - 1; i++)
        for (int j = i + 1; j < cantStreams; j++)
            if (arrIdioma[i] > arrIdioma[j] or
                (arrIdioma[i] == arrIdioma[j] and arrPromTasa[i] < arrPromTasa[j])) {
                cambiarInt(arrStream[i], arrStream[j]);
                cambiarInt(arrIdioma[i], arrIdioma[j]);
                cambiarInt(arrNumCat[i], arrNumCat[j]);
                cambiarInt(arrRepAntigua[i], arrRepAntigua[j]);
                cambiarInt(arrRepReciente[i], arrRepReciente[j]);
                cambiarInt(arrDuracion[i], arrDuracion[j]);
                cambiarInt(arrNumReprod[i], arrNumReprod[j]);
                cambiarInt(arrTotReprod[i], arrTotReprod[j]);
                cambiarChar(arrCarCat[i], arrCarCat[j]);
                cambiarDouble(arrPromRat[i], arrPromRat[j]);
                cambiarDouble(arrPromTasa[i], arrPromTasa[j]);
            }
}

void cambiarInt(int &datoI, int &datoJ) {
    int aux = datoI;
    datoI = datoJ;
    datoJ = aux;
}

void cambiarChar(char &datoI, char &datoJ) {
    char aux = datoI;
    datoI = datoJ;
    datoJ = aux;
}

void cambiarDouble(double &datoI, double &datoJ) {
    double aux = datoI;
    datoI = datoJ;
    datoJ = aux;
}

void imprimirLinea(ofstream &archReporte, char c, int cant) {
    archReporte << setfill(c) << setw(cant) << c << setfill(' ') << endl;
}
