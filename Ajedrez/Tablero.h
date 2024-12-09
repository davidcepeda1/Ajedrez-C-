/***********************************************************************
 * Module:  Tablero.h
 * Author:  Jeimy
 * Modified: viernes, 27 de enero de 2023 9:03:04
 * Purpose: Declaration of the class Tablero
 ***********************************************************************/

#if !defined(__tablero_Tablero_h)
#define __tablero_Tablero_h

class Tablero
{
public:
   virtual void encerarTablero(void)=0;
   virtual void crearArchivo(void)=0;
   virtual void bloquear(int x, int y)=0;
   virtual void mostrar(void)=0;
   virtual void quitarRelleno(int x, int y)=0;
   virtual void solucion(int x, int y, int n1)=0;
   virtual void solucionReinas(void)=0;

protected:
private:

};

#endif

