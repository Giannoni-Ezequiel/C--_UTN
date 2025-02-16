#include<iostream>
using namespace std;

struct Tinfo2{
    int id;
    int nota;
};

struct Nodo2{ 
    Tinfo2 info;
    Nodo2* sgte; 
};

struct Tinfo{
    int a;
    Nodo2* notas;
};

struct Nodo{
    Tinfo info;
    Nodo* sgte;
};

int main(){
    Nodo* Lista;
    Nodo* aux=Lista;
    int sum;
    int cant;
    Nodo2* aux2;
    while(aux!=NULL){
        sum=0;
        cant=0;
        aux2 = aux->info.notas;
        while(aux2!=NULL){
            cant++; 
            sum=sum+aux2->info.nota;
            aux2=aux2->sgte;
        }
        cout<<"El legajo: "<< aux->info.a << " el promedio es: "<< sum/cant<<endl;
        aux=aux->sgte;
    }

}