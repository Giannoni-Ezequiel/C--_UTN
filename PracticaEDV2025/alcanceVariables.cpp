#include <iostream>
using namespace std;

int i = 1;
int Mifuncion();
int main(){
    int i = 2;
    for(int i=3; i<5; i++)
    cout << i << endl;
    cout << i << endl;
    Mifuncion();
    return 0;  
}
int Mifuncion(){
    cout << i << endl;
    return 0;
}