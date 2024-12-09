/***********************************************************************
 * Module:  Reina.h
 * Author:  Jeimy
 * Modified: viernes, 27 de enero de 2023 8:58:41
 * Purpose: Declaration of the class Reina
 ***********************************************************************/

#if !defined(__tablero_Reina_h)
#define __tablero_Reina_h
#include <fstream>
using namespace std;
class Reina
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
   Reina(int n1);
   ~Reina();

public:

   bool **validar;
   char **tablero;
   fstream archivo;
   int contador;
   int n;


};

#endif