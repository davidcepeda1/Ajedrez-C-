#include "Alfil.cpp"
#include "Tablero.h"
using namespace std;
class FuncionA:public Tablero{
	
	public:
	fstream archivo;
	Alfil *alfil;
	FuncionA(Alfil *alf){
		cout<<"Constructor"<<endl;
		this->alfil=alf;
		this->encerarTablero();
		this->crearArchivo();
	}
	void encerarTablero(void);
   	void crearArchivo(void);
   	void bloquear(int x, int y);
   	void mostrar(void);
   	void quitarRelleno(int x, int y);
    void solucion(int x, int y, int n1);
    void solucionReinas(void);
	
		
};