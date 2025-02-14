//tengo que tener la referencia de pila para poder usar la funcion
#include<iostream>
#include<cstring>
struct alumno{
    int legajo;
    char nombre[50+1];
};
struct nodo{
    alumno info;
    nodo* sgte;
};

void push(nodo*& pila, alumno info){
    nodo* aux= new nodo(); //reservar espacio
    aux->info.legajo=info.legajo; //guardar informacion
    strcpy(aux->info.nombre,info.nombre);
	
	aux->sgte = pila; //darle la direccion del anterior
	
	pila = aux; // reapuntar pila al ultimo creado
	
	return;
	
}
