#include "src/Funciones.hpp"

int main() {
    struct ListaCliente lista_clientes;
    struct ListaLibro lista_libros;
    leer_lista_clientes_bloques(lista_clientes, "Data/Clientes.csv");
    imprimir_reporte_prueba_clientes(lista_clientes, "Reports/reporte_clientes_prueba_bloques.txt");
    leer_lista_libros(lista_libros, "Data/Libros.csv");
    imprimir_reporte_prueba_libros(lista_libros, "Reports/reporte_libros_prueba.txt");
    return 0;
}
