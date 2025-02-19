#include<iostream>
using namespace std;

struct TrabajoInvest{
    char titulo[50+1];
    int categorias[5];
    char correoResp[50+1];
    int id_evaluadores1[100];
    int id_evaluadores2[100];
    int id_evaluadores3[100];
    char resultado1[40+1];
    char resultado2[40+1];
    char resultado3[40+1];
}; 

struct Nodo{
    TrabajoInvest info;
    Nodo* sgte;
};

struct Evaluadores{
    int id_evaluador[100];
    char nombre[50+1];
};

Evaluadores evaluadores[100];