//
// Created by Erasmo on 25/08/25.
//

#include "AuxiliaryFunctions.hpp"

void safe_copy(char *dest, const char *src, int max_len) {
    int i = 0;
    for (; src[i] and  i + 1 < max_len; ++i) dest[i] = src[i]; //Tarea: Entender la condicion
    dest[i] = '\0';
}

void CifrarMayusculas(char *s) {
    for (int i = 0; s[i]; ++i) { //Tarea: Entender la condicion
        char c = s[i];
        if (c >= 'a' and c <= 'z') s[i] = char(c - ('a' - 'A'));
    }
}

void print_line(int n, char c) {
    for (int i = 0; i < n; i++) cout << c;
    cout << endl;
}

void print_line_2(int n, char c) {
    cout << setfill(c)<<setw(n)<<""<<endl;
    cout << setfill(' ');
}

void print_center(const char *text, int width, char fill) {
    int len = 0;
    while (text and text[len]) ++len;

    if (len >= width) {
        for (int i = 0; i < len; ++i) std::cout << text[i];
        std::cout << std::endl;
        return;
    }

    int pad_total = width - len;
    int pad_left = pad_total / 2;
    int pad_right = pad_total - pad_left;

    for (int i = 0; i < pad_left; ++i) std::cout << fill;
    for (int i = 0; i < len; ++i) std::cout << text[i];
    for (int i = 0; i < pad_right; ++i) std::cout << fill;
    std::cout << "\n";
}

// ===== Impresión de campos (sin structs) =====
void print_header(const char *titulo, int width) {
    print_line(width, '=');
    print_center(titulo, width);
    print_line(width, '=');
}

// void print_kv(const char *key, const char *value, int keyw, int width) {
//     std::cout << left << setw(keyw) << key
//          << " : " << left << setw(width - keyw - 3) << value << std::endl;
// }
//
// void print_kv_num(const char *key, double value, int precision, int keyw) {
//     std::cout << left << setw(keyw) << key << " : "
//          << fixed << setprecision(precision) << value << std::endl;
// }
//
// void print_fecha(int dia, int mes, int anio, int keyw) {
//     std::cout << left << setw(keyw) << "Fecha" << " : ";
//     std::cout << right;
//     std::cout << setw(2) << setfill('0') << dia;
//     std::cout << "/";
//     std::cout << setw(2) << setfill('0') << mes;
//     std::cout << "/";
//     std::cout << setw(4) << setfill('0') << anio;
//
//     std::cout << setfill(' ') << std::endl;  // restaurar fill a espacio
// }
//
// void print_ubicacion(double lat, double lon, int keyw) {
//     std::cout << left << setw(keyw) << "Ubicacion" << " : "
//          << "(" << fixed << setprecision(6) << lat
//          << ", " << fixed << setprecision(6) << lon << ")"<<std::endl;
// }
//
// void print_bool(const char *key, bool b, int keyw) {
//     std::cout << left << setw(keyw) << key << " : " << (b ? "Si" : "No") << std::endl;
// }

void print_block(const char *title, const char *text, int width) {
    print_line(width, '-');
    print_center(title, width);
    print_line(width, '-');

    const int maxLine = width - 2; // dejando bordes laterales
    int i = 0, col = 0;
    std::cout << "|";
    while (text && text[i]) {
        std::cout << text[i];
        ++i;
        ++col;
        if (col >= maxLine) {
            std::cout << "|"<<std::endl<<"|";
            col = 0;
        }
    }
    while (col++ < maxLine) std::cout << ' ';
    std::cout << "|"<<std::endl;
    print_line(width, '-');
}

// ===== Reporte =====
// void imprimirReporte(
//         int fecha,
//         const char *nombreRestaurante,
//         const char *comentario,
//         double rating,
//         double latitud, double longitud,
//         bool recomendado,
//         char listaComentarios[][MAX_ITEMLEN],
//         int cantComentarios,
//         int width
// ) {
//     const int KEYW = 18; // Ancho del nombre de la propiedad a imprimir
//     int anio = fecha / 10000;        // 2025
//     int mes = (fecha / 100) % 100;  // 08
//     int dia = fecha % 100;          // 25
//
//     print_header("REPORTE DE REVIEW DE RESTAURANTE", width);
//
//     print_fecha(dia, mes, anio, KEYW);
//     print_kv("Nombre", nombreRestaurante, KEYW, width);
//     print_kv_num("Rating", rating, 1, KEYW);
//     print_ubicacion(latitud, longitud, KEYW);
//     print_bool("Recomendado", recomendado, KEYW);
//
//     std::cout << std::endl;
//     print_block("COMENTARIO PRINCIPAL", comentario, width);
//
//     std::cout << left << setw(KEYW) << "Comentarios extra" << " : " << cantComentarios << std::endl;
//     if (cantComentarios > 0) {
//         std::cout << "---------------- LISTA DE COMENTARIOS ----------------"<<std::endl;
//         for (int i = 0; i < cantComentarios; ++i) {
//             std::cout << "  - " << listaComentarios[i] << std::endl;
//         }
//     }
//
//     print_line(width, '=');
// }
//
// // ===== Demostración de “Cifrar” (mayúsculas) =====
// void demoCifrarComentario(char *comentario, int width) {
//     print_center("APLICANDO CIFRADO: MAYUSCULAS AL COMENTARIO", width, ' ');
//     CifrarMayusculas(comentario);
//     print_block("COMENTARIO CIFRADO (MAYUSCULAS)", comentario, width);
// }