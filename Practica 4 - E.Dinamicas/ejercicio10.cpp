/*
    Dada una cola (nodo = registro + puntero), desarrollar y codificar un procedimiento que 
    elimine 2 nodos de la misma (indicar con un parámetro 'S'/'N' si ello fue, o no posible) 
*/


#include <iostream>
using namespace std;

struct nodo{
    int info;
    nodo* sgte;
};

void unqueue2(nodo*&fte, nodo*&fin){
    nodo* p = fte;
    fte = p->sgte;
    if(fte==NULL){
        fin == NULL;
        cout<<"N"<<endl;
    } else {cout<<"S"<<endl;};
    delete p;
    unqueue2(fte,fin);
}

int main(){
    return 0;
}