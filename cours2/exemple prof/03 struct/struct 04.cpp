#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition d'une structure dont un membre est un tableau

int main()
{
	// 1) Définition du type Vecteur3D, Axe et Scalaire
	enum Axe { x, y, z };
	using Scalaire = double;

	struct Vecteur3D
	{
		Scalaire xyz[3];
		Scalaire longueur;
	};

	// 2) Définition d'une variable v de type Vecteur3D et son initialisation
	Vecteur3D v;
	v.xyz[x] = 12.5;
	v.xyz[y] = 15.8;
	v.xyz[z] = 22.1;
	v.longueur = 0; // non encore calculée

	// 3) Calcul de la longueur de v ==> sqrt ( (x)2 + (y)2 + (z)2 )
	for (int i = 0; i < 3; ++i)
		v.longueur += v.xyz[i] * v.xyz[i];
	v.longueur = sqrt(v.longueur);

	// 4) Affichage des infos de v
	cout << "x = " << v.xyz[x] << "\n" << "y = " << v.xyz[y] << "\n" << "z = " << v.xyz[z] << "\n\n";
	cout << "longueur = " << v.longueur;

	// 5) Réinitialiser à zéro toutes les infos de v (5 façons: explicite à totalement implicite)
	
	v = { { 0, 0, 0 }, 0 };
	v = { { 0, 0, 0 }    };

	v = { {         }, 0 };
	v = { {         }    };

	v = {                };

	_getch();
}