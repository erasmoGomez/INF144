#include "Bibliotecas/ListaCliente.hpp"
#include "src/Funciones.hpp"

int main() {
    struct ListaCliente lista_clientes;
    struct Nodo* lista_libros;
    leer_lista_clientes_bloques(lista_clientes, "Clientes.csv");
    imprimir_reporte_prueba_clientes(lista_clientes, "reporte_clientes_prueba_bloques.txt");
    leer_lista_libros(lista_libros, "Libros.csv");
//    imprimir_reporte_prueba_libros(lista_libros, "reporte_libros_prueba.txt");
    return 0;
}
