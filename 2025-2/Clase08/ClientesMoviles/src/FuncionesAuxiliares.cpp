//
// Created by Erasmo on 11/09/25.
//

#include "FuncionesAuxiliares.hpp"

void print_line(int size, char c, ofstream &output) {
    for (int i = 0; i < size; i++)output.put(c);
    output << endl;
}

void to_uppercase(char &c) {
    if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
}

void leer_imprimir_nombre(ifstream &input, ofstream &output, char &primero, char &segundo) {
    char c;
    int cont = 0, size = 0;
    bool inicio_palabra = true;
    input >> ws;
    //PostpagoBasico -> PB
    //PostpagoPlus -> PP
    //Prepago   -> P
    //Ilimitado -> I
    while (true) {
        c = input.get();
        if (c == ' ')break;

        if(inicio_palabra){
            if (cont == 0){
                primero = c;
            }
            if (cont == 2) {
                segundo = c;
            }
            inicio_palabra = false;
        }
        if (c == '-') {
            c = ' ';
            inicio_palabra = true;
            cont++;
        }

        if (cont == 2 and c != ' ') to_uppercase(c);
        output.put(c);
        size++;
    }
    int ancho = ANCHO_REPORTE / N_COLUMNS;
    for (int i = 0; i < ancho - size; i++)output.put(' ');
}

void print_date(int date, ofstream &output) { //20250904
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

int read_date(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> yyyy >> c >> mm >> c >> dd;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

void imrprime_header_datos(ofstream& output){
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"TELEFONO";
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"PLAN";
    output<<setw(ANCHO_REPORTE/N_COLUMNS)<<"FECHA INICIO";
    output<<right<<setw(ANCHO_REPORTE/N_COLUMNS)<<"FECHA FIN";
    output<<right<<setw(ANCHO_REPORTE/N_COLUMNS)<<"MONTO"<<endl;
    print_line(ANCHO_REPORTE, '.', output);
}

double buscar_precio(ifstream& input_busqueda, char id_buscar_1, char id_buscar_2){
    double precio = 0.0;
    //Resetear el archivo
    input_busqueda.clear(); // Limpio las banderas
    input_busqueda.seekg(0, ios::beg); // Ubicar el puntero al inicio del archivo
    //PB101 post_pago_basico_101 100.43
    char cl1, cl2;
    int codigo;
    while(true){
        input_busqueda>>cl1;
        if(input_busqueda.eof())break;
        input_busqueda>>cl2;
        if(cl1 == id_buscar_1 and cl2 == id_buscar_2){
            input_busqueda>>codigo;
            ignorar_cadena(input_busqueda);
            input_busqueda>>precio;
            return precio;
        }
        else
            input_busqueda.ignore(50, '\n');
    }
    return precio;
}

void leer_planes(ifstream &input, ifstream& input_busqueda, ofstream &output,
                 int &es_1, double &es_2, char &es_3) {
    char c;
    //932479584 PostpagoBasico 2025-08-07 2025-12-18 97.12
    int telefono, inicio_plan, fin_plan;
    double monto;
    output << fixed;
    imrprime_header_datos(output);
    char id_buscar_1,  id_buscar_2;
    double precio = 0.0;
    while (true) {
        id_buscar_1 = 'P';
        id_buscar_2 = ' ';
        input >> telefono; //DATO1
        output << left << setw(ANCHO_REPORTE / N_COLUMNS) << telefono;
        leer_imprimir_nombre(input, output,  id_buscar_1,  id_buscar_2); //DATO 2
        inicio_plan = read_date(input); //DATO3
        fin_plan = read_date(input); //DATO4
        input >> monto; //DATO5
        //BUSQUEDA

        precio = buscar_precio(input_busqueda, id_buscar_1, id_buscar_2);
        //buscar_precio(input_busqueda, id_buscar_1, id_buscar_2, precio);
        //output << setw(ANCHO_REPORTE / N_COLUMNS) << "";
        print_date(inicio_plan, output);
        output << setw(ANCHO_REPORTE / N_COLUMNS) << "";
        print_date(fin_plan, output);
        output << setw(ANCHO_REPORTE / N_COLUMNS) << setprecision(2) << monto << endl;
        c = input.get();//DATO6
        if (c == '\n')break;
    }
    print_line(ANCHO_REPORTE, '=', output);
}

void imprime_header(int dni, ifstream &input, ofstream &output) {
    output << left << setw(ANCHO_REPORTE / N_COLUMNS) << "DNI";
    output << left << setw(ANCHO_REPORTE / N_COLUMNS) << "NOMBRE" << endl;
    output << setw(ANCHO_REPORTE / N_COLUMNS) << left << dni; //Imprimimos DNI
    leer_imprimir_nombre(input, output);
    output << endl;
    print_line(ANCHO_REPORTE, '*', output);
}

void lee_imprimr_datos_moviles(ifstream &input, ifstream & input_busqueda, ofstream &output) {
    int dni;
    char c;
    //DNI10218013 Escalona-Zurita-Estela 9
    while (true) {
        input >> c;
        if (input.eof())break;
        input.ignore(2);
        input >> dni;
        imprime_header(dni, input, output);
        leer_planes(input, input_busqueda, output);
        //input.ignore(300, '\n');
        output << endl;
    }
}

void imprime_titulo(const char *titulo, ofstream &output) {
    output << setw((ANCHO_REPORTE + ANCHO_TITULO) / 2) << titulo<<endl;
    print_line(ANCHO_REPORTE, '*', output);
}

void leer_procesar_clientes_moviles(const char *file_name_entrada,
                                    const char* file_name_busqueda,
                                    const char *file_name_salida) {
    ifstream input;
    apertura_archivo_lectura(input, file_name_entrada);
    ifstream input_busqueda;
    apertura_archivo_lectura(input_busqueda, file_name_busqueda);
    ofstream output;
    int est_1;
    double est_2;
    char est_3;

    apertura_archivo_escritura(output, file_name_salida);
    //Codear sin problemas
    // Impresion Titulo
    imprime_titulo("REPORTE DE PLANES DE MOVILES", output);
    // Lectura e Impresion de datos
    lee_imprimr_datos_moviles(input, input_busqueda, output, est_1, est_2, est_3);
    impresion_estadisticas(output, est_1, est_2, est_3);
    input.close();
    output.close();
}

void apertura_archivo_lectura(ifstream &input, const char *file_name) {
    input.open(file_name, ios::in);
    if (!input.is_open()) {
        cout << "El archivo : " << file_name << " No se pudo abrir";
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *file_name) {
    output.open(file_name, ios::out);
    if (!output.is_open()) {
        cout << "El archivo : " << file_name << " No se pudo abrir";
        exit(1);
    }
}
