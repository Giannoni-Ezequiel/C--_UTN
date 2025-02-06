/* 8.	Dados 50 números enteros, informar el promedio de los mayores que 100 y la suma de los menores que -10. */
#include <iostream>
using namespace std;

int main(){
    int numerosEnteros, sumaMayores = 0, promedioMayores = 0, sumaMenores = 0, numero, contAux;
    cout << "Ingrese 50 numeros o menos si se cansa. "<< endl;
    for(int contador=0; numerosEnteros < 50; contador++){
        numerosEnteros++;
        cout << "Numero: " << numerosEnteros << endl;
        cin >> numero;
        cout << "N.Ingresado: " << numero << endl;
        if(numero > 100){
            sumaMayores = sumaMayores + numero;
            contAux++;
        } else if(numero < -10){
            sumaMenores = sumaMenores + numero;
        }
        promedioMayores = sumaMayores / contAux;
        cout << "Promedio de los numeros enteros mayores a 100: " << promedioMayores << endl;
        cout << "La suma de los numeros enteros menores a -10: " << sumaMenores << endl;     
    }
}