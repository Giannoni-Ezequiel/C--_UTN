//Dado un archivo de registro(codPrd; tipoDeProduc) generar 2 archivos ordenados
#include<iostream>
using namespace std;

struct Tinfo{
    int codProd;
    char tipo;
};
struct Nodo{
    Tinfo info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, Tinfo valor);
void liberar(Nodo *&lista);
void mostrar(Nodo *lista);

int main(){
    Nodo *ListaA=NULL;
    Nodo *ListaB=NULL;

    FILE * Arch;
    FILE * ArchA;
    FILE * ArchB;
    Arch = fopen("arch.dat","rb");
    //Ojo los tengo abiertos al pepe
    //ArchA = fopen("archA.dat","wb");
    //ArchB = fopen("archB.dat","wb");
    
    Tinfo raux;
    fread(&raux,sizeof(struct Tinfo),1,Arch);
    while(!feof(Arch)){
        if(raux.tipo=='A'){
            insertarOrdenado(ListaA,raux);
        } else{
            insertarOrdenado(ListaB,raux);
        }
        fread(&raux,sizeof(struct Tinfo),1,Arch);
    }
    fclose(Arch);
    ArchA = fopen("archA.dat","wb");
    Nodo *aux=ListaA;
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(struct Tinfo),1,ArchA);
        aux = aux->sgte;
    }
    fclose(ArchA);
    mostrar(ListaA);
    liberar(ListaA);

    ArchB = fopen("archB.dat","wb");
    aux=ListaB;
    while(aux!=NULL){
        fwrite(&aux->info,sizeof(struct Tinfo),1,ArchB);
        aux=aux->sgte;
    }
    fclose(ArchB);
    mostrar(ListaB);
    liberar(ListaB);
    return 0;
}

void insertarOrdenado(Nodo *&lista, Tinfo valor){
    // crear el nodo
    Nodo *nuevo= new Nodo();
    // cargar el nodo
    nuevo -> info.codProd = valor.codProd;
    nuevo ->info.tipo=valor.tipo;
    nuevo -> sgte = NULL; //xqe no se todavia donde va a ir
    // enlazarlo, en donde?
    Nodo *aux = lista; //poder recorrer sin modificar la lista
    Nodo *ant = NULL; //el q me va a permitir hacer la conexion
    // buscar
    while(aux!=NULL&&aux->info.codProd<valor.codProd){
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
        cout<<""<<aux->info.codProd<<endl;
        cout<<""<<aux->info.tipo<<endl;
        
        aux=aux->sgte; //avanzo al sgte
    }
};