/*
Dada una pila y un valor X, desarrollar un procedimiento que inserte el valor X en la última
posición de la pila y la retorne. (Definir parámetros y codificar).

*/


#include <iostream>
using namespace std;

// Definición de la estructura del nodo para la pila
struct Nodo {
    int info;
    Nodo* sgte;
};

// Prototipos de funciones
void push(Nodo*& pila, int valor);
int pop(Nodo*& pila);
void insertarUltimo(Nodo*& pila, int valorX);
void mostrarPila(Nodo* pila); // Función auxiliar para visualizar la pila

int main(){
    Nodo* miPila = NULL;

    // Llenamos la pila con algunos valores para probar
    push(miPila, 50);
    push(miPila, 40);
    push(miPila, 30);
    push(miPila, 20);
    push(miPila, 10); // Este es el tope de la pila

    cout << "Pila original:" << endl;
    mostrarPila(miPila);

    int valorAInsertar = 99;
    cout << "\nInsertando el valor " << valorAInsertar << " en la ultima posicion." << endl;
    insertarUltimo(miPila, valorAInsertar);

    cout << "\nPila modificada:" << endl;
    mostrarPila(miPila);

    // Prueba con una pila vacía
    Nodo* pilaVacia = NULL;
    cout << "\n--- Probando con una pila vacia ---" << endl;
    cout << "Pila vacia original:" << endl;
    mostrarPila(pilaVacia);
    insertarUltimo(pilaVacia, 100);
    cout << "\nPila vacia despues de insertar 100:" << endl;
    mostrarPila(pilaVacia);

    // Liberar memoria para evitar memory leaks
    while (miPila != NULL) {
        pop(miPila);
    }
    while (pilaVacia != NULL) {
        pop(pilaVacia);
    }

    return 0;
}

// Implementación de la función push (apilar)
void push(Nodo*& pila, int valor) {
    Nodo* nuevo = new Nodo(); // Crear un nuevo nodo
    nuevo->info = valor;      // Asignar el valor al nodo
    nuevo->sgte = pila;       // El nuevo nodo apunta al actual tope de la pila
    pila = nuevo;             // El nuevo nodo se convierte en el tope de la pila
}

// Implementación de la función pop (desapilar)
// Precondición: la pila no debe estar vacía al llamar a pop
int pop(Nodo*& pila) {
    if (pila == NULL) {
        // Manejo de error: intentar desapilar de una pila vacía
        // En un caso real, podrías lanzar una excepción o retornar un valor especial
        cerr << "Error: Intentando hacer pop en una pila vacia." << endl;
        return -1; // Valor de error
    }
    int ret = pila->info; // Guardar el valor del tope
    Nodo* aux = pila;     // Guardar la referencia al nodo a eliminar
    pila = aux->sgte;     // El tope de la pila se mueve al siguiente nodo
    delete aux;           // Liberar la memoria del nodo desapilado
    return ret;           // Retornar el valor
}

/*
Procedimiento para insertar un valor en la última posición de la pila.
Parámetros:
- pila: La pila a modificar (pasada por referencia).
- valorX: El valor entero a insertar.
*/
void insertarUltimo(Nodo*& pila, int valorX) {
    Nodo* pilaAux = NULL; // Pila auxiliar para almacenar temporalmente los elementos

    // 1. Mover todos los elementos de la pila original a la pila auxiliar
    while (pila != NULL) {
        push(pilaAux, pop(pila));
    }

    // 2. Insertar el valor X en la pila original (que ahora está vacía)
    push(pila, valorX);

    // 3. Mover todos los elementos de la pila auxiliar de vuelta a la pila original
    while (pilaAux != NULL) {
        push(pila, pop(pilaAux));
    }
}

// Función para mostrar el contenido de la pila (útil para depuración)
void mostrarPila(Nodo* pila) {
    Nodo* temp = pila;
    if (temp == NULL) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Tope -> ";
    while (temp != NULL) {
        cout << temp->info << " -> ";
        temp = temp->sgte;
    }
    cout << "NULL" << endl;
}