#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition d'un type énuméré

int main()
{
	// 1) Définition du type énuméré "Mois" qui est une liste de 12 valeurs possibles
	enum Mois { JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC };

	// NOTE:
	//	À chacune des valeurs énumérées est associé un entier par défault:
	//		==> 0 pour le premier élément de la liste et augmenté de 1 pour les autres par la suite.
	//		==> JAN = 0, FEV = 1, ..., DEC = 11

	// 2) Définition d'une variable
	Mois mois;

	// 3) Affectation
	mois = JUL;		// mois contient l'entier 6
	
	// 4) Affichage
	cout << mois;  // affiche l'entier 6 et non "JUL"

	// 5) Opérateurs relationnels disponibles grâce aux entiers associés aux valeurs énumérées
	if (mois >= JUN && mois <= AOU)
		cout << "Nous sommes en vacances !!!" << endl;

	// 6) Hypothèse: Le type énuméré Mois pourrait être utilisé dans le programme pour les décisions logiques concernant les mois, alors
	// que le tableau suivant serait employé pour visualiser les valeurs en texte dans l'interface usager.

	string moistxt[12] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

	for (int m = JAN; m <= DEC; m++)
		cout << moistxt[m] << endl;

	_getch();
}