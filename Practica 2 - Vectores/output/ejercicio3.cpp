/*
3.	Dado un conjunto (<100) de valores enteros de los cuales el último es cero y no
debe procesarse:
a.	informe el valor mínimo, su posición dentro del conjunto, si el mínimo no es único, 
    informar todas las posiciones donde se encuentre.
b.	informe el producto de los elementos impares que ocupen posición par.

*/

#include <iostream>
using namespace std;

int main(){
    int vec[]={0};
    int len=0;
    int vecPosMins[]={0};
    int lenM=0;
    int minimo;
    int valor;
    int prodImpars=0; 
    
    cout<<"Ingrese un valor y 0 para cortar"<<endl;
    cin>>valor;
    minimo=valor;
    while(valor!=0){
        vec[len]=valor;
        if(len%2==0 && valor%2==1){
        prodImpars = prodImpars * valor;}
        if(minimo>valor){
            minimo=valor;
        }
        len++;
        cout<<"Ingrese un valor"<<endl;
        cin>>valor;
    }
    for(int i=0;i<len;i++){
        if(vec[i]==minimo){
            vecPosMins[lenM]=i;
            lenM++;
        }
    }
    cout<<"-----------Valor Minimo-------------"<<endl;
    cout<<"----------"<<minimo<<endl;
    if(lenM>0){
        for(int i=0;i<lenM;i++){
        cout<<vec[i]<<endl;
        }
    }
    cout<<"-----------Producto de impares en posicion par-------------"<<endl;
    cout<<"----------"<<prodImpars<<endl;
    return 0;
}