/**/

// 1. Estructura de la información del cliente
struct InfoCliente {
    int dniCliente;
    char nombreCliente[100 + 1];
};

// 2. Nodo para la lista simplemente enlazada de clientes
struct NodoCliente {
    InfoCliente info;
    NodoCliente* sig;
};

// 3. Estructura de cada celda de la matriz
struct CeldaMatriz {
    int cantidadVendida;
    NodoCliente* listaClientes;
};

// Opcional: Podés definir el tipo de la matriz para que el código quede más limpio
// typedef CeldaMatriz MatrizVentas[31][2500];

/**/

#include <string.h> // Necesario para strcmp()

// A) Obtener la fila (Día del mes)
int obtenerPosFilaEnMatriz(int diaDelMes) {
    return diaDelMes - 1; // El día 1 va a la fila 0, el 31 a la 30
}

// B) Obtener la columna (Código de electrodoméstico)
int obtenerPosColumnaEnMatriz(Electrodomestico electrodomesticos[], char codigoElectrodomestico[6 + 1]) {
    int inicio = 0;
    int fin = 2499; // Sabemos que son 2500 exactamente
    int medio;

    // Búsqueda Binaria clásica
    while (inicio <= fin) {
        medio = inicio + (fin - inicio) / 2;
        
        // Comparamos los códigos de las cadenas
        int comparacion = strcmp(electrodomesticos[medio].codigoElectrodomestico, codigoElectrodomestico);
        
        if (comparacion == 0) {
            return medio; // Lo encontramos, retornamos la posición (índice)
        } 
        else if (comparacion < 0) {
            inicio = medio + 1; // Buscamos en la mitad derecha
        } 
        else {
            fin = medio - 1;    // Buscamos en la mitad izquierda
        }
    }
    
    return -1; // Por seguridad, aunque el enunciado dice que siempre existe
}

/**/

void cargarMatriz(FILE* archVentas, Electrodomestico electrodomesticos[], CeldaMatriz matriz[31][2500]) {
    Venta regVenta;

    // 1. Lectura anticipada (primer registro)
    fread(&regVenta, sizeof(Venta), 1, archVentas);

    // 2. Ciclo de lectura secuencial del archivo
    while (!feof(archVentas)) {
        
        // 3. Obtener las coordenadas en la matriz usando las funciones del Punto 2
        int fila = obtenerPosFilaEnMatriz(regVenta.diaDelMes);
        int columna = obtenerPosColumnaEnMatriz(electrodomesticos, regVenta.codigoElectrodomestico);

        // Validamos por seguridad (siempre es buena práctica en C++)
        if (fila >= 0 && fila < 31 && columna >= 0 && columna < 2500) {
            
            // 4. Actualizar el acumulador de ventas en esa celda
            matriz[fila][columna].cantidadVendida += regVenta.cantidadVendida;

            // 5. Armar la información del cliente a insertar
            InfoCliente infoCli;
            infoCli.dniCliente = regVenta.dniCliente;
            strcpy(infoCli.nombreCliente, regVenta.nombreCliente);

            // 6. Insertar el cliente en la lista de esa celda
            // Como no piden orden específico, insertaPrimero es lo más eficiente (O(1))
            insertaPrimero(matriz[fila][columna].listaClientes, infoCli);
        }

        // 7. Leer el siguiente registro para avanzar en el ciclo
        fread(&regVenta, sizeof(Venta), 1, archVentas);
    }
}

/**/

#include <iostream>
using namespace std; // Asumiendo que podés usar cout, si no podés usar printf

void mostrarClientes(CeldaMatriz matriz[31][2500], int fila, int columna) {
    // 1. Validar que la fila y columna existan (buena práctica)
    if (fila >= 0 && fila < 31 && columna >= 0 && columna < 2500) {
        
        // 2. Mostrar la cantidad de ventas de esa celda
        cout << "Cantidad total vendida: " << matriz[fila][columna].cantidadVendida << endl;
        cout << "Listado de DNI de los clientes:" << endl;

        // 3. Crear puntero auxiliar para recorrer sin destruir la lista original
        NodoCliente* aux = matriz[fila][columna].listaClientes;

        // 4. Recorrer e imprimir hasta llegar al final (NULL)
        while (aux != NULL) {
            cout << "- DNI: " << aux->info.dniCliente << endl;
            aux = aux->sig; // Avanzamos al siguiente nodo
        }
        
    } else {
        cout << "Error: Posición fuera de rango." << endl;
    }
}

/*Estructura a utilizar: Un Array de Listas (o Vector de Listas). 
Específicamente, un array estático de 31 posiciones para los días, 
donde cada posición apunta al inicio de una lista simplemente enlazada de 
"Electrodomésticos Vendidos".*/