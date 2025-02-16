#include<iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

int pop(Nodo *&pila){
    int ret;
    ret=pila->info;
    Nodo *aux=pila;
    pila=aux->sgte;

    delete(aux);
    return ret;
}
int suprimir(Nodo *&colafte, Nodo *&colafin);
void agregarPrimero(Nodo*&Lista, int valor){
    //Crear Nodo
    Nodo* nuevo = new Nodo();
    //Cargar el Nodo
    nuevo -> info = valor;
    nuevo -> sgte = Lista;
    //Enlazar
    Lista = nuevo;
}
void unirPilaColaEnLista(Nodo *pila, Nodo *cfte, Nodo *cfin, Nodo *&lista){
    int valor;

    while(pila!=NULL){
        valor=pop(pila);
        agregarPrimero(lista,valor);

    }
    while(cfte!=NULL){
        valor=suprimir(cfte,cfin);
        agregarPrimero(lista,valor);
    }
}