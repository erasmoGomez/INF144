//
// Created by Erasmo on 30/10/25.
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

char *read_str(ifstream &input) {
    char *str, buffer[MAX_CARACTERES];
    // Lectura en el buffer
    input >> buffer;
    if (input.eof()) return nullptr;
    // Reserva de memoria dinamica
    str = new char[strlen(buffer) + 1];
    // Pasar de buffer a str
    strcpy(str, buffer);
    return str;
}

void modificar_cadena(char *cadena) {
    for (int i = 0; cadena[i]; i++)
        if (cadena[i] == '_')cadena[i] = ' ';
}

void leer_datos(const char *file_name, int *dnis, char **nombres, int *edades,
                char **distritos, int &n_datos) {

    ifstream input;
    apertura_archivo_lectura(input, file_name);
    //79672079  contreras_chang_johana_cinthia     31     Chorrillos
    int dni;
    while (true) {
        input >> dni;
        if (input.eof())break;
        dnis[n_datos] = dni;
        nombres[n_datos] = read_str(input);
        // Modificacion a la data
        modificar_cadena(nombres[n_datos]);
        input >> edades[n_datos];
        distritos[n_datos] = read_str(input);
        n_datos++;
    }
}

void ordenar_datos(int *dnis, char **nombres, int *edades,
                   char **distritos, int n_datos) {
    for (int i = 0; i < n_datos - 1; ++i)
        for (int k = i + 1; k < n_datos; ++k)
            if (strcmp(distritos[i], distritos[k]) > 0) {
                swap_int(edades[i], edades[k]);
                swap_int(dnis[i], dnis[k]);
                swap_str(nombres[i], nombres[k]);
                swap_str(distritos[i], distritos[k]);
            }
}

void swap_int(int &datoI, int &datoK) {
    int auxI;
    auxI = datoI;
    datoI = datoK;
    datoK = auxI;
}

void swap_str(char *&datoI, char *&datoK) {
    char *auxI;
    auxI = datoI;
    datoI = datoK;
    datoK = auxI;
}

void imprimir_datos(const char *file_name, int *dnis, char **nombres, int *edades, char **distritos, int n_datos) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    for (int i = 0; i < n_datos; i++) {
        output << left << setw(10) << dnis[i];
        output << setw(45) << nombres[i];
        output << right << setw(5) << edades[i];
        output << right << setw(45) << distritos[i] << endl;
    }
}

void buscar_imprimir_dato(const char *distrito, int *dnis, char **nombres, int *edades, char **distritos, int n_datos) {
    for(int i = 0; i<n_datos; i++)
        if(strcmp(distrito, distritos[i]) == 0){
            cout << left << setw(10) << dnis[i];
            cout << setw(45) << nombres[i];
            cout << right << setw(5) << edades[i];
            cout << right << setw(45) << distritos[i] << endl;
            return;
        }
    cout<<"No se encontro el distrito"<<endl;
}

char* read_str_getline(ifstream& input){
    char *str, buffer[MAX_CARACTERES];
    input.getline(buffer, MAX_CARACTERES);
    if (input.eof()) return nullptr;
    str = new char[strlen(buffer) + 1];
    strcpy(str, buffer);
    return str;
}

void leer_datos_getline(const char *file_name, char **nombres, int &n_datos) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    char* nombre;
    while(true){
        nombre = read_str_getline(input);
        if(input.eof())break;
        nombres[n_datos] = nombre;
        n_datos++;
    }
}

void imprimir_nombres(const char *file_name, char **nombres, int n_datos) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    for(int i=0; i<n_datos; i++)
        output<<left<<setw(45)<<nombres[i]<<endl;
}
