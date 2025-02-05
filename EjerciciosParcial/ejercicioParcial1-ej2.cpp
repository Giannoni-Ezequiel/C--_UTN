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
void mostrar(Alumno, int);

int main(){
    FILE * Alum;

    Alumno vecAp[10];
    int lenA=0;
    Alumno vecRec[10];
    int lenR=0;

    Alumno valor;
    valor.legajo=0; 
    valor.dni=0;
    valor.nota1=0;
    valor.nota2=0;
    inicializar(vecAp,10,valor);
    inicializar(vecRec,10,valor);

    Alum = fopen("AlumnosAyEd.dat", "rb");
    Alumno raux;
    fread(&raux,sizeof(struct Alumno),1,Alum);
    while(!feof(Alum)){
        if(raux.nota1<6 || raux.nota2<6){
            insertarOrdenado(vecRec,lenR,raux);
        } else {
            insertarOrdenado(vecAp,lenA,raux);   }

        fread(&raux,sizeof(struct Alumno),1,Alum);
    
    }
    fclose(Alum);
    mostrar(vecAp,lenA);
    cout<<"----------------------"<<endl;
    mostrar(vecRec,lenR);
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

void mostrar(Alumno vec[], int len2){
    for(int i=0; i<len2; i++){
        cout<<"El valor es: "<<vec[i].legajo<<endl;
        cout<<"El valor es: "<<vec[i].dni<<endl;
        cout<<"El valor es: "<<vec[i].nota1<<endl;
        cout<<"El valor es: "<<vec[i].nota2<<endl;
    }
}
