//
// Created by Erasmo on 4/09/25.
//

#include "AuxiliaryFunctions.hpp"
// ==== IMPLEMENTACIONES ====

// 1) Lectura simple de tres enteros
void leerTresEnteros() {
    int a, b, c;
    cout << "Ingresa 3 enteros separados por espacios: ";
    if (cin >> a >> b >> c) {
        cout << "Leidos: a=" << a << ", b=" << b << ", c=" << c << "\n";
    } else {
        cout << "Entrada invalida.\n";
        cin.clear();
        limpiarLinea();
    }
}

// 2) Mezcla de tipos
void leerEnteroDoubleChar() {
    int x;
    double y;
    char z;
    cout << "Ingresa: <int> <double> <char>: ";
    if (cin >> x >> y >> z) {
        cout << "Leidos -> int:" << x << " double:" << fixed << setprecision(3)
             << y << " char:'" << z << "'\n";
    } else {
        cout << "Entrada invalida.\n";
        cin.clear();
        limpiarLinea();
    }
}

// 3) Leer fecha dd/mm/aaaa
int leerFecha(int &dd, int &mm, int &yyyy) {
    // Estrategia: leer dd, '/', mm, '/', aa verificando separadores
    int date;
    char c;
    dd = mm = yyyy = 0;
    cin >> dd >> c >> mm >> c >> yyyy;
    date = yyyy * 10000 + mm * 100 + dd;

    // Validacion simple de rango (no valida calendario real)
    if (dd < 1 || dd > 31 || mm < 1 || mm > 12 || yyyy < 1) return 0;
    return date;
}

// 4) Leer hora HH:MM:SS
int leerHora(int &HH, int &MM, int &SS) {
    //05:17:39
    int hour;
    char c;
    cin >> HH >> c >> MM >> c >> SS;
    hour = HH * 3600 + MM * 60 + SS;
    if (HH < 0 or HH > 23 or MM < 0 or MM > 59 or SS < 0 or SS > 59) return 0;
    return hour;
}

// 5) Eco de TOKEN a MAYUS sin almacenar (hasta espacio/newline)
void ecoTokenMayusSinAlmacenar() {
    cin >> ws; // ignora espacios iniciales
    while (true) {
        int ch = cin.peek();
        if (ch == EOF) break;
        if (isspace(ch)) { // termina token en espacio o newline
            break;
        }
        ch = cin.get();
        // Importante: convertir con cast a unsigned char para evitar UB en toupper
        char out = static_cast<char>(toupper(static_cast<unsigned char>(ch)));
        cout.put(out);
    }
}

// 6) Eco de LINEA completa a MAYUS sin almacenar (hasta '\n')
void ecoLineaMayusSinAlmacenar() {
    // No usamos string ni buffer: procesamos caracter a caracter.
    int ch;
    while (true) {
        ch = cin.get();
        if (ch == EOF or ch == '\n') break;
        cout.put(ch);
    }
}

// 7) Sumar enteros hasta Tope: patrón correcto
void sumarEnterosHastaTope() {
    long long suma = 0;
    long long x;
    while (true) {
        cin >> x;
        if(x == 0) break;
        suma += x;
    }
    cout << "Suma total = " << suma << "\n";

    // Dejar cin listo para otras lecturas (si vuelves al menu)
    cin.clear();
}

// 8) Demostracion de peek/get/put/ignore/ws
void demoPeekGetPutIgnore() {
    cout << "[Demo] Escribe algo. Se mostrara el primer caracter con peek sin consumirlo:\n";
    cin >> ws; // quita espacios iniciales
    int ch = cin.peek();
    if (ch == EOF) { cout << "(EOF)\n"; return; }
    cout << "peek() ve: '" << static_cast<char>(ch) << "'\n";

    cout << "Ahora get() consumira ese caracter y lo reimprimiremos con put(): ";
    ch = cin.get();
    cout.put(ch);
    cout << "\n";

    cout << "Ignoraremos el resto de la linea con ignore(...,'\\n').\n";
    cin.ignore(100, '\n');
    cout << "Listo. (Linea descartada)\n";
}

// Utilitario: limpia resto de la linea (hasta '\n')
void limpiarLinea() {
    cin.ignore(100, '\n');
}
