#include "src/VideoJuego.hpp"
#include "src/Funciones.hpp"

int main() {
//    struct VideoJuego videojuego1;
//    videojuego1.id = 123;
//    videojuego1.precio = 75.99;
//    videojuego1.es_apto = true;
//    videojuego1.fecha_lanzamiento = 20250915;
//    videojuego1.titulo = asignar_str("Pokemon ZA");
//
//    for(int i=0; i< 5; i++){
//        videojuego1.dlcs[i] = asignar_str("DLC");
//    }
//
//    videojuego1.empresa_desarrolladora.cantidad_desarrolladores = 50;
//    videojuego1.empresa_desarrolladora.nombre = asignar_str("NIATICS!");
//
//    cout<<videojuego1.titulo<<endl;
//    cout<<videojuego1.dlcs[3]<<endl;
//    cout<<videojuego1.empresa_desarrolladora.nombre;
//
//    struct VideoJuego videojuego2;
//
//    videojuego2 = videojuego1;
//
//    cout<<videojuego2.titulo<<endl;
//    cout<<videojuego2.dlcs[3]<<endl;
//    cout<<videojuego2.empresa_desarrolladora.nombre;
//
//    videojuego1.titulo = asignar_str("Cambio");
//    cout<<videojuego1.titulo<<endl;
//    cout<<videojuego2.titulo<<endl;

    struct Cancion canciones[2100];
    int n_canciones = 0;
    cargar_canciones("Data/music_dataset_extended.csv", canciones, n_canciones);
    ordenar_canciones(canciones, n_canciones);
    imprimir_canciones("Reports/reporte.txt", canciones, n_canciones);
    return 0;
}
