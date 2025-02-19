/*
    Desarrolle una función que retorne una lista ordenada a partir de la Intersección de 1 pila y 1 lista.
Defina usted las precondiciones y estructuras de los nodos de la manera que considere más conveniente y detallar. 

*/

#include<iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

void insertarOrdenado(Nodo *&lista, int valor){
    // crear el nodo
    Nodo *nuevo= new Nodo();
    // cargar el nodo
    nuevo -> info = valor;
    nuevo -> sgte = NULL; //xqe no se todavia donde va a ir
    // enlazarlo, en donde?
    Nodo *aux = lista; //poder recorrer sin modificar la lista
    Nodo *ant = NULL; //el q me va a permitir hacer la conexion
    // buscar
    while(aux!=NULL&&aux->info<valor){
        ant=aux;
        aux=aux->sgte;
    }
    if(ant==NULL){ //1)lista vacia o 2)debo insertar al principio
        lista = nuevo;
    }else{ //pude haber salido porque estoy en alguna parte de la lista, o llegamos al final
        ant->sgte=nuevo;
    }
    nuevo->sgte=aux; //se repite en if y else 
};
Nodo* pop(Nodo *&pila){
    int ret;
    ret=pila->info;
    //para no perder la referencia...
    Nodo *aux=pila;
    pila=aux->sgte; // o pila->sgte
    //liberar memoria del nodo que devolvi
    delete(aux);
    return ret;
};
Nodo* funcionP (Nodo*&Lista, Nodo*&Pila){
    Nodo* ListaNueva=NULL;
    Nodo* auxPila;
    Nodo* auxLista;
    while(Pila!=NULL){
        auxPila = pop(Lista);
        insertarOrdenado(ListaNueva,auxPila);
        auxPila = auxPila->sgte;
    }
    while(Lista!=NULL){
        auxPila = pop(Pila);
        insertarOrdenado(ListaNueva,auxPila);
        auxPila = auxPila->sgte;
    }
    return ListaNueva;
}

/*
    Se tiene un vector de Saldos de las cuentas bancarias de una empresa, que contiene los siguientes campos: - Número de cuenta – Cantidad de transacciones – Saldo.
Además, se cuenta con una lista que contiene las últimas transacciones (1 nodo 1 transacción), cada nodo de la lista contiene: - Número de Cuenta - Monto
Se pide, actualizar el vector Saldos con la información que hay en la lista, considerando que debe actualizar el saldo y actualizar la cantidad de transacciones por cuenta. Máximo hay 150 cuentas.

*/

struct Saldos{
    int numeroDeCuenta;
    int cantTransacc;
    float saldo;
};

struct Tinfo{
    int numeroDeCuenta;
    float monto;
};

struct nodo{
    Tinfo info;
    Nodo* sgte;
};

Saldos vec[150];

Saldos ActualizarCuenta(Saldos vec[], nodo* Lista);

/*


*/

void proc (int v[], int len){
    *v=10;
 }
 