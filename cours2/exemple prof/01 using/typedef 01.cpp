#include <string>

using namespace std;

/*

	Définition d'un nouveau nom (un alias) pour un nom de type qui existe déjà avec la clause "typedef ..."

	NOTES:

		Historiquement, la clause "typedef" était utilisée pour faire un alias de type, mais depuis C++ 11,
		il est plutôt recommandé d'utiliser la clause "using" à cet effet, la syntaxe étant plus naturelle.

	Syntaxe 1) : typedef  type_existant  nouveau_nom;
	Syntaxe 2) : typedef  type_existant  nouveau_nom [Taille];

*/

int main()
{
	// Exemples de définitions de types alias

	typedef double Millimètres;

	typedef unsigned long Kilomètres;
	typedef Kilomètres Km;

	typedef char Twitte [140];			// et non: typedef char [140] Twitte;

	typedef string  CeciEstUnTypeAvecUnNomTresTresLong;
	typedef CeciEstUnTypeAvecUnNomTresTresLong  NomCourt;
}