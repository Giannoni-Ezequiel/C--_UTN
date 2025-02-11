/*
a) Ordenar el archivo BurgerFast.dat por codigo de producto
b) Generar un archivo solo para panes Pan.dat con la siguiente estructura:alignas
 -> Codigo de Producto: 99999
 -> Cantidad de unidades en deposito: 999999
 -> Vencimiento: MMAAAA
c) Generar un archivo UsarAntes.dat con los productos que tengan mas de  1000 unidades en stock 
*/

#include<iostream>
using namespace std;

struct producto{
    int codProd;
    int descProd;
    int cantUnid;
    char tipoP;
    int vencimiento;
};

struct panesProd{
    int codigo;
    int cantidad;
    int vencimiento;
};

struct nodo{
    producto info;
    nodo *sgte;
};

void insertarOrdenado(nodo*&lista, producto valor);
void liberar(nodo*&lista);
void mostrar(nodo*lista);

int main(){
    return 0;
}

void insertarOrdenado(nodo*&lista, producto valor);
void liberar(nodo*&lista);
void mostrar(nodo*lista);
