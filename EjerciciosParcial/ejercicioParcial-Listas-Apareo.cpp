#include<iostream>
using namespace std;

struct Burger{
    int codigo;
    int cant;
    char tipo;
};

struct Panes{
    int codigo;
    int cant;
};

int main(){
    FILE*agos=fopen("BurgerFastAgosto.dat","rb");
    FILE*sept=fopen("BurgerFsSeptiembre","rb");
    FILE*completo=fopen("BurgerFast","wb");
    FILE*panes=fopen("Pan.dat","wb");

    Burger septiembre, agosto;
    Panes arch;
    fread(&septiembre,sizeof(struct Burger),1,sept);
    fread(&agosto,sizeof(struct Burger),1,agos);
    while(!feof(agos)&&!feof(sept)){
        if(septiembre.codigo > septiembre.codigo){
            if(septiembre.tipo == 'p'){
                arch.codigo = septiembre.codigo;
                arch.codigo = septiembre.cant;
                fwrite(&arch,sizeof(struct Burger),1,panes);
            }
            fwrite(&septiembre,sizeof(struct Burger),1,completo);
            fread(&septiembre,sizeof(struct Burger),1,sept);    
        } else {
            if(agosto.tipo == 'p'){
            arch.codigo = agosto.codigo;
            arch.cant = septiembre.cant;
            fwrite(&arch,sizeof(struct Burger),1,panes);
            }
            fwrite(&agosto,sizeof(struct Burger),1,completo);
            fread(&agosto,sizeof(struct Burger),1,agos);
        }
    }
    while(!feof(agos)){
        if(agosto.tipo == 'p'){
            arch.codigo = agosto.codigo;
            arch.cant = agosto.cant;
            fwrite(&arch,sizeof(struct Burger),1,panes);
        }
        fwrite(&agosto,sizeof(struct Burger),1,completo);
        fread(&agosto,sizeof(struct Burger),1,agos);
    }
    while(!feof(sept)){
        if(septiembre.tipo == 'p'){
            arch.codigo = septiembre.codigo;
            arch.cant = septiembre.cant;
            fwrite(&arch,sizeof(struct Burger),1,panes);
        
        }
        fwrite(&septiembre,sizeof(struct Burger),1,completo);
        fread(&septiembre,sizeof(struct Burger),1,sept);    
    }
    fclose(agos);
    fclose(sept);
    fclose(completo);
    fclose(panes);


    return 0;
}