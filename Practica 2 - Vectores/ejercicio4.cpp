/*
4.	Dado un número N (<25), y dos vectores A y B de N elementos que contenga
valores reales
a) genere e informe un tercer vector C intercalando los valores de posición impar de A 
    y los valores de posición par de B.
b) genere e informe un tercer vector D donde cada elemento contenga un valor cero si
los elementos de una misma posición de A y B son iguales, o un valor uno si no lo
son.

*/
#include <iostream>
using namespace std;

int main(){
    int vecA[10]={1,0,2,3,4,1,2,3,4,5};
    int lenA=0;
    int vecB[10]={2,3,3,2,5,6,7,38,4,5};
    int lenB=0;
    int vecC[]={0};
    int lenC=0;
    int vecD[]={0};
    int lenD=0;
    for(int i=0;i<20;i++){
        if(lenA%2==1){
            vecC[lenC] = vecA[lenA];
            lenC++;
        }
        if(lenB%2==0){
            vecC[lenC] = vecB[lenB];
            lenC++;
        }
        
    }
    for(int i=0;i<lenC;i++){
        cout<<"Vector C"<<endl;
        cout<<vecC[i]<<endl;
    }
    for(int i=0;i<20;i++){
        if(vecA[i]==vecB[i]){
            vecD[lenD] = 0;
            lenD++;
        } else {
            vecD[lenD] = 1;
            lenD++;
        }
    }
    for(int i=0;i<lenD;i++){
        cout<<"Vector D"<<endl;
        cout<<vecD[i]<<endl;
    }

    return 0;
}