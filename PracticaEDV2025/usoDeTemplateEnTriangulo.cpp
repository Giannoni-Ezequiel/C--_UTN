//Rectangulo

#include <iostream>

using namespace std;

//Repaso de funciones

template <typename T>void rectangulo(T lado1, T lado2, T& superficie, T& perimetro){
	
	superficie = lado1*lado2;
	perimetro = 2*lado1 + 2*lado2;
	
}

int main(){
	
	int a = 5;
	int b = 4;
	int sup;
	int pm;
	float c = 3.5;
	float d = 5.4;
	float sup2;
	float pm2;
	
	//Invocamos la funcion nombre_de_la funcion (argumentos)
	//Invocar la funcion con tipos de datos enteros
	
	rectangulo<int>(a, b, sup, pm);
	cout << "La superficie es " << sup << endl;
	cout << "El perimetro es " << pm << endl;	
	
	//Invocar la funcion con tipos de datos float
	rectangulo<float>(c, d, sup2, pm2);
	cout << "La superficie es " << sup2 << endl;
	cout << "El perimetro es " << pm2 << endl;
	
	return 0;
}