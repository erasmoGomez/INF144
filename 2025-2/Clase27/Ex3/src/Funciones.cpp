//
// Created by Erasmo on 22/11/25.
//
#include "Funciones.hpp"
#include <fstream>
#include <iostream>

using namespace std;

bool es_lista_vacia(struct ListaCliente &l) {
    return l.inicio == nullptr;
}

char *leer_cadena(ifstream &input, char delim) {
    char *cadena, buffer[100];
    input.getline(buffer, 100, delim);
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char *leer_cadena_txt(ifstream &input) {
    char *cadena, buffer[100];
    input >> buffer;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

char *asignar_cadena(const char *buffer) {
    char *cadena;
    cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void apertura_archivo_lectura(ifstream &input, const char *nombre_archivo) {
    input.open(nombre_archivo, ios::in);
    if (!input.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void apertura_archivo_escritura(ofstream &output, const char *nombre_archivo) {
    output.open(nombre_archivo, ios::out);
    if (!output.is_open()) {
        cout << "Fue pe" << endl;
        exit(0);
    }
}

void inicializa_lista_clientes(struct ListaCliente &lista_clientes) {
    lista_clientes.cantidad_clientes = 0;
    lista_clientes.cantidad_impares = 0;
    lista_clientes.cantidad_pares = 0;
    lista_clientes.inicio = nullptr;
    lista_clientes.fin = nullptr;
    lista_clientes.limite = nullptr;
}

void inicializa_lista_libros(struct ListaLibro &lista_libros) {
    lista_libros.cantidad_libros = 0;
    lista_libros.inicio = nullptr;
}

bool es_lista_vacia_2(struct ListaCliente &lista_clientes) {
    return lista_clientes.inicio == nullptr and lista_clientes.fin == nullptr;
}

void insertar_nodo_cliente_inicio(struct ListaCliente &lista_clientes, struct Cliente &c) {
    // Crear el nodo
    struct NodoCliente *nuevo_nodo;
    nuevo_nodo = new struct NodoCliente; //Reservamos memoria x q es puntero
    nuevo_nodo->dato = c;
    nuevo_nodo->siguiente = nullptr;

    //Conexiones
    //Caso A: Lista Vacia -> lista_clientes == nullptr;
    nuevo_nodo->siguiente = lista_clientes.inicio;
    if (es_lista_vacia_2(lista_clientes)) {
        //Actualizo mi TAD
        lista_clientes.inicio = nuevo_nodo;
        lista_clientes.fin = nuevo_nodo;
    }
    //Caso B: Lista Llena
    lista_clientes.inicio = nuevo_nodo; //Update de la TAD
    lista_clientes.cantidad_pares++;
    lista_clientes.cantidad_clientes++;
}

void insertar_nodo_libro_inicio(struct ListaLibro &lista_libros, struct Libro l) {
    // Crear el nodo
    struct NodoLibro *nuevo_nodo;
    nuevo_nodo = new struct NodoLibro;
    nuevo_nodo->dato = l;
    nuevo_nodo->siguiente = lista_libros.inicio;

    lista_libros.inicio = nuevo_nodo; //Update de la TAD
    lista_libros.cantidad_libros++;
}

void insertar_nodo_libro_ordenado(struct ListaLibro &lista_libros, struct Libro l) {
    // Inicializar punteros
    struct NodoLibro *recorrido = lista_libros.inicio;
    struct NodoLibro *anterior = nullptr;

    // Crear el nodo
    struct NodoLibro *nuevo_nodo;
    nuevo_nodo = new struct NodoLibro;
    nuevo_nodo->dato = l;
    nuevo_nodo->siguiente = nullptr;
    nuevo_nodo->siguiente = lista_libros.inicio;

    //Buscar Posicion y actualizar recorrido y anterior
    while (recorrido) {
        // recorrido != nullptr
        if (strcmp(recorrido->dato.codigo, l.codigo) > 0) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    //Hacer las conexiones.
    nuevo_nodo->siguiente = recorrido;
    if (anterior == nullptr) lista_libros.inicio = nuevo_nodo;
    else anterior->siguiente = nuevo_nodo;
    lista_libros.cantidad_libros++;
}

void inicializar_nuevo_nodo(struct NodoCliente *&nuevo_nodo, struct Cliente &c) {
    nuevo_nodo = new struct NodoCliente;
    nuevo_nodo->dato = c;
    nuevo_nodo->siguiente = nullptr;
}

void insertar_nodo_cliente_fin(struct ListaCliente &lista_clientes, struct Cliente &c) {
    // Crear el nodo
    struct NodoCliente *nuevo_nodo;
    inicializar_nuevo_nodo(nuevo_nodo, c);

    if (es_lista_vacia_2(lista_clientes)) {
        lista_clientes.inicio = nuevo_nodo;
        lista_clientes.fin = nuevo_nodo;
    }

    lista_clientes.fin->siguiente = nuevo_nodo;
    lista_clientes.fin = nuevo_nodo; //Update de la TAD
    lista_clientes.cantidad_impares++;
    lista_clientes.cantidad_clientes++;
}

void leer_lista_clientes(struct ListaCliente &lista_clientes, const char *nombre_archivo, const char *opt) {
    inicializa_lista_clientes(lista_clientes);
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //54393647,Reyes Tang Edward
    struct Cliente c{};
    int dni_cliente;
    while (true) {
        input >> dni_cliente;
        if (input.eof())break;
        input.get();
        c.nombre = leer_cadena(input, '\n');
        c.dni = dni_cliente;
        if (strcmp(opt, "inicio") == 0)
            insertar_nodo_cliente_inicio(lista_clientes, c);
        else
            insertar_nodo_cliente_fin(lista_clientes, c);
    }
}

void imprimir_reporte_prueba_clientes(struct ListaCliente &lista_clientes, const char *nombre_archivo) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);

    struct NodoCliente *recorrido = lista_clientes.inicio;
    while (recorrido) {
        output << setw(10) << recorrido->dato.dni << setw(50) << recorrido->dato.nombre << endl;
        recorrido = recorrido->siguiente;
    }
    output << setw(30) << "Total Clientes: " << lista_clientes.cantidad_clientes << endl;
    output << setw(30) << "Total Clientes con DNI Par: " << lista_clientes.cantidad_pares << endl;
    output << setw(30) << "Total Clientes con DNI Impar: " << lista_clientes.cantidad_impares << endl;
}

void leer_lista_clientes_bloques(struct ListaCliente &lista_clientes, const char *nombre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);

    inicializa_lista_clientes(lista_clientes); // No olvidar

    struct Cliente c{};
    int dni_cliente;
    // 67066631,Arca Amezquita Edric Ronald
    while (true) {
        input >> dni_cliente;
        if (input.eof())break;
        input.get(); //Leemos la coma
        c.dni = dni_cliente;
        c.nombre = leer_cadena(input, '\n');
        //hasta aqui tenemos el Cliente bien leido.

        //Tenemos que validar como hacer la insercion
        if (dni_cliente % 2 == 0) {
            insertar_nodo_cliente_inicio(lista_clientes, c);
        } else
            insertar_nodo_cliente_fin(lista_clientes, c);

        // Practiquen insercion en medio
        // Practiquen insertar ordenado
    }
}

double leer_double(ifstream &input) {
    double d;
    input >> d;
    input.get();
    return d;
}

int leer_entero(ifstream &input, bool opt = true) {
    int i;
    input >> i;
    if (opt)
        input.get();
    return i;
}


void leer_lista_libros(struct ListaLibro &lista_libros, const char *nombre_archivo) {
    inicializa_lista_libros(lista_libros);
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,69.02
    struct Libro l{};
    char codigo_libro[20];
    while (true) {
        input.getline(codigo_libro, 20, ',');
        if (input.eof()) break;
        l.titulo = leer_cadena(input, ',');
        l.autor = leer_cadena(input, ',');
        l.precio = leer_double(input);
        l.codigo = asignar_cadena(codigo_libro);
        l.total_ventas = 0;
        l.cantidad_buenas_calificaciones = 0;
        l.suma_buenas_calificaciones = 0;
        l.unidades_vendidas = 0;
        for (auto &libreria: l.librerias) {
            libreria.ventas = new Venta[10];
            libreria.cantidad_ventas = 0;
        }
        //insertar_nodo_libro_inicio(lista_libros, l);
        insertar_nodo_libro_ordenado(lista_libros, l);
    }
}

void imprimir_reporte_prueba_libros(struct ListaLibro &lista_libros, const char *nombre_archivo) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);

    struct NodoLibro *recorrido = lista_libros.inicio;
    while (recorrido) {
        output << setw(10) << recorrido->dato.codigo << setw(80) << recorrido->dato.titulo << setw(4)<<recorrido->dato.cantidad_librerias<<endl;
        for (int i=0; i<recorrido->dato.cantidad_librerias; i++)
            output<<setw(10)<<recorrido->dato.librerias[i].codigo;
        output<<endl;
        output<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        recorrido = recorrido->siguiente;
    }
    output << setw(30) << "Total Libros: " << lista_libros.cantidad_libros << endl;
}

int leer_fecha(ifstream &input) {
    int dd, mm, aa;
    char c;
    input >> dd >> c >> mm >> c >> aa;
    input.get();
    int fecha = aa * 10000 + mm * 100 + dd;
    return fecha;
}

char *buscar_nombre(int dni_comprador, struct ListaCliente &lista_clientes) {
    NodoCliente *recorrido = lista_clientes.inicio;
    while (recorrido) {
        if (dni_comprador == recorrido->dato.dni) return recorrido->dato.nombre;
        recorrido = recorrido->siguiente;
    }
    return nullptr;
}

struct NodoLibro *buscar_nodo_libro(struct ListaLibro &lista_libros, char *codigo_libro) {
    NodoLibro *recorrido = lista_libros.inicio;
    int cont = 0;
    while (recorrido) {
        cont++;
        if (strcmp(codigo_libro, recorrido->dato.codigo) == 0) return recorrido;
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

void insertar_venta(struct ListaLibro &lista_libros, struct Venta &venta, char *codigo_libro, int codigo_libreria) {
    NodoLibro *nuevo_nodo = new NodoLibro;
    nuevo_nodo->dato = buscar_nodo_libro(lista_libros, codigo_libro);
    // if (strcmp(codigo_libro,"AGQ7769") == 0) {
    //     cout<<"parar"<<endl;
    // }
    int index_libreria = nuevo_nodo->dato.cantidad_librerias;
    int index_venta = nuevo_nodo->dato.librerias[index_libreria].cantidad_ventas;

    if (nuevo_nodo->dato.librerias[index_libreria].codigo == codigo_libreria) {
        nuevo_nodo->dato.librerias[index_libreria].cantidad_ventas++;
        nuevo_nodo->dato.librerias[index_libreria].ventas[index_venta] = venta;
        nuevo_nodo->dato.librerias[index_libreria].total_ventas++;
    }
    else {
        lista_libros.inicio->dato.librerias[lista_libros.inicio->dato.cantidad_librerias].codigo = codigo_libreria;
        lista_libros.inicio->dato.librerias[lista_libros.inicio->dato.cantidad_librerias].ventas[lista_libros.inicio->dato.librerias[lista_libros.inicio->dato.cantidad_librerias].cantidad_ventas] = venta;
        lista_libros.inicio->dato.librerias[lista_libros.inicio->dato.cantidad_librerias].cantidad_ventas++;
        lista_libros.inicio->dato.librerias[lista_libros.inicio->dato.cantidad_librerias].total_ventas++;
        lista_libros.inicio->dato.cantidad_librerias++;
        nuevo_nodo->siguiente = lista_libros.inicio;
        lista_libros.inicio = nuevo_nodo;
        lista_libros.cantidad_libros++;
    }
}

void leer_ventas(ifstream &input, struct ListaCliente &lista_clientes, struct ListaLibro &lista_libros, int fecha,
                 int codigo_libreria) {
    char c;
    struct Venta venta{};
    double monto_comprado = 0, descuento_futuro = 0;
    while (true) {
        char *codigo_libro = leer_cadena_txt(input);
        venta.dni_comprador = leer_entero(input);
        venta.calificacion = leer_entero(input, false);
        venta.fecha = fecha;
        venta.nombre_comprador = buscar_nombre(venta.dni_comprador, lista_clientes);
        insertar_venta(lista_libros, venta, codigo_libro, codigo_libreria);
        monto_comprado = 123;
        descuento_futuro = 20;
        delete[] codigo_libro;
        c = input.get();
        if (c == '\n') break;
    }
    cout << "Procese Linea" << endl;
}

void actualizar_clientes_libros(struct ListaCliente &lista_clientes, struct ListaLibro &lista_libros,
                                const char *nombre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    struct Cliente c{};
    int codgo_libreria, fecha;
    while (true) {
        input >> codgo_libreria;
        if (input.eof())break;
        input.get();
        fecha = leer_fecha(input);
        leer_ventas(input, lista_clientes, lista_libros, fecha, codgo_libreria);
    }
}
