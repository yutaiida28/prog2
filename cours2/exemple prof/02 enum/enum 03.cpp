#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition de type énumérés avec des valeurs entières (int) explicitement spécifiées

int main()
{
	// 1) Définition du type énuméré Cadran avec des angles
	enum Cadran { ND = 0 , NE = 45 , ES = 90, SE = 135, SU = 180, SO = 225, OU = 270, NO = 315 } ;

	// 2) Définition du type énuméré Note avec un équivalent entier
	enum Note { AA = 100, A = 90, B = 80, C = 70 , D = 60, E = 50 };


	// 3) Définition du type énuméré Bidon avec des entiers quelconques
	enum Bidon { a, b, c = 0, d = a + 2, e };	// ici: a = 0, b = 1, c = 0, d = 2, e = 3

	// 4) Définition du type énuméré Autre
	enum Autre { V = 0, X = 2, Y = 2, Z = 0 };

	Autre autre = X;			// autre contient 2

	if (autre == Y)				// puisque que Y vaut 2, le test autre == Y est vrai
		cout << "vrai";


	// NOTES:
	/*

		1) le premier élément obtient la valeur 0 par défaut, à moins d'être explicitement donné
		2) tout autre élément prend la valeur de son précédant augmenté de 1, à moins d'être explicitement donné
		3) les éléments peuvent avoir comme valeur toute celle disponible d'un int, donc négative aussi
		4) des éléments peuvent aussi avoir les mêmes valeurs, mais ils deviendront indistingable mutuellement

	*/
}