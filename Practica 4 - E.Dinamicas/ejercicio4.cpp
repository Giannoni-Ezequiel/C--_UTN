/*

*/
#include <iostream>
using namespace std;
struct Nodo{
    int info;
    Nodo* sgte;
};
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
void insertarEnPosicion(Nodo *&pila, int X, int I){
    Nodo* aux = NULL;
    int cantidad = 0;
    int int2;
    while(pila!=NULL && cantidad != (I-1)){
        int2 = pop(pila);
        push(aux,int2);
        cantidad++;
    }
    if(cantidad==(I-1)){
        push(pila,X);
    }
    while(aux!=NULL){
        int2=pop(aux);
        push(pila,int2);
    }
}
int main(){
   

    return 0;
}