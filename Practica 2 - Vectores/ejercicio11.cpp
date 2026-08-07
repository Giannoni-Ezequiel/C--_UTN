/*
Dado un valor N (<50), y una matriz MAT[NxN] que contiene valores enteros.
Se pide:
a) Leerla por fila
b) Informarla por columna
c) Informar la sumatoria de sus elementos y el valor promedio
d) Informar el máximo elemento y su ubicación (fila y columna)
e) Informar el mínimo de cada fila y el máximo de cada columna
f) Informar cuantos elementos positivos hay en la diagonal principal y cuantos
negativos en la diagonal secundaria

*/


#include <iostream>
using namespace std;
int main() {
    const int MAX_SIZE = 50;
    int MAT[MAX_SIZE][MAX_SIZE];
    int N;

    // Pedir N al usuario, asegurando que esté en el rango válido
    do {
        cout << "Ingrese el tamano de la matriz (N < 50): ";
        cin >> N;
        if (N <= 0 || N >= MAX_SIZE) {
            cout << "Numero invalido. Por favor, ingrese un numero entre 1 y 49." << endl;
        }
    } while (N <= 0 || N >= MAX_SIZE);

    // --- a) Leer la matriz por fila ---
    cout << "\n--- a) Ingrese los elementos de la matriz ---" << endl;
    long long sumatoria = 0; // Usamos long long para evitar desbordes con sumas grandes
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "Ingrese el valor para MAT[" << i << "][" << j << "]: ";
            cin >> MAT[i][j];
            sumatoria += MAT[i][j]; // Aprovechamos para calcular la sumatoria
        }
    }

    // --- b) Informar la matriz por columna ---
    cout << "\n--- b) Matriz informada por columna ---" << endl;
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            cout << MAT[i][j] << "\t";
        }
        cout << endl;
    }

    // --- c) Informar la sumatoria y el promedio ---
    cout << "\n--- c) Sumatoria y promedio ---" << endl;
    double promedio = static_cast<double>(sumatoria) / (N * N);
    cout << "La sumatoria de todos los elementos es: " << sumatoria << endl;
    cout << "El valor promedio es: " << promedio << endl;

    // --- d) Informar el máximo elemento y su ubicación ---
    cout << "\n--- d) Maximo elemento y su ubicacion ---" << endl;
    int maxElemento = MAT[0][0];
    int maxFila = 0;
    int maxColumna = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (MAT[i][j] > maxElemento) {
                maxElemento = MAT[i][j];
                maxFila = i;
                maxColumna = j;
            }
        }
    }
    cout << "El maximo elemento es " << maxElemento << " y se encuentra en la posicion [" << maxFila << "][" << maxColumna << "]." << endl;

    // --- e) Informar el mínimo de cada fila y el máximo de cada columna ---
    cout << "\n--- e) Minimo por fila y maximo por columna ---" << endl;
    // Mínimo de cada fila
    for (int i = 0; i < N; ++i) {
        int minFila = MAT[i][0];
        for (int j = 1; j < N; ++j) {
            if (MAT[i][j] < minFila) {
                minFila = MAT[i][j];
            }
        }
        cout << "El minimo de la fila " << i << " es: " << minFila << endl;
    }
    cout << endl; // Separador
    // Máximo de cada columna
    for (int j = 0; j < N; ++j) {
        int maxCol = MAT[0][j];
        for (int i = 1; i < N; ++i) {
            if (MAT[i][j] > maxCol) {
                maxCol = MAT[i][j];
            }
        }
        cout << "El maximo de la columna " << j << " es: " << maxCol << endl;
    }

    // --- f) Informar positivos en diagonal principal y negativos en secundaria ---
    cout << "\n--- f) Elementos en las diagonales ---" << endl;
    int positivosPrincipal = 0;
    int negativosSecundaria = 0;
    for (int i = 0; i < N; ++i) {
        // Diagonal principal: MAT[i][i]
        if (MAT[i][i] > 0) {
            positivosPrincipal++;
        }
        // Diagonal secundaria: MAT[i][N - 1 - i]
        if (MAT[i][N - 1 - i] < 0) {
            negativosSecundaria++;
        }
    }
    cout << "Cantidad de elementos positivos en la diagonal principal: " << positivosPrincipal << endl;
    cout << "Cantidad de elementos negativos en la diagonal secundaria: " << negativosSecundaria << endl;

    return 0;
}