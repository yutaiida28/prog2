#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// D�finition d'un tableau dont le type est une structure

int main()
{
	// 1) D�finition du type Livre
	struct Livre
	{
		string titre;
		string auteur;
		int pages;
	};

	// 2) D�finition d'une collection (un tableau) de Livre
	Livre collection[10]; // attention: chaque case du tableau est un Livre et permet donc de m�moriser les 3 informations d'un Livre

	// 3) Affecter un nouveau livre � l'indice 0 de la collection
	collection[0].titre = "Fundamentals of Algorithmics";
	collection[0].auteur = "Gilles Brassard";
	collection[0].pages = 524;

	// 4) Affecter un nouveau livre � l'indice 1 de la collection, syntaxe alternative
	collection[1] = { "Deep Learning" , "Yoshua Bengio" , 775 };

	// 5) Copier le contenu de la collection � l'indice 0 vers l'indice 2
	collection[2] = collection[0];

	// 6) Afficher le 3i�me livre de la collection
	cout
		<< "Titre  = " << collection[2].titre << endl
		<< "Auteur = " << collection[2].auteur;

	_getch();
}