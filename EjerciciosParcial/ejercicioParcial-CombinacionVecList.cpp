/*
Dado un vector de registros de 20 posiciones que contiene:
- id_prod, unidades en stock.
Ademas se cuenta con una lista de los nuevos pedidos que ingresaron 
(id_prod y unidades que entraton).
Se pide actualizar el vector con los nuevos ingresos. 
*/
//Estrategia:
//Recorrer la lista e ir a buscar los productos al vector y actualizar el campo de unidades.
#include<iostream>
using namespace std;

struct tInfo{
    int id_prod;
    int stock;
};
struct Nodo{
    tInfo info;
    Nodo *sgte;
};

int buscar(tInfo vec[], int len, int valor);
void liberar(Nodo *&lista);

int main(){
    tInfo vec[20];
    int len;

    Nodo *lista;
    //para recorrer lista un aux
    Nodo *aux;
    int pos;
    while(aux!=NULL){
        pos=buscar(vec,len,aux->info.id_prod);
        if(pos > -1){
            vec[pos].stock = vec[pos].stock+aux->info.stock;
        } else {
            cout<<"No se encontro el producto."<<endl;
        }

    }
    liberar(lista);
}

void liberar(Nodo *&lista){
    Nodo * aux;
    while(lista!=NULL){
        aux=lista;
        lista = lista->sgte;
        delete(aux);
    }

};

int buscar(tInfo vec[], int len, int valor){
    int i=0;
    while(i<len && vec[i].id_prod!=valor){
        i++;
    }
    if(i==len){
        return -1;
    } else {
        return i;
    }
}