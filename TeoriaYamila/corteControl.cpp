#include<iostream>
#include<stdio.h>
using namespace std;

struct Infraccion{
    int dominio;
    int tipo;
    int importe;
};

int main(){
    FILE * Infracc;
    Infracc = fopen("multas.dat","rb");
    
    Infraccion raux;
    int anterior; //voy a almacenar las claves
    int sumaInfraccion;
    fread(&raux,sizeof(struct Infraccion),1,Infracc);
    while(!feof(Infracc)){
        anterior=raux.dominio; //guardo la clave q se repite
        sumaInfraccion = 0; // sumo aca 

        while(!feof(Infracc)&&(anterior==raux.dominio)) //corte y control
        {
            sumaInfraccion = sumaInfraccion+raux.importe;
            fread(&raux,sizeof(struct Infraccion),1,Infracc);
        }
        cout<<"Dominio "<<anterior<<" tiene un total de multas de: "<<sumaInfraccion<<endl;
    }
    fclose(Infracc);
    return 0;
}