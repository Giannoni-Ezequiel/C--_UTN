#include<iostream>
using namespace std;
//Autopista del sol tiene un archivo de registros que cada registro contiene
//estacion de peaje, int[1-10], patente del automotor
//se requiere hacer un programa que muestre por pantalla
//ordenado por cabina de peaje, y numero de patente, los coches que pasaron por cada uno de los peajes.
struct Nodo{
    int info;
    Nodo* sgte;
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

struct tipoRegistro{
    int campo1; //es entero entre 1 y 10
    int campo2; //representa la patente
};

int main(){
    Nodo* vec[10] = {NULL};
    FILE* f=fopen("peajes","rb+");
    tipoRegistro registro;
    int i;
    int patente;
    while(fread(&registro,sizeof(registro),1,f)){
        insertarOrdenado(vec[registro.campo1-1],registro.campo2);
    }
    for (i = 0; i < 10;i++)
    {
        while(vec[i]!=NULL){
            patente = pop(vec[i]);
        }
        /* code */
    }
    
    return 0;
}