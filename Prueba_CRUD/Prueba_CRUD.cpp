#include "Estudiante.h"
#include <iostream>
using namespace std;

int main()
{
    string codigo, nombres, apellidos, direccion, fecha_nacimiento;
    int telefono = 0, id_tipo_sangre = 0, id = 0;
    Estudiante c = Estudiante();
    c.leer();
    cout << "Ingrese ID: " << endl;
    cin >> id;
    cin.ignore();
    cout << "Ingrese codigo: " << endl;
    getline(cin, codigo);
    cout << "Ingrese nombres: " << endl;
    getline(cin, nombres);
    cout << "Ingrese apellidos: " << endl;
    getline(cin, apellidos);
    cout << "Ingrese direccion: " << endl;
    getline(cin, direccion);
    cout << "Ingrese telefono: " << endl;
    cin>>telefono;
    cin.ignore();
    cout << "Ingrese fecha de nacimiento: " << endl;
    cin>>fecha_nacimiento;
    cout << "Ingrese ID tipo de sangre: " << endl;
    cin>>id_tipo_sangre;
    c = Estudiante(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre,id);
    c.crear();
    c.leer();
    cout << "Ingrese ID: " << endl;
    cin >> id;
    c.setId(id);
    c.borrar();
    c.leer();
    system("pause");
}
