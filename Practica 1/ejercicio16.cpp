/*16.	Dado un conjunto de valores enteros, calcular e informar 
a) cuantos valores cero hubo, 
b) promedio de valores positivos, 
c) sumatoria de valores negativos.

Resolver el ejercicio para los siguientes lotes de datos:

a.	167 valores enteros
b.	N valores, donde el valor de N debe ser leido previamente
c.	El conjunto de valores termina con un valor igual al anterior
d.	Se dan N valores, pero el proceso deberá finalizar si se procesan todos los valores 
o si la cantidad de ceros supera a cuatro
e.	Se dan N valores, pero el proceso deberá finalizar si se cumple alguna de las condiciones d) 
o si el promedio de positivos resulta mayor que seis.
*/
#include <iostream>
using namespace std;

int main(){
    int numero;
    int cantCeros=0;
    int cantNPositivos=0;
    int sumNPositivos=0;
    int promedioPositivos;
    int cantNnegativos=0;
    for(int i=0; i<167;i++){
        cout<<"Ingrese numeros."<<endl;
        cin>>numero;
        if(numero==0){
            cantCeros++;
        }
        if(numero > 0){
            cantNPositivos++;
            sumNPositivos=sumNPositivos+numero;
        }
        if(numero < 0){
            cantNnegativos=cantNnegativos+numero;
        }
    }
    promedioPositivos=sumNPositivos/cantNPositivos;
    cout<<"a)--------------------------------"<<endl;
    cout<<"Cantidad de valores 0: "<<cantCeros<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Promedio de valores positivos: "<<promedioPositivos<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Sumatoria de valores negativos: "<<cantNnegativos<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"----------------------------------"<<endl;
    cantCeros=0;
    cantNPositivos=0;
    sumNPositivos=0;
    cantNnegativos=0;
    cout<<"Ingrese la cantidad de numeros que quiere ingresar."<<endl;
    cin>>numero;
    for(int i=0; i<numero;i++){
        cout<<"Ingrese los numeros."<<endl;
        cin>>numero;
        if(numero==0){
            cantCeros++;
        }
        if(numero > 0){
            cantNPositivos++;
            sumNPositivos=sumNPositivos+numero;
        }
        if(numero < 0){
            cantNnegativos=cantNnegativos+numero;
        }
    }
    promedioPositivos=sumNPositivos/cantNPositivos;
    cout<<"b)---------------------------------"<<endl;
    cout<<"Cantidad de valores 0: "<<cantCeros<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Promedio de valores positivos: "<<promedioPositivos<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Sumatoria de valores negativos: "<<cantNnegativos<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"----------------------------------"<<endl;

    return 0;
}