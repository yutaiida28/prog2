#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <ctime>
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
	{ Color::blk, '\x20' }
};

// AFFICHAGE DU CURSEUR

char cursor[3][3] =							// informations pour l'affichage du curseur
{
	{ '\xC9', '\xCB', '\xBB' },
	{ '\xCC', '\xCE', '\xB9' },
	{ '\xC8', '\xCA', '\xBC' }
};
//char curseur[CASE_Y][CASE_X] = { {}, {}, {} };


void affiche_titre()
{
	const string titre  = "D\x90""COUVREZ ET AMASSEZ 15 CASES $$$$";
	gotoxy((WIN_X - titre.size())/2,2);
	cout << titre;
}

void position(size_t c, size_t l, int i)
{
	gotoxy(START_X + (DELTA_X * c), START_Y + (DELTA_Y * l) + i);
}

void affiche_case(LC lc)
{
	Case box = {};
	
	box = damier[lc.l][lc.c];
	
	setcolor(map[box].color);
	string ligne(CASE_X, map[box].c);
	for (int i = 0; i < CASE_Y; i++)
	{
		position(lc.c, lc.l, i);
		cout << ligne;
	}	

}

void affiche_damier(LC lc)
{
	while (lc.l < LIG)
	{
		for (lc.c = 0; lc.c < COL; lc.c++)
		{
			affiche_case(lc);
		}
		lc.l++;
	}
	setcolor(Color::wht);
}

bool deplacement_dispo( LC lc)
{
	LC position = lc;
	Case box = {};
	int direction = 8;
	int option  = 8; 
	bool disponible = true;
	
	for (size_t i = 0; i < direction; i++)
	{
		lc = position;
		switch (i)			
		{
		case 0:		lc.c--; lc.l--; 	break;
		case 1:		lc.c;	lc.l--;		break;
		case 2:		lc.c++; lc.l--;		break;
		case 3:		lc.c--; lc.l;		break;
		case 4:		lc.c++; lc.l;		break;
		case 5:		lc.c--; lc.l++;		break;
		case 6:		lc.c;	lc.l++;		break;
		case 7:		lc.c++; lc.l++;		break;
		}
		box = damier[lc.l][lc.c]; 

		if (lc.l < 0 || lc.c < 0 || lc.l > LIG || lc.c > COL)
		{
			option--;
		}
		else if(box == CV)
		{
			option--;
		}

	}
	if (option == 0)
	{
		disponible = false;
	}
	return disponible;
}



int main()
{
	setwsize(WIN_Y, WIN_X);								// redimensionner la fenêtre de la console
	show(true);											// afficher (oui/non) le trait d'affichage de la console

	Move m;
	m.from = { 0,0 };										// coordonnée logique {l,c} du curseur au départ du jeu
	XY xy = { START_X , START_Y };
	LC lc = {};

	affiche_titre();									// affichez titre

	affiche_damier(lc);									//affichez damié
	
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
	
	

	Case box = {};
	m.to = { 0,0 };
	bool partie_en_cours = true;
	bool victoir = true;
	int point = 0;
	int deplacement = 0;
	bool chronometre = false;
	int  debut = 0;
	

	do
	{
			//afficher curseur
			//affiche_curseur(xy, & curseur[CASE_Y][CASE_X]);
		setcolor(Color::yel);					
		for (int yi = 0; yi < CASE_Y; yi++)
		{
			for (int xi = 0; xi < CASE_X; xi++)
			{
				gotoxy(xy.x + (DELTA_X * m.from.c) + xi, xy.y + (DELTA_Y * m.from.l) + yi);
				cout << curseur[yi][xi];
			}
		}
		setcolor(Color::wht);

			//afficher le pointage
		gotoxy(START_X + (DELTA_X * 11) - 3, START_Y + (DELTA_Y * LIG));

		setcolor(Color::grn);
		cout << "$$$$ : " << setw(2) << right << point;
		setcolor(Color::wht);
		cout << left;
		
		
		uint8_t v;
		bool valid = false;
		do
		{
			v = _getch();
			if (v == 0 || v == 224)
			{
				if (_kbhit())							// soyons prudent tout de même !
				{
					v = _getch();						// lire le code ascii suivant
					if (chronometre == false)			//chronometre
					{
						debut = time(0);

						chronometre = true;
					}
					
					
					switch (Ak(v))			// Ak(c) ==> convertir c en Ak
					{
					case Ak::up_left:		m.to.c--; m.to.l--; 	break;
					case Ak::up:			m.to.c; m.to.l--;		break;
					case Ak::up_right:		m.to.c++; m.to.l--;		break;
					case Ak::left:			m.to.c--; m.to.l;		break;
					case Ak::right:			m.to.c++; m.to.l;		break;
					case Ak::down_left:		m.to.c--; m.to.l++;		break;
					case Ak::down:			m.to.c; m.to.l++;		break;
					case Ak::down_right:	m.to.c++; m.to.l++;		break;
					}

					if (m.to.l >= 0 && m.to.c >= 0 && m.to.l < LIG && m.to.c < COL) // validation du deplacement (verifier qui ne sor pas du tableau)
					{
						if (damier[m.to.l][m.to.c] != CV)							// validation de la case si elle est accesible 
						{
							lc = m.from;
							affiche_case(lc);

							
							valid = true;
						}
						else
						{
							m.to = m.from;
							valid = false;
						}
					}
					else
					{
						m.to = m.from;
						valid = false;
					}
				}
			}

		} while (valid == false);	
		deplacement++; // calculer combien de d/placement
		

		position(0, LIG, 0);			//afficher de  ou on c'est deplacer a ou 
		setcolor(Color::yel);
		cout << "move : ( " << m.from.l << "," << m.from.c <<" )-- > ( " << m.to.l << "," << m.to.c <<")";
		setcolor(Color::wht);


		m.from = m.to;					// calculer combien de point on a cumuler
		box = damier[m.from.l][m.from.c];
		if (box == CD)
		{
			point++;
		}
		damier[m.from.l][m.from.c] = futur[box];

		lc = m.from; 
		if (deplacement_dispo(lc) == false)			// verrifier si la partie est fini si impossible de se deplacer
		{
			partie_en_cours = false;
			victoir = false;
		}
		else if (point == 15)						// v/rifier si on a pas completer le jeux 
		{
			partie_en_cours = false;
			victoir = true;
		}
		

	} while (partie_en_cours == true);

	clrscr();
	int fin = time(0);					//arret chronometre 
	char input = 'a';

	if (victoir == true)				// affichage victoire
	{
		setcolor(Color::grn);
		cout << "\n" << "VICTOIR ! \n\n";


	}
	else								// affichage de deffaite
	{
		setcolor(Color::red);
		cout << "\n" << "\x90""CHEC ! \n\n";
		
	}												// afficher detail  
	cout << setw(28) << "  Total des points" << ": " << point << " sur sur un objectif de 15\n\n";
	cout << setw(28) << "  Total des déplacements" << ": " << deplacement << endl << endl ;
	cout << setw(28) << "  Temps écoulé" << ": " << fin - debut << " sec" << endl << endl << endl;

	cout << "  Appuyez sur 'Q' pour quitter";

	do											//fonction pour quitter
	{
		input  = _getch();
		input = toupper(input);

	} while (input != 'Q');
	_getch();
}