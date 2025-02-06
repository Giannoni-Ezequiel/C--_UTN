#include<iostream>
using namespace std;

int main(){

    struct Persona{
        string nombre;
        int tiempo;
    };
    string elNombreMasVeloz;
    int distancia = 1500;
    int velocidad, velocidadAux = 0;
    Persona persona;
    cout << "Ingrese su nombre: "<< endl;
    cin >> persona.nombre;
    cout << "Ingrese el tiempo que tardo en recorrer la carrera: "<< endl;
    cin >> persona.tiempo;

    velocidad = distancia/persona.tiempo;
    if (velocidadAux>velocidad)
    {
        velocidad = velocidadAux;
        elNombreMasVeloz = persona.nombre;
    }
    cout << "El nombre mas Veloz es: "<< elNombreMasVeloz << endl;
    return 0;
}