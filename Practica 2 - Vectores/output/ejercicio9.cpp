/*
Dado un numero N (<=50) y un conjunto de Nombres y Fechas de nacimientos
(AAAAMMDD),
informar el conjunto:
• ordenado por nombre
• ordenado por fecha y nombre
• ordenado por nombre y fecha
NOTA: Modifique y utilice el procedimiento Burbujeo
*/

#include <iostream>
#include <string>

using namespace std;

// Estructura para almacenar los datos de una persona
struct Persona {
    string nombre;
    int fecha; // Formato AAAAMMDD
};

/**
 * @brief Imprime los datos de un vector de Personas.
 * @param vec El vector de Personas.
 * @param n La cantidad de elementos.
 */
void imprimirPersonas(Persona vec[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  Nombre: " << vec[i].nombre << ", Fecha: " << vec[i].fecha << endl;
    }
    cout << "----------------------------------------" << endl;
}

/**
 * @brief Intercambia dos estructuras Persona.
 * @param a Referencia a la primera Persona.
 * @param b Referencia a la segunda Persona.
 */
void swapPersonas(Persona &a, Persona &b) {
    Persona temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Ordena un vector de Personas por nombre en orden ascendente.
 * @param vec El vector a ordenar.
 * @param n La cantidad de elementos.
 */
void ordenarPorNombre(Persona vec[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j].nombre > vec[j + 1].nombre) {
                swapPersonas(vec[j], vec[j + 1]);
            }
        }
    }
}

/**
 * @brief Ordena un vector de Personas por fecha y luego por nombre.
 * @param vec El vector a ordenar.
 * @param n La cantidad de elementos.
 */
void ordenarPorFechaYNombre(Persona vec[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Criterio primario: fecha. Criterio secundario: nombre.
            if (vec[j].fecha > vec[j + 1].fecha ||
               (vec[j].fecha == vec[j + 1].fecha && vec[j].nombre > vec[j + 1].nombre)) {
                swapPersonas(vec[j], vec[j + 1]);
            }
        }
    }
}

/**
 * @brief Ordena un vector de Personas por nombre y luego por fecha.
 * @param vec El vector a ordenar.
 * @param n La cantidad de elementos.
 */
void ordenarPorNombreYFecha(Persona vec[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Criterio primario: nombre. Criterio secundario: fecha.
            if (vec[j].nombre > vec[j + 1].nombre ||
               (vec[j].nombre == vec[j + 1].nombre && vec[j].fecha > vec[j + 1].fecha)) {
                swapPersonas(vec[j], vec[j + 1]);
            }
        }
    }
}


int main(){
    const int MAX_SIZE = 50;
    Persona personas[MAX_SIZE];
    int N;

    // Pedir N al usuario, asegurando que esté en el rango válido
    do {
        cout << "Ingrese la cantidad de personas (un numero menor a 50): ";
        cin >> N;
        if (N <= 0 || N >= MAX_SIZE) {
            cout << "Numero invalido. Por favor, ingrese un numero entre 1 y 49." << endl;
        }
    } while (N <= 0 || N >= MAX_SIZE);

    // Pedir los datos de cada persona
    cout << "Ingrese los datos de " << N << " personas:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Persona " << i + 1 << " - Nombre: ";
        cin >> personas[i].nombre;
        cout << "Persona " << i + 1 << " - Fecha de nacimiento (AAAAMMDD): ";
        cin >> personas[i].fecha;
    }

    // --- Ordenado por nombre ---
    ordenarPorNombre(personas, N);
    cout << "\nConjunto ordenado por nombre:" << endl;
    imprimirPersonas(personas, N);

    // --- Ordenado por fecha y nombre ---
    ordenarPorFechaYNombre(personas, N);
    cout << "Conjunto ordenado por fecha y nombre:" << endl;
    imprimirPersonas(personas, N);

    // --- Ordenado por nombre y fecha ---
    ordenarPorNombreYFecha(personas, N);
    cout << "Conjunto ordenado por nombre y fecha:" << endl;
    imprimirPersonas(personas, N);

    return 0;
}