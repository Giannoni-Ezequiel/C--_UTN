//Dadas 2 pilas de enteros, genere la union de ambas en pila C
#include<iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void push(Nodo *&pila, int valor);
int pop(Nodo *&pila);
void unirPilas(Nodo *&pilaA, Nodo *&pilaB, Nodo *&pilaC);

int main(){
    return 0;
}

void push(Nodo *&pila, int valor){
    Nodo *nuevo=new Nodo();
    nuevo ->info=valor;
    nuevo->sgte=pila;
    pila=nuevo;
}


int pop(Nodo *&pila){
    int ret;
    ret=pila->info;
    Nodo *aux=pila;
    pila=aux->sgte;

    delete(aux);
    return ret;
}

void unirPilas(Nodo *&pilaA, Nodo *&pilaB, Nodo *&pilaC){
    int auxA;
    while(pilaA!=NULL){
        auxA=pop(pilaA);
        push(pilaC,auxA);
    }
    int auxB;
    while(pilaB!=NULL){
        auxB=pop(pilaB);
        push(pilaC,auxB);
    }
}