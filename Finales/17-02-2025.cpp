#include<iostream>
using namespace std;

// 1) Codificar todas las declaraciones para los anteriores arreglos y funciones.
struct Mesa
{
    int id;
    string asignatura;
    int fecha;
    ListaEstudiantes *listaEstudiantes;
};

struct Tinfo{
    int id;
    int nota;
};

struct ListaEstudiantes
{
    Tinfo info;
    ListaEstudiantes *siguiente;
};

struct Estudiante
{
    int id;
    string nombreyApe;
    ListaMesas *listaMesas;
};

struct ListaMesas
{
    int id;
    ListaMesas *siguiente;
};

Mesa Mesas[50];
int lenMesas;
Estudiante Estudiantes[150];

int IndiceDeMesa(int id);
int IndiceDeEstudiante(int id);

/*NodoListaPrincipal* insertaOrdenadoListaPrincipal(NodoListaPrincipal*& lista,TipoInfoLP info){//no siempre
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
}*/

void insertarOrdenado1(ListaEstudiantes*& listaE, Tinfo info){
    // crear el nodo
    ListaEstudiantes *nuevo= new ListaEstudiantes();
    // cargar el nodo
    nuevo -> info.id = info.id;
    nuevo -> info.nota = info.nota;
    nuevo -> siguiente = NULL; //xqe no se todavia donde va a ir
    // enlazarlo, en donde?
    ListaEstudiantes *aux = listaE; //poder recorrer sin modificar la lista
    ListaEstudiantes *ant = NULL; //el q me va a permitir hacer la conexion
    // buscar
    while(aux!=NULL&&aux->info.id<info.id){
        ant=aux;
        aux=aux->siguiente;
    }
    if(ant==NULL){ //1)lista vacia o 2)debo insertar al principio
        listaE = nuevo;
    }else{ //pude haber salido porque estoy en alguna parte de la lista, o llegamos al final
        ant->siguiente=nuevo;
    }
    nuevo->siguiente=aux; //se repite en if y else 
};
void insertarOrdenado2(ListaMesas*& listaM, int id){
    // crear el nodo
    ListaEstudiantes *nuevo= new ListaEstudiantes();
    // cargar el nodo
    nuevo -> info.id = info.id;
    nuevo -> info.nota = info.nota;
    nuevo -> siguiente = NULL; //xqe no se todavia donde va a ir
    // enlazarlo, en donde?
    ListaEstudiantes *aux = listaE; //poder recorrer sin modificar la lista
    ListaEstudiantes *ant = NULL; //el q me va a permitir hacer la conexion
    // buscar
    while(aux!=NULL&&aux->info.id<info.id){
        ant=aux;
        aux=aux->siguiente;
    }
    if(ant==NULL){ //1)lista vacia o 2)debo insertar al principio
        listaE = nuevo;
    }else{ //pude haber salido porque estoy en alguna parte de la lista, o llegamos al final
        ant->siguiente=nuevo;
    }
    nuevo->siguiente=aux; //se repite en if y else 
};

void Inscribir(int mesaId, int estudianteId, Mesa Mesas[],Estudiante Estudiantes[]){
    int posMesa = IndiceDeMesa(mesaId);
    int posEstudiante = IndiceDeEstudiante(estudianteId);
    ListaEstudiantes* auxEstudiante = Mesas[posMesa].listaEstudiantes;
    int encontrado1 = 0;
    Mesas[posMesa].listaEstudiantes;
    
    //se valida que la misma mesa no pueda tener 2 veces al mismo estudiante
    while(auxEstudiante->siguiente!=NULL){
        if(auxEstudiante->info.id==posEstudiante){
            cout<<"Ya esta cargado"<<endl;
            encontrado1 = 1;            
            break;
        } 
        auxEstudiante = auxEstudiante -> siguiente;
    }
    if(encontrado1==0){
        Tinfo raux;
        raux.id=estudianteId;
        raux.nota=0;
        insertarOrdenado1(Mesas[posMesa].listaEstudiantes,raux);
    }
    //se valida que el estudian solo se pueda inscribir una vez a una mesa
    Estudiantes[posEstudiante].listaMesas;
    ListaMesas* auxMesa = Estudiantes[posEstudiante].listaMesas;
    int encontrado2 = 0;
    while(auxMesa->siguiente!=NULL){
        if(auxMesa->id==posMesa){
            cout<<"Ya esta cargado"<<endl;
            encontrado2 = 1;            
            break;
        } 
        auxMesa = auxMesa -> siguiente;
    }
    if(encontrado2==0){
        insertarOrdenado2(Estudiantes[posEstudiante].listaMesas,mesaId);
    }
}

///2
struct RegistroNotas{
    int mesaId;
    int estudianteId;
    int nota;
};

void RegistrarNotas(FILE* arch,Mesa Mesas[],int &lenMesas){
    arch = fopen("notas","rb");
    RegistroNotas raux;

    while(fread(&raux, sizeof(raux),1,arch)){
        int posMesa = IndiceDeMesa(raux.mesaId);
        int posEstudiante = IndiceDeEstudiante(raux.estudianteId);
        ListaEstudiantes*aux= Mesas[posMesa].listaEstudiantes;
        while(aux->siguiente!=NULL){
            if(Mesas[posMesa].listaEstudiantes->info.id==raux.estudianteId){
               Mesas[posMesa].listaEstudiantes->info.nota = raux.nota;  
            }
            aux = aux ->siguiente;
        }
 
    }
    fclose(arch);
}

//3 