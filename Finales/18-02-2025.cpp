#include<iostream>
using namespace std;

//cargar los datos de un archivo a un vector de listas de listas.
//en el archivo tenemos 3 campos.
//campo1: [1..10] -- perfectamente acotado
//campo2: entero
//campo3: entero
//en el vector el campo1, en la lista principal el campo2, en la lista secu el campo3
//para cargar en el vector, como el numero esta en 1 y 10, la carga va a ser directa.
//para cargar en la lista, como esta indeterminado y tiene que ser sin repetir la clave, vamos a utilizar
//cargar sin repetir.
//para cargar en la sublista, dado q no importa si se repite o no, vamos a utilizar insertarOrdenado.

struct RegistroDelArchivo{
    int campo1;
    int campo2;
    int campo3;
};

//vamos a declarar los nodos
//estamos declarando el nodo de la sublista.
struct NodoListaSecundaria{
    int info;  //dijimos que el campo de la informacion es un int
    NodoListaSecundaria* sgte; // es un puntero a una estructura del mismo tipo(autoreferenciada).
};

//declarar el tipo info de la lista principal.
//tiene que tener el entero q se corresponde con el campo2, y el puntero a la lista secundario.

struct TipoInfoLP{
    int campo2; //el dato para ordenar
    NodoListaSecundaria* sublista; //el puntero a la lista secundaria
}; 

struct NodoListaPrincipal{
    TipoInfoLP info;//el campo de la informacion tiene el campo2 y el puntero a la sublista
    NodoListaPrincipal* sgte;//la referencia al sgte nodo
};
//Declarar el vector de punteros
NodoListaPrincipal* vector[10]={NULL}; //el vector para dirigir el campo1 es un vector de punteros inicilizado en null.

FILE* f = fopen("archivo","rb+"); //suponemos que el archivo existe

NodoListaSecundaria* insertaOrdenado(NodoListaSecundaria*& lista,int x){//siempre tenemos que insertar
    NodoListaSecundaria* nuevo = new NodoListaSecundaria();
    nuevo->info = x;
    if(lista==NULL||x<lista->info){
        nuevo->sgte=lista;
        lista=nuevo;
    }else{
        NodoListaSecundaria* q = lista;
        while(lista->sgte!=NULL && x>lista->sgte->info){
            q = q->sgte;
        }
        nuevo->sgte=q->sgte;
        q->sgte=nuevo;
    }
    return nuevo;
}

NodoListaPrincipal* insertaOrdenadoListaPrincipal(NodoListaPrincipal*& lista,TipoInfoLP info){//no siempre
    NodoListaPrincipal* nuevo = new NodoListaPrincipal();
    nuevo->info = info;
    if(lista==NULL||info.campo2<lista->info.campo2){
        nuevo->sgte=lista;
        lista=nuevo;
    }else{
        NodoListaPrincipal* q = lista;
        while(lista->sgte!=NULL && info.campo2>lista->sgte->info.campo2){
            q = q->sgte;
        }
        nuevo->sgte=q->sgte;
        q->sgte=nuevo;
    }
    return nuevo;
}
//buscamos para saber si esta o no y si no esta usamos el 2do insertar.
NodoListaPrincipal* buscar(NodoListaPrincipal* lista, TipoInfoLP x){
    NodoListaPrincipal* q = lista; // ponemos un puntero al principio de la estructura poara empezar a recorrer
    while(lista!=NULL&&q->info.campo2!=x.campo2){//buscamos mientras la lista sea distinto de null o si el nodo lo encontramos
        q=q->sgte;
    }
    return q; //retorna null si no lo encuentra y donde esta el nodo en caso de encontrarlo
}
NodoListaPrincipal* cargarSinRepetir(NodoListaPrincipal*& lista, TipoInfoLP x){
    NodoListaPrincipal* p = buscar(lista,x);
    if(p==NULL){
        p = insertaOrdenadoListaPrincipal(lista,x);
    }
    return p;
}

int main(){
    RegistroDelArchivo registro;
    //recordar que en las listas tenemos el puntero ya inicializado
    NodoListaPrincipal* p;
    NodoListaSecundaria* q;
    TipoInfoLP valor;
    while(fread(&registro,sizeof(registro),1,f)){
        valor.campo2=registro.campo2;//cargamos la informacion al nodo de la lista principal
        valor.sublista=NULL;
        p = cargarSinRepetir(vector[registro.campo1-1],valor);
        insertaOrdenado(p->info.sublista,registro.campo3); 

    }

    return 0;
}



