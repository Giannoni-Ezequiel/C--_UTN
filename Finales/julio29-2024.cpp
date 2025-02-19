/*
Defina la funcion void dictamen
(vector de listas con los trabajos, vector de enteros con los resultados del evaluador, ID_Evaluador, la categoria y el titulo del trabajo) 
para que complete el campo de resultado del dictamen 
según las notas del evaluador del trabajo que usted debe interpretar los datos 
y establecer el dictamen según los mismos

2. Defina la funcion trabajos aprobados que emita un listado de los trabajos aprobados 
y a continuacion los que requieren modificacion por categoria

3. Declare todas las estructuras de datos que requiera la implementacion de las funciones pedidas
*/


#include <iostream>
using namespace std;

struct Evaluador{
    int vecA[100];
    int vecB[100];
    int vecC[100];
};

struct Resultado{
    char c1[40+1];
    char c2[]
};

struct dictamen{
    char titulo[50+1];
    int vecCat[5];
    char correoResp[50+1];
    Evaluador id_evaluador;
    Resultado resul;

};

struct nodo{
    int info;
    nodo* sgte;
};


void dictamen(nodo* vec[], int vec1[], Evaluador id_evaluador, la categoria y el titulo del trabajo);


int main(){
    nodo*vec[10];
    int len;
    int sum;
    nodo*aux; // para recorrer la lista
    for(int i=0;i<len;i++){
        sum=0;
        aux=vec[i]; // el puntero apunta a la posicion i
        while(aux!=NULL){
            aux=aux->sgte;  //recorro listas 
        }
    }
    return 0;
}