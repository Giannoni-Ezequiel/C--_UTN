/*

*/

struct RegistroHisopado {
    int dni;                               // DNI del paciente
    char apellidoNombre[60];               // Apellido y nombre
    char fechaNacimiento[9];               // Fecha de nacimiento (ej: AAAAMMDD)
    char domicilio[80];                    // Domicilio del paciente
    char centroTesteo[50];                 // Centro de testeo
    char tipoTest[15];                     // Tipo de test ("antígeno" o "PCR")
    char obraSocial[50];                   // Obra social o "NA"
    int dosisAplicadas;                    // Cantidad de dosis aplicadas
    char fechaContactoEstrecho[9];         // Fecha del posible contacto
    char resultado[15];                    // Resultado del test ("Positivo" o "Negativo")
};

struct InfoPaciente {
    int dni;
    char apellidoNombre[60];
    char fechaNacimiento[9];
    char domicilio[80];
};

struct NodoPaciente {
    InfoPaciente info;
    NodoPaciente* sig;
};

struct InfoTest {
    char tipoTest[15];                     // "antígeno" o "PCR"
    NodoPaciente* listaPacientes;          // Puntero al nivel 3 (Pacientes)
};

struct NodoTest {
    InfoTest info;
    NodoTest* sig;
};

struct InfoObraSocial {
    char nombreObraSocial[50];
    NodoTest* vecResultado[2];             // Pos 0: Negativos, Pos 1: Positivos
};

struct NodoObraSocial {
    InfoObraSocial info;
    NodoObraSocial* sig;
};

/*
*/

// Primitivas de la lista principal (Obras Sociales)
NodoObraSocial* buscarEInsertaOrdenado(NodoObraSocial*& raiz, InfoObraSocial info, bool& enc);

// Primitivas del nivel 2 (Tipos de Test)
NodoTest* buscarEInsertaOrdenado(NodoTest*& raiz, InfoTest info, bool& enc);

// Primitivas del nivel 3 (Pacientes)
void insertaPrimero(NodoPaciente*& raiz, InfoPaciente info);

// Lista auxiliar para filtrar DNI
struct NodoDNI {
    int dni;
    NodoDNI* sig;
};
NodoDNI* insertarOrdenado(NodoDNI*& raiz, int dni);
NodoDNI* buscar(NodoDNI* raiz, int dni);

NodoObraSocial* cargarEstructura(FILE* arch) {
    NodoObraSocial* listaObrasSociales = NULL;
    NodoDNI* listaDNIsProcesados = NULL; // Lista auxiliar para evitar repetidos
    RegistroHisopado reg;

    // Leer el primer registro
    fread(&reg, sizeof(RegistroHisopado), 1, arch);

    while (!feof(arch)) {
        // 1. Filtrar DNI repetidos
        if (buscar(listaDNIsProcesados, reg.dni) == NULL) {
            
            // Si no existe, lo agregamos a nuestra lista auxiliar de control
            insertarOrdenado(listaDNIsProcesados, reg.dni);

            // 2. Buscar o Insertar la Obra Social
            InfoObraSocial infoOS;
            strcpy(infoOS.nombreObraSocial, reg.obraSocial);
            // Inicializamos los punteros del vector en NULL si es nueva
            infoOS.vecResultado[0] = NULL; 
            infoOS.vecResultado[1] = NULL;
            
            bool encOS = false;
            NodoObraSocial* nodoOS = buscarEInsertaOrdenado(listaObrasSociales, infoOS, encOS);

            // 3. Determinar el índice del resultado (0: Negativo, 1: Positivo)
            int indiceResultado = 0; // Asumimos Negativo por defecto
            if (strcmp(reg.resultado, "Positivo") == 0) {
                indiceResultado = 1;
            }

            // 4. Buscar o Insertar el Tipo de Test dentro del vector correspondiente
            InfoTest infoTest;
            strcpy(infoTest.tipoTest, reg.tipoTest);
            infoTest.listaPacientes = NULL; // Inicializamos su lista de pacientes en NULL
            
            bool encTest = false;
            // nodoOS->info.vecResultado[indiceResultado] es la raíz de la lista de tests
            NodoTest* nodoTestActual = buscarEInsertaOrdenado(nodoOS->info.vecResultado[indiceResultado], infoTest, encTest);

            // 5. Insertar al Paciente (podemos usar insertaPrimero porque no piden orden específico)
            InfoPaciente infoPac;
            infoPac.dni = reg.dni;
            strcpy(infoPac.apellidoNombre, reg.apellidoNombre);
            strcpy(infoPac.fechaNacimiento, reg.fechaNacimiento);
            strcpy(infoPac.domicilio, reg.domicilio);

            insertaPrimero(nodoTestActual->info.listaPacientes, infoPac);
        }

        // Leer el siguiente registro
        fread(&reg, sizeof(RegistroHisopado), 1, arch);
    }

    // Liberamos la memoria de la lista auxiliar de DNIs (buena práctica)
    // liberar(listaDNIsProcesados); 

    return listaObrasSociales;
}