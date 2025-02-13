/*
1.	Dado un número N (<30), genere e informe un vector VEC de N elementos 
que contenga los primeros N números naturales pares.
*/

#include <iostream>
using namespace std;



int main(){
    int n;
    cout<<"Ingrese un valor < 30"<<endl;
    cin>>n;
    int vec[n]={0};
    int len=0;
    for(int i=0;i<n;i++){
        if(i%2==0&&i>0){
            vec[len]=i;
            len++;
        }
    }
    cout<<"-----------Numeros pares-------------"<<endl;
    for(int i=0;i<len;i++){
        cout<<vec[i]<<endl;
    }
    return 0;

}