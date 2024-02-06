#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
// vos autres includes ici

#include "../../cvm 23.h"

// PRAGMA
#pragma warning (disable:6031)		// valeur de retour ignorée '_getch'
#pragma warning (disable:26812)		// type enum 'type-name' est non délimité. Préférez 'enum class' à 'enum' (enum.3)

using namespace std;

// DIMENSION DU DAMIER

const size_t LIG = 8, COL = 12;											// lignes et colonnes du damier

// POSITION DU DAMIER À LA CONSOLE

const size_t START_X = 10;												// x du coin supérieur gauche du damier dans la console
const size_t START_Y = 5;												// y du coin supérieur gauche du damier dans la console

// CARACTÉRISTIQUES DES CASES À LA CONSOLE

const size_t CASE_X = 6;												// largeur d'une case à l'affichage, 2 minimum
const size_t CASE_Y = 3;												// hauteur d'une case à l'affichage, 2 minimum

const size_t SPACE_X = 2;												// nombres de colonnes vides entre les cases, 1 minimum
const size_t SPACE_Y = 1;												// nombres de lignes vides entre les cases, 1 minimum

const size_t DELTA_X = CASE_X + SPACE_X;								// saut d'une case à l'autre, sur l'axe des X
const size_t DELTA_Y = CASE_Y + SPACE_Y;								// saut d'une case à l'autre, sur l'axe des Y

// DIMENSION DE LA FENÊTRE

const size_t WIN_X = 2 * START_X + (COL - 1) * DELTA_X + CASE_X;		// nombres de colonnes pour l'affichage d'une case
const size_t WIN_Y = 2 * START_Y + (LIG - 1) * DELTA_Y + CASE_Y;		// nombres de lignes   pour l'affichage d'une case

// COMMANDES

enum class Arrowkeys						// Code ascii décimal des touches fléchées du clavier
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

enum Case { CO, CS, CD, CF, CV };			// les différentes cases possibles: ordinaire, surprise, dollars, fragile, vide

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

// COOODONNÉE LOGIQUE D'UN DÉPLACEMENT 

struct LC									// ligne et colonne (l,c) d'une case du damier[l][c]
{
	size_t l, c;							// ligne: [0..LIG-1] -- colonne: [0..COL-1]
};

struct Move									// coordonnées des 2 cases impliquées dans un déplacement
{
	LC from, to;
};

// AFFICHAGE DES CASES

struct XY									// coordonnée graphique (x,y) d'une case dans la console
{
	size_t x, y;
};

struct Style								// le style pour l'affichage d'une case
{
	Color color; char c;					// le membre 'c' est le caractère à utiliser pour l'affichage
};

Style map[5] =								// les style pour toutes les cases
{
	{ Color::blu, '\xB2' },					// ex: map[CO].c == '\xB2'				==> le caractère à utiliser
	{ Color::blu, '\xB2' },
	{ Color::grn, '\x24' },					// ex: map[CD].color == Color::grn		==> la couleur à utiliser
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


int main()
{
	setwsize(WIN_Y, WIN_X);								// redimensionner la fenêtre de la console
	show(true);											// afficher (oui/non) le trait d'affichage de la console

	Move m;
	m.from = {0,0};										// coordonnée logique {l,c} du curseur au départ du jeu

	/*
		NOTE 1)

			m.to = {?,?};								// déterminer la case d'arrivée du curseur avec la direction de la flèche demandée
			
			// ex: flèche droite ==>

			m.to.l = m.from.l;							// la ligne n'a pas changée
			m.to.c = m.from.c + 1;						// déplacement d'une colonne vers la droite

		NOTE 2)

			if ( damier[m.to.l][m.to.c] == CD )		// pour vérifier de quelle case il s'agit dans le tableau damier
				...
		NOTE 3)

			Utilisez le calcul énoncé dans la spécification au point 10) pour retrouver la coordonnée graphique (x,y) d'une case à partir de sa coordonnée logique (l,c)

		NOTE 4)

			m.from = m.to;								// ne pas oublier que l'arrivée deviendra le départ du déplacement suivant

	*/


	// Continuez ici...
	//affichage titre est damié
	
	XY xy = {};
	LC lc = {};
	

	// titre

	//case
	gotoxy(START_X, START_Y);

	while (lc.l < LIG )
	{
		for (lc.c = 0 ; lc.c < COL; lc.c++)
		{
		xy.x = START_X;
		xy.y = START_Y;
		gotoxy(xy.x + (DELTA_X * lc.c), xy.y + (DELTA_Y * lc.l));
		cout << "a";
		lc.c++;

		}
		lc.l++;
		
		
		

	}
	_getch();
}