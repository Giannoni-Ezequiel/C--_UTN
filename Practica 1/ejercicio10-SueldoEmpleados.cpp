/*10.	Se ingresa un conjunto de valores float, cada uno de los cuales representan el sueldo de un empleado, 
excepto el ultimo valor que es cero e indica el fin del conjunto.
 Se pide desarrollar un programa que determine e informe:
•Cuantos empleados ganan menos $ 1.520.
•Cuantos ganan $1.520 o mas pero menos de $2.780.
•Cuantos ganan $2.780 o mas pero menos de $5.999.
•Cuantos ganan $5.999 o mas.
*//**/
#include <iostream>
#include <vector>
using namespace std;

struct Empleado{
    float sueldo;
};
void sueldoEmpleados(){
    vector<Empleado> empleados;
    float sueldo;
    int contador1 = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
    cout << "Ingrese el sueldo de sus empleados. Para finalizar y ver la cantidad de empleados que ganan det. sueldos precione 0" << endl;
    cin >> sueldo;
    while (sueldo != 0){
        Empleado emp;
        emp.sueldo = sueldo;
        empleados.push_back(emp);
        cin >> sueldo;
    }
    for (int i = 0; i < empleados.size(); i++){
        if (empleados[i].sueldo < 1520){
            contador1++;
        } else if (empleados[i].sueldo >= 1520 && empleados[i].sueldo < 2780){
            contador2++;
        } else if (empleados[i].sueldo >= 2780 && empleados[i].sueldo < 5999){
            contador3++;
        } else if (empleados[i].sueldo >= 5999){
            contador4++;
        }
    }
    cout << "Cantidad de empleados que ganan menos de $1520: " << contador1 << endl;
    cout << "Cantidad de empleados que ganan entre $1520 y $2780: " << contador2 << endl;
    cout << "Cantidad de empleados que ganan entre $2780 y $5999: " << contador3 << endl;
    cout << "Cantidad de empleados que ganan mas de $5999: " << contador4 << endl;
}
int main(){
    sueldoEmpleados();
return 0;
}

