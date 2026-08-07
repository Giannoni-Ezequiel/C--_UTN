/*
2.	Ingresar un valor entero N (< 30) 
y a continuación un conjunto de N elementos. 
Si el último elemento del conjunto tiene un valor menor que 10 
imprimir los negativos y en caso contrario los demás
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    int valor;
    cout<<"Ingrese un valor < 30"<<endl;
    cin>>n;
    int vecPositivos[n]={0};
    int vecNegativos[n];
    int vecNumeros[n];
    int lenP=0;
    int lenN=0;
    int len=0;
    while(n>0){
        cout<<"Ingrese los valores"<<endl;
        cin>>valor;
        vecNumeros[len] = valor;
        len++;
        if(n<0){
            vecNegativos[lenN] = valor;
            lenN++;
        } else {
            vecPositivos[lenP] = valor;
            lenP++;
        }
        
        n--;
    }
    if(vecNumeros[n-1]<10){
        cout<<"Valores negativos:"<<endl;
        for(int i=0; i<lenN;i++){
            cout<<vecNegativos[i]<<endl;
        }
    } else {
        cout<<"Valores positivos:"<<endl;
        for(int i=0; i<lenP;i++){
            cout<<vecPositivos[i]<<endl;
        }
    }
    return 0;

}