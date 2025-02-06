#include<iostream>
using namespace std;
/*
    Realizar la suma de todos los números pares entre 2 y 10000 
*/
int main(){
    int nroPar;
    cout << "Ingrese un numero" << endl;
    cin >> nroPar;
    if(nroPar%2 == 0){
        cout <<"El numero "<< nroPar <<" es Par." << endl;
    } else {
        cout <<"El numero "<< nroPar <<" es Impar." << endl;
    }
    
    return 0;
}