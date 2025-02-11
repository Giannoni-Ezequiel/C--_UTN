/* 3) Dado un vector acerca del stock de un deposito,
que contiene el codigo de producto y la cantidad de un
a- Cual es el producto que mas unidades tiene
b- Cual es el producto que menos unidades tiene
c- Indicar la cantidad total de productos almacenados segun el vector*/
#include<iostream>
using namespace std;

struct producto{
    int codProducto;
    int cantProductos;
};

void masunidades(producto vec[],int len);
void menosunidades(producto vec[], int len);
void sumatoria(producto vec[], int len);

int main(){
    producto vec[150];
    int len;

    masunidades(vec,len);
    menosunidades(vec,len);
    sumatoria(vec,len);

    return 0;
}

void masunidades(producto vec[],int len){
    int pos=0;
    int max = vec[0].cantProductos;

    for(int i=1;i<len;i++){
        if(vec[i].cantProductos>max){
            pos=i;
            max=vec[i].cantProductos;
        }
    }
    cout<<"El producto: "<<vec[pos].codProducto<<" tiene el maximo de unidades con un total de: "<<max<<endl;
}

void menosunidades(producto vec[],int len){
    int pos=0;
    int min = vec[0].cantProductos;

    for(int i=1;i<len;i++){
        if(vec[i].cantProductos<min){
            pos=i;
            min=vec[i].cantProductos;
        }
    }
    cout<<"El producto: "<<vec[pos].codProducto<<" tiene el minimo de unidades con un total de: "<<min<<endl;
}

void sumatoria(producto vec[], int len){
    int sum=0;

    for(int i=0; i<len; i++){
        sum = sum + vec[i].cantProductos;
    }
    cout<<"La suma de los productos es: "<<sum<<endl;

}