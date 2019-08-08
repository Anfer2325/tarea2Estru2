#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>

#include <stdio.h>
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
class ArchivoItem
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

	void buscarSecuencial(const char* nombre) {
		ifstream input_file("items.dat", ios::binary);
		if (input_file) {


			input_file.seekg(0, ios::beg);
			item items;
			input_file.read(reinterpret_cast<char*> (&items), sizeof(item));
			while (!input_file.eof()) {
				if (strcmp(nombre, items.nombres) == 0)
				{
					cout << "Codigo: " << items.codigo << " Nombre: " << items.nombres << " Ciudad: " << items.ciudad << endl;
					break;
				}
				input_file.read(reinterpret_cast<char*> (&items), sizeof(item));
			}
			input_file.close();


		};
	};

	void buscarBinario(const char* nombre) {
		ifstream input_file("items.dat", ios::binary);
		if (input_file) {
			input_file.seekg(0, ios::end);
			int size = input_file.tellg();
			int tmp = 0;
			int total = size / sizeof(item);
			int it = total;
			item actual;
			while (true) {
				int mitad = it / 2;
				int bytes = (mitad*sizeof(item));
				//cout << " MITAD: " << mitad;
				int a;

				//cin >>a;
				input_file.seekg(bytes, ios::beg);
				input_file.read(reinterpret_cast<char*> (&actual), sizeof(item));
				//cout << actual.nombres;
				int result=strcmp(nombre, actual.nombres);
				// (l+r)/2= mitad de los limites;
				
				if (result < 0)
				{
					//cout << "Es menor";
					//menor
					total = mitad+1;
					it = tmp+total;
				}else if (result > 0)
				{
					//cout << "Es mayor";
					//mayor
					tmp = mitad-1;
					it = mitad + total;

				}
				else 
				{
					//cout << "HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
					//igual
					cout << "Se encontro " << actual.codigo << " "<< actual.nombres;
					
					break;
				}
				//sleep(500);
				
			}
		}
	}

};
