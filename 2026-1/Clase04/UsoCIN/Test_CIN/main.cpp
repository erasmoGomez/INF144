#include "src/AuxiliaryFunctions.hpp"

int main() {

    while (true) {
        cout << "\n===== MENU DE PRUEBAS CIN =====\n";
        cout << "1) Leer 3 enteros (cin >> a >> b >> c)\n";
        cout << "2) Leer int, double, char (mezcla de tipos)\n";
        cout << "3) Leer FECHA (dd/mm/aaaa)\n";
        cout << "4) Leer HORA (HH:MM[:SS])\n";
        cout << "5) Eco de TOKEN en MAYUS sin almacenar (hasta espacio/newline)\n";
        cout << "6) Eco de LINEA en MAYUS sin almacenar (hasta newline)\n";
        cout << "7) Sumar enteros hasta tope (patron correcto)\n";
        cout << "8) Demostracion peek/get/put/ignore/ws\n";
        cout << "0) Salir\n";
        cout << "Opcion: ";

        int op;
        if (!(cin >> op)) {
            cout << "Entrada no valida. Saliendo.\n";
            break;
        }

        if (op == 0) break;

        switch (op) {
            case 1:
                leerTresEnteros();
                break;
            case 2:
                leerEnteroDoubleChar();
                break;
            case 3: {
                cout << "Ingresa fecha (dd/mm/aaaa): ";
                int d, m, a;
                if (leerFecha(d, m, a)) {
                    cout << "Fecha leida: "
                         << setw(2) << setfill('0') << d << '/'
                         << setw(2) << setfill('0') << m << '/'
                         << setw(4) << setfill('0') << a << setfill(' ')
                         << "\n";
                } else {
                    cout << "Formato de fecha invalido.\n";
                }
                break;
            }
            case 4: {
                cout << "Ingresa hora (HH:MM o HH:MM:SS): ";
                int hh, mm, ss;
                if (leerHora(hh, mm, ss)) {
                    cout << "Hora leida: "
                         << setw(2) << setfill('0') << hh << ':'
                         << setw(2) << setfill('0') << mm << ':'
                         << setw(2) << setfill('0') << ss << setfill(' ')
                         << "\n";
                } else {
                    cout << "Formato de hora invalido.\n";
                }
                break;
            }
            case 5:
                cout << "Escribe un token (se corta en espacio o newline): ";
                ecoTokenMayusSinAlmacenar();
                cout << "\n";
                break;
            case 6:
                cout << "Escribe una linea y se imprimira en MAYUS: ";
                ecoLineaMayusSinAlmacenar();
                cout << "\n";
                break;
            case 7:
                cout << "Escribe enteros, al final un 0 como tope:\n";
                sumarEnterosHastaTope();
                break;
            case 8:
                demoPeekGetPutIgnore();
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    }

    cout << "Fin de pruebas.\n";
    return 0;
}
