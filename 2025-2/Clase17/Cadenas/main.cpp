#include <iostream>
#include <cstring>

using namespace std;

int main() {
    //Cadenas
    //Estatica
    char cadena[20] = "Hola";
    // strlen
    cout << strlen(cadena) << endl;
    // strcat
    strcat(cadena, " mundo");
    cout << cadena << endl;

    //Dinamica
    char *nombre;
    nombre = new char[20];
    strcpy(nombre, "Erasmo");
    cout << nombre << endl;
    //Lecturas
//    char buffer[5];
//    cin>>buffer;
//    cout<<buffer<<endl;

    char buffer[10];
//    cin>>buffer;
//    cout<<buffer<<endl;
    //Comparacion
    char cadena2[20] = "Hola";

    int cmp = strcmp(cadena2, "Hola");
    cout<<cmp<<endl;
    char cadena3[20] = "Holiss";
    int cmp2 = strcmp(cadena3, cadena2);
    cout<<cmp2<<endl;
    return 0;
}
