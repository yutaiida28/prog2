#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// D�finition d'une structure dont un membre est une structure (structures imbriqu�es)

int main()
{
	// 1) D�finition des types Eleve et Cours
	struct Eleve
	{
		int mat;
		string nom;
		double moy;
	};

	struct Cours
	{
		string prof;
		Eleve liste[30];
		double moy;
	};

	// 2) D�finition d'une variable de type Cours
	Cours c;

	// 3A) Initialiser la variable c
	c.prof = "Le Prof";
	c.moy = 0; // non encore calcul�e
	for (int e = 0; e < 30; ++e)
	{
		c.liste[e].mat = 0;
		c.liste[e].nom = "";
		c.liste[e].moy = 0;
	}

	// 3B) initialiser la liste d'�l�ves (syntaxe alternative)
	for (int e = 0; e < 30; ++e)
		c.liste[e] = {};			// attention: c.liste = {};  --> d�fendu  --> erreur de compilation

	// 3C) Initialiser la variable c (syntaxe alternative)
	c = { "Le Prof", {} , 0 };		// idem que 3A)

	// 4) D�finition d'une variable e de type Eleve et initialisation
	Eleve e;
	e.nom = "Pierre Roy";
	e.mat = 1069866;
	e.moy = 85.5;

	// 5) Affecter (copier) l'�l�ve e comme �tant le 10i�me �l�ve de la classe
	c.liste[9] = e;

	// 6) Affichage les infos du 10 i�me �l�ve de la classe 
	cout << "moyenne de " << c.liste[9].nom << " = " << c.liste[9].moy << endl;

	_getch();
}