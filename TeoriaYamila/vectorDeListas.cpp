// Dado un vector de listas Mostrar la cantidad total de unidades por id de producto

#include<iostream>
using namespace std;

struct Tinfo{
    int a;
    int b;
};

struct Nodo{
    Tinfo info;
    Nodo* sgte;
};

void liberar(Nodo *&lista);

int main(){
    Nodo*vec[10];
    int len;
    int sum;
    Nodo*aux; // para recorrer la lista
    for(int i=0;i<len;i++){
        sum=0;
        aux=vec[i]; // el puntero apunta a la posicion i
        while(aux!=NULL){
            sum=sum+aux->info.a;
            aux=aux->sgte;  //recorro listas 
        }
        cout<<"El producto: "<<i<<" el stock es: "<<sum;
        liberar(vec[i]);
    }
    return 0;
}

void liberar(Nodo *&lista){
    Nodo * aux;
    while(lista!=NULL){
        aux=lista;
        lista = lista->sgte;
        delete(aux);
    }

};