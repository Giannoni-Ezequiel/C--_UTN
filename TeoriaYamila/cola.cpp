#include<iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

void agregar(Nodo *&colafte, Nodo *&colafin,int valor);
int suprimir(Nodo *&colafte, Nodo *&colafin);

int main(){
    Nodo* colafte=NULL;
    Nodo* colafin=NULL;
    int carga;
    cout<<"Ingrese un valor o termine con 0."<<endl;
    cin>>carga;
    while(carga!=0){
        agregar(colafte,colafin,carga);
        cout<<"Ingrese un valor o termine con 0."<<endl;
        cin>>carga;
    }

    int rdo;
    while(colafte!=NULL){
        rdo=suprimir(colafte,colafin);
        cout<<rdo<<endl;
    }
    return 0;
}

void agregar(Nodo *&colafte, Nodo *&colafin,int valor){
    //Crear nodo
    Nodo *nuevo = new Nodo();
    //Cargo el nodo
    nuevo -> info = valor;
    nuevo -> sgte = NULL;
    //Encolarlo
    if(colafte==NULL){
        colafte=nuevo;
    } else {
        colafin->sgte=nuevo;
    }
    colafin = nuevo;
};
int suprimir(Nodo *&colafte, Nodo *&colafin){
    int ret;
    Nodo *aux=colafte;
    ret=aux->info;
    colafte=aux->sgte;
    if(colafte==NULL){
        colafin=NULL;
    }
    delete(aux);
    return ret;
};
