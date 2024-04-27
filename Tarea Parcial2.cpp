#include <iostream>
#include <string>

using namespace std;

struct Estudiante { // Definición de la estructura Estudiante que contiene la información de cada estudiante
    int id;
    string nombre;
    string apellido;
    float* notas; // Puntero para almacenar las notas de cada estudiante
};

int main() {
    int N;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N; // Solicita al usuario ingresar la cantidad de estudiantes

    Estudiante* estudiantes = new Estudiante[N]; // Declaración de un arreglo dinámico de estructuras Estudiante

    for (int i = 0; i < N; ++i) { // Bucle para ingresar información de cada estudiante
        estudiantes[i].notas = new float[4]; // Asignación de memoria para las notas de cada estudiante

        cout << "Ingrese ID del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].id;
        cout << "Ingrese nombre del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].nombre;
        cout << "Ingrese apellido del estudiante " << i+1 << ": ";
        cin >> estudiantes[i].apellido;

        float sumaNotas = 0;
        for (int j = 0; j < 4; ++j) { // Bucle para ingresar las notas de cada estudiante
            cout << "Ingrese nota " << j+1 << " del estudiante " << i+1 << ": ";
            cin >> estudiantes[i].notas[j];
            sumaNotas += estudiantes[i].notas[j];
        }

        float promedio = sumaNotas / 4; // Cálculo del promedio de las notas del estudiante
        cout << "El promedio del estudiante " << i+1 << " es: " << promedio << endl; // Imprime el promedio
        if (promedio > 60)
            cout << "El estudiante " << i+1 << " ha aprobado." << endl; // Indica si el estudiante aprobó
        else
            cout << "El estudiante " << i+1 << " ha reprobado." << endl; // Indica si el estudiante reprobó

        delete[] estudiantes[i].notas; // Libera la memoria asignada para las notas de cada estudiante
    }

    delete[] estudiantes; // Libera la memoria asignada para el arreglo dinámico de estudiantes

    return 0;
}
