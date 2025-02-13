#include<iostream>
using namespace std;

int main(){
    /*int *p,*y;
    int w;
    p=new int();
    w=85;
    *p=w;
    y=p;
    w++;
    cout<<*y<<endl;*/
    int *p;
    p= new int[5];
    p[0]=67;
    p[1]=70;
    p[2]=15;
    p[3]=81;
    p[4]=23;
    cout<<*(p+2)<<endl;
    return 0;
}