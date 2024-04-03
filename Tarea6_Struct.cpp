//structuras struct 
//una forma de agrupar varias variables relacionadas en un solo lugar
//son utiles cuando se necesitan agrupar variables

#include <iostream>
using namespace std;

struct Estudiante{
	int *codigo;
	string *nombre;
	int **notas;
};
////////////PUNTEROS//////////////
main(){
	Estudiante estudiante;
	
	int fila = 0, columna = 0;
	cout<<"Cuantos Estudiantes desea agregar: ";
	cin>>fila;
	
	cout<<"Cuantas notas por Estudiante desea agregar: ";
	cin>>columna;
	
	
	estudiante.codigo = new int [fila];
	estudiante.nombre = new string[fila];
	estudiante.notas = new int *[fila];
	
	for (int i=0;i<fila;i++){
		estudiante.notas[i] = new int[columna];
		
	}
	cout<<"________________________Ingreso de Notas: ____________________"<<endl;
	
	///////
	for (int i=0;i<fila;i++){
		
		cout<<"Codigo["<<i<<"]:";
		cin>>estudiante.codigo[i];
		cin.ignore();
		cout<<"Nombre Completo["<<i<<"]:";
		getline(cin,estudiante.nombre[i]);
		for (int ii=0;ii<columna;ii++){
			cout<<"Ingrese Nota["<<ii<<"] :";
			cin>>*(*(estudiante.notas+i)+ii);
		}
		cout<<"_________________________"<<endl;
	
}
	cout<<"__________________Mostrar Datos__________________"<<endl;
	
	for (int i=0;i<fila;i++){
		
		cout<<"Codigo["<<i<<"]:"<<estudiante.codigo[i]<<endl;
		cout<<"Nombre Completo["<<i<<"]:"<<estudiante.nombre[i]<<endl;
		for (int ii=0;ii<columna;ii++){
			cout<<"Ingrese Nota["<<ii<<"] :"<<*(*(estudiante.notas+i)+ii)<<endl;
		}

		cout<<"_________________________"<<endl;
}
	
	for (int i=0;i<fila;i++){
		delete[] estudiante.notas[i];
		
	}
	delete[] estudiante.codigo;
	delete[] estudiante.nombre;
	delete[] estudiante.notas;
	
		
	system("pause");
	
}

	////////////////Datos primitivos
	/*for (int i=0;i<4;i++){
		cout<<"_______________________"<<endl;
		cout<<"Ingrese Codigo: ";
	    cin>>estudiante.codigo[i];
	cin.ignore();
	cout<<"Ingrese Nombre Completo: ";
	getline(cin,estudiante.nombre[i]);
	cout<<"Ingrese Nota: ";
	cin>>estudiante.nota[i];
		
	}
	cout<<"Ingrese Codigo: ";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"Ingrese Nombre Completo: ";
	getline(cin,estudiante.nombre);
	cout<<"Ingrese Nota: ";
	cin>>estudiante.nota;
	for (int i=0;i<4;i++){
		cout<<"_______________________"<<endl;
	
		cout<<"Codigo: "<<estudiante.codigo[i]<<endl;
		cout<<"Nombre Completo: "<<estudiante.nombre[i]<<endl;
		cout<<"Nota: "<<estudiante.nota[i]<<endl;
	}*/
