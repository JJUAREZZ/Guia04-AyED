/*Una empresa fabrica y distribuye sus productos mediante su flota de vehículos. Cada vehículo
tiene asignado un código que es un número entero y los posibles valores van de 15 a 24. Se
tiene un archivo en el cual, por cada entrega realizada, se anota el código del vehículo que hizo.
Se pide hacer un programa que con los datos del archivo informe que vehículo (código) hizo la
mayor cantidad de entregas.
Nota: Usando el archivo datosG04E14.txt el resultado es: vehículo 17 con 15 entregas
*/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;


int main()
{
	ifstream archivo;
	archivo.open("datosG04E14.txt");
	if (archivo == NULL)
	{
		cout<<"No se pudo abrir el archivo";
		return 1;
	}
	
	cout<<"LEYENDO...."<<endl;
	// cuento la cantidad de elementos que hay en el archivo y los pongo en un vector
	int nro,cont=0;
	vector<int> codigo;
	while( archivo >> nro)
    {
   		codigo.push_back(nro);
   		cont++;
    }
    // ordeno el vector de forma descendente
    int aux;
	for (int i=0;i<cont;i++)
	{
		for (int j=0;j<cont;j++)
		{
			if (codigo[j] > codigo[j+1])
			{
				/*aux = codigo[j];
				codigo[j] = codigo[j+1];
				codigo[j+1] = aux;*/
				swap(codigo[j],codigo[j+1]);
			}
		}
	}
   	//luego de ordenar el vector, busco la cantidad de veces que se repite cierto valor y guardo el de mayor cantidad
   	int cant=0, cant_posta=0,num;
	for (int i=0;i<cont;i++)
	{
		cant=0;
		for (int j=0;j<cont;j++)
		{
			if (codigo[i] == codigo[j])
			{
				cant++;
			}
		}
		if (cant > cant_posta)
		{
			cant_posta = cant;
			num = codigo[i];
		}
	}
	cout<<"El vehiculo "<<num<<" hizo la mayor cantidad de entregas ("<<cant_posta<<" entregas)";
	
	archivo.close();
	getch();
	return 0;
}
