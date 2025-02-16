/*
    Dada una lista (nodo = registro + puntero), desarrollar y codificar una funcion que devuelva 
    la cantidad de nodos que tiene. 
*/


#include <iostream>
#include <stdio.h>
using namespace std;


struct nodo{
    int info;
    nodo* sgte;
};

int contarNodos(nodo *lista);

int main(){
  
    return 0;
}

int contarNodos(nodo *lista){
    nodo* q = NULL;
    int contador=0;
    if(lista == NULL){
        return contador;
    } else {
        nodo* q = lista;
        while(q->sgte != NULL){
            q = q->sgte;
            contador++;
        }
        return contador;
    }
}