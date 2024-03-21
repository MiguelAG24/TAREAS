#include <iostream>
using namespace std;

main (){
	
	//ARREGLOS BIDIMENSIONALES, MATRIS, TABLA
	int matriz[2][3]={{10,20,30},{40,50,60}};
	cout <<matriz[0][0]<<endl;
	cout <<matriz[0][1]<<endl;
	cout <<matriz[0][2]<<endl;
	cout <<matriz[1][0]<<endl;
	cout <<matriz[1][1]<<endl;
	cout <<matriz[1][2]<<endl;
	
	
       
	system("pause");
}


/*/REALIZAR CON FOR

main() {

    int fil=0,col=0;
    cout<<"Ingrese colimnas: ";
    cin>>fil;
    cout<<"Ingrese columnas: ";
    cin>>col;
    int matriz[fil][col];
    cout<<"------------Ingresar----------";
    for (int i=0;i<fil;i++){
    	for(int ii=0;ii<col;ii++){
    		cout<<i<<","<<ii<<": ";
    		cin>>matriz[i][ii];
		}
		cout<<"___________________"<<endl;
	}
    cout<<"--------Mostrar------------"<<endl;
    for (int i=0;i<fil;i++){
    	for(int ii=0;ii<col;ii++){
    		cout<<i<<","<<ii<<": "<<matiz[i][ii]<<endl;
		}
	}
/*/
//
