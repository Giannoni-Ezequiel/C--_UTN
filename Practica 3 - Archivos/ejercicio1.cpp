/*
Se conoce de cada alumno de un curso los siguientes datos: legajo (8digitos) y las notas de 
2 parciales (0..10), que finaliza con un legajo negativo. 
Se pide desarrollar un programa que ingrese los datos de los alumnos por teclado y grabe 
un archivo binario CURSO.BIN con una línea por cada alumno, con el número de legajo y su 
promedio (real). 
*/


#include <iostream>
#include <stdio.h>
using namespace std;

struct alumno{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
};

struct nodo{
    alumno info;
    nodo* sgte;
};

int main(){
    FILE* curso = fopen("Curso.bin","wb");
    alumno aux;
    cout<<"Ingrese legajo"<<endl;
    cin>>aux.legajo;
    cout<<"Ingrese nota1"<<endl;
    cin>>aux.nota1;
    cout<<"Ingrese nota2"<<endl;
    cin>>aux.nota2;
    aux.promedio = (aux.nota1 + aux.nota2)/2;
    fwrite(&aux,sizeof (struct alumno),1,curso);
    while(aux.legajo>0){
        cout<<"Ingrese legajo"<<endl;
        cin>>aux.legajo;
        cout<<"Ingrese nota1"<<endl;
        cin>>aux.nota1;
        cout<<"Ingrese nota2"<<endl;
        cin>>aux.nota2;
        aux.promedio = (aux.nota1 + aux.nota2)/2;
        fwrite(&aux,sizeof (struct alumno),1,curso);
    }
    fclose(curso);
    return 0;
}