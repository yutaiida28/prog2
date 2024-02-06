#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition d'une structure dont un membre est une structure (structures imbriquées)

int main()
{
	// 1) Définition des types Maison, Espace, Dimension et Fonction

	using Pieds = int;
	
	enum Fonction { salon = 1, salle_de_bain, cuisine, chambre, boudoire, bureau, salle_de_jeu, lingerie, buanderie, solarium, garage };
	
	struct Dimension
	{
		Pieds largeur, longueur, hauteur;
	};

	struct Piece
	{
		Fonction fct;
		Dimension dim;
	};

	struct Etage
	{
		int pieces;			// le nombre de pièces sur l'étage, max 10
		Piece pi[10];
	};

	struct Maison
	{
		string proprio, adresse;
		double prix;

		int etages;			// le nombre d'étages, max 4
		Etage et[4];
	};


	// 2) Définition d'une variable m de type Maison et initialisée à zéro
	
	Maison m = {};

	// 3) affectation d'informations dans m

	m.prix = 900000;
	m.proprio = "Big Shot";
	m.adresse = "12 ave Dollars";
	m.etages = 3;


	// sous-sol 
	m.et[0].pieces = 2;

	//  sous-sol -- 1ère pièce
	m.et[0].pi[0].fct = garage;
	m.et[0].pi[0].dim.largeur = 15;
	m.et[0].pi[0].dim.longueur = 20;
	m.et[0].pi[0].dim.hauteur = 9;

	//  sous-sol -- 2ième pièce
	m.et[0].pi[1].fct = buanderie;
	m.et[0].pi[1].dim = { 10, 10, 9 };


	// 1er étage
	m.et[1].pieces = 4;
	m.et[1].pi[0] = { cuisine,			{20, 20, 9} };
	m.et[1].pi[1] = { salon,			{25, 25, 9} };
	m.et[1].pi[2] = { salle_de_bain,	{12, 12, 9} };
	m.et[1].pi[3] = { boudoire,			{10, 15, 9} };

	// 2ième étage
	m.et[2] = { 5, { {chambre, {20, 20, 9}} , {chambre, {15, 15, 9}} , {salle_de_bain, {12, 12, 9}} , {salle_de_bain, {8, 10, 9}} , {bureau, {10, 15, 9}} } };


	_getch();
}