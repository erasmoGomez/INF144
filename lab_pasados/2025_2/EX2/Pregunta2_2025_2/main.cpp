#include "Bibliotecas/Funciones.hpp"

int main() {
    struct ListaPalabra stopwords{}; //importante inicializar su lista.
    struct ListaPalabra palabras{};
    struct ListaPalabra ranking{};
    cargar_stopwords("ArchivosDeDatos/stopwords.txt", stopwords);
    cargar_palabras("ArchivosDeDatos/comentarios.csv", palabras);
    imprimir_palabras("ArchivosDeReportes/reporte_stopwords.txt", stopwords);
    imprimir_palabras("ArchivosDeReportes/reporte_tokens.txt", palabras);
    eliminar_stopwords(palabras, stopwords);
    imprimir_palabras("ArchivosDeReportes/tokens_sin_stopwords.txt", palabras);
    cargar_palabras_ordenado("ArchivosDeReportes/tokens_sin_stopwords.txt", ranking);
    imprimir_palabras("ArchivosDeReportes/reporte_tokens_sin_stopwords_ordenado_frecuencia.txt", ranking);
    return 0;
}


