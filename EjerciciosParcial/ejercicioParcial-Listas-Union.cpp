#include<iostream>
using namespace std;
struct Nodo{
    int info;
    Nodo *sgte;
};

void unionListas(Nodo *ListaA, Nodo *ListaB, Nodo *&ListaC){
    int aux;
    Nodo *auxListaA=ListaA;
    Nodo *auxListaB=ListaB;
    while(auxListaA!=NULL){
        aux = auxListaA->info;
        agregarPrimero(ListaC,aux);
        auxListaA=auxListaA->sgte;
    }
    while(auxListaB=NULL){
        aux = auxListaB>info;
        agregarPrimero(ListaC,aux);
        auxListaB=auxListaB->sgte;
    }


    
}

void unionListas2(Nodo *listaA, Nodo *listaB, Nodo *&ListaC){
    int valor;
    while(listaA!=NULL){
        valor=eliminarPrimero(listaA);
        agregarPrimero(listaC,valor);

    }
    while(listaB!=NULL){
        valor=eliminarPrimero(listaB);
        agregarPrimero(listaC,valor);
    }
}
