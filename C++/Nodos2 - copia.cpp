//práctica No 2.2.- inserta non par primos o no primo por valor
#include <iostream>
using namespace std;

void insertaNon(int);
void insertaPar(int);
void insertaPrimo(int);
void insertaNoPrimo(int);
int Menu();
void PideNumero();
int esPrimo(int);
void imprimeNoPrimo();
void imprimePrimo();
void imprimeNon();
void imprimePar();

typedef struct Registros {
	struct Registros* Ant;
	int Numero;
	struct Registros* Sig;
};

Registros* TraNon = NULL, * IniNon = NULL, * FinNon = NULL;
Registros* TraPar = NULL, * IniPar = NULL, * FinPar = NULL;
Registros* TraPrimo = NULL, * IniPrimo = NULL, * FinPrimo = NULL;
Registros* TraNoPrimo = NULL, * IniNoPrimo = NULL, * FinNoPrimo = NULL;

void main() {
	int op = 0;
	do {
		op = Menu();
		switch (op)
		{
		case 1: {PideNumero(); break; }
		case 2: { imprimeNon();
			imprimePar();
			imprimePrimo();
			imprimeNoPrimo();
			system("pause");
			break;
		}
		}
	} while (op != 3);
}

int Menu() {
	int op = 0;
	do {
		system("cls");
		cout << endl << "Opciones" << endl << "1.- Ingresar numero" << endl << "2.- Reportes" <<
			endl << "3.- salir" << endl << "Opcion [ ]\b\b";
		cin >> op;
	} while (op < 1 || op > 3);
	return op;
}

void PideNumero() {
	int Numero = 0;
	char otro = 's';
	do {
		system("cls");
		cout << endl << "Ingresa Numero [ ] \b\b\b\b";
		cin >> Numero;

		if ((Numero % 2) == 0)
			insertaPar(Numero);
		else
			insertaNon(Numero);
		if (esPrimo(Numero) <= 2)
			insertaPrimo(Numero);
		else
			insertaNoPrimo(Numero);
		cout << endl << "Otro Numero S/N ? ";
		cin >> otro;
	} while (otro == 's' || otro == 'S');
}

int esPrimo(int Numero) {
	int r = 0;
	int veces = 0;
	int x = 0;
	for (x = 1; x <= Numero; x++) {
		r = Numero % x;
		if (r == 0)
			veces++;
	}
	return veces;
}

void insertaNon(int Numero) {
	TraNon = (Registros*)malloc(sizeof(Registros));
	TraNon->Numero = Numero;
	TraNon->Ant = NULL;
	TraNon->Sig = NULL;

	if (IniNon == NULL) {
		IniNon = TraNon;
	}
	else {
		FinNon->Sig = TraNon;
		TraNon->Ant = FinNon;
	}
	FinNon = TraNon;
}

void insertaPar(int Numero) {
	TraPar = (Registros*)malloc(sizeof(Registros));
	TraPar->Numero = Numero;
	TraPar->Ant = NULL;
	TraPar->Sig = NULL;

	if (IniPar == NULL) {
		IniPar = TraPar;
	}
	else {
		FinPar->Sig = TraPar;
		TraPar->Ant = FinPar;
	}
	FinPar = TraPar;
}

void insertaPrimo(int Numero) {
	TraPrimo = (Registros*)malloc(sizeof(Registros));
	TraPrimo->Numero = Numero;
	TraPrimo->Ant = NULL;
	TraPrimo->Sig = NULL;

	if (IniPrimo == NULL) {
		IniPrimo = TraPrimo;
	}
	else {
		FinPrimo->Sig = TraPrimo;
		TraPrimo->Ant = FinPrimo;
	}
	FinPrimo = TraPrimo;
}

void insertaNoPrimo(int Numero) {
	TraNoPrimo = (Registros*)malloc(sizeof(Registros));
	TraNoPrimo->Numero = Numero;
	TraNoPrimo->Ant = NULL;
	TraNoPrimo->Sig = NULL;

	if (IniNoPrimo == NULL) {
		IniNoPrimo = TraNoPrimo;
	}
	else {
		FinNoPrimo->Sig = TraNoPrimo;
		TraNoPrimo->Ant = FinNoPrimo;
	}
	FinNoPrimo = TraNoPrimo;
}

void imprimeNon() {
	int coontador = 0;
	int tsuma = 0;
	TraNon = IniNon;
	cout << endl << "NON" << endl;
	while (TraNon != NULL) {
		cout << TraNon->Numero << " ";
		coontador++;
		tsuma += TraNon->Numero;
		TraNon = TraNon->Sig;
	}
	cout << endl << "Total Numeros " << coontador;
	cout << endl << "La suma es " << tsuma;
}

void imprimePar() {
	int coontador = 0;
	int tsuma = 0;
	TraPar = IniPar;
	cout << endl << "Par" << endl;
	while (TraPar != NULL) {
		cout << TraPar->Numero << " ";
		coontador++;
		tsuma += TraPar->Numero;
		TraPar = TraPar->Sig;
	}
	cout << endl << "Total Numeros " << coontador;
	cout << endl << "La suma es " << tsuma;
}

void imprimePrimo() {
	int coontador = 0;
	int tsuma = 0;
	TraPrimo = IniPrimo;
	cout << endl << "Primos" << endl;
	while (TraPrimo != NULL) {
		cout << TraPrimo->Numero << " ";
		coontador++;
		tsuma += TraPrimo->Numero;
		TraPrimo = TraPrimo->Sig;
	}
	cout << endl << "Total Numeros " << coontador;
	cout << endl << "La suma es " << tsuma;
}
void imprimeNoPrimo() {
	int coontador = 0;
	int tsuma = 0;
	TraNoPrimo = IniNoPrimo;
	cout << endl << "No primos" << endl;
	while (TraNoPrimo != NULL) {
		cout << TraNoPrimo->Numero << " ";
		coontador++;
		tsuma += TraNoPrimo->Numero;
		TraNoPrimo = TraNoPrimo->Sig;
	}
	cout << endl << "Total Numeros " << coontador;
	cout << endl << "La suma es " << tsuma;
}