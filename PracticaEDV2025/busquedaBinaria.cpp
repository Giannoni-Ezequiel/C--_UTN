//reduce la cantidad de comparacion que debo hacer para buscar un valor especifico
#include <iostream>
using namespace std;
struct Alumno{
    string nombre;
    int id;
};
int bbs(Alumno v[],int buscado,int& primero,int N);
int main(){
//buscar el medio, nuevo medio...
//cuando se corta? si lo encuentra, y si no esta? chequear cuando la posicion final es menor que la posicion inicial.
// tambien la ultima posicion inicial me dice en que lugar deberia ponerlo.
//si quiero, en una funcion devolver mas de un valor, utilizar variables por referencia.
    int N = 5, primero = 0;
    Alumno alumnos[5] = {{"Juan", 5},{"Lucas", 12},{"Maria", 22}, {"Tomas", 36}, {"Jorge", 40}};

    int resultado = bbs(alumnos, 22, primero, N);
    if(resultado != -1){
        cout<<"Se encontro al alumno: "<<alumnos[resultado].nombre <<"\nen la posicion: "<<primero<<endl;
    }else{
        cout<<"No se encontro, podria ser agregado en la posicion: "<<primero;
    };

    return 0;
}

int bb(int v[],int buscado,int& primero,int N){
    primero=0;
    int ultimo=N-1; //posicion valida
    int medio;
    while(primero<=ultimo){
        medio=(primero+ultimo)/2; //posicion del medio
        if(v[medio]==buscado){
            return medio;
        }
        if(v[medio]>buscado){
            ultimo = medio - 1;
        }
        else {
            primero = medio + 1;
        }
    }
    return -1;
}

int bbs(Alumno v[],int buscado,int& primero,int N){
    primero=0;
    int ultimo=N-1; //posicion valida
    int medio;
    while(primero<=ultimo){
        medio=(primero+ultimo)/2; //posicion del medio
        if(v[medio].id==buscado){
            return medio;
        }
        if(v[medio].id>buscado){
            ultimo = medio - 1;
        }
        else {
            primero = medio + 1;
        }
    }
    return -1;
}

