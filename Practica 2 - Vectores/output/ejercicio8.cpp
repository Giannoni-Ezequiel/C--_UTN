/*
    Dado un numero N (<50), y un vector VEC de N valores enteros positivos ordene el
    contenido del vector y lo informe, aplicando el procedimiento Burbujeo:

    • en orden ascendente
    • en orden descendente
*/

#include <iostream>
using namespace std;

/**
 * @brief Imprime los elementos de un vector en una sola línea.
 * @param vec El vector a imprimir.
 * @param n La cantidad de elementos en el vector.
 */
void imprimirVector(int vec[], int n) {
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/**
 * @brief Intercambia los valores de dos variables enteras.
 * @param a Referencia a la primera variable.
 * @param b Referencia a la segunda variable.
 */
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Ordena un vector en orden ascendente usando el método de burbuja.
 * @param vec El vector a ordenar.
 * @param lenVec La cantidad de elementos en el vector.
 */
void burbujeoAscendente(int vec[], int lenVec) {
    for (int i = 0; i < lenVec - 1; i++) {
        // En cada pasada, el elemento más grande "burbujea" hasta su posición final.
        // Por eso, el bucle interno puede ser más corto en cada iteración (n - i - 1).
        for (int j = 0; j < lenVec - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

/**
 * @brief Ordena un vector en orden descendente usando el método de burbuja.
 * @param vec El vector a ordenar.
 * @param lenVec La cantidad de elementos en el vector.
 */
void burbujeoDescendente(int vec[], int lenVec) {
    for (int i = 0; i < lenVec - 1; i++) {
        for (int j = 0; j < lenVec - i - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main(){
    const int MAX_SIZE = 50;
    int VEC[MAX_SIZE];
    int N;

    // Pedir N al usuario, asegurando que esté en el rango válido
    do {
        cout << "Ingrese la cantidad de elementos (un numero menor a 50): ";
        cin >> N;
        if (N <= 0 || N >= MAX_SIZE) {
            cout << "Numero invalido. Por favor, ingrese un numero entre 1 y 49." << endl;
        }
    } while (N <= 0 || N >= MAX_SIZE);

    // Pedir los elementos del vector al usuario
    cout << "Ingrese " << N << " valores enteros positivos:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Valor " << i + 1 << ": ";
        cin >> VEC[i];
        // Validar que el valor ingresado sea positivo
        if (VEC[i] <= 0) {
            cout << "El valor debe ser positivo. Intentelo de nuevo." << endl;
            i--; // Decrementar i para reingresar el valor en la misma posición
        }
    }

    // --- Ordenamiento Ascendente ---
    burbujeoAscendente(VEC, N);
    cout << "\nVector ordenado en forma ascendente:" << endl;
    imprimirVector(VEC, N);

    // --- Ordenamiento Descendente ---
    burbujeoDescendente(VEC, N);
    cout << "\nVector ordenado en forma descendente:" << endl;
    imprimirVector(VEC, N);

    return 0;
}