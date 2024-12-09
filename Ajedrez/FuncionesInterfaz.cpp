#include "FuncionesInterfaz.h"


void FuncionesInterfaz::encerarTablero(void){
	for(int i=0;i<this->reina->n;i++){
		this->reina->validar[i]=new bool[this->reina->n];
		this->reina->tablero[i]=new char[this->reina->n];
		for(int j=0;j<this->reina->n;j++){
			*(*(this->reina->validar+i)+j)=false;
			*(*(this->reina->tablero+i)+j)='*';
		}
	}
}


void FuncionesInterfaz::crearArchivo(void){
	this->archivo.open("exaustivo.txt",fstream::out);
	this->archivo<<"solucion"<<this->reina->n<<"*"<<this->reina->n<<endl<<endl;
	this->reina->contador=0;
}

void FuncionesInterfaz::bloquear(int x, int y){
//	cout<<"Bloquear"<<endl;
	int aux1,aux2;
	aux2=y;
	aux1=0;
	while(aux1<this->reina->n){//vertical
	//	cout<<"while "<<endl;
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux1++;
	}
	aux2=0;
	aux1=x;
	while(aux2<this->reina->n){
	//	cout<<"while2 "<<endl;
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux2++;
	}
	aux2=y;//diagonal
	aux1=x;
	while(aux1>0&&aux2>0){
		aux1--;
		aux2--;
	}
	aux2=y;
	aux1=x;
	while(aux1<this->reina->n && aux2>0){
		aux1++;
		aux2--;
	}
	aux1--;
	aux2++;
	while(aux1>=0 && aux2<this->reina->n){
		*(*(this->reina->validar+aux1)+aux2)=true;
		aux1--;
		aux2++;
	}
}

void FuncionesInterfaz::mostrar(void){

	this->reina->contador++;
	this->archivo<<"solucion N "<<this->reina->contador<<endl;
	cout<<endl;
	for(int i=0;i<this->reina->n;i++){
		for(int j=0;j<this->reina->n;j++){
			this->archivo<<*(*(this->reina->tablero+i)+j)<<" ";
			cout<<*(*(this->reina->tablero+i)+j)<<" ";
		}
		this->archivo<<endl;
		cout<<endl;
	}
	this->archivo<<endl;
	cout<<endl;
}

void FuncionesInterfaz::quitarRelleno(int x, int y){
	*(*(this->reina->tablero +x)+y)='*';
	for(int i=0;i<this->reina->n;i++){
		for(int j=0;j<this->reina->n;j++){
			*(*(this->reina->validar +i)+j)=false;
		}
			}
	for(int i=0;i<this->reina->n;i++){
		for(int j=0;j<this->reina->n;j++){
			if(*(*(this->reina->tablero  +i)+j)=='R')
			bloquear(i,j);
		}	
	}
}

void FuncionesInterfaz::solucion(int x, int y, int n1){
	*(*(this->reina->tablero +x)+y)='R';
	bloquear(x,y);
	if(n1==this->reina->n){
		mostrar();
	}else{
		for(int i=0;i<this->reina->n ;i++){
			if(*(*(this->reina->validar +i )+ y+1)==false){
				solucion(i,y+1,n1+1);
			}
		}
	}
	quitarRelleno(x,y);	
}

void FuncionesInterfaz::solucionReinas(void){
	for(int i=0;i<this->reina->n ;i++){
		solucion(i,0,1);
	}
	archivo.close();
}