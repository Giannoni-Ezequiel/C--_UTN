/*
Escriba un programa que permita ingresar la tirada de un par de dados 50 veces
y muestre una lista donde se vea cuántas veces se dio cada uno de los resultados posibles. 
Por cada tirada se deberán ingresar 2 valores, cada uno representa el valor de un dado. 
El formato de la salida debe ser el siguiente:
2 salió ... veces
3 salió ... veces
. . 12 salió ... veces

*/
void contarRepes(int, int);

#include <iostream>
using namespace std;

struct Tirada{
    int dado1;
    int dado2;
}

int main(){
    int dado1,dado2;
    Tirada tiradas[50];
    int numeros[5];
    int lenT = 0;
    int lenN;
    int i=0;
    int suma;
    for(i;i>lenT;i++){
        cout<<"Ingresar par de dados"<<endl;
        cin>>tiradas[lenT].dado1;
        cin>>tiradas[lenT].dado2;
        lenT++;
        suma = dado1+dado2;
    }
    cout<<"1 salio "<<numeros[0]<<" veces."<<endl;
    cout<<"2 salio "<<numeros[1]<<" veces."<<endl;
    cout<<"3 salio "<<numeros[2]<<" veces."<<endl;
    cout<<"4 salio "<<numeros[3]<<" veces."<<endl;
    cout<<"5 salio "<<numeros[4]<<" veces."<<endl;
    cout<<"6 salio "<<numeros[5]<<" veces."<<endl;
    return 0;
}

int contarRepes(int x, int numeros[]){
    switch(x){
        case 1:
            numeros[x-1] = 1;
            break;
        case 2:
            x = 2;
            break;
        case 3:
            x = 3;
            break;
        case 4:
            x = 4;
            break;
        case 5:
            x = 5;
            break;
        case 6:
            x = 6;
            break;
    }
    return x;
}