#include "src/FuncionesCadenas.hpp"

int main() {
    cout << "=========== DEMO CADENAS ===========\n\n";

    // ------------------------------------------------------------
    // BLOQUE 1: Lectura y modificación sencilla de un nombre
    // ------------------------------------------------------------
    {
        char nombre1[30];
        char nombre2[30];

        cout << "[Bloque 1] Ingrese un nombre (sin espacios, max 29 chars): ";
        cin >> nombre1;
        nombre1[0] = 'E';    // Fuerza la inicial a 'E' (ejemplo de acceso)
        cout << "Nombre modificado: " << nombre1 << "\n\n";
        cout << "[Bloque 1.1] Ingrese un nombre completo (sin espacios y/o separados por / y - max 29 chars): ";
        cin>>nombre2;
        modificar_cadena(nombre2);
        camelizar(nombre2);
        cout << "Nombre modificado: " << nombre2 << "\n\n";
    }

    // ------------------------------------------------------------
    // BLOQUE 2: Tamaño / Longitud (manual vs. libreria)
    // ------------------------------------------------------------
    {
        char nombre1[30] = "Erasmo";
        // Sin libreria (conteo manual)
        int n = longitud(nombre1);
        cout << "[Bloque 2] Longitud (manual) de \"" << nombre1 << "\": " << n << "\n";
        // Con la libreria: strlen
        cout << "[Bloque 2] Longitud (strlen) de \"" << nombre1 << "\": " << strlen(nombre1) << "\n\n";
    }

    // ------------------------------------------------------------
    // BLOQUE 3: Copiar cadenas (propia vs. libreria)
    // ------------------------------------------------------------
    {
        // Sin Libreria (usando tu función copiar)
        char nombre1[30];
        copiar(nombre1, "Erasmo Gomez");
        cout << "[Bloque 3] Copiar (propia): " << nombre1 << "\n";

        // Con Libreria: strcpy
        char nombre2[30];
        strcpy(nombre2, "Miguel Guanira");
        cout << "[Bloque 3] Copiar (strcpy) : Miguel Guanira: " << nombre2 << "\n\n";
    }

    // ------------------------------------------------------------
    // BLOQUE 4: Comparar cadenas (propia vs. libreria)
    // ------------------------------------------------------------
    {
        char nombre[30];
        char nombre2[30];
        strcpy(nombre, "Rony Cueva");
        strcpy(nombre2, "Rony Cueba");

        // Sin Libreria (usando tu función comparar)
        int cmp = comparar(nombre, nombre2);
        cout << "[Bloque 4] Comparar (propia) Nombre1: Rony Cueva, Nombre2: Rony Cueba: resultado = " << cmp << "\n";

        // Con libreria : strcmp
        int comp = strcmp(nombre, nombre2);
        cout << "[Bloque 4] Comparar (strcmp): ";
        if (comp == 0) cout << "Son Iguales\n\n";
        else if (comp < 0) cout << "Nombre1 es menor que Nombre2\n\n";
        else cout << "Nombre1 es mayor que Nombre2\n\n";
    }

    // ------------------------------------------------------------
    // BLOQUE 5: Concatenar cadenas (propia vs. libreria)
    // ------------------------------------------------------------
    {
        // Sin Libreria (usando tu función concatenar)
        char palabra[30];
        strcpy(palabra, "Hola");
        concatenar(palabra, " Mundo");
        cout << "[Bloque 5] Concatenar (propia): " << palabra << "\n";

        // Con la libreria : strcat
        char cadena_inicial[60];
        strcpy(cadena_inicial, "Los alumnos de TP");
        strcat(cadena_inicial, " van a jalar el lab");
        strcat(cadena_inicial, " de chill");
        cout << "[Bloque 5] Concatenar (strcat): " << cadena_inicial << "\n\n";
    }

    cout << "============= FIN DEMO =============\n";
    return 0;
}
