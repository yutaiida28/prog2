#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// D�finition de type � l'aide du concept de structure

int main()
{
	// 1) D�finition du type Produit et de la variable pc
	using kilo = double;
	struct Produit
	{
		string nom;
		kilo poids;
		double prix;
	};

	Produit pc = { "Macbook Air", 1.06, 900 };


	// 2) D�finition du type Film et de la constante culte
	using ann�e = int;
	using minutes = int;
	struct Film
	{
		string titre;
		ann�e date;
		minutes dur�e;
	};

	const Film culte = { "2001 Odyss�e de l'espace", 1968, 149 };


	// 3) D�finition du type Contact et de la variable prof
	struct Contact
	{
		string nom, courriel;
	};

	Contact prof;
	prof = { "Alain", "athiboutot@cvm.qc.ca" };

	_getch();
}