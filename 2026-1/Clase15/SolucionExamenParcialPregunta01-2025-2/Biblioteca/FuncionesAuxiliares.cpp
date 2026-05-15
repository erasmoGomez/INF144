#include "FuncionesAuxiliares.hpp"

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

void emitirElReporteDeReproduccionesDeStreams(const char *nombArchCanales,
                                              const char *nombArchStreams, const char *nombArchIdiomas,
                                              const char *nombArchCategoria, const char *nombArchReporte) {
    ifstream archCanales;
    apertura_archivo_lectura(archCanales, nombArchCanales);
    ifstream archStream;
    apertura_archivo_lectura(archStream, nombArchStreams);
    ifstream archIdiomas;
    apertura_archivo_lectura(archIdiomas, nombArchIdiomas);
    ifstream archCategoria;
    apertura_archivo_lectura(archCategoria, nombArchCategoria);
    ofstream archReporte;
    apertura_archivo_escritura(archReporte, nombArchReporte);
    // 803100    1:22:25    4003    C1072
    int codigoStream, hora, minuto, segundo, codigoIdioma, codigoCateg, numStreams = 0;
    char letraCateg, c;
    double duracion, duracionTotal = 0;

    archReporte.precision(2);
    archReporte << fixed;
    imprimeTitulos(archReporte);
    while (true) {
        imprimeLinea(archReporte, '=',MAX_CAR_LIN);
        archStream >> codigoStream;
        if (archStream.eof())break;
        numStreams++;
        archStream >> hora >> c >> minuto >> c >> segundo >> codigoIdioma
                >> letraCateg >> codigoCateg;
        archReporte << left << "STREAM: " << setw(8) << codigoStream
                << "CATEGORIA: " << letraCateg << codigoCateg << " - ";
        leeImprimeCategoria(letraCateg, codigoCateg, archCategoria, archReporte,
                            MAX_CAR_CATEG);
        archReporte << "IDIOMA: " << setw(5) << codigoIdioma << " - ";
        leeImprimeIdioma(codigoIdioma, archIdiomas, archReporte,MAX_CAR_IDIOM);
        archReporte << "DURACION: " << right << setfill('0') << setw(2) << hora << ':'
                << setw(2) << minuto << ':' << setw(2) << segundo << setfill(' ')
                << endl;
        imprimeLinea(archReporte, '=',MAX_CAR_LIN);
        duracion = hora * 3600 + minuto * 60 + segundo;
        duracionTotal += duracion;
        imprimeCanales(codigoStream, duracion, archCanales, archReporte);
    }
    archReporte << "RESUMEN TOTAL:" << endl;
    imprimeLinea(archReporte, '-',MAX_CAR_LIN);
    archReporte << "# STREAMS: " << numStreams << endl;
    archReporte << "DURACION TOTAL REPRODUCCION: ";
    imprimeHora(duracionTotal, archReporte);
    archReporte << endl;
    imprimeLinea(archReporte, '=',MAX_CAR_LIN);
}

void imprimeTitulos(ofstream &archReporte) {
    imprimeLinea(archReporte, '=',MAX_CAR_LIN);
    archReporte << right << setw(85) << "PLATAFORMA DE STREAMING TP" << endl;
    archReporte << right << setw(84) << "REPRODUCCION DE STREAMS" << setw(5) << endl;
}

void leeImprimeCategoria(char letraCateg, int codigoCateg,
                         ifstream &archCategoria, ofstream &archReporte,
                         int numCar) {
    int codigo;
    char letra;

    archCategoria.clear();
    archCategoria.seekg(0, ios::beg);
    while (true) {
        archCategoria >> letra;
        if (archCategoria.eof())break;
        archCategoria >> codigo;
        if (letra == letraCateg and codigo == codigoCateg) {
            leeImprimeTexto(archCategoria, archReporte, numCar, true);
            return;
        } else while (archCategoria.get() != '\n');
    }
    archReporte << "NO SE ENCONTRO" << endl;
}

void leeImprimeIdioma(int codigoIdioma, ifstream &archIdiomas,
                      ofstream &archReporte, int numCar) {
    int codigo;

    archIdiomas.clear();
    archIdiomas.seekg(0, ios::beg);
    while (true) {
        archIdiomas >> codigo;
        if (archIdiomas.eof())break;
        if (codigo == codigoIdioma) {
            leeImprimeTexto(archIdiomas, archReporte, numCar, false);
            return;
        } else while (archIdiomas.get() != '\n');
    }
    archReporte << "NO SE ENCONTRO" << endl;
}

void leeImprimeTexto(ifstream &archLee, ofstream &archReporte, int numCar,
                     bool enMayuscula) {
    char car;
    int ncar = 0, numBlanc;
    bool primeraLetra = true;
    archLee >> ws;
    while (true) {
        car = archLee.get();
        if (car == '\n') break;
        if (enMayuscula or primeraLetra) {
            if (car >= 'a' and car <= 'z') car -= 'a' - 'A';
            primeraLetra = false;
        }
        if (car == '_') car = ' ';
        archReporte.put(car);
        ncar++;
    }
    numBlanc = numCar - ncar;
    for (int i = 0; i < numBlanc; i++) archReporte.put(' ');
}

void imprimeLinea(ofstream &archReporte, char car, int cant) {
    for (int i = 0; i < cant; i++) archReporte.put(car);
    archReporte << endl;
}

void imprimeCanales(int codigoStream, int duracion, ifstream &archCanales,
                    ofstream &archReporte) {
    int dia, mes, año, codigoCanal, codigoCanalMay, codigoCanalMen, nCanal = 0, duracionTotal = 0;
    char letraCanal, letraCanalMay, letraCanalMen, c;
    double tasaDropMayor = 0, tasaDropMenor = 2;
    archCanales.clear();
    archCanales.seekg(0, ios::beg);
    while (true) {
        archCanales >> dia;
        if (archCanales.eof())break;
        archCanales >> c >> mes >> c >> año >> letraCanal >> codigoCanal;
        archCanales >> ws;
        while (archCanales.get() != ' ');
        leeImprimeStreams(nCanal, letraCanal, codigoCanal, duracion, duracionTotal, codigoStream, archCanales,
                          archReporte, tasaDropMayor, tasaDropMenor, letraCanalMay, codigoCanalMay
                          , letraCanalMen, codigoCanalMen);
    }
    if (nCanal > 0) {
        imprimeLinea(archReporte, '-',MAX_CAR_LIN);
        archReporte << "RESUMEN DEL STREAM:" << endl;
        archReporte << "# VECES REPRODUCIDAS: " << setw(10) << nCanal << endl;
        archReporte << "TIEMPO TOTAL REPRODUCION: ";
        imprimeHora(duracionTotal, archReporte);
        archReporte << endl;
        archReporte << "TASA DROP-OFF MENOR: " << setw(5) << tasaDropMenor << " CANAL: " << letraCanalMen
                << codigoCanalMen << endl;
        archReporte << "TASA DROP-OFF MAYOR: " << setw(5) << tasaDropMayor << " CANAL: " << letraCanalMay
                << codigoCanalMen << endl;
    }
}

void leeImprimeStreams(int &nCanal, char letraCanal, int codigoCanal,
                       int duracion, int &duracionTotal, int codigoStream, ifstream &archCanales,
                       ofstream &archReporte, double &tasaDropMayor, double &tasaDropMenor,
                       char &letraCanalMay, int &codigoCanalMay, char &letraCanalMen,
                       int &codigoCanalMen) {
    int n = 0, codStr, dia, mes, año, hora, minuto, segundo, horaIni, horaFin, totalReproducido;
    char c;
    double rating, tasaDrop, sumaRat = 0, sumaTasa = 0;

    while (true) {
        archCanales >> codStr >> dia >> c >> mes >> c >> año >> hora >> c >> minuto >> c >> segundo
                >> rating >> tasaDrop;
        horaIni = hora * 3600 + minuto * 60 + segundo;
        if (codigoStream == codStr) {
            if (n == 0) {
                if (nCanal != 0) imprimeLinea(archReporte, '-',MAX_CAR_LIN);
                nCanal++;
                archReporte << "  " << setfill('0') << setw(2) << nCanal << setfill(' ')
                        << ")  CANAL: " << letraCanal << codigoCanal << endl;
                archReporte << right << "      " << "REPRODUCCIONES" << endl;
                archReporte << "      No." << setw(8) << "FECHA" << setw(13) << "INICIO"
                        << setw(8) << "FIN" << setw(19) << "RATING CALIDAD"
                        << setw(15) << "TASA DROP-OFF" << endl;
            }
            //else imprimeLinea(archReporte,'-',MAX_CAR_LIN);
            n++;
            horaFin = horaIni + duracion;
            duracionTotal += duracion;
            archReporte << "      " << setfill('0') << setw(2) << n << ")  " << setw(2) << dia << '/'
                    << mes << '/' << año << "   ";
            imprimeHora(horaIni, archReporte);
            archReporte << "  ";
            imprimeHora(horaFin, archReporte);
            archReporte << setfill(' ') << setw(11) << rating << setw(16) << tasaDrop * 100 << '%' << endl;
            sumaRat += rating;
            sumaTasa += tasaDrop;
            if (tasaDrop < tasaDropMenor) {
                tasaDropMenor = tasaDrop;
                letraCanalMen = letraCanal;
                codigoCanalMen = codigoCanal;
            }
            if (tasaDrop > tasaDropMayor) {
                tasaDropMayor = tasaDrop;
                letraCanalMay = letraCanal;
                codigoCanalMay = codigoCanal;
            }
        }
        if (archCanales.get() == '\n')break;
    }
    if (n > 0) {
        archReporte << "      TOTAL TIEMPO REPRODUCCIONES: ";
        imprimeHora(duracionTotal, archReporte);
        archReporte << "\n      PROMEDIO RATING CALIDAD: " << setw(10) << sumaRat / n << endl;
        archReporte << "      PROMEDIO TASA DROP-OFF:  " << setw(10) << sumaTasa / n * 100 << '%' << endl;
    }
}

void imprimeHora(int horaIni, ofstream &archReporte) {
    int hora, minuto, segundo;
    hora = horaIni / 3600;
    horaIni %= 3600;
    minuto = horaIni / 60;
    segundo = horaIni % 60;
    archReporte << setfill('0') << setw(2) << hora << ':' << setw(2) << minuto << ':' << setw(2) << segundo <<
            setfill(' ');
}
