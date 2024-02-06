#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// D�finition de type �num�r�s avec des valeurs enti�res (int) explicitement sp�cifi�es

int main()
{
	// 1) D�finition du type �num�r� Cadran avec des angles
	enum Cadran { ND = 0 , NE = 45 , ES = 90, SE = 135, SU = 180, SO = 225, OU = 270, NO = 315 } ;

	// 2) D�finition du type �num�r� Note avec un �quivalent entier
	enum Note { AA = 100, A = 90, B = 80, C = 70 , D = 60, E = 50 };


	// 3) D�finition du type �num�r� Bidon avec des entiers quelconques
	enum Bidon { a, b, c = 0, d = a + 2, e };	// ici: a = 0, b = 1, c = 0, d = 2, e = 3

	// 4) D�finition du type �num�r� Autre
	enum Autre { V = 0, X = 2, Y = 2, Z = 0 };

	Autre autre = X;			// autre contient 2

	if (autre == Y)				// puisque que Y vaut 2, le test autre == Y est vrai
		cout << "vrai";


	// NOTES:
	/*

		1) le premier �l�ment obtient la valeur 0 par d�faut, � moins d'�tre explicitement donn�
		2) tout autre �l�ment prend la valeur de son pr�c�dant augment� de 1, � moins d'�tre explicitement donn�
		3) les �l�ments peuvent avoir comme valeur toute celle disponible d'un int, donc n�gative aussi
		4) des �l�ments peuvent aussi avoir les m�mes valeurs, mais ils deviendront indistingable mutuellement

	*/
}