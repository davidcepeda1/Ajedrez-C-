#include "Tablero.h"
#include <iostream>
#include <fstream>
#include "Reina.cpp"
using namespace std;
class FuncionesInterfaz:public Tablero{
	
	public:
	fstream archivo;
	Reina *reina;
	FuncionesInterfaz(Reina *rei){
		this->reina=rei;
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