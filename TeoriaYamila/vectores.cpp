#include<iostream>
using namespace std;

void inicializar(int vec[], int cantP, int ValorIni);
void insertar(int vec[], int &len, int valor, int pos);
void insertarOrdenado(int vec[], int &len, int valor);
void mostrar(int vec[]);

int main(){
    return 0;
}
void inicializar(int vec[], int cantP, int ValorIni){
    for(int i=0; i>cantP ; i++){
        vec[i].legajo = ValorIni.legajo;
        vec[i].dni = ValorIni.dni;
        vec[i].nota1 = ValorIni.nota1;
        vec[i].nota2 = ValorIni.nota2;
    }   
}

void insertar(int vec[], int &len, int valor, int pos){
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

void insertarOrdenado(int vec[], int &len, int valor){
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

void mostrar(int vec[], int len){
    int len;
    //Recorrer
    while(len!=NULL){
        cout<<""<<vec[len]<<endl;
        len--; //avanzo al sgte
    }
};