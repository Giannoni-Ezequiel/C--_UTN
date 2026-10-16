#include<iostream>
using namespace std;

struct NodoPila{
    Viaje viaje;
    NodoLista* sgte;
};

struct NodoCola{
    Viaje viaje;
    NodoLista* sgte;
};

struct NodoLista{
    Viaje viaje;
    NodoLista* sgte;
};

struct Viaje{
    int id_viaje;
    int kilometrosRecorridos;
};

Viaje pop(NodoPila*&);
Viaje unqueue(NodoCola*&, NodoCola*&);
void insertarSinRepetir(NodoLista*&, Viaje);

NodoLista* unificarViajes(NodoPila*& pila, NodoCola*& fte, NodoCola*& fin)
{
    NodoLista* lista = NULL;
    Viaje viajeAux;
    int kilometrosRecorridosTotales = 0;
    while(pila != NULL){
    viajeAux = pop(pila);
    insertarSinRepetir(lista, viajeAux);

    }
    while(fte != NULL){
    viajeAux = unqueue(fte, fin);
    insertarSinRepetir(lista, viajeAux);    
    }
    NodoLista* ptrAuxLista = lista;
    while(ptrAuxLista != NULL){
        kilometrosRecorridosTotales += ptrAuxLista->viaje.kilometrosRecorridos;
        ptrAuxLista = ptrAuxLista->sgte;
    }
    cout << "La cantidad de kilometros recorrida es: " << kilometrosRecorridosTotales <<endl;
    return lista;
}





int main(){
     
}