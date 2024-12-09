#include "FuncionA.h"
void FuncionA::encerarTablero(){
	for(int i=0;i<MAX;i++){
		this->alfil->validar[i]=new bool[MAX];
		this->alfil->tablero[i]=new char[MAX];
		for(int j=0;j<MAX;j++){
			*(*(this->alfil->validar+i)+j)=false;
			*(*(this->alfil->tablero+i)+j)='*';
			}
	}	
}
void FuncionA::crearArchivo(){
	cout<<"Archivo"<<endl;
	this->archivo.open("exaustivoAlfiles.txt",fstream::out);
	this->archivo<<"solucion"<<this->alfil->n<<"*"<<this->alfil->n<<endl<<endl;
	this->alfil->contador=0;
}

void FuncionA::bloquear(int x, int y){
	int aux1,aux2;
	aux2=y;//diagonal
	aux1=x;
	while(aux1>0&&aux2>0){
		aux1--;
		aux2--;
	}
	aux2=y;
	aux1=x;
	while(aux1<MAX && aux2>0){
		aux1++;
		aux2--;
	}
	aux1--;
	aux2++;
	while(aux1>=0 && aux2<MAX){
		*(*(this->alfil->validar+aux1)+aux2)=true;
		aux1--;
		aux2++;
	}
	}
	void FuncionA::mostrar(){
		this->alfil->contador++;
		this->archivo<<"solucion N "<<this->alfil->contador <<endl;
		cout<<"solucion N "<<this->alfil->contador <<endl;
		cout<<endl;
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				this->archivo<<*(*(this->alfil->tablero+i)+j)<<" ";
				cout<<*(*(this->alfil->tablero+i)+j)<<" ";
			}
			this->archivo<<endl;
			cout<<endl;
		}
		this->archivo<<endl;
		cout<<endl;
	}
	void FuncionA::quitarRelleno(int x, int y){
		*(*(this->alfil->tablero +x)+y)='*';
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				*(*(this->alfil->validar+i)+j)=false;
			}
		}
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				if(*(*(this->alfil->tablero +i)+j)=='A')
				bloquear(i,j);
			}	
		}
	}

	
	void FuncionA::solucion(int x, int y, int n1){
		*(*(this->alfil->tablero +x)+y)='A';
		bloquear(x,y);
		if(n1==this->alfil->n){
			mostrar();
		}else{
			for(int i=0;i<MAX;i++){
				if(*(*(this->alfil->validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void FuncionA::solucionReinas(){
	cout<<"Hola";	
		for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			solucion(i,j,1);
		}
	}
		archivo.close();	
	}