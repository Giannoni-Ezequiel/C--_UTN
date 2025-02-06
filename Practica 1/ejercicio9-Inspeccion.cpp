/*9.	Se realiza una inspección en una fábrica de pinturas, y se detectaron 20 infracciones. De cada infracción se tomó nota de los siguientes datos:
- Tipo de Infracción (1, 2, 3, o 4)
- Motivo de la Infracción
- Valor de la multa (un entero)
- Gravedad de la infracción (‘L’,‘M’, ‘G’)
Se pide informar al final del proceso:
• Los valores totales de la multa a pagar de acuerdo al tipo de gravedad.
• La leyenda “Clausurar fabrica” si la cantidad de infracciones 3 y 4 con gravedad “G” sean mayor a 3.
*/
#include <iostream>
#include <vector>
using namespace std;

// Definimos una estructura para almacenar los datos de cada infracción
struct Infraccion{
    int tipo;
    string motivo;
    int valor_multa;
    char gravedad;
};

int main(){
vector<Infraccion> infracciones(20);

//variables totales de multa
int total_multa_L = 0;
int total_multa_M = 0;
int total_multa_G = 0;
int contador_infracciones_graves = 0;

for ( int i = 0; i < 20; i++){
    cout << "Ingrese los datos de la infracción " << i+1 << endl;
    cout << "Tipo de infracción: 1, 2, 3 o 4 " << endl;
    cin >> infracciones[i].tipo;
    cout << "Motivo de la infracción: " << endl;
    cin.ignore();
    getline(cin, infracciones[i].motivo);
    cout << "Valor de la multa: " << endl;
    cin >> infracciones[i].valor_multa;
    cout << "Gravedad de la infracción: L, M o G " << endl;
    cin >> infracciones[i].gravedad;

    switch (infracciones[i].gravedad){
    case 'L':
        total_multa_L += infracciones[i].valor_multa;
        break;
    case 'M':
        total_multa_M += infracciones[i].valor_multa;
        break;
    case 'G':
        total_multa_G += infracciones[i].valor_multa;
           if (infracciones[i].tipo == 3 || infracciones[i].tipo == 4){
           contador_infracciones_graves++;
           }
        break;
    }

    cout << "Total multa L: " << total_multa_L << endl;
    cout << "Total multa M: " << total_multa_M << endl;
    cout << "Total multa G: " << total_multa_G << endl;

    if (contador_infracciones_graves > 3){
        cout << "Clausurar fabrica" << endl;
    }
    }

    cout << "Total multa L: " << total_multa_L << endl;
    cout << "Total multa M: " << total_multa_M << endl;
    cout << "Total multa G: " << total_multa_G << endl;

    if (contador_infracciones_graves > 3){
        cout << "Clausurar fabrica" << endl;
    }

return 0;
}