#include<iostream>
using namespace std;
/*
    Realizar la suma de todos los números pares entre 2 y 10000 
*/
int main(){
    int nroPar=2;
    int suma=0;
    while(nroPar<10000){
    if(nroPar%2 == 0){
        suma = suma+nroPar;
        cout <<"El numero "<< nroPar <<" es Par." << endl;
    } else {
        cout <<"El numero "<< nroPar <<" es Impar." << endl;
    }}
    cout <<"La suma: "<< suma << endl;
    return 0;
}