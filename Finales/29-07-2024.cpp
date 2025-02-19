#include<iostream>
using namespace std;

struct Hisopados{
   
    int centroTesteo;
    
    
    int cantDosis;
    int fechaContac;
    bool resultado;
};

struct Paciente{
    int dni;
    char nomyApe[30+1];
    int fechaNac;
    char domicilio[50+1];
};

struct NodoA{
    Paciente info;
    NodoA* sgte;
};

struct Test{
    int tipoTest;
    NodoA* Pacientes;
};
struct NodoB{
    Test info;
    NodoB* sgte;
};

struct Resultado{
    int negativo;
    NodoA* Pacientes;
    int positivo;
    NodoB* Tests;
};

struct ObraSocial{
    char obraSocial[50+1];
    Resultado VecResultado;
};

struct NodoC{
    ObraSocial info;
    NodoC* sgte;
};