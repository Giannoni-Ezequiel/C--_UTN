/**/

#include <string.h>

// 1. Estructura del registro para leer el archivo binario
struct RegistroBuceo {
    char operadora[20 + 1];
    int dni;
    int edad;
    char pais[20 + 1];
    int dia, mes, anio; 
    char sitio[20 + 1];
    char dificultad[15];
    int profundidad;      // en metros
    int tiempoBuceo;      // en minutos
    float horaInicio;     // Ej: 19.30 para las 19:30hs
};

// 2. Estructura para la lista dinámica de países (sin repetidos)
struct NodoPais {
    char pais[20 + 1];
    NodoPais* sig;
};

// 3. Estructura principal que irá dentro del array de Operadores
struct InfoOperador {
    char nombreOperadora[20 + 1];
    int cantBuceosProfundos;       // >= 30 metros
    int cantBuceosNocturnos;       // >= 19.00 hs
    NodoPais* listaPaises;         // Lista de países de origen
};

// Declaración del Array (sería la variable principal en el main)
// InfoOperador operadores[20];

/**/

int buscarOAgregarOperador(InfoOperador operadores[20], int& cantOperadores, char nombreOp[]) {
    // 1. Buscamos si el operador ya existe en el array
    for (int i = 0; i < cantOperadores; i++) {
        if (strcmp(operadores[i].nombreOperadora, nombreOp) == 0) {
            return i; // Lo encontró, retornamos su posición
        }
    }
    
    // 2. Si no existe y hay espacio, lo agregamos e inicializamos
    if (cantOperadores < 20) {
        strcpy(operadores[cantOperadores].nombreOperadora, nombreOp);
        operadores[cantOperadores].cantBuceosProfundos = 0;
        operadores[cantOperadores].cantBuceosNocturnos = 0;
        operadores[cantOperadores].listaPaises = NULL;
        
        cantOperadores++; // Incrementamos la cantidad de operadores cargados
        return cantOperadores - 1; // Retornamos la posición donde lo guardamos
    }
    
    return -1; // Por seguridad (si hubiera más de 20)
}
//
// Asumimos que existen estas primitivas permitidas por el enunciado:
// NodoPais* buscarEnLista(NodoPais* raiz, char paisBuscado[]);
// void insertarOrdenado(NodoPais*& raiz, char nuevoPais[]);

void cargarEstructura(FILE* arch, InfoOperador operadores[20], int& cantOperadores) {
    RegistroBuceo reg;
    
    // Lectura anticipada
    fread(&reg, sizeof(RegistroBuceo), 1, arch);
    
    while (!feof(arch)) {
        // 1. Obtener la posición del operador en el array
        int pos = buscarOAgregarOperador(operadores, cantOperadores, reg.operadora);
        
        if (pos != -1) {
            // 2. Condición: Buceos a 30 metros o más
            if (reg.profundidad >= 30) {
                operadores[pos].cantBuceosProfundos++;
            }
            
            // 3. Condición: Buceos nocturnos (a partir de las 19.00hs)
            if (reg.horaInicio >= 19.00) {
                operadores[pos].cantBuceosNocturnos++;
            }
            
            // 4. Países de origen (Sin repetidos)
            // Buscamos si el país ya está en la lista de ese operador
            NodoPais* paisEncontrado = buscarEnLista(operadores[pos].listaPaises, reg.pais);
            
            // Si devuelve NULL, significa que es la primera vez que viene alguien de ese país
            if (paisEncontrado == NULL) {
                // Lo insertamos en la lista
                insertarOrdenado(operadores[pos].listaPaises, reg.pais);
            }
        }
        
        // Leer el siguiente registro
        fread(&reg, sizeof(RegistroBuceo), 1, arch);
    }
}

/**/

#include <iostream>
using namespace std; // Asumo el uso de cout para imprimir en C++

void listarEstadisticas(InfoOperador operadores[20], int cantOperadores) {
    
    // 1. Recorremos el array de operadores válidos
    for (int i = 0; i < cantOperadores; i++) {
        
        cout << "=========================================" << endl;
        cout << "Operador: " << operadores[i].nombreOperadora << endl;
        
        // 2. Imprimimos los contadores simples (Puntos b y c)
        cout << "- Buceos profundos (>= 30m): " << operadores[i].cantBuceosProfundos << endl;
        cout << "- Buceos nocturnos: " << operadores[i].cantBuceosNocturnos << endl;
        
        // 3. Imprimimos la lista de países (Punto a)
        cout << "- Países de los buzos: ";
        
        // Regla de oro: Usar un puntero auxiliar para NO romper la lista
        NodoPais* aux = operadores[i].listaPaises;
        
        if (aux == NULL) {
            cout << "No se registraron buzos." << endl;
        } else {
            // Recorremos la lista enlazada hasta el final
            while (aux != NULL) {
                cout << aux->pais;
                
                // Formateo visual (poner coma si no es el último)
                if (aux->sig != NULL) {
                    cout << ", ";
                }
                
                // Avanzamos al siguiente nodo
                aux = aux->sig;
            }
            cout << endl; // Salto de línea al terminar los países
        }
    }
    cout << "=========================================" << endl;
}