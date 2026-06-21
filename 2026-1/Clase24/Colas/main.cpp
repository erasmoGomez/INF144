#include "src/BibliotecaCola/Cola.hpp"

int main() {
    //Trabajaremos con una COLA TAD
    struct Cola cola_tad;
    inicializa(cola_tad);
    encolar(cola_tad, 18);
    encolar(cola_tad, 15);
    encolar(cola_tad, 20);

    int dato_desencolado;
    desencolar(cola_tad, dato_desencolado);
    cout<<dato_desencolado<<endl;
    desencolar(cola_tad, dato_desencolado);
    cout<<dato_desencolado<<endl;
    //Luego de 2 desencolar
    //Lo que queda en la cola es la cima, es decir el inicio.
    cout<<cola_tad.inicio->dato<<endl;
    return 0;
}
