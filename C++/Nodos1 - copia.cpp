//Practica 2.1: Lista inserta directa

#include<iostream>
using namespace std;
#include <string.h>

void imprimeNodos();
void InsertaNodo(char[15], char[30]);

typedef struct Nodoz {
	struct Nodoz* Ant;
	char NoCta[15];
	char Nombre[30];
	struct Nodoz* Sig;
};

Nodoz* Trabajo = NULL, * Inicio = NULL, * Final = NULL, * Trabajo2 = NULL;
Nodoz* Lizq = NULL, * Lder = NULL, * Lugar = NULL;

void main() {
	char clave[15], nombre[30];
	char otro = 's';
	while (otro == 's') {
		cout << "\n Clave "; cin >> clave;
		cout << "\n Nombre "; cin >> nombre;
		InsertaNodo(clave, nombre);
		cout << endl;
		imprimeNodos();
		cout << "\n Otro nodo s/n ?";
		cin >> otro;
	}
	imprimeNodos();
}

void InsertaNodo(char clave[15], char Nombre[30])
{
	char salir = 'n';
	int bandera = 0;
	Trabajo = (Nodoz*)malloc(sizeof(Nodoz));
	strcpy_s(Trabajo->NoCta, clave);
	strcpy_s(Trabajo->Nombre, Nombre);
	Trabajo->Ant = NULL;
	Trabajo->Sig = NULL;
	if (Inicio == NULL) { // nodo primero
		Inicio = Trabajo;
		Final = Trabajo;
	}
	else {
		//identificar lugar
		Lugar = Inicio;
		while (salir == 'n')
		{
			bandera = strcmp(clave, Lugar->NoCta);
			if (bandera < 0 || bandera == 0) {
				Lizq = Lugar->Ant;
				salir = 's';
			}
			else {
				Lugar = Lugar->Sig;
				if (Lugar == NULL) {
					Lder = NULL;
					salir = 's';
				}
			}

		}
		if (Lizq == NULL && Inicio == NULL) { //nodo es el inicio nuevo
			Lugar->Ant = Trabajo;
			Inicio = Trabajo;
			Trabajo->Sig = Lugar;
			Lizq = Inicio;
		}

		else if (Lder == NULL) {
			Final->Sig = Trabajo;
			Trabajo->Ant = Lugar;
			Final = Trabajo;
			Lder = Final;
		}
		else
		{
			Lizq->Sig = Trabajo;
			Trabajo->Ant = Lizq;
			Trabajo->Sig = Lugar;
			Lugar->Ant = Trabajo;
		}
	}
}

void imprimeNodos()
{
	Trabajo2 = Inicio;
	while (Trabajo2 != NULL) {
		cout << "\n" << Trabajo2->NoCta << "\t" << Trabajo2->Nombre;
		Trabajo2 = Trabajo2->Sig;
	}
}

char buscarLugar(char clave[15]) {
	char lado;
	int resultado = 0;
	Trabajo = Inicio;
	while (Trabajo != NULL) {
		resultado = strcmp(clave, Trabajo->NoCta);
		if (resultado < 0) {
			Lizq = Trabajo;
			lado = 'I';
			break;
		}
		Trabajo = Trabajo->Sig;
	}
	return lado;
}