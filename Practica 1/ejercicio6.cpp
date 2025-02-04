#include <iostream>
using namespace std;

int main(){
    int edad;
    cout << "Ingrese su edad, o 0 para terminar" << endl;
    cin >> edad;
    while(edad>0){
    if(edad <= 12) {
        cout << "menor" << endl;
        }
        else if(edad >=13 && edad <= 18) {
            cout << "cadete" << endl;
            }
        else if(edad > 18 && edad <= 26) {
            cout << "juvenil" << endl;
            }
        else   {cout << "mayor\n";};
    cout << "Ingrese su edad, o 0 para terminar, please!" << endl;
    cin >> edad;
    }
    return 0;
}