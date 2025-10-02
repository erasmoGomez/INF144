#include "src/Funciones.hpp"

int main() {
    // /////////////////////////////////////////////////////////////
    //                  ALGORITMOS DE ORDENAMIENTO               //
    // ///////////////////////////////////////////////////////////

    int datos[5] = {5, 3, 4, 1, 2};
    int n = 5;
//    insertion_sort(datos, n);
//    imprime_datos(datos, n);
//
//    selection_sort(datos, n);
//    imprime_datos(datos, n);

//    bubble_sort(datos, n);
//    imprime_datos(datos, n);

//    selection_sort_not_efficient(datos, n);
//    imprime_datos(datos, n);

//    int arr[10];
//    int size = 0;
//
//    insert_ordered(arr, 15, size);
//    insert_ordered(arr, 8, size);
//    insert_ordered(arr, 12, size);
//    insert_ordered(arr, 20, size);
//    insert_ordered(arr, 3, size);
//
//    imprime_datos(arr, n);
    // Result: [3, 8, 12, 15, 20]
    // /////////////////////////////////////////////////////////////
    //                    ARREGLOS DEL DATASET                   //
    // ///////////////////////////////////////////////////////////
    int dnis[MAX_DATOS], fechasIng[MAX_DATOS], telefonos[MAX_DATOS], numDat = 0;
    char sexos[MAX_DATOS];
    double sueldos[MAX_DATOS];

    // /////////////////////////////////////////////////////////////
    //                     ORDENAR UN DATASET                    //
    // ///////////////////////////////////////////////////////////

    leer_empleados("Data/Empleados.txt", dnis, fechasIng,
                   sexos, telefonos, sueldos, numDat);

    ordenar_por_dni(dnis, fechasIng,
                    sexos, telefonos, sueldos, numDat);

    imprimir_empleados("Reports/ReporteEmpleadosOrdDni.txt", dnis,
                       fechasIng, sexos, telefonos, sueldos, numDat);


    // /////////////////////////////////////////////////////////////
    //              INSERTAR ORDENADO UN DATASET                 //
    // ///////////////////////////////////////////////////////////

//    leer_insertar_ordenado("Data/Empleados.txt", dnis, fechasIng,
//                           sexos, telefonos, sueldos, numDat);
//    imprimir_empleados("Reports/ReporteEmpleadosInsertarOrdenado.txt", dnis,
//                       fechasIng, sexos, telefonos, sueldos, numDat);
    return 0;
}
