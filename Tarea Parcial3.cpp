#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char *nombre_archivo = "notas.dat";

struct Estudiante { 
    int id;
    char nombres[50];
    char apellidos[50];
    float notas[4];
    float promedio;
    string resultado;
};
int menu();
void Leer();
void Crear();
void Actualizar();
void Borrar();
main(){
	//archivos
	menu();
	Leer();
	Crear();
	Borrar();
	Actualizar();
	system("pause");
}
void Leer() {
    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Estudiante estudiante;
    int id = 0;
    cout << "______________________________________________________________" << endl;
    cout << " ID " << "|" << " Nombres " << "|" << " Apellidos " << "|" << " Notas " << "|" << " Promedio " << "|" << " Resultado " << endl;
    while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
        cout << id << "|" << estudiante.nombres << "|" << estudiante.apellidos << "|";
        for (int i = 0; i < 4; ++i) {
            cout << estudiante.notas[i] << " ";
        }
        cout << "|" << estudiante.promedio << "|" << estudiante.resultado << endl;
        id++;
    }
    fclose(archivo);
}

void Crear() {
    FILE* archivo = fopen(nombre_archivo, "ab");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    char res;
    Estudiante estudiante;
    do {
        cout << "Ingrese ID: ";
        cin >> estudiante.id;
        cin.ignore();
        
        cout << "Ingrese Nombres: ";
        cin.getline(estudiante.nombres, 50);
        
        cout << "Ingrese Apellidos: ";
        cin.getline(estudiante.apellidos, 50);
        
        cout << "Ingrese Notas (separadas por espacios): ";
        for (int i = 0; i < 4; ++i) {
            cin >> estudiante.notas[i];
        }
        float sumaNotas = 0;
        for (int i = 0; i < 4; ++i) {
            sumaNotas += estudiante.notas[i];
        }
        estudiante.promedio = sumaNotas / 4;
        if (estudiante.promedio > 60)
            estudiante.resultado = "Aprobado";
        else
            estudiante.resultado = "Reprobado";

        fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
        cout << "Desea ingresar otro estudiante (s/n): ";
        cin >> res;
    } while (res == 's' || res == 'S');
    
    fclose(archivo);
}

void Actualizar() {
    FILE* archivo = fopen(nombre_archivo, "r+b");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    int id;
    cout << "Ingrese el ID del estudiante a actualizar: ";
    cin >> id;
    
    fseek(archivo, id * sizeof(Estudiante), SEEK_SET);
    Estudiante estudiante;
    cout << "Ingrese ID: ";
    cin >> estudiante.id;
    cin.ignore();
    
    cout << "Ingrese Nombres: ";
    cin.getline(estudiante.nombres, 50);
    
    cout << "Ingrese Apellidos: ";
    cin.getline(estudiante.apellidos, 50);
    
    cout << "Ingrese Notas (separadas por espacios): ";
    for (int i = 0; i < 4; ++i) {
        cin >> estudiante.notas[i];
    }
    float sumaNotas = 0;
    for (int i = 0; i < 4; ++i) {
        sumaNotas += estudiante.notas[i];
    }
    estudiante.promedio = sumaNotas / 4;
    if (estudiante.promedio > 60)
        estudiante.resultado = "Aprobado";
    else
        estudiante.resultado = "Reprobado";

    fwrite(&estudiante, sizeof(Estudiante), 1, archivo);
    fclose(archivo);
}

void Borrar() {
    const char *nombre_archivo_temp = "temp.dat";
    FILE* archivo_temp = fopen(nombre_archivo_temp, "w+b");
    if (!archivo_temp) {
        cout << "No se pudo abrir el archivo temporal." << endl;
        return;
    }

    FILE* archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        fclose(archivo_temp);
        return;
    }

    int id;
    cout << "Ingrese el ID del estudiante a eliminar: ";
    cin >> id;
    
    int actual_id = 0;
    Estudiante estudiante;
    while (fread(&estudiante, sizeof(Estudiante), 1, archivo)) {
        if (actual_id != id) {
            fwrite(&estudiante, sizeof(Estudiante), 1, archivo_temp);
        }
        actual_id++;
    }

    fclose(archivo);
    fclose(archivo_temp);

    remove(nombre_archivo);
    rename(nombre_archivo_temp, nombre_archivo);
}

int menu() {
    int opcion;
    do {
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Crear estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Actualizar estudiante" << endl;
        cout << "4. Eliminar estudiante" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                Crear();
                break;
            case 2:
                Leer();
                break;
            case 3:
                Actualizar();
                break;
            case 4:
                Borrar();
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    return 0;
}
