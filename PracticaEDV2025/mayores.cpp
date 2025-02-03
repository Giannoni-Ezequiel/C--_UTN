//Ejercicio de Mayores

#include <iostream>

using namespace std;

//Desarrollar una funcion que dados 2 valores distintos, retorne el mayor

int mayorDeDos(int a, int b){
	
	if (a > b){
		return a;
	}
	
	else{
		return b;
	}
	/*
	return a > b? a: b;
	*/
}

//Desarrollar una funcion que reciba 3 valores enteros y que retorne el mayor

int mayorDeTres(int a, int b, int c){
	
	int mayor;
	if (a > b){
		mayor = a;
	}
	
	else{
		mayor = b;
	}
	
	if(c > mayor){
		mayor = c;
	}
	
	return mayor;
	
}

//Desarrollar una funcion que informe el maximo de 10 valores

/*
Existen varias formas de buscar un maximo o un minimo, lo que se debe hacer es tener
un identificador para las distintas lecturas y un identificador para el maximo.
El identificador del maximo debe ser inicializado, esto puede ser con un valor arbitrario
o con la primera de las lecturas. Luego, con cada una de las lecturas, si el valor leido
es mayor que el maximo, desplaza el maximo y tenemos uno nuevo.
*/


int maximoDeDiez(){
	
	//Ingresamos 10 valores mayores a 0, por lo cual al maximo, le vamos a asignar un valor
	//arbitrario chico, como por ejemplo 0
	
	int maximo = 0;
	int valor;
	int i;
	
	for (i=0; i<10; i++){
		cout << "Ingrese un valor mayor a 0: ";
		cin>>valor;
		
		if (valor > maximo){
			maximo = valor;
		}
	}
	
	return maximo;
	
}

int maximoDeDiez(){
	
	//Ingresamos 10 valores enteros, por lo cual al maximo, le vamos a asignar  
	//la primera de las lecturas. 
	
	int maximo;
	int valor;
	int i;
	
	cout << "Ingrese un valor: ";
	cin>>valor;
	maximo = valor;
	
	for (i=0; i<9; i++){
		
		cout << "Ingrese un valor: ";
		cin>>valor;
		
		if (valor > maximo){
			maximo = valor;
		}
	}
	
	return maximo;
	
}

int maximo(){
	
	//Ingresamos 10 valores enteros, por lo cual al maximo, le vamos a asignar  
	//la primera de las lecturas. 
	
	int maximo;
	int valor;
	int i;
	
	for (i=0; i<10; i++){
		
		cout << "Ingrese un valor: ";
		cin>>valor;
		
		if (i == 0 || valor > maximo){
			maximo = valor;
		}
	}
	
	return maximo;
	
}

//Desarrollar una funcion que dado un conjunto de valores distintos de 0,
//informe cual es el maximo



int main(){
	
	int valor;
	int maximo;
	
	cout << "Ingrese un valor: ";
	cin>>valor;
	
	maximo = valor;
	
	while(valor != 0){
		
		if(valor > maximo){
			maximo = valor;
		}
		
		cout << "Ingrese un valor: ";
		cin>>valor;
		
	}
	
	if (maximo == 0){
		cout << "No hay valores para evaluar";
	}
	else{
		cout << "El maximo es: " << maximo;
	}
	
	return 0;
}