#include <string>

using namespace std;

/*

	Définition d'un nouveau nom (un alias) pour un nom de type qui existe déjà avec la clause "using ..."

	Syntaxe 1) : using nouveau_nom = type_existant ;
	Syntaxe 2) : using nouveau_nom = type_existant [taille] ;

*/

int main()
{
	// 1) définitions de types alias
	
	using Millimètres	= double;

	using Kilomètres	= unsigned long;
	using Km			= Kilomètres;		// on peut faire un alias d'un alias !

	using Twitte		= char [140];

	using CeciEstUnTypeAvecUnNomTresTresLong = string;
	using NomCourt = CeciEstUnTypeAvecUnNomTresTresLong;


	// 2) définition de variables avec ces nouveaux noms de types

	Millimètres largeur = 11.25, profondeur = 8.5, hauteur = 0.88;

	Kilomètres distance = 14;
	Km vitesse = 300000;

	Twitte message = "Compilé c'est livré ! :)";


	/*
		NOTES

		1: Ces nouveaux noms de types sont remplacés par leur types sous-tendant lors de la compilation

		2: Permet d'utiliser un nom plus évocateur pour le type employé
		3: Facilitera un changement ultérieur en modifiant seulement l'alias du type
		4: Simplifie la recherche par nom de type dans un programme.
		5: Permet de spécifier un nom abrégé pour un type.

		6: Techniquement, l'utilisation de cet outil du langage ne cré pas un nouveau type mais seulement un nouveau nom.
		7: Historiquement, le concept d'alias était (et est toujours) offert avec le mot clé "typedef" et une syntaxe différente.
		8: Il est recommandé maintenant d'utiliser using

		X: Le mot clé "using" permet aussi de gérer les "namespace", mais ce n'est pas la même chose.

	*/
}