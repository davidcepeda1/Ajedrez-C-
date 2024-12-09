#include "FuncionesInterfaz.cpp"
#include "FuncionA.cpp"
int main(int argc, char** argv) {
	
	int n;
	cout<<"\tIngrese el numero de Reinasq"<<endl;
	cin>>n;
	Reina *rei=new Reina(n);
	FuncionesInterfaz *obj;
	obj= new FuncionesInterfaz(rei);
	obj->solucionReinas();
	cout<<"Se creo el archivo txt"<<endl;
	system("pause");
	
	
	Alfil *alfil=new Alfil(4);
	FuncionA *obj1;
	obj1= new FuncionA(alfil);
	obj1->solucionReinas();
	cout<<"Se creo el archivo txt"<<endl;
	return 0;
}

