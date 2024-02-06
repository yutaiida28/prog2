#include <string>

using namespace std;

/*

	D�finition d'un nouveau nom (un alias) pour un nom de type qui existe d�j� avec la clause "typedef ..."

	NOTES:

		Historiquement, la clause "typedef" �tait utilis�e pour faire un alias de type, mais depuis C++ 11,
		il est plut�t recommand� d'utiliser la clause "using" � cet effet, la syntaxe �tant plus naturelle.

	Syntaxe 1) : typedef  type_existant  nouveau_nom;
	Syntaxe 2) : typedef  type_existant  nouveau_nom [Taille];

*/

int main()
{
	// Exemples de d�finitions de types alias

	typedef double Millim�tres;

	typedef unsigned long Kilom�tres;
	typedef Kilom�tres Km;

	typedef char Twitte [140];			// et non: typedef char [140] Twitte;

	typedef string  CeciEstUnTypeAvecUnNomTresTresLong;
	typedef CeciEstUnTypeAvecUnNomTresTresLong  NomCourt;
}