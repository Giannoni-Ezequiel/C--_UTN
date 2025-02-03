//Rectangulo con Struct

#include <iostream>

using namespace std;

struct tipo_rectangulo{
	int perimetro;
	int superficie;
};

tipo_rectangulo Rectangulo(int lado1, int lado2){
	
	tipo_rectangulo r;
	r.perimetro = 2*lado1 + 2*lado2;
	r.superficie = lado1 * lado2;
	
	return r;
	
}

int main(){
	
	int l1 = 5;
	int l2 = 4;
	tipo_rectangulo r = Rectangulo(l1, l2);
	
	cout << "La superficie es " << r.superficie << endl;
	cout << "El perimetro es " << r.perimetro << endl;
	
	return 0;
}