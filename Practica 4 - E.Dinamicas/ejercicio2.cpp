/*
Dada una pila y un valor I, desarrollar un procedimiento que inserte I como tercer valor de
la pila. (Definir parámetros y codificar).
*/

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void push(Nodo*& pila, int valor);
int pop(Nodo*& pila);
void insertarTercero(Nodo*& pila, int valorI);
void mostrarPila(Nodo* pila);

int main() {
    Nodo* miPila = NULL;

    // Llenamos la pila con algunos valores para probar
    push(miPila, 50); // 5to
    push(miPila, 40); // 4to
    push(miPila, 30); // 3ro
    push(miPila, 20); // 2do
    push(miPila, 10); // 1ro (tope)

    cout << "Pila original:" << endl;
    mostrarPila(miPila);

    int valorAInsertar = 99;
    cout << "\nInsertando el valor " << valorAInsertar << " en la tercera posicion." << endl;
    insertarTercero(miPila, valorAInsertar);

    cout << "\nPila modificada:" << endl;
    mostrarPila(miPila);

    // Prueba con una pila con menos de 2 elementos
    Nodo* pilaCorta = NULL;
    push(pilaCorta, 100);
    cout << "\n--- Probando con una pila de 1 elemento ---" << endl;
    cout << "Pila corta original:" << endl;
    mostrarPila(pilaCorta);
    insertarTercero(pilaCorta, 200);
    cout << "\nPila corta despues de intentar insertar:" << endl;
    mostrarPila(pilaCorta);

    // Liberar memoria para evitar memory leaks
    while (miPila != NULL) {
        pop(miPila);
    }
    while (pilaCorta != NULL) {
        pop(pilaCorta);
    }

    return 0;
}

void push(Nodo*& pila, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte = pila;
    pila = nuevo;
}

int pop(Nodo*& pila) {
    // Precondición: la pila no debe estar vacía
    int ret = pila->info;
    Nodo* aux = pila;
    pila = aux->sgte;
    delete aux;
    return ret;
}

/*
Procedimiento para insertar un valor como tercer elemento de la pila.
Parámetros:
- pila: La pila a modificar (pasada por referencia).
- valorI: El valor entero a insertar.
Precondición: La pila debe tener al menos 2 elementos para que la inserción ocurra.
Si tiene menos, la pila no se modifica.
*/
void insertarTercero(Nodo*& pila, int valorI) {
    Nodo* pilaAux = NULL;

    if (pila != NULL && pila->sgte != NULL) {
        push(pilaAux, pop(pila));
        push(pilaAux, pop(pila));
        push(pila, valorI);
        push(pila, pop(pilaAux));
        push(pila, pop(pilaAux));
    }
}

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