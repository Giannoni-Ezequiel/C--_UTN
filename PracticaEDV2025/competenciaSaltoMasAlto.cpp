//Ejercicio de Atletas

#include <iostream>

using namespace std;

//Desarrollar una funcion que reciba 3 valores enteros y retorne el mayor de los 3
/*
En una competencia de salto en alto, se dispone de los 3 valores de los participantes
de la competencia. La cantidad de atletas son 5.
Determinar el nombre del ganador.
*/
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

int main(){
	
	int id_atleta;
	int salto1;
	int salto2;
	int salto3;
	int mejorMarca;
	int saltoGanador = 0;
	int id_ganador;
	int i;
	
	for(i=0; i<5; i++){
		
		cout << "Ingrese el ID del atleta: ";
		cin>>id_atleta;
		
		cout << "Ingrese primer salto: ";
		cin>>salto1;
		
		cout << "Ingrese segundo salto: ";
		cin>>salto2;
		
		cout << "Ingrese tercer salto: ";
		cin>>salto3;
		
		mejorMarca = mayorDeTres(salto1, salto2, salto3);
		
		if(mejorMarca > saltoGanador){
			saltoGanador = mejorMarca;
			id_ganador = id_atleta;
		}
		
	}
	
	cout << "El ganador es: " << id_ganador;
	
	return 0;
}