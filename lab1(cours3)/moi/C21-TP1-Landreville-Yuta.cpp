#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
// vos autres includes ici

#include "../../cvm 23.h"

// PRAGMA
#pragma warning (disable:6031)		// valeur de retour ignor�e '_getch'
#pragma warning (disable:26812)		// type enum 'type-name' est non d�limit�. Pr�f�rez 'enum class' � 'enum' (enum.3)

using namespace std;

// DIMENSION DU DAMIER

const size_t LIG = 8, COL = 12;											// lignes et colonnes du damier

// POSITION DU DAMIER � LA CONSOLE

const size_t START_X = 10;												// x du coin sup�rieur gauche du damier dans la console
const size_t START_Y = 5;												// y du coin sup�rieur gauche du damier dans la console

// CARACT�RISTIQUES DES CASES � LA CONSOLE

const size_t CASE_X = 6;												// largeur d'une case � l'affichage, 2 minimum
const size_t CASE_Y = 3;												// hauteur d'une case � l'affichage, 2 minimum

const size_t SPACE_X = 2;												// nombres de colonnes vides entre les cases, 1 minimum
const size_t SPACE_Y = 1;												// nombres de lignes vides entre les cases, 1 minimum

const size_t DELTA_X = CASE_X + SPACE_X;								// saut d'une case � l'autre, sur l'axe des X
const size_t DELTA_Y = CASE_Y + SPACE_Y;								// saut d'une case � l'autre, sur l'axe des Y

// DIMENSION DE LA FEN�TRE

const size_t WIN_X = 2 * START_X + (COL - 1) * DELTA_X + CASE_X;		// nombres de colonnes pour l'affichage d'une case
const size_t WIN_Y = 2 * START_Y + (LIG - 1) * DELTA_Y + CASE_Y;		// nombres de lignes   pour l'affichage d'une case

// COMMANDES

enum class Arrowkeys						// Code ascii d�cimal des touches fl�ch�es du clavier
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

using Ak = Arrowkeys;						// un alias plus concis

// CASES, DAMIER ET TRANSFORMATIONS

enum Case { CO, CS, CD, CF, CV };			// les diff�rentes cases possibles: ordinaire, surprise, dollars, fragile, vide

Case damier[LIG][COL] =						// le damier et ses cases initiales
{
	{ CO, CO, CO, CO, CO, CO, CO, CO, CV, CO, CO, CS },
	{ CO, CO, CV, CV, CO, CO, CO, CO, CO, CV, CO, CV },
	{ CO, CO, CV, CS, CV, CO, CO, CO, CO, CO, CV, CS },
	{ CO, CO, CV, CS, CV, CO, CO, CV, CV, CO, CV, CS },
	{ CS, CO, CV, CV, CV, CS, CV, CO, CV, CO, CV, CO },
	{ CS, CO, CS, CS, CO, CS, CV, CS, CV, CO, CV, CO },
	{ CS, CO, CS, CO, CO, CO, CV, CV, CV, CO, CV, CO },
	{ CS, CS, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO }
};

Case futur[5] = { CF, CD, CF, CV, CV };		// la liste des transformations possibles  --  ex: futur[CO] ==> CF

// COOODONN�E LOGIQUE D'UN D�PLACEMENT 

struct LC									// ligne et colonne (l,c) d'une case du damier[l][c]
{
	size_t l, c;							// ligne: [0..LIG-1] -- colonne: [0..COL-1]
};

struct Move									// coordonn�es des 2 cases impliqu�es dans un d�placement
{
	LC from, to;
};

// AFFICHAGE DES CASES

struct XY									// coordonn�e graphique (x,y) d'une case dans la console
{
	size_t x, y;
};

struct Style								// le style pour l'affichage d'une case
{
	Color color; char c;					// le membre 'c' est le caract�re � utiliser pour l'affichage
};

Style map[5] =								// les style pour toutes les cases
{
	{ Color::blu, '\xB2' },					// ex: map[CO].c == '\xB2'				==> le caract�re � utiliser
	{ Color::blu, '\xB2' },
	{ Color::grn, '\x24' },					// ex: map[CD].color == Color::grn		==> la couleur � utiliser
	{ Color::pur, '\xB0' },
	{ Color::blk, '\x00' }
};

// AFFICHAGE DU CURSEUR

char cursor[3][3] =							// informations pour l'affichage du curseur
{
	{ '\xC9', '\xCB', '\xBB' },
	{ '\xCC', '\xCE', '\xB9' },
	{ '\xC8', '\xCA', '\xBC' }
};


void affiche_titre()
{
	const string titre  = "D\x90""COUVREZ ET AMASSEZ 15 CASES $$$$";
	gotoxy((WIN_X - titre.size())/2,2);
	cout << titre;
}
/*void affiche_curseur(XY, curseur[CASE_Y][CASE_X])
{
	for (int yi = 0; yi < CASE_Y; yi++)
	{
		for (int xi = 0; xi < CASE_X; xi++)
		{
			gotoxy(xy.x + (DELTA_X * m.from.c) + xi, xy.y + (DELTA_Y * m.from.l) + yi);
			cout << curseur[yi][xi];
		}
	}
	setcolor(Color::wht);
}
*/
void affiche_case(int c, size_t l, size_t x)
{
	Case box;
	
	
	for (c = 0; c < CASE_Y; c++)
	{
		string ligne(CASE_X, map[c].c);
		for (int i = 0; i < CASE_Y; i++)
		{
			gotoxy(START_X + (DELTA_X * c), START_Y + (DELTA_Y * l) + i);
			cout << ligne;
		}
	}
		

}
int main()
{
	
	setwsize(WIN_Y, WIN_X);								// redimensionner la fen�tre de la console
	show(true);											// afficher (oui/non) le trait d'affichage de la console

	Move m;
	m.from = {0,0};										// coordonn�e logique {l,c} du curseur au d�part du jeu

	/*
		NOTE 1)

			m.to = {?,?};								// d�terminer la case d'arriv�e du curseur avec la direction de la fl�che demand�e
			
			// ex: fl�che droite ==>

			m.to.l = m.from.l;							// la ligne n'a pas chang�e
			m.to.c = m.from.c + 1;						// d�placement d'une colonne vers la droite

		NOTE 2)

			if ( damier[m.to.l][m.to.c] == CD )		// pour v�rifier de quelle case il s'agit dans le tableau damier
				...
		NOTE 3)

			Utilisez le calcul �nonc� dans la sp�cification au point 10) pour retrouver la coordonn�e graphique (x,y) d'une case � partir de sa coordonn�e logique (l,c)

		NOTE 4)

			m.from = m.to;								// ne pas oublier que l'arriv�e deviendra le d�part du d�placement suivant

	*/

	// Continuez ici...
	//affichage titre est dami�
	
	XY xy = { START_X , START_Y };
	LC lc = {};
	
	// affichez titre
	affiche_titre();

	//affichez dami�
	{
	Case box = {};
	

	while (lc.l < LIG)
	{
		for (lc.c = 0; lc.c < COL; lc.c++)
		{
			box = damier[lc.l][lc.c];
			//int a = box;
			affiche_case(box,lc.c, lc.l);
			
			//setcolor(map[box].color);
			//string ligne(CASE_X, map[box].c);

			//for (int i = 0; i < CASE_Y; i++)
			//{
			//	gotoxy(xy.x + (DELTA_X * lc.c), xy.y + (DELTA_Y * lc.l) + i);
			//	cout << ligne;
			//}
		}
		lc.l++;
	}
	setcolor(Color::wht);
	}
	gotoxy(START_X, START_Y);
	

	//structure curseur
	
	int curseurx = 0;
	int curseury = 0;

	char curseur[CASE_Y][CASE_X] = {};
	for (curseury = 0; curseury < CASE_Y; curseury++)
	{
		for (curseurx = 0; curseurx < CASE_X; curseurx++)
		{

			if (curseury == 0)
			{
				curseur[curseury][curseurx] = { '\xCB' };
			}
			else  if (curseurx == 0)
			{
				curseur[curseury][curseurx] = { '\xCC' };
			}
			else  if (curseurx == CASE_X - 1)
			{
				curseur[curseury][curseurx] = { '\xB9' };
			}
			else if (curseury == CASE_Y - 1)
			{
				curseur[curseury][curseurx] = { '\xCA' };

			}
			else
			{
				curseur[curseury][curseurx] = { '\xCE' };
			}

		}
	}
	curseur[0][0] = { '\xC9' };
	curseur[0][CASE_X - 1] = { '\xBB' };
	curseur[CASE_Y - 1][0] = { '\xC8' };
	curseur[CASE_Y - 1][CASE_X - 1] = { '\xBC' };
	
	//afficher curseur
	//affiche_curseur(xy, & curseur[CASE_Y][CASE_X]);


	bool partie_en_cours = true;
	do
	{
		setcolor(Color::yel);					// la fonction setcolor est sp�cifi�e dans cvm 21.h
		for (int yi = 0; yi < CASE_Y; yi++)
		{
			for (int xi = 0; xi < CASE_X; xi++)
			{
				gotoxy(xy.x + (DELTA_X * m.from.c) + xi, xy.y + (DELTA_Y * m.from.l) + yi);
				cout << curseur[yi][xi];
			}
		}
		setcolor(Color::wht);

















	} while (partie_en_cours /*!*/ = false);

	
	_getch();
		
}