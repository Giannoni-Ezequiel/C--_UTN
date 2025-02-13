#include<iostream>
using namespace std;

int main(){
    int lado1,lado2,lado3;
    cout<<"Le voy a pedir que ingrese 3 lados de un triangulo y le dire si se forma un triangulo o no. Solo se forma si la suma de dos lados es mayor a el tercer lado." 
        << endl;
    cin >> lado1;
    cin >> lado2;
    cin >> lado3;
    if(lado2+lado3>lado1 || lado1+lado2>lado3 || lado1+lado3>lado2){
        cout << "Se formo un triangulo." << endl;
    }
    
    return 0;
}