#include<iostream>
#include<stdio.h>
using namespace std;

struct Alumno{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){
    Alumno raux;
    int suma = 0;
    int cont = 0;
    FILE * Alum;
    Alum = fopen("AlumnosAyEd.dat","rb");
    fread(&raux,sizeof(struct Alumno),1,Alum);
    while(!feof(Alum)){
        cont++;
        cout<<"Registro legajo: "<<raux.legajo<<endl;
        cout<<"Registro dni: "<<raux.dni<<endl;
        cout<<"Registro nota1: "<<raux.nota1<<endl;
        cout<<"Registro nota2: "<<raux.nota2<<endl;
        fread(&raux,sizeof(struct Alumno),1,Alum);
    
    }
    fclose(Alum);
    cout<<"El promedio es: "<<suma/cont<<endl;
    return 0;
}