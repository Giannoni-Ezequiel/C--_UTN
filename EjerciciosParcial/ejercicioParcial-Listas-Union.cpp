#include<iostream>
using namespace std;
struct Nodo{
    int info;
    Nodo *sgte;
};

void agregarPrimero(Nodo*&Lista, int valor){
    //Crear Nodo
    Nodo* nuevo = new Nodo();
    //Cargar el Nodo
    nuevo -> info = valor;
    nuevo -> sgte = Lista;
    //Enlazar
    Lista = nuevo;
}

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
        aux = auxListaB->info;
        agregarPrimero(ListaC,aux);
        auxListaB=auxListaB->sgte;
    }


    
}

int eliminarPrimero(Nodo*&Lista){
    int ret;
    ret = Lista->info;
    Nodo*aux=Lista;
    Lista = aux->sgte; //Lista = Lista->sgte
    delete (aux);
    return ret; 
}

void unionListas2(Nodo *listaA, Nodo *listaB, Nodo *&ListaC){
    int valor;
    while(listaA!=NULL){
        valor=eliminarPrimero(listaA);
        agregarPrimero(ListaC,valor);

    }
    while(listaB!=NULL){
        valor=eliminarPrimero(listaB);
        agregarPrimero(ListaC,valor);
    }
}
