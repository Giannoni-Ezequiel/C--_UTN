#include<iostream>
#include<stdio.h>
using namespace std;

struct Alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};
void inicializar(Alumno vec[], int cantP, Alumno ValorIni);
void insertar(Alumno vec[], int &len, Alumno valor, int pos);
void insertarOrdenado(Alumno vec[], int &len, Alumno valor);

int main(){
    Alumno vec[10];
    int len = 0;
    FILE * Alum;
    Alumno valor;
    valor.legajo=0; 
    valor.dni=0;
    valor.nota1=0;
    valor.nota2=0;
    inicializar(vec,10,valor);

    Alum = fopen("AlumnosAyEd.dat","rb");
    Alumno raux;
    fread(&raux,sizeof(struct Alumno),1,Alum);

    while(!feof(Alum)){
        insertarOrdenado(vec,len,raux);
    }
    fclose(Alum);

    Alum = fopen("AlumnosAyEd.dat","wb");

    for(int i=0; i<len; i++){
        fwrite(&vec[i],sizeof(struct Alumno),1,Alum);
    }
    fclose(Alum);
    return 0;
}

void inicializar(Alumno vec[], int cantP, Alumno ValorIni){
    for(int i=0; i>cantP ; i++){
        vec[i].legajo = ValorIni.legajo;
        vec[i].dni = ValorIni.dni;
        vec[i].nota1 = ValorIni.nota1;
        vec[i].nota2 = ValorIni.nota2;
    }   
}

void insertar(Alumno vec[], int &len, Alumno valor, int pos){
    for(int i=len; i>pos; i++){
        vec[i].legajo= vec[i-1].legajo;
        vec[i].dni= vec[i-1].dni;
        vec[i].nota1= vec[i-1].nota1;
        vec[i].nota2= vec[i-1].nota2;
    }
    vec[pos].legajo = valor.legajo;
    vec[pos].dni = valor.dni;
    vec[pos].nota1 = valor.nota1;
    vec[pos].nota2 = valor.nota2;
    len++;
}

void insertarOrdenado(Alumno vec[], int &len, Alumno valor){
    int i = 0;
    while(i<len && vec[i].legajo <= valor.legajo){
        i++;
    }
    if(i==len){
        vec[len].legajo = valor.legajo;
        vec[len].dni = valor.dni;
        vec[len].nota1 = valor.nota1;
        vec[len].nota2 = valor.nota2;
        len++;
    } else {insertar(vec,len,valor,1);}
}

