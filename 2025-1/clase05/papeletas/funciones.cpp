#include "funciones.hpp"

// Implementación de funciones

bool esta_en_rango(int fecha, int inicio, int fin) {
    return fecha >= inicio and fecha <= fin;
}

void actualizar_resumen(double& distancia_corta, double& papeleta_cara,
        int& n_papeletas_mayo, int& n_conductores_inactivos,
        int fecha, double distancia, double monto, bool estado) {
    if (distancia < distancia_corta)
        distancia_corta = distancia;
    if (monto > papeleta_cara)
        papeleta_cara = monto;
    int mes = (fecha / 100) % 100;
    if (mes == 5)
        n_papeletas_mayo++;
    if (!estado)
        n_conductores_inactivos++;
}

void imprimir_linea_papeleta(int hora, int tipo_falta,
        double distancia, double monto, bool estado) {
    imprime_hora(hora);
    cout << setw(TAM_REPORTE / N_COLUMNAS + 10) << conseguir_tipo_falta(tipo_falta);
    cout << setw(TAM_REPORTE / N_COLUMNAS - 10) << setprecision(2) << distancia << "km.";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << monto;
//    if(estado){
//        cout << setw(TAM_REPORTE / N_COLUMNAS) <<"ACTIVO";
//    }
//    else
//        cout << setw(TAM_REPORTE / N_COLUMNAS) <<"INACTIVO";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << (estado ? "ACTIVO" : "INACTIVO");
    cout << endl;
}

void procesar_papeleta(int fecha, int dni, double& distancia_corta,
        double& papeleta_cara, int& n_papeletas_mayo,
        int& n_conductores_inactivos) {
    int hora, tipo_falta, puntos;
    double monto, distancia;
    bool estado;
    imprime_fecha(fecha);
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << dni;
    lee_imprime_nombre();
    hora = leer_hora();
    cin >> tipo_falta;
    distancia = calcula_distancia();
    cin >> monto >> puntos >> estado;

    imprimir_linea_papeleta(hora, tipo_falta, distancia, monto, estado);
    actualizar_resumen(distancia_corta, papeleta_cara, n_papeletas_mayo,
            n_conductores_inactivos, fecha, distancia, monto, estado);
}

void leer_y_procesar_papeletas() {
    int fecha_inicio = leer_fecha();
    int fecha_fin = leer_fecha();

    int fecha, dni;
    double distancia_corta = 1e9, papeleta_cara = 0.0;
    int n_papeletas_mayo = 0, n_conductores_inactivos = 0;

    cout << fixed << setprecision(2);
    imprimir_titulo("REPORTE DE PAPELETAS DE LOS MESES", (fecha_inicio / 100 % 100), (fecha_fin / 100 % 100));
    imprimir_headers();

    while (true) {
        fecha = leer_fecha(); // Lectura del primer dato <- aqui
        if (cin.eof()) break; // Si se llego al final del archivo entonces salgo del bucle.
        if (!esta_en_rango(fecha, fecha_inicio, fecha_fin)) {
            cin.ignore(180, '\n'); //Saltarme esta linea
            continue; // -> desde aqui
        }
        cin >> dni;
        procesar_papeleta(fecha, dni, distancia_corta,
                papeleta_cara, n_papeletas_mayo,
                n_conductores_inactivos);
    }

    imprime_resumen(distancia_corta, papeleta_cara, n_papeletas_mayo, n_conductores_inactivos);  

}

void imprime_resumen(double distancia_corta, double papeleta_cara,
        int n_papeletas_mayo, int n_conductores_inactivos) {
    imprimir_linea('*');
    cout << "RESUMEN" << endl;
    cout << "La distancia mas corta hacia la referencia: " << distancia_corta << " km." << endl;
    cout << "La papeleta mas cara: S/." << papeleta_cara << endl;
    cout << "Papeletas en mayo: " << n_papeletas_mayo << endl;
    cout << "Cantidad de conductores de baja: " << n_conductores_inactivos << endl;
    imprimir_linea('*');
}

void imprimir_titulo(const char* titulo, int mes_inicio, int mes_final) {
    imprimir_linea('*');
    cout << setw((TAM_REPORTE + TITULO_TAM_CAR) / 2) << titulo << endl; // ******hola
    
    cout << setw((TAM_REPORTE - SUB_TITULO_TAM_CAR) / 2) << ""; // **********
    imprimir_rango_meses(mes_inicio, mes_final); // **********julio, agosto y setiembre
    imprimir_linea('*');
}

void imprimir_headers() {
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "FECHA";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "DNI";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 10) << "NOMBRE";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "HORA";
    cout << setw(TAM_REPORTE / N_COLUMNAS + 5) << "TIPO";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "DISTANCIA";
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "MONTO";
    cout << setw(TAM_REPORTE / N_COLUMNAS) << "ESTADO";
    cout << endl;
    imprimir_linea('*');
}

void imprime_fecha(int fecha) {
    cout << setw(TAM_REPORTE / N_COLUMNAS - 13) << ""
            << setfill('0') << setw(2) << (fecha % 100) << '/'
            << setw(2) << (fecha / 100 % 100) << '/'
            << setfill(' ') << (fecha / 10000);
}

void lee_imprime_nombre() {
    int n_caracteres = 0;
    char c;
    cin >> ws; //Leer todos los espacios en blanco
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "";
    // Gomez/Lopez/Luisa
    // Gomez Lopez Luisa
    while (true) {
        c = cin.get(); //Lee un caracter
        if (c == ' ') break;
        if (c == '/') c = ' ';
        cout.put(c); //Imprime un caracter
        n_caracteres++;
    }
    int tam = TAM_REPORTE / N_COLUMNAS;
    // Gomez Lopez Luisa           |    23:23:32
    // Erasmo Gomez Montoya        |    12:32:12
    for (int i = 0; i < tam - n_caracteres; i++) cout.put(' ');
}

void imprime_hora(int s) {
    cout << setw(TAM_REPORTE / N_COLUMNAS - 15) << ""
            << setfill('0') << setw(2) << s / 3600 << ':'
            << setw(2) << (s / 60) % 60 << ':'
            << setw(2) << s % 60;
    cout << setfill(' ');
}

double calcula_distancia() {
    double distancia;
    double h_loc_1, m_loc_1, s_loc_1;
    double h_loc_2, m_loc_2, s_loc_2;
    char car;
    cin >> h_loc_1 >> car >> m_loc_1 >> car >> s_loc_1 >> car;
    cin >> h_loc_2 >> car >> m_loc_2 >> car >> s_loc_2 >> car;

    double lat1 = grados_a_decimal(h_loc_1, m_loc_1, s_loc_1);
    double lon1 = grados_a_decimal(h_loc_2, m_loc_1, s_loc_1);

    double lat2 = -12.089575625131468;
    double lon2 = -77.08777225126937;

    distancia = haversine(lat1, lon1, lat2, lon2);
    return distancia;
}

double grados_a_decimal(double degrees, double minutes, double seconds) {
    double sign = degrees < 0 ? -1.0 : 1.0; //condicional
//    if(degrees<0)
//        sign = -1;
//    else
//        sign = 1.0;
    return sign * (abs(degrees) + minutes / 60.0 + seconds / 3600.0);
}

double convertir_radianes(double degrees) {
    return degrees * M_PI / 180.0;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    lat1 = convertir_radianes(lat1);
    lon1 = convertir_radianes(lon1);
    lat2 = convertir_radianes(lat2);
    lon2 = convertir_radianes(lon2);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = pow(sin(dlat / 2), 2) +
            cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

int leer_fecha() {
    int fecha, dd, mm, aa;
    char slash;
    cin >> dd >> slash >> mm >> slash >> aa;
    fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

int leer_hora() {
    int hora, hh, mm, ss;
    char dospuntos;
    cin >> hh >> dospuntos >> mm >> dospuntos >> ss;
    hora = hh * 3600 + mm * 60 + ss;
    return hora;
}

void ignorar_nombre() {
    char c;
    cin >> ws;
    while (true) {
        c = cin.get();
        if (c == ' ') break;
    }
}

void leer_imprimir_location(const char* tipo) {
    int h_loc = 0, m_loc = 0, s_loc = 0;
    char car;
    cin >> h_loc >> car >> m_loc >> car >> s_loc >> car;
    cout << setw(TAM_REPORTE / N_COLUMNAS - 5) << "";
    cout << h_loc << ":" << m_loc << ":" << s_loc;
}

void imprimir_rango_meses(int inicio, int fin) {
    for (int i = inicio; i <= fin; ++i) {
        cout << conseguir_nombre_mes(i);
        if (i < fin - 1) {
            cout << ", ";
        } else if (i == fin - 1) {
            cout << " y ";
        }
    }
    cout << endl;
}

const char* conseguir_nombre_mes(int mes) {
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

const char* conseguir_tipo_falta(int tipo_falta) {
    switch (tipo_falta) {
        case 1: return "Conducir Estado Ebriedad";
        case 2: return "Cruce Luz Roja";
        case 3: return "Exceso de Velocidad";
        case 4: return "Uso de Celular al Conducir";
        case 5: return "Sin Licencia de Conducir";
        default: return "Falta Desconocida";
    }
}

void imprimir_linea(char c) {
    cout << setfill(c) << setw(TAM_REPORTE - 1) << c << endl;
    cout << setfill(' ');
}
