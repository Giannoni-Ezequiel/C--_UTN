/*
    Se tiene un archivo de registros de tamaño fijo de los jugadores
    Cod_jug:
*/

#include<iostream>
using namespace std;

struct Jugador{
    int cod_jug;
    int seleccion;
    int edad;
    int altura;
};

struct Jugador2{
    int cod_jug;
    int seleccion;
    int edad;
};
void inicializar(Jugador vec[], int cantP, Jugador ValorIni);
void inicializar2(Jugador2 vec[], int cantP, Jugador2 ValorIni);
void insertar(Jugador vec[], int &len, Jugador valor, int pos);
void insertarOrdenado(Jugador vec[], int &len, Jugador valor);
void insertarOrdenado2(Jugador2 vec[], int &len, Jugador2 valor);

int main(){
    Jugador sub23[100];
    int len1=0;
    Jugador2 may180[100];
    int len2=0;

    Jugador ValorIni;
    ValorIni.cod_jug = 0;
    ValorIni.edad = 0;
    ValorIni.altura = 0;
    ValorIni.seleccion = 0;
    Jugador2 ValorIni2;
    ValorIni2.cod_jug = 0;
    ValorIni2.seleccion = 0;
    ValorIni2.edad = 0;

    inicializar(sub23, 100, ValorIni);
    inicializar2(may180, 100, ValorIni2);
    
    FILE * Copa;
    Copa = fopen("","rb");
    
    Jugador raux;
    Jugador2 aux;
    fread(&raux,sizeof(struct Jugador),1,Copa);
    while(!feof(Copa)){
        if(raux.edad<=23){
            insertarOrdenado(sub23,len1,raux);
        }
        if(raux.altura>=180){
            aux.cod_jug=raux.cod_jug;
            aux.seleccion=raux.seleccion;
            aux.edad = raux.edad;
            insertarOrdenado2(may180,len2,aux);
        }
        fread(&raux,sizeof(struct Jugador),1,Copa);
    }
    fclose(Copa);
    return 0;
}

void inicializar(Jugador vec[], int cantP, Jugador ValorIni){
    for(int i=0; i<cantP ; i++){
        vec[i].cod_jug = ValorIni.cod_jug;
        vec[i].seleccion = ValorIni.seleccion;
        vec[i].edad = ValorIni.edad;
        vec[i].altura = ValorIni.altura;
    }   
}

void inicializar2(Jugador2 vec[], int cantP, Jugador2 ValorIni){
    for(int i=0; i<cantP ; i++){
        vec[i].cod_jug = ValorIni.cod_jug;
        vec[i].seleccion = ValorIni.seleccion;
        vec[i].edad = ValorIni.edad;
    }   
}

void insertar(Jugador vec[], int &len, Jugador valor, int pos){
    for(int i=len; i>pos; i--){
        vec[i].cod_jug= vec[i-1].cod_jug;
        vec[i].seleccion= vec[i-1].seleccion;
        vec[i].edad= vec[i-1].edad;
        vec[i].altura= vec[i-1].altura;
    }
    vec[pos].cod_jug = valor.cod_jug;
    vec[pos].seleccion = valor.seleccion;
    vec[pos].edad = valor.edad;
    vec[pos].altura = valor.altura;
    len++;
}

void insertar2(Jugador2 vec[], int &len, Jugador2 valor, int pos){
    for(int i=len; i>pos; i--){
        vec[i].cod_jug= vec[i-1].cod_jug;
        vec[i].seleccion= vec[i-1].seleccion;
        vec[i].edad= vec[i-1].edad;
     }
    vec[pos].cod_jug = valor.cod_jug;
    vec[pos].seleccion = valor.seleccion;
    vec[pos].edad = valor.edad;
    len++;
}

void insertarOrdenado(Jugador vec[], int &len, Jugador valor){
    int i = 0;
    while(i<len && vec[i].cod_jug <= valor.cod_jug){
        i++;
    }
    if(i==len){
        vec[len].cod_jug = valor.cod_jug;
        vec[len].seleccion = valor.seleccion;
        vec[len].edad = valor.edad;
        vec[len].altura = valor.altura;
        len++;
    } else {insertar(vec,len,valor,1);}
}

void insertarOrdenado2(Jugador2 vec[], int &len, Jugador2 valor){
    int i = 0;
    while(i<len && vec[i].cod_jug <= valor.cod_jug){
        i++;
    }
    if(i==len){
        vec[len].cod_jug = valor.cod_jug;
        vec[len].seleccion = valor.seleccion;
        vec[len].edad = valor.edad;
        len++;
    } else {insertar2(vec,len,valor,1);}
}