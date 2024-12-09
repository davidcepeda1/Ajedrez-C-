/***********************************************************************
 * Module:  Reina.h
 * Author:  Jeimy
 * Modified: viernes, 27 de enero de 2023 8:58:41
 * Purpose: Declaration of the class Reina
 ***********************************************************************/

#define __tablero_Reina_h
#include <fstream>

using namespace std;
class Alfil
{
public:
   bool** getValidar(void);
   void setValidar(bool **newValidar);
   char** getTablero(void);
   void setTablero(char **newTablero);
   fstream getArchivo(void);
   void setArchivo(fstream newArchivo);
   int getContador(void);
   void setContador(int newContador);
   int getN(void);
   void setN(int newN);
   Alfil(int n1);
   ~Alfil();
   void encerarTablero(void);
   	void crearArchivo(void);
   	void bloquear(int x, int y);
   	void mostrar(void);
   	void quitarRelleno(int x, int y);
    void solucion(int x, int y, int n1);
    void solucionReinas(void);

public:

   bool **validar;
   char **tablero;
   int contador;
   int n;
    	fstream archivo;


};
