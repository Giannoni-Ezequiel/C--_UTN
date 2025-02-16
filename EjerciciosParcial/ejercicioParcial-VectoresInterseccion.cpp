//Desarrolle los sigtes procedimientos:
//a-Dados 2 vectores de enteros(A[10],B[10]) genere la interseccion de ambos en C[10].
#include<iostream>
using namespace std;

void interseccionVectoresAB(int vecA[], int vecB[], int vecC[], int lenA, int lenB, int &lenC){
    for(int i=0; i<lenA; i++){
        for(int j=0; j<lenB; j++){
            if(vecA[i]==vecB[i]){ 
              vecC[lenC]=vecA[i];
              lenC++;
            }
        }
    }
}