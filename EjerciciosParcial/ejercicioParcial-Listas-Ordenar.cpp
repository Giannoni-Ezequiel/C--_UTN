//Dado un archivo de enteros, ordenarlo.
#include<iostream>
#include<stdio.h>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};
void insertarOrdenado(Nodo *&lista, int valor);
void liberar(Nodo *&lista);
void mostrar(Nodo *lista);

int main(){
    //----Creacion y carga del archivo-------
    /*FILE * Ent;
    Ent = fopen("enteros.dat","wb");
    int carga;
    cout<<"Ingrese numeros enteros termine con 0."<<endl;
    cin>>carga;
    while(carga!=0){
        fwrite(&carga,sizeof(int),1,Ent);
        cout<<"Ingrese numeros enteros termine con 0."<<endl;
        cin>>carga;
    }
    fclose(Ent);*/
    //----------------------------------
    Nodo *Lista=NULL;
    FILE *Ent;
    Ent=fopen("enteros.dat","rb");
    int auxRead;
    fread(&auxRead,sizeof(int),1,Ent);
    while(!feof(Ent)){
        insertarOrdenado(Lista,auxRead);
        fread(&auxRead,sizeof(int),1,Ent);
    } //tengo todo lo que necesita el archivo, la lista esta ordenada
    fclose(Ent);
    //ahora voy a pisar el archivo para ordenarlo
    Ent=fopen("enteros.dat","wb");
    Nodo *aux=Lista;
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(int),1,Ent);
        aux=aux->sgte;
    }
    fclose(Ent);
    mostrar(Lista);
    liberar(Lista);
    return 0;
}

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

void liberar(Nodo *&lista){
    Nodo * aux;
    while(lista!=NULL){
        aux=lista;
        lista = lista->sgte;
        delete(aux);
    }

};

void mostrar(Nodo *lista){
    Nodo *aux = lista;
    //Recorrer
    while(aux!=NULL){
        cout<<""<<aux->info<<endl;
        aux=aux->sgte; //avanzo al sgte
    }
};