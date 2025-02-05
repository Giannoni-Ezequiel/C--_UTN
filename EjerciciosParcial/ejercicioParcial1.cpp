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
    FILE * Alum;
    FILE * Aprob;
    FILE * Recu;
    
    Alum = fopen("AlumnosAyEd.dat","rb");
    Aprob = fopen("AlumnosAyEdAp.dat","wb");
    Recu = fopen("AlumnosAyEdRec.dat","wb");

    Alumno raux;
    fread(&raux,sizeof(struct Alumno),1,Alum);

    while(!feof(Alum)){

        if(raux.nota1<6 || raux.nota2<6){
            fwrite(&raux,sizeof(struct Alumno),1,Recu);
        } else {
            fwrite(&raux,sizeof(struct Alumno),1,Aprob);
        }

        fread(&raux,sizeof(struct Alumno),1,Alum);
    }

    fclose(Alum);
    fclose(Aprob);
    fclose(Recu);

    return 0;
}