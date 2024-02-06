#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition de type à l'aide du concept de structure

int main()
{
	// 1) Définition du type Produit et de la variable pc
	using kilo = double;
	struct Produit
	{
		string nom;
		kilo poids;
		double prix;
	};

	Produit pc = { "Macbook Air", 1.06, 900 };


	// 2) Définition du type Film et de la constante culte
	using année = int;
	using minutes = int;
	struct Film
	{
		string titre;
		année date;
		minutes durée;
	};

	const Film culte = { "2001 Odyssée de l'espace", 1968, 149 };


	// 3) Définition du type Contact et de la variable prof
	struct Contact
	{
		string nom, courriel;
	};

	Contact prof;
	prof = { "Alain", "athiboutot@cvm.qc.ca" };

	_getch();
}