#include <iostream>
using namespace std;
//new =espacio en memoria 
//delete = liberar la memoria

main() {
	int fil = 0, col = 0,**pm_notas;
	cout<<"Ingrese la cantidad de Estudiantes:";
	cin>>fil;
	cout<<"Ingrese la cantidad de Notas:";
	cin>>col;
	
	pm_notas = new int *[fil];
	for(int i=0;i<fil;i++){
		pm_notas[i] = new int[col];
	}
	for (int i=0;i<fil;i++){
		cout<<"--------Estudiante--------"<<i<<endl;
		for (int ii=0;ii<col;ii++){
			cout<<"Nota:"<<ii<<" : ";
			cin>>*(*(pm_notas+i)+ii);
		}
		cout<<"_______________________"<<endl;
	}
	for(int i=0;i<fil;i++){
		delete [] pm_notas[i];
	}
	delete [] pm_notas;
	
	
	
	system ("pause");
}
