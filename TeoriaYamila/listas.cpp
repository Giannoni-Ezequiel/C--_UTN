#include<iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

void agregarPrimero(Nodo *&lista, int valor);
int eliminarPrimero(Nodo *&lista);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);
void insertarOrdenado(Nodo *&lista, int valor);
Nodo *buscar(Nodo *lista,int valor);
void buscarYmostrar(Nodo *lista,int valor);

int main(){
    Nodo * lista = NULL;
    int carga;
    cout<<"Ingrese un valor o termine con 0."<<endl;
    cin>>carga;
    while(carga!=0){
        agregarPrimero(lista,carga);
        cout<<"Ingrese un valor o termine con 0."<<endl;
        cin>>carga;
    }
    insertarOrdenado(lista,8);
    /*Nodo * rdo; //para mostrar el buscado
    rdo=buscar(lista,3);
    if(rdo!=NULL){
        cout<<rdo->info<<endl;
    } else{
        cout<<"No se encontro."<<endl;
    }*/
    buscarYmostrar(lista,8);
    mostrar(lista);
    liberar(lista);
    /*int rdo;
    while(lista!=NULL){
        rdo=eliminarPrimero(lista);
        cout<<rdo<<endl;
    }*/
    return 0;
}

void agregarPrimero(Nodo *&lista, int valor){
    Nodo * nuevo = new Nodo();
    nuevo -> info = valor;
    nuevo -> sgte = lista;
    lista = nuevo;
};
int eliminarPrimero(Nodo *&lista){
    int ret;
    ret = lista -> info;
    Nodo *aux = lista;
    lista = aux->sgte;
    delete(aux);
    return ret;
};
void mostrar(Nodo *lista){
    Nodo *aux = lista;
    //Recorrer
    while(aux!=NULL){
        cout<<""<<aux->info<<endl;
        aux=aux->sgte; //avanzo al sgte
    }
};
void liberar(Nodo *&lista){
    Nodo * aux;
    while(lista!=NULL){
        aux=lista;
        lista = lista->sgte;
        delete(aux);
    }

};
void insertarOrdenado(Nodo *&lista, int valor){
    // crear el nodo
    Nodo *nuevo= new Nodo();
    // cargar el nodo
    nuevo -> info = valor;
    nuevo -> sgte = NULL; //xqe no se todavia donde va a ir
    // enlazarlo, en donde?
    Nodo *aux = lista; //poder recorrer sin modificar la lista
    Nodo *ant = NULL; //el q me va a permitir hacer la conexion
    // buscar
    while(aux!=NULL&&aux->info<valor){
        ant=aux;
        aux=aux->sgte;
    }
    if(ant==NULL){ //1)lista vacia o 2)debo insertar al principio
        lista = nuevo;
    }else{ //pude haber salido porque estoy en alguna parte de la lista, o llegamos al final
        ant->sgte=nuevo;
    }
    nuevo->sgte=aux; //se repite en if y else 
};
Nodo *buscar(Nodo *lista,int valor){
    Nodo *aux=lista;
    while(aux!=NULL&&aux->info!=valor){
        aux= aux->sgte;
    }
    return aux;
};
void buscarYmostrar(Nodo *lista,int valor){
    Nodo *aux=lista;
    while(aux!=NULL&&aux->info!=valor){
        aux= aux->sgte;
    }
    if(aux!=NULL){
        cout<<"Encontre: "<<aux->info<<endl;
    } else{
        cout<<"No se encontro."<<endl;
    }
};