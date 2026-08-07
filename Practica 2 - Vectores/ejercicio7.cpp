/*
7. Dado un conjunto de N cursos ( <=20) de la cátedra de algoritmos, de cada uno
de ellos código de curso ( 4 caracteres) y cantidad de alumnos, y de cada curso el
número de legajo y nota (0..10) de los alumnos.
Se pide:
• informar de cada curso la cantidad de alumnos que tuvieron como nota 0, 1, ...,9, 10
• informar al final del proceso el código de curso, el % de aprobados y el de
insuficientes de cada curso.
*/

#include <iostream>
#include <string>

using namespace std;

// Estructura para almacenar los datos y resultados de cada curso
struct ReporteCurso {
    string codigo;
    int totalAlumnos = 0;
    int aprobados = 0;
    int insuficientes = 0;
    int notas[11] = {0}; // Un contador para cada nota de 0 a 10
};

int main() {
    int nCursos;
    cout << "Ingrese la cantidad de cursos a procesar (max 20): ";
    cin >> nCursos;

    // Validar la cantidad de cursos
    if (nCursos <= 0 || nCursos > 20) {
        cout << "Cantidad de cursos invalida. El programa terminara." << endl;
        return 1;
    }

    // Usamos un array de structs para guardar la informacion de cada curso
    ReporteCurso reportes[20];

    // Procesar cada curso
    for (int i = 0; i < nCursos; ++i) {
        cout << "\n--- Procesando Curso " << i + 1 << " ---" << endl;
        cout << "Ingrese el codigo del curso (4 caracteres): ";
        cin >> reportes[i].codigo;

        cout << "Ingrese la cantidad de alumnos: ";
        cin >> reportes[i].totalAlumnos;

        if (reportes[i].totalAlumnos < 0) {
            cout << "Cantidad de alumnos invalida. Se asignara 0." << endl;
            reportes[i].totalAlumnos = 0;
        }

        // Procesar cada alumno del curso actual
        for (int j = 0; j < reportes[i].totalAlumnos; ++j) {
            int legajo, nota;
            cout << "Ingrese legajo y nota (0-10) del alumno " << j + 1 << ": ";
            cin >> legajo >> nota;

            // Validar la nota y contarla
            if (nota >= 0 && nota <= 10) {
                reportes[i].notas[nota]++;
                if (nota >= 6) { // Asumimos que se aprueba con 6 o más
                    reportes[i].aprobados++;
                } else {
                    reportes[i].insuficientes++;
                }
            } else {
                cout << "Nota invalida. Por favor ingrese una nota entre 0 y 10." << endl;
                j--; // Repetir el ingreso para este alumno
            }
        }

        // Informar la cantidad de alumnos por nota para el curso actual
        cout << "\n> Reporte de notas para el curso " << reportes[i].codigo << ":" << endl;
        for (int k = 0; k <= 10; ++k) {
            cout << "  Nota " << k << ": " << reportes[i].notas[k] << " alumno(s)" << endl;
        }
    }

    // Informar el reporte final de porcentajes
    cout << "\n\n--- Reporte Final de Cursos ---" << endl;

    for (int i = 0; i < nCursos; ++i) {
        float porc_aprobados = 0.0;
        float porc_insuficientes = 0.0;

        if (reportes[i].totalAlumnos > 0) {
            porc_aprobados = (static_cast<float>(reportes[i].aprobados) / reportes[i].totalAlumnos) * 100.0;
            porc_insuficientes = (static_cast<float>(reportes[i].insuficientes) / reportes[i].totalAlumnos) * 100.0;
        }

        cout << "Curso: " << reportes[i].codigo
             << " | % Aprobados: " << porc_aprobados << "%"
             << " | % Insuficientes: " << porc_insuficientes << "%" << endl;
    }

    return 0;
}