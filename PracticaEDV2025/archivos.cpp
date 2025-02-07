#include <iostream>
#include <stdio.h>
using namespace std;
struct tipoRegistro{
    int campo1;
    int campo2;
};

int main(){
    FILE * f = fopen("Miarchivo.dat", "wb+");

    tipoRegistro r;
    int i;

    r.campo1 = 1;
    r.campo2 = 10;

    fwrite(&r,sizeof(r),1,f);

    r.campo1 = 2;
    r.campo2 = 20;

    fwrite(&r,sizeof(r),1,f);
    r.campo1 = 3;
    r.campo2 = 30;

    fwrite(&r,sizeof(r),1,f);
    r.campo1 = 4;
    r.campo2 = 40;

    fwrite(&r,sizeof(r),1,f);

    fseek(f, 0, SEEK_SET);

    fread(&r,sizeof(r),1,f);

    while(!feof(f)){
        cout<<r.campo1<<endl;
        cout<<r.campo2<<endl;
        fread(&r,sizeof(r),1,f);
    }
    fclose(f);
    return 0;
}