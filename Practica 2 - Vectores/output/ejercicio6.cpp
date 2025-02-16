/*
6.	En un club social se abrieron las inscripciones de los socios distintos deportes,
codificados de 1 a 20, y de cada inscripción se conoce número de socio y código de deporte.
Las inscripciones finalizan con un número de socio igual a 0.
Se pide informar:
•la cantidad de inscriptos en cada deporte
•el código de deporte con la mayor cantidad de inscriptos

*/


#include <iostream>
using namespace std;

int main(){
    int numSoc;
    int codDep;
    int deportes[20]={0};
    int mayor=0;
    cout<<"Ingrese el numero de socio: ";
    cin>> numSoc;
    while(numSoc != 0){
        cout << "Ingreso el codigo del deporte: ";
        cin>> codDep;
        deportes[codDep - 1]++;
        cout << "Ingrese el numero de socio: ";
        cin >> numSoc;
    }
    for(int i=0; i<20; i++){
        if (mayor < deportes[i]) mayor = deportes[i];
        
    }
    for(int i=0; i<20; i++){
        cout<<"La cantidad de inscriptos en el deporte: "<<i+1<<" es: "<<deportes[i];
        
    }
        cout<<"El deporte con mas inscriptos fue: " << mayor;
    return 0;
}