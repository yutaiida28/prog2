#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition d'un type énuméré

int main()
{
	// 1) Définition du type énuméré "Direction" qui est une liste de 5 valeurs possibles
	enum Direction { NORD , SUD , EST , OUEST, INCONNU };

	// 2) Définition de la variable cap avec ce nouveau type
	Direction cap;

	// 3) L'affectation
	cap = NORD;

	// 4) Avec l'instruction de décision if
	if (cap == NORD)
		cap = SUD;		// virement de bord!

	// 5) Avec l'instruction de décision switch
	string le_lieu;
	switch (cap)
	{
		case NORD:	le_lieu = "le nord";	break;
		case SUD:	le_lieu = "le sud";		break;
		case EST:	le_lieu = "l'est";		break;
		case OUEST:	le_lieu = "l'ouest";	break;
		default:	le_lieu = "l'inconnu";	break;
	}
	cout << "ce dirige vers " << le_lieu << endl;

	// 6) Affectations défendues par le compilateur
	// cap = 4;
	// cap = "OUEST";

	_getch();
}