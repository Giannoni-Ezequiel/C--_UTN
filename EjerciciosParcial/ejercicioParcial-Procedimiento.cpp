//2)Desarrolle un procedimiento que muestre por pantalla
/*  el numero escrito en letras, del numero que recibe*/
#include<iostream>
using namespace std;

void numAletra(int n);

int main(){
    
    return 0;
}

void numaletra(int n){
    switch(n){
        case 100: cout<<"CIEN"<<endl;
        break;
        case 200: cout<<"DOSCIEN"<<endl;
        break;
        case 300: cout<<"TRESCIEN"<<endl;
        break;
        case 400: cout<<"CUATROCIEN"<<endl;
        break;
        case 500: cout<<"QUINIEN"<<endl;
        break;
        default: cout<<"ERROR"<<endl;
    }
}