/*18.	Desarrollar la función
string Tendencia(int A, int B)que dados dos valores A y B, 
retorne una cadena de acuerdo al siguiente cuadro:
    B - A < 0        |  Decreciente   |  B - A < 2% de A  |  Estable
    B - A < 5% de A  |  Leve ascenso  |  Resto            |  En ascenso
*/
#include <iostream>
using namespace std;

string Tendencia(int A, int B);

int main(){
    Tendencia(1,2);
    return 0;
}

string Tendencia(int A, int B){
    if(B - A < 0 ){
        return "Decreciente";
    }
    if(B - A < (A/100)*2){
        return "Estable";
    }
    if(B - A < (A/100)*5){
        return "Leve ascenso";
    } else {
        return "En ascenso";
    }
}