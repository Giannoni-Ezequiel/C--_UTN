/*Se tiene un archivo de disponibilidad para las habitaciones
de un hotel en la costa de verano Verano2025.dat (sin orden):
- Numero de habitacion
- Tipo
- Dias disponibles de la temporada
- Precio por dia de la habitacion
Se pide:
a) Ordenar el archivo Verano2025 por num de habitacion
b) Armar una lista, ordenada por Numero de habitacion, y mostrarla
por pantalla si el numero de dias disponibles es menor a 50 y
son habitaciones singles o dobles. 
*/
//un archivo y dos listas..
#include<iostream>
using namespace std;

struct tInfo{
    int numHab;
    char tipo;
    int disp;
    int precio;
}; 

struct Nodo{
    tInfo info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, tInfo valor);
void liberar(Nodo *&lista);
void mostrar(Nodo *lista);


int main(){
    Nodo *listaA=NULL;
    Nodo *listaB=NULL;
    FILE *Hotel;
    Hotel=fopen("Verano2025.dat","rb");
    tInfo raux;
    fread(&raux,sizeof(struct tInfo),1,Hotel);
    while(!feof(Hotel)){
        insertarOrdenado(listaA,raux); //puntoA
        if(raux.disp<50&&raux.tipo=='S'||raux.tipo=='D'){
            insertarOrdenado(listaB,raux);
        }
        fread(&raux,sizeof(struct tInfo),1,Hotel);
    }
    fclose(Hotel);

    Hotel=fopen("Verano2025.dat","wb");
    Nodo *aux=listaA;
    while(aux!=0){
        fwrite(&aux->info,sizeof(struct tInfo),1,Hotel);
        aux = aux->sgte;
    }
    fclose(Hotel);
    liberar(listaA);

    mostrar(listaB);
    liberar(listaB); 
    return 0;
}

void insertarOrdenado(Nodo *&lista, tInfo valor){
    // crear el nodo
    Nodo *nuevo= new Nodo();
    // cargar el nodo
    nuevo -> info.numHab = valor.numHab;
    nuevo -> info.tipo = valor.tipo;
    nuevo -> info.disp = valor.disp;
    nuevo -> info.precio = valor.precio;
    nuevo -> sgte = NULL; //xqe no se todavia donde va a ir
    // enlazarlo, en donde?
    Nodo *aux = lista; //poder recorrer sin modificar la lista
    Nodo *ant = NULL; //el q me va a permitir hacer la conexion
    // buscar
    while(aux!=NULL&&aux->info.numHab<valor.numHab){
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
        cout<<""<<aux->info.numHab<<endl;
        cout<<""<<aux->info.tipo<<endl;
        cout<<""<<aux->info.disp<<endl;
        cout<<""<<aux->info.precio<<endl;
        aux=aux->sgte; //avanzo al sgte
    }
};