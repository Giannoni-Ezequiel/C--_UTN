/* Se tiene un archivo de peliculas infantiles en una plataforma digital
con los titulos disponibles para la 
- Codigo de pelicula: 999999
- Cantidad de opiniones positivas: 99999
- Cantidad de vistas: 999999
Se pide:
a) Ordenar el Archivo por Opiniones Positivas
b) Listar las 10 peliculas que mas vistas tuvieron 
(al listar incluir toda la info referente)
Nota: Solo debe leer 1 vez el archivo. Se sabe que no hay mas de 50 peliculas

*/

#include<iostream>
#include<stdio.h>
using namespace std;

struct peli{
    int cod;
    int opi;
    int vistas;
};
void inicializar(peli vec[], int cantP, peli ValorIni);
void insertar(peli vec[], int &len, peli valor, int pos);
void insertarOrdenadoA(peli vec[], int &len, peli valor);
void insertarOrdenadoB(peli vec[], int &len, peli valor);

int main(){
    peli vecA[50];
    int lenA=0;
    peli vecB[50];
    int lenB=0;
    FILE * titulos;
    peli ini;
    ini.cod = 0;
    ini.opi = 0;
    ini.vistas = 0;
    inicializar(vecA, 50, ini);
    inicializar(vecB, 50, ini);

    titulos=fopen("Infantil.dat","rb");

    peli raux;  //auxiliar responsable para cargar en memoria
    fread(&raux, sizeof(struct peli),1,titulos);
    while(!feof(titulos)){
        insertarOrdenadoA(vecA,lenA,raux);
        insertarOrdenadoB(vecB,lenB,raux);
        fread(&raux, sizeof(struct peli),1,titulos);
    }
    fclose(titulos);

    titulos=fopen("Infantiles.dat","wb");
    //a
    for(int i=0; i<lenA; i++){
        fwrite(&vecA[i],sizeof(struct peli),1,titulos);
    }
    fclose(titulos);
    //b
    if(lenB>10){
    for(int i=0; i<10; i++){
        cout<<"--------------"<<endl;
        cout<<"Codigo: "<<vecB[i].cod<<endl;
        cout<<"Opiniones positivas: "<<vecB[i].opi<<endl;
        cout<<"Vistas: "<<vecB[i].vistas<<endl;
        
    } }else{
        for(int i=0; i<lenB; i++){
        cout<<"--------------"<<endl;
        cout<<"Codigo: "<<vecB[i].cod<<endl;
        cout<<"Opiniones positivas: "<<vecB[i].opi<<endl;
        cout<<"Vistas: "<<vecB[i].vistas<<endl;}

    }
    return 0;
}

void inicializar(peli vec[], int cantP, peli ValorIni){
    for(int i=0; i>cantP ; i++){
        vec[i].cod = ValorIni.cod;
        vec[i].opi = ValorIni.opi;
        vec[i].vistas = ValorIni.vistas;
    }   
}

void insertar(peli vec[], int &len, peli valor, int pos){
    for(int i=len; i>pos; i--){
        vec[i].cod= vec[i-1].cod;
        vec[i].opi= vec[i-1].opi;
        vec[i].vistas= vec[i-1].vistas;
    }
    vec[pos].cod = valor.cod;
    vec[pos].opi = valor.opi;
    vec[pos].vistas = valor.vistas;

    len++;
}

void insertarOrdenadoA(peli vec[], int &len, peli valor){
    int i = 0;
    while(i<len && vec[i].opi <= valor.opi){
        i++;
    }
    if(i==len){
        vec[len].cod = valor.cod;
        vec[len].opi = valor.opi;
        vec[len].vistas = valor.vistas;
        len++;
    } else {insertar(vec,len,valor,1);}
}

void insertarOrdenadoB(peli vec[], int &len, peli valor){
    int i = 0;
    while(i<len && vec[i].vistas >= valor.vistas){
        i++;
    }
    if(i==len){
        vec[len].cod = valor.cod;
        vec[len].opi = valor.opi;
        vec[len].vistas = valor.vistas;
        len++;
    } else {insertar(vec,len,valor,1);}
}
