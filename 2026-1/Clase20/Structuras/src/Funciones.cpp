//
// Created by Erasmo on 6/11/25.
//

#include "Funciones.hpp"
void apertura_archivo_lectura(ifstream& input, const char* file_name){
   input.open(file_name, ios::in);
   if(not input.is_open()){
       cout<<"No se pudo abrir el archivo "<<file_name<<endl;
       exit(1);
   }
}

void apertura_archivo_escritura(ofstream& output, const char* file_name){
    output.open(file_name, ios::out);
    if(not output.is_open()){
        cout<<"No se pudo abrir el archivo "<<file_name<<endl;
        exit(1);
    }
}

char* asignar_str(const char* orig){
    char* str;
    str = new char[strlen(orig)+1];
    strcpy(str, orig);
    return str;
}

char* read_str(ifstream& input, char delim){
    char* str, buffer[MAX_CAR];
    input.getline(buffer, MAX_CAR, delim);
    str = new char[strlen(buffer)+1];
    strcpy(str, buffer);
    return str;
}

int read_int(ifstream& input){
    int i;
    input>>i;
    input.get(); // la coma
    return i;
}

double read_double(ifstream& input){
    double d;
    input>>d;
    input.get(); // la coma
    return d;
}

void cargar_canciones(const char *file_name, struct Cancion *canciones, int &n_canciones) {
    ifstream input;
    apertura_archivo_lectura(input, file_name);
    struct Cancion c;
    char* artista;
    //Ariana Grande,boyfriend,186106,0.4,pop
    while(true){
        artista = read_str(input, ',');
        if(input.eof())break;
        c.artista = artista;
        c.titulo = read_str(input, ',');
        c.n_reproducciones = read_int(input);
        c.danceability = read_double(input);
        c.genero = read_str(input, '\n');
        //c.genero = modificar_genero(c.genero);
        canciones[n_canciones] = c;
        n_canciones++;
    }
}

void swap_struct(struct Cancion& a, struct Cancion& b){
    struct Cancion aux;
    aux = a;
    a = b;
    b = aux;
}


void ordenar_canciones(struct Cancion *canciones, int n_canciones) {
    for(int i=0; i<n_canciones-1; i++)
        for(int j=i+1; j<n_canciones; j++)
            if(strcmp(canciones[i].artista, canciones[j].artista)>0){
                swap_struct(canciones[i], canciones[j]);
            }
}

void print_headers(ofstream& output){
    output<<setw(30)<<"ARTISTA";
    output<<setw(45)<<"TITULO";
    output<<setw(35)<<"GENERO"<<endl;
    for(int i=0; i<110;i++)output.put('=');
    output<<endl;
}
void imprimir_canciones(const char *file_name, struct Cancion *canciones, int n_canciones) {
    ofstream output;
    apertura_archivo_escritura(output, file_name);
    print_headers(output);
    for(int i=0; i<n_canciones;i++){
        output<<setw(30)<<canciones[i].artista;
        output<<setw(45)<<canciones[i].titulo;
        output<<setw(35)<<canciones[i].genero<<endl;
    }
}
