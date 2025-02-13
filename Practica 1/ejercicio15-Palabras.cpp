/*15.	Dada una serie de caracteres que conforman una oración, 
donde cada palabra esta separada de la siguiente por un carácter blanco 
y la oración finaliza con un punto. Se pide informar:
cantidad de veces que apareció cada vocal
cantidad de palabras que contiene la oración
cantidad de letras que posee la palabra mas larga.
*/
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char palabra[50+1];
    char oracion[100+1];
    int longitud;
    int contVocalA=0;
    int contVocalE=0;
    int contVocalI=0;
    int contVocalO=0;
    int contVocalU=0;
    int contPalabras=0;
    char PalabraMasLarga[50+1];
    int palabraMasLarga;
    cout<<"Ingrese una palabra"<<endl;
    cin>>palabra;
    longitud = strlen(palabra);
    cout<<longitud<<endl;
    while(longitud>1){
        strcat(oracion,palabra);
        strcat(oracion," ");// acepta solo strings este no lo acepta ->' '
        contPalabras++;
        if(strlen(palabra)>strlen(PalabraMasLarga)){
            strcpy(PalabraMasLarga,palabra);
        }
        cout<<"Ingrese una palabra o 0 para terminar"<<endl;
        cin>>palabra;
        longitud = strlen(palabra);
    }
    longitud = strlen(oracion);
    for(int i=0;i<longitud;i++){
        char letra;
        letra = oracion[i];
        switch(letra){
            case 'a':
                contVocalA++;
                break;
            case 'e':
                contVocalE++;
                break;
            case 'i':
                contVocalI++;
                break;
            case 'o':
                contVocalO++;
                break;
            case 'u':
                contVocalU++;
                break;
        }
    }
    
    strcat(oracion,".");
    palabraMasLarga=strlen(PalabraMasLarga);
    cout<<"La oracion es: "<<oracion<<endl;
    cout<<"Cantidad de la vocal a: "<<contVocalA<<endl;
    cout<<"Cantidad de la vocal e: "<<contVocalE<<endl;
    cout<<"Cantidad de la vocal i: "<<contVocalI<<endl;
    cout<<"Cantidad de la vocal o: "<<contVocalO<<endl;
    cout<<"Cantidad de la vocal u: "<<contVocalU<<endl;
    cout<<"Cantidad de palabras: "<<contPalabras<<endl;
    cout<<"Cantidad de letras de la palabra mas larga es: "<<palabraMasLarga<<endl;
    
    return 0;
}