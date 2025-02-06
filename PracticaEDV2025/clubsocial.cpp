#include<iostream>
using namespace std;
struct inscripciones{

};
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