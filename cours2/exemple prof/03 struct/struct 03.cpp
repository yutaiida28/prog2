#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition d'un tableau dont le type est une structure

int main()
{
	// 1) Définition du type Livre
	struct Livre
	{
		string titre;
		string auteur;
		int pages;
	};

	// 2) Définition d'une collection (un tableau) de Livre
	Livre collection[10]; // attention: chaque case du tableau est un Livre et permet donc de mémoriser les 3 informations d'un Livre

	// 3) Affecter un nouveau livre à l'indice 0 de la collection
	collection[0].titre = "Fundamentals of Algorithmics";
	collection[0].auteur = "Gilles Brassard";
	collection[0].pages = 524;

	// 4) Affecter un nouveau livre à l'indice 1 de la collection, syntaxe alternative
	collection[1] = { "Deep Learning" , "Yoshua Bengio" , 775 };

	// 5) Copier le contenu de la collection à l'indice 0 vers l'indice 2
	collection[2] = collection[0];

	// 6) Afficher le 3ième livre de la collection
	cout
		<< "Titre  = " << collection[2].titre << endl
		<< "Auteur = " << collection[2].auteur;

	_getch();
}