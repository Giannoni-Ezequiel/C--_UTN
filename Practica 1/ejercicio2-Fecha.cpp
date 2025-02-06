#include <iostream>
using namespace std;
/*Dado un numero entero de la forma (AAAAMMDD), que representa
  una fecha valida. Mostrar el dia, mes y anio que representa.
  */
int main() {

    int fecha;
    cout << "Ingrese una fecha (AAAAMMDD)" << endl;
    cin >> fecha;

    int anio = fecha / 10000;
    int mes = (fecha / 100)%100;
    int dia = fecha % 100;
   
    cout << "Anio: " << anio << endl;
    cout << "Mes: " << mes << endl;
    cout << "Dia: " << dia << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
}