#include <iostream>
using namespace std;
#define EXCURSIONES_MAXIMAS 100

struct Excursiones{
    int id_excursion;
    char zona;
    int cupos_disponibles;
};

Excursiones excursiones[EXCURSIONES_MAXIMAS];

struct Reserva{
    int id_excursion;
    int cupos_reservados;
};
struct NodoReserva{
    Reserva reserva;
    NodoReserva* sgte;
};
struct Zona{
    char zona;
    NodoReserva* listaReservas;
};
struct NodoZona{
    Zona zona;
    NodoZona* sgte;
};
int buscar(Excursiones excursiones[], int len, int valor);
void actualizarVectorDeExcursiones(Excursiones excursiones[], int lenExcursiones, NodoZona* zonas){
    NodoZona* zonaAux = zonas;
    while(zonaAux != NULL){
    NodoReserva* reservaAux = zonaAux->zona.listaReservas;
    while(reservaAux != NULL){
        int posicionExcursion = buscar(excursiones, lenExcursiones, reservaAux->reserva.id_excursion);
        if(posicionExcursion != -1){
            if(excursiones[posicionExcursion].cupos_disponibles >= 0 && excursiones[posicionExcursion].cupos_disponibles >= reservaAux->reserva.cupos_reservados)
            {
                excursiones[posicionExcursion].cupos_disponibles -= reservaAux->reserva.cupos_reservados;

            }
        }
        reservaAux->sgte;
        }
        zonaAux->sgte;
    }


}

int main(){

}