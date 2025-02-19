/*
 Cada localidad se representa con un número entre 1 y 100, y las distancias y rutas con enteros positivos. Usted es 
responsable de realizar las consultas sobre los datos que ya están en memoria.


1. Codifique todas las declaraciones para el arreglo Rutas. 
2. Codifique el prototipo (no la definición) de la función InicializarM que inicializa M con los datos necesarios para resolver las 
consultas. Decida los parámetros y justifique su decisión. 
3. Diseñe o codifique la función MostrarRuta que dado tres parámetros localidad1, localidad2, y M, muestra por cout (la salida 
estándar) el identificador de la ruta y la distancia que une localidad1 con localidad2. Si no hay ruta, muestra un mensaje apropiado.  
4. Diseñe o codifique la función MostrarVecinas. Dada dos parámetros localidad, y M, muestra por cout las localidades 
con las que localidad tiene ruta directa. Si no hay vecinas, 
muestra un mensaje apropiado. 
*/

#include<iostream>
using namespace std;

struct Ruta{
    int localidad1[100];
    int localidad2[100];
    int distancia;
    int ruta;
};

Ruta Rutas[];

int M[100][100];

