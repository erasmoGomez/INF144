#include "src/Funciones.hpp"

int main() {
    char ruta[100];
    //char* nombre = read_str(input);
    strcpy(ruta, "Reports/"); //RutaBase
    strcat(ruta, "erasmo"); //Anexos o agregaciones
    strcat(ruta, ".txt"); //Tipo de Archivo
    cout<<ruta<<endl;
    ofstream output;
    apertura_archivo_escritura(output, ruta);
    output<<"Esta es la data de Erasmo"<<endl;

//    char cadena[20] = "Erasmo, Gomez";
//    char nombre[20];
//    int indice_nombre = 0;
//    for(int i=0; cadena[i]; i++){
//        if(cadena[i]!= ','){
//            nombre[indice_nombre] = cadena[i];
//            indice_nombre++;
//        }
//
//    }
//    strcpy(nombre_completo, apellido);
//    strcat(nombre_completo, " ");
//    strcat(nombre_completo, nombre);
//    cout<<nombre_completo<<endl;
//    //Gomez Erasmo

    // char buffer[20]; //Cadena Statica -> const char*
    // const char* -> NO VARIAR LA CADENA
    // char* nombre; // Cadena Dinámica
    // const es q NO podemos modificarla cuando tiene CONST
    // funcion("Data/archivo.txt")
    // const char* file_name;
    return 0;
}
