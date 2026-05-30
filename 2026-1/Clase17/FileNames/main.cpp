#include "src/Funciones.hpp"

int main() {
    char ruta[100];
    strcpy(ruta, "Reportes/"); //RutaBase
    strcat(ruta, "Personal/"); //Anexos o agregaciones
    strcat(ruta, "ErasmoGomez"); //Agregacion
    strcat(ruta, ".txt"); //Tipo de Archivo
    cout<<ruta<<endl;
    ofstream output;
    apertura_archivo_escritura(output, ruta);
    output<<"Esta es la data de Erasmo"<<endl;

    return 0;
}
