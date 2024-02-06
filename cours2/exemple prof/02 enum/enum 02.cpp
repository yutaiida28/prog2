#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// D�finition d'un type �num�r�

int main()
{
	// 1) D�finition du type �num�r� "Mois" qui est une liste de 12 valeurs possibles
	enum Mois { JAN, FEV, MAR, AVR, MAI, JUN, JUL, AOU, SEP, OCT, NOV, DEC };

	// NOTE:
	//	� chacune des valeurs �num�r�es est associ� un entier par d�fault:
	//		==> 0 pour le premier �l�ment de la liste et augment� de 1 pour les autres par la suite.
	//		==> JAN = 0, FEV = 1, ..., DEC = 11

	// 2) D�finition d'une variable
	Mois mois;

	// 3) Affectation
	mois = JUL;		// mois contient l'entier 6
	
	// 4) Affichage
	cout << mois;  // affiche l'entier 6 et non "JUL"

	// 5) Op�rateurs relationnels disponibles gr�ce aux entiers associ�s aux valeurs �num�r�es
	if (mois >= JUN && mois <= AOU)
		cout << "Nous sommes en vacances !!!" << endl;

	// 6) Hypoth�se: Le type �num�r� Mois pourrait �tre utilis� dans le programme pour les d�cisions logiques concernant les mois, alors
	// que le tableau suivant serait employ� pour visualiser les valeurs en texte dans l'interface usager.

	string moistxt[12] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

	for (int m = JAN; m <= DEC; m++)
		cout << moistxt[m] << endl;

	_getch();
}