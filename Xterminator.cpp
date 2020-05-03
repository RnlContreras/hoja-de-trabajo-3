#include <iostream>
#include <fstream>
#include <windows.h>
//el try sirve para manejo de errores catch
//XTERMINIO SA, tiene las siguientes tarifas tipo servisio costo x hertarea mala hierba 10, langostas 20, gusanos 30, todo lo anteriror.
using namespace std;

void principal();
void nuevoDato(ofstream &dato);
void leerDato(ifstream &lec);

main(){
	principal();
}

void principal(){
	ofstream dato;
	ifstream lec;
	
	int seleccion, numeral;
	
	cout<<"***MENU PRINCIPAL***"<<endl;
	cout<<"--------------------"<<endl;
	cout<<"1.Nueva compra"<<endl;
	cout<<"2.Total de compras"<<endl;
	cout<<"3.Top de ventas"<<endl;
	cin>>numeral;
	
	do{
		switch(numeral){
			case 1:{
				nuevoDato(dato);
				break;
			}
			case 2:{
				leerDato(lec);
				break;
			}
			case 3:
				system("cls");
				cout<<"Estamos trabajando en ello :)";
		}
	}while(seleccion != 0);
	
}
void nuevoDato(ofstream &dato){
	system("cls");
	int tipo = 0;
	int servicio = 0;
	float costoDatoCliente;
	float malaHierba = 10;
	float langostas = 20;
	float gusanos = 30;
	float todos = 50;
	float costoTotal = 0;
	
	
	int seleccion = 1;
	
	do{
		system("cls");
	cout<<"INGRESE EL TIPO DE PRODUCTO NIVEL 1, NIVEL 2, NIVEL 3, NIVEL 4: "<<endl;
	cin>>tipo;
	cout<<"TIPO DE SERVICIO 1)MALA HIERBA, 2)LANGOSTAS, 3)GUSANOS, 4)TODO LO ANTERIOR: "<<endl;
	cin>>servicio;
	cout<<"HECTAREA A FUMIGAR: "<<endl;
	cin>>costoDatoCliente;	
	
	if(servicio == 1){
		costoTotal = (costoDatoCliente*malaHierba);
	}
	else if(servicio == 2){
		costoTotal = (costoDatoCliente*langostas);
	}
	else if(servicio == 3){
		costoTotal = (costoDatoCliente*gusanos);
	}
	else if(servicio == 4){
		costoTotal = (costoDatoCliente*todos);
	}
	
	if(costoDatoCliente>=500){
		costoTotal = costoTotal-(costoTotal*0.05);
		cout<<"Usted tiene un descuento del 5% "<<costoTotal<<endl;
	}
	
	if(costoTotal>=1500){
		int descuento2 = ((costoTotal-1500)*0.10);
		costoTotal = costoTotal-descuento2;
		cout<<"Por su compra usted resibe un descuento extra del 10% "<<costoTotal<<endl;
	}
	
	cout<<"TOTAL A PAGAR: "<<costoTotal;
	
		dato.open("SVO01.txt", ios::out|ios::app);
		
		dato<<"TIPO "<<tipo<<"\t"<<"SERVICIO "<<servicio<<"\t"<<"COSTO TOTAL Q."<<costoTotal<<endl;
		
		dato.close();
		
	cout<<"\nDESEA INGRESAR OTRO DATO: SI(1)NO(0): ";
	cin>>seleccion;	
	}while(seleccion == 1);
}

void leerDato(ifstream &lec){
	system("cls");
	int tipo;
	int servicio;
	float costoTotal;
	
	lec.open("SVO01.txt", ios::out|ios::in);
	
	lec>>tipo;
	while(!lec.eof()){
		lec>>servicio;
		lec>>costoTotal;
		
		cout<<"TIPO "<<tipo<<"\t"<<"SERVICIO "<<servicio<<"\t"<<"COSTO TOTAL Q."<<costoTotal<<endl;
		
		lec>>tipo;
		system("pause");
	}
	
	lec.close();
}

