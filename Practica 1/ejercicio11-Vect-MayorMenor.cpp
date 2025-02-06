/*11.	Dados N valores informar el mayor, el menor y en que posición del conjunto fueron ingresados.*/
#include <iostream>
using namespace std;

int main(){
    int n;
    int vec[n];
    int len = 0;
    cout<<"Ingrese un valor entero: "<<endl;
    cin>>n;
    cout<<"Ingrese 0 para cortar. "<<endl;
    while(n>0){
        int mayor = 0;
        int menor = 0;
        vec[len] = n;
        if(mayor>n){
            mayor = n;
            cout<<"El numero mayor de los ingresados es: "<<mayor<<endl;
            cout<<"El mismo se encuentra en la posicion "<<len<<" del conjunto ingresado."<<endl;
        } else if(menor>n){ menor = n;
            cout<<"El numero menor de los ingresados es: "<<endl;
        }     
        len++;
        cout<<"Ingrese un valor entero: "<<endl;
        cin>>n;
        cout<<"Ingrese 0 para cortar. "<<endl;
    }
    return 0;
}