#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

void insertaNumeros(char[16]);
void Imprimir();
int siExiste(char[16]);

typedef struct Inventarios {
	struct Inventarios* Ant;
	char CodigoArticulo[16];
	char Nombre[40];
	struct Inventarios* Sig;
	double inventario;
};

Inventarios* Trabajo = NULL, * Inicio = NULL, * Lugar = NULL, * Final = NULL;

void main() {
	char codigo[16];
	int existe = 0;
	char otro = 's';
	do {
		cout << "\nTeclar codigo ";
		cin >> codigo;

		existe = siExiste(codigo);
		if (existe == 0)
		{
			insertaNumeros(codigo);
		}
		else {

			cout << "Ya existe";
		}
		Imprimir();
		cout << "Otro elemento s/n?";
		cin >> otro;
	} while (otro == 's' || otro == 'S');
}

void insertaNumeros(char codigo[16]) {
	Trabajo = (Inventarios*)malloc(sizeof(Inventarios));
	/* cout << "\nInserta codigo";
	cin >> Trabajo->CodigoArticulo; */
	strcpy_s(Trabajo->CodigoArticulo, codigo);
	cout << "\Nombre articulo";
	cin >> Trabajo->Nombre;
	cout << "\nInventario";
	cin >> Trabajo->inventario;
	Trabajo->Ant = NULL;
	Trabajo->Sig = NULL;
	if (Inicio == NULL) {
		Inicio = Trabajo;
	}
	else {
		Final->Sig = Trabajo;
		Trabajo->Ant = Final;
	}
	Final = Trabajo;
}

void Imprimir() {
	Trabajo = Inicio;
	double inventario = 0;
	cout << endl;
	while (Trabajo != NULL) {
		cout << Trabajo->CodigoArticulo << " " << Trabajo->inventario;
		inventario += Trabajo->inventario;
		Trabajo = Trabajo->Sig;
	}
	cout << "\ntotal [ ]\b\b\b" << inventario;
}

int siExiste(char Codigo[16]) {
	Lugar = Inicio;
	int existe = 0;

	while (Lugar != NULL)
	{
		if (strcmp(Lugar->CodigoArticulo, Codigo) == 0) {
			existe = 1;
			break;
		}
		else
		{
			Lugar = Lugar->Sig;
		}
	}
	return existe;
}