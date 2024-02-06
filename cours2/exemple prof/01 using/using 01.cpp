#include <string>

using namespace std;

/*

	D�finition d'un nouveau nom (un alias) pour un nom de type qui existe d�j� avec la clause "using ..."

	Syntaxe 1) : using nouveau_nom = type_existant ;
	Syntaxe 2) : using nouveau_nom = type_existant [taille] ;

*/

int main()
{
	// 1) d�finitions de types alias
	
	using Millim�tres	= double;

	using Kilom�tres	= unsigned long;
	using Km			= Kilom�tres;		// on peut faire un alias d'un alias !

	using Twitte		= char [140];

	using CeciEstUnTypeAvecUnNomTresTresLong = string;
	using NomCourt = CeciEstUnTypeAvecUnNomTresTresLong;


	// 2) d�finition de variables avec ces nouveaux noms de types

	Millim�tres largeur = 11.25, profondeur = 8.5, hauteur = 0.88;

	Kilom�tres distance = 14;
	Km vitesse = 300000;

	Twitte message = "Compil� c'est livr� ! :)";


	/*
		NOTES

		1: Ces nouveaux noms de types sont remplac�s par leur types sous-tendant lors de la compilation

		2: Permet d'utiliser un nom plus �vocateur pour le type employ�
		3: Facilitera un changement ult�rieur en modifiant seulement l'alias du type
		4: Simplifie la recherche par nom de type dans un programme.
		5: Permet de sp�cifier un nom abr�g� pour un type.

		6: Techniquement, l'utilisation de cet outil du langage ne cr� pas un nouveau type mais seulement un nouveau nom.
		7: Historiquement, le concept d'alias �tait (et est toujours) offert avec le mot cl� "typedef" et une syntaxe diff�rente.
		8: Il est recommand� maintenant d'utiliser using

		X: Le mot cl� "using" permet aussi de g�rer les "namespace", mais ce n'est pas la m�me chose.

	*/
}