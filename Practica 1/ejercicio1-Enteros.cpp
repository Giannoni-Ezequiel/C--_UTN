#include <iostream>
using namespace std;
/*Dados dos valores enteros A y B, informar
  la suma, la resta y el producto.
  */
int main() {

    int A,B;
    char C=0;
    cout<<C<<endl;
    int suma, resta, producto;
    cout << "Ingrese un valor enteero" << endl;
    cin >> A;
    cout << "Ingrese otro valor entero" << endl;
    cin >> B;
    suma = A + B;
    cout << "Sumaaa de ambos: " << suma << endl;
    resta = A - B;
    cout << "Resta de ambos: " << resta << endl;
    producto = A * B;
    cout << "Producto de ambos: " << producto << endl;
}