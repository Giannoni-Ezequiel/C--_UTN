/*Dado un conjunto de Nombres y Fechas de nacimientos (AAAAMMDD), que finaliza con un Nombre= “FIN”, 
informar el nombre de la persona con mayor edad y el de la mas joven. 
Utilizar la función strcmp (<cstring>) para evaluar fin de datos.*/
#include <iostream>
#include <cstring>
using namespace std;

struct Fecha {
    int anio;
    int mes;
    int dia;
};
struct Persona {
    char Nombre[25];
    Fecha fecha;
};
void inicializar();
int bb();
int main(){

    char A[10];
    char B[14];
    //strcmp(B,A); // B < A -> -1    B = A -> 0   B > A -> 1
    cout<<"Ingrese un Nombre o FIN para cortar: ";
    cin>> A;
    int fecha;
    int mayor_edad=-1;
	int menor_edad=-1;
	char nombre_mayor[50+1];
	char nombre_joven[50+1];
	char nombre[50+1];
    cout << "Ingrese una fecha de nacimiento(AAAAMMDD)" << endl;
    cin >> fecha;

    int anio = fecha / 10000;
    int mes = (fecha / 100)%100;
    int dia = fecha % 100;
    
    while(strcmp(A,"FIN") != 0){
        cout<<"Ingrese un Nombre o FIN para cortar: ";
        cin>> A;
        cout << "Ingrese una fecha de nacimiento(AAAAMMDD)" << endl;
        cin >> fecha;
    }
    //cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    return 0;

}

void inicializar();
int bb();