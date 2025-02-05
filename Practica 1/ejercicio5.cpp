#include <iostream>
using namespace std;

//1.Desarrollar una funcion que reciba 3 valores de tipo entero y determine si forma un triangulo o no.
//2.Desarrollar una funcion que reciba 3 valores de tipo entero que forman un triangulo y determine si es equilatero, isosceles o escaleno.
//3.Hacer un programa que ingrese un conjunto de terna de valores que informe cuantas ternas no forman triangulo, cuantas formas equilateros, cuantas isosceles y cuantas escalenos.
//Prototipo de las funciones

int esTriangulo (int a, int b, int c){ // los 3 parametros estan pasados por valor
    //como pre.condicion, establecemos que los valores son mayores a 0
    if (a<(b+c) && b<(a+c) && c<(a+b))
        return 1; // Si la expresion es verdadera, termina la funcion retornado 1
    return 0; // Si la expresion es falsa, no se ejecuta la accion anterior y retorna 0
}

int tipoTriangulo (int a, int b, int c){ //pre-condicion: tenemos la certeza de que los 3 valores forman un triangulo
        if ( a==b && a==c)
            return 1;
        if (a==b || a==c || b==c)
            return 2;
        return 3;
}

int main (){
    int x;
    int y;
    int z;
    int i;
    int j;
    int noTriangulo =0;
    int equilatero =0;
    int isosceles =0;
    int escaleno =0;

    // Ingresar los valores
    cout << "Ingrese un primer numero entero:";
    cin >> x;
    cout << "Ingrese un segundo numero entero: ";
    cin >> y;
    cout << "Ingrese un tercer numero entero: ";
    cin >> z;

    while (x>0 && y>0 && z>0){
        //invocar las funciones
        i = esTriangulo (x,y,z); //se invoca a la funcion con los argumentos ingresados
        if (i==0){
            noTriangulo ++;
        } else {
            j = tipoTriangulo (x,y,z);
            if (j==1) equilatero ++;
            if (j==2) isosceles ++;
            if (j==3) escaleno ++;
        }
        cout << "Ingrese un primer numero entero:";
        cin >> x;
        cout << "Ingrese un segundo numero entero: ";
        cin >> y;
        cout << "Ingrese un tercer numero entero: ";
        cin >> z;
    }
        cout << "Estos numeros se llamaran ternas y se tomaron para formar y clasificar un triangulo."<< endl;
        cout << "Las ternas que no forman triangulo son: " << noTriangulo << endl;
        cout << "Las ternas que forman equilateros son: " << equilatero << endl;
        cout << "Las ternas que forman isosceles son: " << isosceles << endl;
        cout << "Las ternas que forman escalenos son: " << escaleno << endl;

    return 0;
}