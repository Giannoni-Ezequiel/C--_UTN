#include<iostream>
using namespace std;

bool impar(int anio);

int main(){
    bool aux;

    aux=impar(5);
    cout<<"0 par y 1 impar: "<<aux<<endl;

    return 0;
}
/*bool impar(int anio){
    if(anio%2!=0){
        return true;
    }else {return false;}
}*/

bool impar (int anio){
    return anio%2;
}