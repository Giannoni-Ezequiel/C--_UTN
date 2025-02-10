#include<iostream>
#include<stdio.h>
using namespace std;

struct Alum{
    int legajo;
    int dni;
    int Nota1;
    int Nota2;
};

int main(){
    FILE * A;
    FILE * B;
    FILE * C;

    A = fopen("archA.dat","rb");
    B = fopen("archB.dat","rb");
    C = fopen("archC.dat","wb");

    Alum rauxA;
    Alum rauxB;

    fread(&rauxA,sizeof(struct Alum),1,A);
    fread(&rauxB,sizeof(struct Alum),1,B);
    while(!feof(A)&&!feof(B)){
        if(rauxA.legajo<rauxB.legajo){
            fwrite(&rauxA,sizeof(struct Alum),1,C);
            fread(&rauxA,sizeof(struct Alum),1,A);
        } else{
            fwrite(&rauxB,sizeof(struct Alum),1,C);
            fread(&rauxB,sizeof(struct Alum),1,B);
        }}
    while(!feof(A)){
        fwrite(&rauxA,sizeof(struct Alum),1,C);
        fread(&rauxA,sizeof(struct Alum),1,A);
       
    }
    while(!feof(B)){
        fwrite(&rauxB,sizeof(struct Alum),1,C);
        fread(&rauxB,sizeof(struct Alum),1,B);
    }
    fclose(A);
    fclose(B);
    fclose(C);
    return 0;
}