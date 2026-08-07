/*
 Genere e informe una matriz MUL[10x10] con las tablas de multiplicar.
*/


#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;
    int MUL[SIZE][SIZE];

    // 1. Generar la matriz con las tablas de multiplicar
    // El primer bucle recorre las filas (primer factor de la multiplicación)
    for (int i = 0; i < SIZE; ++i) {
        // El segundo bucle recorre las columnas (segundo factor)
        for (int j = 0; j < SIZE; ++j) {
            // Los índices van de 0 a 9, pero las tablas son del 1 al 10.
            // Por eso, multiplicamos (i+1) por (j+1).
            MUL[i][j] = (i + 1) * (j + 1);
        }
    }

    // 2. Informar (imprimir) la matriz
    cout << "Matriz con las tablas de multiplicar del 1 al 10:" << endl;
    cout << "-------------------------------------------------" << endl;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // Usamos un tabulador '\t' para separar los numeros.
            // La alineacion puede no ser perfecta, pero no requiere librerias adicionales.
            cout << MUL[i][j] << "\t";
        }
        cout << endl; // Salto de línea al final de cada fila
    }

    return 0;
}