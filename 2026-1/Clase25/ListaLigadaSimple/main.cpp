#include "BibliotecaListaSimple/ListaSimpleTAD.hpp"
#include "BibliotecaFuncionesAuxiliares/FuncionesAuxiliares.hpp"

int main() {
    ListaTAD lista_codigos_0{};
    cargar_lista_codigos_al_inicio(lista_codigos_0,
        "ArchivosDeDatos/codigos.txt");
    ListaTAD lista_codigos_1{};
    cargar_lista_codigos_al_final_opc1(lista_codigos_1,
        "ArchivosDeDatos/codigos.txt");
    ListaTAD lista_codigos_2{};
    cargar_lista_codigos_al_final_opc2(lista_codigos_2,
        "ArchivosDeDatos/codigos.txt");
    ListaTAD lista_codigos_3{};
    cargar_lista_codigos_ordenado(lista_codigos_3,
        "ArchivosDeDatos/codigos.txt");

    imprimir_lista("ArchivosDeReportes/reporte_lista_0.txt", lista_codigos_0);
    imprimir_lista("ArchivosDeReportes/reporte_lista_1.txt", lista_codigos_1);
    imprimir_lista("ArchivosDeReportes/reporte_lista_2.txt", lista_codigos_2);
    imprimir_lista("ArchivosDeReportes/reporte_lista_3.txt", lista_codigos_3);

    return 0;
}
