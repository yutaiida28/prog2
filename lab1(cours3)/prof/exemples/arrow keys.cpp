#include <iostream>
#include <conio.h>

#include "../../cvm 23.h"

using namespace std;

/*

	Ce programme est un exemple pour lire les touches fl�ch�es (arrow keys) du clavier

	Elles peuvent provenir de deux endroits sur le clavier:

		1) 8 touches fl�ch�es disponibles avec le clavier num�rique (numpad), si celui-ci est d�verrouill� (touche du coin sup�rieur gauche du numpad)

		2) 4 touches fl�ch�es disponibles avec la section fl�ch�e (arrowpad) du clavier r�gulier

*/


enum class Arrowkeys		// �num�ration des touches fl�ch�es du clavier et leur code ascii respectif (num�ros en d�cimals)
{
	up_left		= 71,
	up			= 72,
	up_right	= 73,
	left		= 75,
	right		= 77,
	down_left	= 79,
	down		= 80,
	down_right	= 81,
};

using Ak = Arrowkeys;		// un alias plus concis


/*

NOTES:

	A) � chaque fois que l'on appuie sur une touche fl�ch�e, DEUX codes ascii sont ajout�s dans le tampon d'input

		1) le premier code ascii ajout� sera toujours un code r�serv� ayant soit le num�ro d�cimal 0 (s'il provient du numpad) ou soit 224 (s'il provient du arrowpad)
		
		2) le deuxi�me code ascci sera celui de la fl�che (ex: num�ro ascii 71 pour "up_left")

	B) Il faudra toujours v�rifier la pr�sence de ce code ascii sp�cial (0 ou 224) :
	
		s'il est pr�sent	--> lire le code suivant pour d�duire la touche fl�ch�e appuy�e

		sinon				--> il s'agira du code d'un caract�re r�gulier
	
	C) Remarqu� que "up_left" porte le code ascii 71 qui est le m�me que celui du 'G' majuscule, mais "up_left" aura envoy� un code r�serv� avant,
	   ce qui permettra de le distinguer du 'G'

	   exemple:

			TOUCHE CLAVIER APPUY�				TAMPON D'INPUT
				'G'						==>			71					touche r�guli�re du clavier
				up_left (numpad)		==>			0 (suivi de) 71		touche sp�ciale du clavier

*/

int main ()
{
	string out;
	const uint8_t ESCAPE = 27;			// "uint8_t" est un alias standard --> using uint8_t = unsigned char;

	uint8_t c;
	size_t x, y;

	gotoxy(3,5); cout << "Appuyez sur une touche fl\202ch\202e : "; x = wherex(); y = wherey();

	do
	{
		c = _getch();					// lire le premier code ascii du tampon
		gotoxy(x, y); clreol();

		if (c == 0 || c == 224)			// v�rifier s'il s'agit du code r�serv�. Si oui, il faut lire le code suivant
		{
			if (_kbhit())				// soyons prudent tout de m�me !
			{
				c = _getch();			// lire le code ascii suivant
				out = "";
				switch (Ak(c))			// Ak(c) ==> convertir c en Ak
				{
					case Ak::up_left:		out = "UP_LEFT";	break;
					case Ak::up:			out = "UP";			break;
					case Ak::up_right:		out = "UP_RIGHT";	break;
					case Ak::left:			out = "LEFT";		break;
					case Ak::right:			out = "RIGHT";		break;
					case Ak::down_left:		out = "DOWN_LEFT";	break;
					case Ak::down:			out = "DOWN";		break;
					case Ak::down_right:	out = "DOWN_RIGHT";	break;
				}
				cout << out;
			}
		}
		else
		{
			// ici pour traiter �ventuellement un caract�re r�gulier
		}
	}
	while (c != ESCAPE); // escape termine le programme
}