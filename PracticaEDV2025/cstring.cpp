#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char nombre[50];
    char nombre_copia[50];
    char nombre2[50];
    cout<<"Ingrese primer nombre: "<<endl;
    cin>>nombre;
    cout<<"Ingrese segundo nombre: "<<endl;
    cin>>nombre2;
    cout<<"Valor del primer nombre: "<<nombre<<endl;
    cout<<"Valor del segundo nombre: "<<nombre2<<endl;
    strcpy(nombre_copia, nombre);
    cout<<"Valor strcpy primer nombre en un tercer nombre: "<<nombre_copia<<endl;
    strcpy(nombre, nombre2);
    cout<<"Valor strcpy segundo nombre en primer nombre: "<<nombre<<endl;
    /*strcpy(nombre2, nombre);
    cout<<"Valor guardado en nombre: "<<nombre2<<endl;*/
    char A[10];
    char B[12];
    char C[10];
    strcpy(nombre_copia, nombre);
    //strcmp(B,A); // B < A -> -1    B = A -> 0   B > A -> 1
    cout<<"Ingrese los nombres pedidos para la comprension de strcmp. "<<endl;
    cout<<"Ingrese el nombre Aldo: "<<endl;
    cin>>A;
    cout<<"Ingrese el nombre Josefa: "<<endl;
    cin>>B;
    cout<<"Ingrese el nombre Pepo: "<<endl;
    cin>>C;
    cout<<"Al hacer strcmp(Josefa,Aldo), obtengo que Josefa tiene 6 caracteres por lo tanto es mayor, ergo devuelvo: "<<strcmp(B,A)<<endl;
    cout<<"Al hacer strcmp(A,B), obtengo que Aldo tiene 4 caracteres por lo tanto es menor, ergo devuelvo: "<<strcmp(A,B)<<endl;
    cout<<"Al hacer strcmp(A,C), obtengo que Aldo tiene 4 caracteres y Pepo tambien, ergo devuelvo: "<<strcmp(A,C)<<endl;
    
    return 0;

}