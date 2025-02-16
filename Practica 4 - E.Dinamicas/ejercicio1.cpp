/*
    Dada una pila y un valor I, desarrollar un procedimiento que elimine los 2 primeros nodos 
    de la pila y deje el valor I como primero. (Definir parámetros y codificar). 
*/


#include <iostream>
#include <stdio.h>
using namespace std;

struct nodo{
    int info;
    nodo* sgte;
};
void push(nodo*&pila, int valorI);
void eliminar2(nodo*&pila2, nodo*&pila, int valorI);

int main(){
    
    return 0;
}



void push(nodo *&pila,int valor){
    //Crear el nodo, pedir memoria
    nodo* nuevo=new nodo();
    //Cargar el nodo
    nuevo -> info = valor;
    nuevo -> sgte = pila;
    //Conectarlo con el resto de los nodos
    pila = nuevo;
};
int pop(nodo *&pila){
    int ret;
    ret=pila->info;
    //para no perder la referencia...
    nodo *aux=pila;
    pila=aux->sgte; // o pila->sgte
    //liberar memoria del nodo que devolvi
    delete(aux);
    return ret;
};
void eliminar2(nodo*&pila2, nodo*&pila, int valorI){
    int i;
    for(i=0;i<2;i++){
        push(pila2,pop(pila));
    }
    if(i==2)
	{
		push(pila,valorI);
		}
}