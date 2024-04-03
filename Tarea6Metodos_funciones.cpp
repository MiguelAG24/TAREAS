//Metodos y funciones = ejecutan una porcion de codino 
                    //N cantidad de veces segun se mande a llamar
//metodo = no retorna un tipo de dato
//funcion = retorna un tipo de dato determinado 
	
#include <iostream>
using namespace std;


//metodo y envio de parametros por referencia
void suma(int &num1,int &num2){
	int resultado = 0;
	num1+=1;
	num2+=1;
	resultado = num1+num2;
	cout<<resultado<<endl;
}
//funcion que sume 2 varoles
int suma(int num1,int num2, int num3){
	int resultado = 0;
	resultado = num1+num2+num3;
	return resultado;
}
/*int resta(int num1,int num2){
	int resultado = 0;
	resultado = num1-num2;
	return resultado;
}*/

main(){
	int a=10,b = 20;
	
	suma(a,b);
	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;
	
	system("pause");
}
