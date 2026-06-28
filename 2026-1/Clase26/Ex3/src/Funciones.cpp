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

bool es_lista_vacia(struct ListaLibro &l) {
    return l.inicio == nullptr;
}

int leer_fecha(ifstream &input) {
    int dd, mm, yyyy, date;
    char c;
    input >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;
    return date;
}

char *leer_cadena(ifstream &input, char delim) {
    char *cadena, buffer[100];
    input.getline(buffer, 100, delim);
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

struct Cliente asignar_struct_cliente(struct Cliente &cliente) {
    struct Cliente c;
    c.dni = cliente.dni;
    c.nombre = asignar_cadena(cliente.nombre); //Este nos daba problemas x eso le asignamos nueva memoria
    c.monto_comprado = cliente.monto_comprado;
    c.descuento_futuro = cliente.descuento_futuro;
    return c;
}

void insertar_nodo_cliente_inicio(struct ListaCliente &lista_clientes, struct Cliente &c) {
    // Crear el nodo
    struct NodoCliente *nuevo_nodo; //Definicion o instancia
    nuevo_nodo = new struct NodoCliente; //Reservamos memoria x q es puntero
    //nuevo_nodo->dato = c; //Esto da error, mas seguro es usar un asignar_struct
    nuevo_nodo->dato = asignar_struct_cliente(c);
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

    if (es_lista_vacia(lista_libros)) {
        lista_libros.inicio = nuevo_nodo;
    }
    lista_libros.inicio = nuevo_nodo; //Update de la TAD
    lista_libros.cantidad_libros++;
}

void inicializar_nuevo_nodo(struct NodoCliente *&nuevo_nodo, struct Cliente &c) {
    nuevo_nodo = new struct NodoCliente;
    nuevo_nodo->dato = asignar_struct_cliente(c);
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
    struct Cliente c;
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
    int dni_cliente;
    // 67066631,Arca Amezquita Edric Ronald
    while (true) {
        input >> dni_cliente;
        if (input.eof())break;
        input.get(); //Leemos la coma
        struct Cliente c{};
        c.dni = dni_cliente;
        c.nombre = leer_cadena(input, '\n');
        //hasta aqui tenemos el Cliente bien leido.

        //Tenemos que validar como hacer la insercion
        if (dni_cliente % 2 == 0) {
            insertar_nodo_cliente_inicio(lista_clientes, c);
        } else
            insertar_nodo_cliente_fin(lista_clientes, c);
        delete c.nombre;

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

void leer_lista_libros(struct ListaLibro &lista_libros, const char *nombre_archivo) {
    inicializa_lista_libros(lista_libros);
    ifstream input;
    apertura_archivo_lectura(input, nombre_archivo);
    //IIM5175,Diamantes y pedernales,Jose Maria Arguedas,69.02
    char codigo_libro[20];
    while (true) {
        input.getline(codigo_libro, 20, ',');
        if (input.eof()) break;
        struct Libro l{};
        l.titulo = leer_cadena(input, ',');
        l.autor = leer_cadena(input, ',');
        l.precio = leer_double(input);
        l.codigo = asignar_cadena(codigo_libro);
        l.librerias = new Libreria[10]{};
        l.cantidad_librerias = 0;
        l.total_ventas = 0.0;
        insertar_nodo_libro_inicio(lista_libros, l);
    }
}

void imprimir_reporte_prueba_libros(struct ListaLibro &lista_libros, const char *nombre_archivo) {
    ofstream output;
    apertura_archivo_escritura(output, nombre_archivo);

    struct NodoLibro *recorrido = lista_libros.inicio;
    while (recorrido) {
        output << setw(10) << recorrido->dato.codigo << setw(80) << recorrido->dato.titulo << endl;
        recorrido = recorrido->siguiente;
    }
    output << setw(30) << "Total Libros: " << lista_libros.cantidad_libros << endl;
}

int buscar_libreria(Libreria *librerias, int cantidad_librerias,
                    int codigo_buscado) {
    for (int i = 0; i < cantidad_librerias; i++) {
        if (librerias[i].codigo == codigo_buscado) {
            return i;
        }
    }
    return -1;
}

struct Venta asignar_struct_venta(struct Venta & v) {
    struct Venta venta;
    venta.dni_comprador = v.dni_comprador;
    venta.nombre_comprador = asignar_cadena(v.nombre_comprador);
    venta.calificacion = v.calificacion;
    venta.fecha = v.fecha;
    return venta;
}

void insertar_libreria(struct ListaLibro lista_libro, int codigo_libreria, char *codigo_libro, struct Venta v) {
    struct NodoLibro *recorrido = lista_libro.inicio;
    double precio_libro = 0;
    while (recorrido) {
        if (strcmp(recorrido->dato.codigo, codigo_libro) == 0) {
            precio_libro = recorrido->dato.precio;
            break;
        }
        recorrido = recorrido->siguiente;
    }
    Libreria *librerias = recorrido->dato.librerias;
    int cantidad_librerias = recorrido->dato.cantidad_librerias;
    int pos = buscar_libreria(librerias, cantidad_librerias, codigo_libreria);
    cout<<pos<<endl;
    if (pos == -1) {
        librerias[pos].codigo = codigo_libreria;
        librerias[pos].ventas  = new Venta[50];
        librerias[pos].ventas[0] = asignar_struct_venta(v);
        librerias[pos].cantidad_ventas = 1;
        librerias[pos].total_ventas = precio_libro;
    }
    else {
        librerias[pos].ventas[librerias[pos].cantidad_ventas] = asignar_struct_venta(v);
        librerias[pos].cantidad_ventas++;
        librerias[pos].total_ventas += precio_libro;
    }
}

char * buscar_nombre(struct ListaCliente & lista_cliente, int dni_comprador) {
    struct NodoCliente *recorrido = lista_cliente.inicio;
    while (recorrido) {
        if (recorrido->dato.dni == dni_comprador)
            return asignar_cadena(recorrido->dato.nombre);
        recorrido= recorrido->siguiente;
    }
    return nullptr;
}

void leer_actualizar_datos_venta(struct ListaCliente &lista_cliente,
                                 struct ListaLibro lista_libro,
                                 const char *momnre_archivo) {
    ifstream input;
    apertura_archivo_lectura(input, momnre_archivo);
    //99377   29/4/2024   RZX8790   92240876   18   RAO4129   15129661   21
    int codigo_libreria, fecha_compra, dni_comprador, calificacion, pos;
    char codigo_libro[20];
    while (true) {
        input >> codigo_libreria;
        if (input.eof() or input.fail()) {
            cout<<codigo_libreria<<endl;
            break;
        }
        fecha_compra = leer_fecha(input);
        while (true) {
            //Primera Forma
            input >> codigo_libro;
            input >> dni_comprador;
            input >> calificacion;
            Venta v;
            v.dni_comprador = dni_comprador;
            v.calificacion = calificacion;
            v.fecha = fecha_compra;
            v.nombre_comprador = buscar_nombre(lista_cliente, dni_comprador);
            insertar_libreria(lista_libro, codigo_libreria, codigo_libro, v);
            char c = input.get();
            if (c == '\n') break;
        }
    }
}