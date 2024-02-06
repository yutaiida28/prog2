#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "../../cvm 23.h"

using namespace std;

// TP1 DÉMO: AFFICHAGE DES CASES AVEC DE LA COULEUR


const size_t CASE_X = 10;					// largeur d'une case à l'affichage, 2 minimum
const size_t CASE_Y = 5;					// hauteur d'une case à l'affichage, 2 minimum


enum Case { CO, CS, CD, CF, CV };			// les différentes cases possibles: ordinaire, surprise, dollars, fragile, vide

struct XY									// coordonnée graphique (x,y) d'une case dans la console
{
	size_t x, y;
};

struct Style								// le style pour l'affichage d'une case
{
	Color color; char c;					// c est un caractère de remplissage pour afficher une case
};

Style map[5] =								// les style pour toutes les cases
{
	{ Color::blu, '\xB2' },					// ex: map[CO].c == '\xB2'
	{ Color::blu, '\xB2' },
	{ Color::grn, '\x24' },					// ex: map[CD].color == Color::grn 
	{ Color::pur, '\xB0' },
	{ Color::blk, '\x00' }
};

/*
	le type énuméré "Color" est spécifié dans le fichier cvm 21.h

	la fonction setcolor() permet de changer la couleur des prochains output (cout)

	la couleur initiale est le blanc: setcolor(Color::wht);
*/

void main()
{	
	XY xy;
	Case box;

	// TROIS MÉTHODES POUR AFFICHER UNE CASE EN COULEUR

	// MÉTHODE 1) -- caractère par caractère
	{
		box = CO;									// type de case
		xy = {10,5};								// coordonnée supérieure gauche de la case

		setcolor(map[box].color);					// la fonction setcolor est spécifiée dans cvm 21.h
		for (size_t y = 0; y < CASE_Y; ++y)	
		{
			gotoxy(xy.x, xy.y++);
			for (size_t x = 0; x < CASE_X; ++x)
				cout << map[box].c;
		}
		setcolor(Color::wht);						// remettre en blanc
	}

	// MÉTHODE 2) -- usage de setfill
	{
		box = CD;									// type de case
		xy.y += 2;									// coordonnée supérieure gauche de la case

		setcolor(map[box].color);					// choix de la couleur
		cout << setfill(map[box].c);				// choix du caractère de remplissage

		for (size_t y = 0; y < CASE_Y; ++y)
		{
			gotoxy(xy.x, xy.y++);
			cout << setw(CASE_X) << "";
		}

		cout << setfill(' ');						// remettre le setfill par défaut
		setcolor(Color::wht);						// remettre en blanc
	}

	// MÉTHODE 3) -- préfabriquer une string ligne 
	{
		box = CF;									// type de case
		xy.y += 2;									// coordonnée supérieure gauche de la case

		string ligne(CASE_X, map[box].c);			// préfabriquer une string

		setcolor(map[box].color);					// choix de la couleur
		for (size_t y = 0; y < CASE_Y; ++y)
		{
			gotoxy(xy.x, xy.y++);
			cout << ligne;
		}
		setcolor(Color::wht);						// remettre en blanc
	}

	_getch();
}