#include <iostream>
using namespace std;

int main() {
	string semana[7]={"lunes,""martes","miercoles","jueves","viernes","sabado","domimgo"};
	semana[3]= "jueves";
	for(int i=0;i<7;i++){
		cout<<semana[i]<<endl;
	}
}
	
	
