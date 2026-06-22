//
// Created by erasmo on 6/22/26.
//

#include "FuncionesEstructuras.hpp"

struct Categoria leer_categoria(ifstream &input, char *buffer_codigo) {
    Categoria c;
    c.codigo = asignar_cadena(buffer_codigo);
    c.nombre = leer_cadena(input, ',', 60);
    c.descripcion = leer_cadena(input, '\n', 100);
    c.reproducciones = new struct Reproduccion[40]{};
    c.n_reproducciones = 0;
    c.promedio_rating = 0.0;
    c.duracion_total = 0.0;
    return c;
}

void cargar_categorias(const char *nombre_archivo, struct Categoria *&categorias, int &cantidad_categorias) {
    //UM163F47,just chatting,Casual conversations; reactions; and hangouts without a main game.
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    categorias = new struct Categoria[MAX_CATEGORIAS]{};
    char buffer_codigo[20];

    while (true) {
        input.getline(buffer_codigo, 20, ',');
        if (input.eof()) break;
        categorias[cantidad_categorias] = leer_categoria(input, buffer_codigo);
        cantidad_categorias++;
    }
}

void imprimir_duracion(ofstream &output, int seg) {
    int h = seg / 3600;
    int m = seg % 3600;
    int s = (seg % 3600) % 60;
    output << setw(3) << ' ' << setfill('0') << setw(2) << h << ':' << setw(2) << m << ':'
            << setw(2) << s << setfill(' ') << endl;
}

void imprimir_reporte(const char *nombre_archivo, struct Categoria *categorias, int cantidad_categorias) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);

    output << setw(50) << "REPORTE POR CATEGORIAS" << endl;
    imprimir_linea('=', ANCHO_REPORTE, output);
    for (int i = 0; i < cantidad_categorias; i++) {
        output << "Codigo: " << categorias[i].codigo << endl;
        output << "Nombre: " << categorias[i].nombre << endl;
        output << "Descripcion: " << categorias[i].descripcion << endl;
        imprimir_linea('-', ANCHO_REPORTE, output);
        if (categorias[i].n_reproducciones > 0) {
            output << "REPRODUCCIONES:" << endl;
            struct Reproduccion auxRepro;
            for (int j = 0; j < categorias[i].n_reproducciones; j++) {
                auxRepro = categorias[i].reproducciones[j];
                output << "CANAL: " << left << setw(15) << auxRepro.canal
                        << right << "RATING: " << setw(8) << auxRepro.rating << endl << "DURACION: ";
                imprimir_duracion(output, auxRepro.duracion);
                if (auxRepro.n_comentarios > 0) {
                    output << setw(15) << "COMENTARIOS:" << endl;
                    for (int k = 0; k < auxRepro.n_comentarios; k++)
                        output << setw(4) << "- " << auxRepro.comentarios[k] << endl;
                }
            }
            imprimir_linea('=', ANCHO_REPORTE, output);
        }
    }
}
