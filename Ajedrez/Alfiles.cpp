#include <iostream>
#include <fstream>
#define MAX 8
using namespace std;
class Alfil{
	public:
		bool **validar;
		char **tablero;
		fstream archivo;
		int contador;
		int n;
		void encerarTablero(){
			for(int i=0;i<MAX;i++){
				validar[i]=new bool[MAX];
				tablero[i]=new char[MAX];
				for(int j=0;j<MAX;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
		}
	void crearArchivo(){
		archivo.open("exaustivo.txt",fstream::out);
		archivo<<"solucion"<<n<<"*"<<n<<endl<<endl;
		contador=0;
	}
	Alfil(int n1){
		n=n1;
		validar=new bool *[MAX];
		tablero=new char *[MAX];
		encerarTablero();
		crearArchivo();
	}
	void bloquear(int x, int y){
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
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}
	void mostrar(){
		contador++;
		archivo<<"solucion N "<<contador <<endl;
		cout<<"solucion N "<<contador <<endl;
		cout<<endl;
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				archivo<<*(*(tablero+i)+j)<<" ";
				cout<<*(*(tablero+i)+j)<<" ";
			}
			archivo<<endl;
			cout<<endl;
		}
		archivo<<endl;
		cout<<endl;
	}
	void quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				if(*(*(tablero +i)+j)=='A')
				bloquear(i,j);
			}	
		}
	}

	
	void solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='A';
		bloquear(x,y);
		if(n1==n){
			mostrar();
		}else{
			for(int i=0;i<MAX;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void solucionReinas(){
		for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			solucion(i,j,1);
		}
	}
		archivo.close();	
	}
};
int main(int argc, char** argv) {
	int n;
	cout<<"\tIngrese el numero de afiles"<<endl;
	Alfil *obj=new Alfil(4);
	obj->solucionReinas();
	cout<<"Se creo el archivo txt"<<endl;
	return 0;
}