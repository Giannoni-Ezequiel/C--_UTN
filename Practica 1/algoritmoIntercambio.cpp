#include <iostream>
using namespace std;
/*
  */
void intercambio(int medio,int mayor){
        int aux;
        aux = medio;
        mayor = medio;
        medio = aux;
    }

int main() {

    int mayor = 5 ,medio = 7, menor = 6;
    cout<< "+ Mayor" << mayor <<endl;
    cout<< "+ Medio" << medio <<endl;
    cout<< "+ Menor" << menor <<endl;
    cout<< "---Intercambio---" <<endl;
    if(medio>mayor) intercambio(medio,mayor);
    if(menor>mayor) intercambio(menor,mayor);
    if(menor>medio) intercambio(menor,medio);
    cout<< "+ Mayor" << mayor <<endl;
    cout<< "+ Medio" << medio <<endl;
    cout<< "+ Menor" << menor <<endl;
}   