

#include "src/AuxiliaryFunctions.hpp"

int main() {
    // ===== Declaración de variables básicas =====
    int dia = 25, mes = 8, anio = 2025;
    int fecha = anio*10000+mes*100+dia;

    char nombreRestaurante[MAX_NOMBRE];
    char comentario[MAX_COMENT];
    double rating = 0.78; //Valores entre 0 a 1.

    double latitud  = -12.0464;
    double longitud = -77.0428; // Lima, Perú

    bool recomendado = true;

    char listaComentarios[MAX_LISTA][MAX_ITEMLEN];
    int  cantComentarios = 0;

    // ===== Seteo de valores =====
    safe_copy(nombreRestaurante, "La Sazon Peruana", MAX_NOMBRE);

    safe_copy(comentario,
              "Muy buena atencion y comida deliciosa. "
              "El aji de gallina estuvo excelente; sirven rapido y el local es limpio.",
              MAX_COMENT
    );

    // Lista de comentarios adicionales
    safe_copy(listaComentarios[0], "El ceviche estaba fresco.", MAX_ITEMLEN);
    safe_copy(listaComentarios[1], "El lomo saltado muy sabroso.", MAX_ITEMLEN);
    safe_copy(listaComentarios[2], "Los postres podrian mejorar.", MAX_ITEMLEN);
    safe_copy(listaComentarios[3], "Precio/calidad correcto. Volveria.", MAX_ITEMLEN);
    cantComentarios = 4;

    // ===== Reporte inicial =====
    imprimirReporte(
            fecha,
            nombreRestaurante,
            comentario,
            rating,
            latitud, longitud,
            recomendado,
            listaComentarios,
            cantComentarios,
            REP_WIDTH
    );

    // ===== Demostración de “Cifrar” (a MAYÚSCULAS) =====
    demoCifrarComentario(comentario, REP_WIDTH);

    // ===== Cambio de valores y reimpresión =====
    rating = 0.98;
    recomendado = true;
    cout << endl;
    print_center("ACTUALIZANDO RATING Y REIMPRESION DEL REPORTE", REP_WIDTH);
    imprimirReporte(
            fecha,
            nombreRestaurante,
            comentario,          // ya viene en mayúsculas tras el “cifrado”
            rating,
            latitud, longitud,
            recomendado,
            listaComentarios,
            cantComentarios,
            REP_WIDTH
    );

    return 0;
}

