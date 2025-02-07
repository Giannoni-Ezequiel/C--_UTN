#include <iostream>

using namespace std;

struct tipoInfoModelos{
    int id_accesorio;
    int cantidad;
};
struct NodoModelos{
    tipoInfoModelos info;
    NodoModelos* sgte;
};

//3) declarar el registro
struct registroModelos{
    int  id_modelo;
    char descripcion[100+1];
    float precio_base;
    char temporada;
    NodoModelos* ListaDeCompon = NULL;
};

//4) declarar el vector

registroModelos vectorModelos[50];

struct tipoInfoProveedores{
    int id_proveedor;
    char nombre[50];
    float valorUnitario;
};
struct NodoProveedores{
    tipoInfoProveedores info;
    NodoProveedores* sgte;
};
struct RegistroComponentes{
    int  id_componente;
    char descripcion[100+1];
    NodoProveedores* listaProveedores = NULL;
    char stock;
    
};

RegistroComponentes componentes[1000];

struct Pedido{
    int id_pedido;
    int id_linea;
    int fecha;
    int id_modelo;
    int cantidad;
    float costo;
}; 


