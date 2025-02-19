#include<iostream>
using namespace std;

struct Buzo{
    char operadora[20+1];
    int dni;
    int edad;
    int fechaDeSalida; //dia mes anio
    int lvlDificultad;
    int profundidad;
    int tiempoBuceo;
    int horaInicio;

};

struct Nodo{
    Buzo info;
    Nodo* sgte;
};