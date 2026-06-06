#include "Bibliotecas/FuncionesAuxiliares.hpp"

/*-----------------------------------------*/
int main() {
    char texto[MAX] = "Hola, Mundo!!! NLP-2026.";
    char nombre_largo[MAX] = "juan carlos perez lopez";
    char resultado[MAX];
    char path[MAX];

    cout << "Texto original: " << texto << endl;

    a_mayusculas(texto);
    cout << "Mayusculas: " << texto << endl;

    a_minusculas(texto);
    cout << "Minusculas: " << texto << endl;

    remover_no_alfanumericos(texto);
    cout << "Sin simbolos: " << texto << endl;

    espacios_a_guion_bajo(texto);
    cout << "Con guion bajo: " << texto << endl;

    char frase[MAX] = "juan perez lopez";
    camelizar(frase);
    cout << "Camelizado: " << frase << endl;

    generar_nombre_corto(nombre_largo, resultado);

    cout << "Nombre corto: " << resultado << endl;

    generar_codigo("juan", "perez", resultado);
    cout << "Codigo: " << resultado << endl;

    formar_path("datos", "alumnos.csv", path);
    cout << "Path generado: " << path << endl;

    abrir_archivos_multiples();

    return 0;
}