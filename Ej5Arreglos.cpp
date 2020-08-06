#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
	int nro;
	int cant = 0;
	ifstream archilec;
	archilec.open("entreada.txt", ios::in);
	if (!archilec) {
		cout << "Error al tratar de abrir el archivo para lectura" << endl;
		return 1;
	}

	cout << "Leyendo el archivo" << endl;
	while (archilec >> nro) 
	{ 
		if (nro>0)
		{
			cant++;
		}
	}
	cout<<"los numeros mayores a 0 son: "<<cant;
	archilec.close();
	
	getch();
	return 0;
}
