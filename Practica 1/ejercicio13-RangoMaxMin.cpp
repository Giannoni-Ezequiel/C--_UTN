/*13.	Dado un conjunto de valores, que finaliza con un valor nulo, determinar e imprimir (si hubo valores):
•El valor máximo negativo
•El valor mínimo positivo
•El valor mínimo dentro del rango -17.3 y 26.9
•El promedio de todos los valores.
*/
#include <iostream>
using namespace std;

int main(){
    int valor;
    int valorMaxNegativo=0;
    int valorMinimoPositivo;
    int valorMinimoRango;
    float promedio;
    int contador=0;
    float sumador=0;
    cout<<"Ingrese un valor o 0 para cortar: "<<endl;
    cin>>valor;
    while(valor!=0){
        
        if(valor<0 && valor<valorMaxNegativo){
            valorMaxNegativo = valor;
        } else if(valor > 0 && valor < valorMinimoPositivo){
            valorMinimoPositivo = valor;
        } else if(valor >= -17 && valor < 26){
                if(valor < valorMinimoRango){
            valorMinimoRango = valor;
        }}
        contador++;
        sumador = sumador + valor;
        cout<<"Ingrese un valor o 0 para cortar: "<<endl;
        cin>>valor;
    }
    cout<<"El valor maximo negativo: "<<valorMaxNegativo<<endl;
    cout<<"El valor minimo positivo: "<<valorMinimoPositivo<<endl;
    cout<<"El valor minimo dentro del rango -17.3 y 26.9: "<<valorMinimoRango<<endl;
    promedio=sumador/contador;
    cout<<"El promedio de todos los valores: "<<promedio<<endl;
    return 0;
}

