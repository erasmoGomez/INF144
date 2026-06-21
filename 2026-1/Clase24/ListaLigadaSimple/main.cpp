#include "BibliotecaListaSimple/ListaSimpleTAD.hpp"
#include "BibliotecaFuncionesAuxiliares/FuncionesAuxiliares.hpp"
int main() {
    ListaTAD lista_codigos;
    cargar_lista_codigos_al_inicio(lista_codigos, "ArchivosDeDatos/codigos.txt");
    return 0;
}