/*19.	Desarrolle un procedimiento que reciba el costo en pesos de un abono telefónico, 
la cantidad de minutos libres que incluye el abono, el cargo en pesos por minuto excedente 
y la cantidad de minutos utilizados por un abonado, 
retorne la cantidad de minutos excedidos 
y el monto en pesos a abonar (costo del abono mas minutos excedidos por el costo de minutos excedidos) 
mas el 21% del valor del IVA.
UTILICE FUNCIONES.
*/
#include <iostream>
using namespace std;

void abonoTelefonico(float, int, float, int);
float iva(float, int);

int main(){
    abonoTelefonico(12000, 500, 120, 600);
    return 0;
}

float iva(float costo, int iva){
    return (costo/100)*iva;
}

void abonoTelefonico(float costo, int cantMinLibres, float costoExcedente, int cantMinUtilizados){
    int cantMinExc;
    if(cantMinLibres < cantMinUtilizados){
        cantMinExc = cantMinUtilizados-cantMinLibres;
        cout<<"La cantidad de minutos excedidos es: "<<cantMinExc<<endl;
    } else {
        cout<<"No hay exceso de minutos"<<endl;
    }
    float costoTotal=iva((costo+(cantMinExc*costoExcedente)),21);
    cout<<"El monto a abonar es: $"<<costoTotal<<endl;
    
};