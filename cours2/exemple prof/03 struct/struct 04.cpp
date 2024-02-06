#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// D�finition d'une structure dont un membre est un tableau

int main()
{
	// 1) D�finition du type Vecteur3D, Axe et Scalaire
	enum Axe { x, y, z };
	using Scalaire = double;

	struct Vecteur3D
	{
		Scalaire xyz[3];
		Scalaire longueur;
	};

	// 2) D�finition d'une variable v de type Vecteur3D et son initialisation
	Vecteur3D v;
	v.xyz[x] = 12.5;
	v.xyz[y] = 15.8;
	v.xyz[z] = 22.1;
	v.longueur = 0; // non encore calcul�e

	// 3) Calcul de la longueur de v ==> sqrt ( (x)2 + (y)2 + (z)2 )
	for (int i = 0; i < 3; ++i)
		v.longueur += v.xyz[i] * v.xyz[i];
	v.longueur = sqrt(v.longueur);

	// 4) Affichage des infos de v
	cout << "x = " << v.xyz[x] << "\n" << "y = " << v.xyz[y] << "\n" << "z = " << v.xyz[z] << "\n\n";
	cout << "longueur = " << v.longueur;

	// 5) R�initialiser � z�ro toutes les infos de v (5 fa�ons: explicite � totalement implicite)
	
	v = { { 0, 0, 0 }, 0 };
	v = { { 0, 0, 0 }    };

	v = { {         }, 0 };
	v = { {         }    };

	v = {                };

	_getch();
}