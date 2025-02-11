#include<iostream>
using namespace std;

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