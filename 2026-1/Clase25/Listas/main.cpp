#include "src/BibliotecaLista/Lista.hpp"
#include "src/BibliotecaLista/ListaTAD.hpp"

int main() {
    struct Nodo *lista;
    //Trabajemos con una lista simplemente ligada.
//    crear_lista(lista, "Data/datos.txt");
//    imprimir_lista(lista, "Reports/reporte.txt");

    // Trabajemos con lista simplemente ligada ORDENADA
    crear_lista_ordenada(lista, "Data/Datos.txt");
    imprimir_lista(lista, "Reports/reporte_ordenado.txt");
    remover_elemento_lista(lista, 18);
    imprimir_lista(lista, "Reports/reporte_ordenado_sin_elemento_18.txt");

    // Trabajaremos con una lista simplemente ligada como TAD
//    struct Lista lista_tad;
//    crear_lista_tad(lista_tad, "Data/datos.txt");
//    imprimir_lista_tad(lista_tad, "Reports/reporte_lista_tad.txt");
    return 0;
}
