#include<iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
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
int eliminarPrimero(Nodo*&Lista){
    int ret;
    ret = Lista->info;
    Nodo*aux=Lista;
    Lista = aux->sgte; //Lista = Lista->sgte
    delete (aux);
    return ret; 
}
void UnionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC){
    int valor;

    while(listaA!=NULL){
        valor = eliminarPrimero(listaA);
        agregarPrimero(listaC,valor);
    }
    while(listaB!=NULL){
        valor=eliminarPrimero(listaB);
        agregarPrimero(listaC,valor);
    }
}