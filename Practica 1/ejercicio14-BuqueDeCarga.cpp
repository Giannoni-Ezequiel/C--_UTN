/*14.	Un buque de carga traslada 100 contenedores a tres diferentes puertos del país. 
Los puertos se identifican con los números 1, 2 y 3.
De cada contenedor que el buque traslade se registran los siguientes datos:
•Identificación del contenedor (entero)
•Peso del contenedor en kg (entero)
•Puerto de arribo(un valor de 1 a 3).
Se pide calcular e informar:
i. El peso total que el buque debe trasladar
ii. La identificación del contenedor de mayor peso
iii. La cantidad de contenedores que debe trasladar a cada puerto
*/
#include <iostream>
using namespace std;

int main(){
    int puerto;
    int id_contenedor=0;
    int peso;
    int pesoTotal=0;
    int elDeMayorPeso=0;
    int cantP1=0;
    int cantP2=0;
    int cantP3=0;
    cout<<"Indique numero de puerto (1-3) o cualquier otro numero para terminar"<<endl;
    cin>>puerto;
    while(((puerto<=3)&&(puerto>0)) || id_contenedor>=100){
        id_contenedor++;
        cout<<"Indique cuanto pesa"<<endl;
        cin>>peso;
        pesoTotal = pesoTotal + peso;
        if(peso>elDeMayorPeso){
            elDeMayorPeso = id_contenedor;
        }
        switch(puerto){
            case 1:
                cantP1++;
                break;
            case 2:
                cantP2++;
                break;
            case 3:
                cantP3++;
                break;
        }
        cout<<"Indique numero de puerto (1-3) o cualquier otro numero para terminar"<<endl;
        cin>>puerto; 
    }
    cout<<"i.----------------------------------------------"<<endl;
    cout<<"Peso total: "<<pesoTotal<<" kg."<<endl;
    cout<<"ii.----------------------------------------------"<<endl;
    cout<<"La identificacion del contenedor de mayor peso es: "<<id_contenedor<<endl;
    cout<<"iii.----------------------------------------------"<<endl;
    cout<<"Cantidad en puerto 1: "<<cantP1<<endl;
    cout<<"Cantidad en puerto 2: "<<cantP2<<endl;
    cout<<"Cantidad en puerto 3: "<<cantP3<<endl;
    cout<<"----------------------------------------------"<<endl;
    return 0;
}