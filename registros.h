#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct item
{
	int codigo;
	char nombres[30];
	char apellidos[30];
	char ciudad[50];
	item() {

	};
};
class registros
{
public:
	void crearArchivo(int n) {


		for (int i = 0; i < n; i++)
		{
			item items;
			cout << "Ingrese codigo: " << endl;
			cin >> items.codigo;
			cout << "Ingrese el nombre: " << endl;
			cin >> items.nombres;
			cout << "Ingrese el apellido: " << endl;
			cin >> items.apellidos;
			cout << "Ingrese ciudad: " << endl;
			cin >> items.ciudad;
			ofstream myFile("historial.dat", ios::out | ios::binary | ios::app);
			//.seekp(0, ios::end);
			myFile.write(reinterpret_cast<const char*> (&items), sizeof(item));
			myFile.close();

		};
	};

	void buscarSecuencial(int codigo) {
		ifstream input_file("hisotrial.dat", ios::binary);
		if (input_file) {


			input_file.seekg(0, ios::beg);
			item items;
			input_file.read(reinterpret_cast<char*> (&items), sizeof(item));
			while (!input_file.eof()) {
				if(items.codigo == codigo)
				cout << "Codigo: " << items.codigo << " Nombre: " << items.nombres << " Ciudad: " << items.ciudad << endl;

				input_file.read(reinterpret_cast<char*> (&items), sizeof(item));
			}
			input_file.close();


		};
	};

};
