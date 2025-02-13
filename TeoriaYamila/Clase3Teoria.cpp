#include <iostream>
using namespace std;

//encabezados de las funciones y procedimientos
int Doble (int numero); //tipodatoretorno nombre de funcion (parametro)

int main() {
    int x;
    int Rdo;

    cout<<"ingrese un numero"<<endl;
    cin>>x;
    Rdo = Doble(x);
    cout<<"el resultado es: "<<Rdo<<endl; 
    return 0;
}

//Desarrollo de las funciones y procedimientos
int Doble(int numero) {
    return numero*2; 
}

//Ahora lo voy a resolver de otra manera, a travez de un procedimiento

//void MostrarDoble (int num);

//El main se deja igual pero cambio la funcion ya que es otra 

// void MostrarDoble (int num){
//int aux;
//aux=num*2;
//cout<<"el doble es: "<<aux<<endl;
//}
