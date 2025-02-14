/*17.	Desarrolle la función
float CalcularPorcentajeDiferencia(int A ,int B) que recibe dos valores 
y retorne el siguiente calculo:
(B-A) *100 / (A+B)
*/
#include <iostream>
using namespace std;

float CalcularPorcentajeDiferencia(int A ,int B);

int main(){
    CalcularPorcentajeDiferencia(20,10);
    return 0;
}

float CalcularPorcentajeDiferencia(int A ,int B){
    return (B-A) *100 / (A+B);
}