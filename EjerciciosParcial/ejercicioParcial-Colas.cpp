//Dadas 2 colas, generar una nueva con la union de ambas
#include<iostream>
#include<stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void agregar(Nodo *&colafte, Nodo *&colafin,int valor);
int suprimir(Nodo *&colafte, Nodo *&colafin);
void unionColas(Nodo *cfteA,Nodo *cfinA,Nodo *cfteB,Nodo *cfinB,Nodo *&cfteC,Nodo *&cfinC);
void unionColasEnPila(Nodo *cfteA,Nodo *cfinA,Nodo *cfteB,Nodo *cfinB,Nodo *&pila);
void push(Nodo *&pila,int valor);
int pop(Nodo *&pila);

int main(){

}

void unionColas(Nodo *cfteA,Nodo *cfinA,Nodo *cfteB,Nodo *cfinB,Nodo *&cfteC,Nodo *&cfinC){
    int valor;
    while(cfteA!=NULL){
        valor=suprimir(cfteA,cfinA);
        agregar(cfteC,cfinC,valor);
    }
    while(cfteB!=NULL){
        valor=suprimir(cfteB,cfinB);
        agregar(cfteC,cfinC,valor);
    }
}

void push(Nodo *&pila,int valor){
    //Crear el nodo, pedir memoria
    Nodo* nuevo=new Nodo();
    //Cargar el nodo
    nuevo -> info = valor;
    nuevo -> sgte = pila;
    //Conectarlo con el resto de los nodos
    pila = nuevo;
};
int pop(Nodo *&pila){
    int ret;
    ret=pila->info;
    //para no perder la referencia...
    Nodo *aux=pila;
    pila=aux->sgte; // o pila->sgte
    //liberar memoria del nodo que devolvi
    delete(aux);
    return ret;
};

void unionColasEnPila(Nodo *cfteA,Nodo *cfinA,Nodo *cfteB,Nodo *cfinB,Nodo *&pila){
    int valor;
    while(cfteA!=NULL){
        valor=suprimir(cfteA,cfinA);
        push(pila,valor);
    }
    while(cfteB!=NULL){
        valor=suprimir(cfteB,cfinB);
        push(pila,valor);
    }
}
