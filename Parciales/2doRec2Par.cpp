/*
1. Declare el vector principal y todos los tipos de datos necesarios para que sea válida la
 declaración del mismo. (2 puntos)
 2. Confeccione un procedimiento que reciba el vector, un struct “pedido” y un número de
 comuna. El subprograma debe agregar el envío al final de la lista que menos envíos tenga
 asignados. (4 puntos).
 3. Realice un procedimiento que reciba el vector principal, la ruta y nombre de un archivo
 de envíos y agregue, al final del archivo, todos los envíos de las comunas que tengan
 todos los envíos entregados. Luego del proceso, las listas de las comunas en cuestión
 deben quedar vacías. Puede utilizar el subprograma:
 bool quitarPrimero(NodoListaSE *&lista, Pedido &p)
 Que quita el primer nodo de la lista, asignando al segundo como primero si hubiera más
 nodos o dejando la lista en NULL si se quitara el último nodo. En caso que se haya podido
 quitar un nodo devuelve true y los datos de la info del nodo a través del parámetro p. En
 caso de que no se haya podido quitar un nodo, la función devuelve false. (4 puntos)
*/

#include <iostream>
using namespace std;

struct Pedido{
    char direcEntrega[100+1];
    int DNI;
    char palabraClave[15+1];
};
struct Nodo{
    Pedido info;
    Nodo* sgte;
};
struct Comuna{
    int cantTotalEnvios = 0;
    Nodo* ListaSE = NULL;
    Nodo* ListaSE2 = NULL;
};
Comuna comu[15];
void cargar(Comuna comu[], Pedido ped ,int comuna){
    Nodo* q = comu[comuna-1].ListaSE;
    Nodo* r = comu[comuna-1].ListaSE2;
    
}