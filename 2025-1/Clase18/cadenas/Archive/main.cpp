#include "Funciones.hpp"


int main() {
    //leer_archivo_imprimir_personas("personas.txt");
    //leer_archivo_imprimir_tiktokers("tiktokers.txt");
//    char oracion[50] = "Hola me llamo erasmo!";
//    char oracion_cpy[50];
//    my_strncpy(oracion_cpy, oracion, 4);
//    //strncpy(oracion_cpy, oracion,4);
//    my_strcat(oracion_cpy, " mundo");
//    cout << oracion << endl;
//    cout << oracion_cpy << endl;
//    int iguales = my_strcmp("Hola ", "Hola");
//    cout << iguales << endl;
//    iguales = strcmp("Hola ", "Hola");
//    cout << iguales << endl;
//    iguales = my_strncmp("Hola ", "Hola", 4);
//    cout << iguales << endl;
//    iguales = strncmp("Hola ", "Hola", 4);
//    cout << iguales << endl;
//
//    int pos = my_strchr("Hola mundo", 'o');
//    cout << pos << endl;
//    char *texto;
//    texto = new char[50];
//    my_strncpy(texto, "Hola mundo", 50);
//    char *pos_ptr;
//    pos_ptr = strchr(texto, 'o');
//    cout << pos_ptr << endl;
//
//    int start, end;
//    my_strstr("Hola mundo que tal", "mundo", start, end);
//
//    if (start != -1)
//        cout << "Subcadena encontrada de " << start << " a " << end << "\n";
//    else
//        cout << "Subcadena no encontrada\n";
//
//    const char *sub = strstr("Hola mundo que tal", "mundo");
//    if (sub != nullptr)
//        cout << sub << endl;
//    else cout << "No se encontro sub cadena" << endl;

//    char linea_2[100] = "uno, dos; tres,  cuatro";
//    char* linea = new char[100];
//    strcpy(linea, linea_2);
//
//    char* token = my_strtok(linea, " ,;");
//    while (token != nullptr) {
//        cout << "[" << token << "]" << endl;
//        token = my_strtok(linea, " ,;");
//    }
    char palabra[100] = "Hola mundo";
    prepend(palabra, "Buenos Dias: ");
    cout << palabra << endl;
    return 0;
}
