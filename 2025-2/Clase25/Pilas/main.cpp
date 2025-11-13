#include "src/BibliotecaPila/Pila.hpp"

int main() {
    struct Nodo *lista;
    //Trabajaremos con una Pila como TAD
    Pila pila_tad;
    inicializa(pila_tad);
    push(pila_tad, 5);
    push(pila_tad, 10);
    push(pila_tad, 15);
    int dato_desapilado;
    pop(pila_tad,dato_desapilado);
    cout<<dato_desapilado<<endl;
    pop(pila_tad,dato_desapilado);
    cout<<dato_desapilado<<endl;

    return 0;
}
