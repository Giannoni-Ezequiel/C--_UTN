#include<iostream>
using namespace std;

struct Info{
    int cod;
};
struct Nodo{
    int info;
    Nodo* sgte;
};
void push(Nodo *&pila,int valor);
int pop(Nodo *&pila);
int main(){
    Nodo* pila=NULL;
    int carga;
    cout<<"Ingrese un valor o termine con 0."<<endl;
    cin>>carga;
    while(carga!=0){
        push(pila,carga);
        cout<<"Ingrese un valor o termine con 0."<<endl;
        cin>>carga;
    }

    int rdo;
    while(pila!=NULL){
        rdo=pop(pila);
        cout<<rdo<<endl;
    }

    return 0;
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