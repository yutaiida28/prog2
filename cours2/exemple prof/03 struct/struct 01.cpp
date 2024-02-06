#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Définition de type à l'aide du concept de structure et son mot clé "struct"

int main()
{
	// 1) Définition du type Fraction
	struct Fraction
	{
		int num; // numérateur
		int div; // diviseur
	};

	// 2) Définition d'un variable de type Fraction	
	Fraction score;

	// 3) Affecter une valeur à chacun des membres de la variable score (i.e. num et div)
	// attention: utilisation de l'opérateur "." pour accéder à un membre de la structure
	score.num = 10;
	score.div = 15;

	// 4) Afficher la variable score
	cout << "score = " << score.num << "/" << score.div; // cout << score; --> erreur de compilation

	// 5) Calculer et afficher la valeur réelle de score
	double val = score.num;
	val /= score.div;
	cout << " = " << val;

	// 6) Affectation d'une nouvelle valeur à score: syntaxe alternative
	score = { 12 , 25 }; // num = 12 et div = 25

	// 7) Définition d'une autre variable de type Fraction 
	Fraction exam = { 85 , 100 };

	// 8) Copier le contenu de la variable exam dans score
	score = exam;

	// 9) NOTES
	// 1: Le nom d'un nouveau type devrait débuter par une majuscule
	// 2: le nom d'un membre d'une structure devrait débuter par une minuscule comme les variables

	_getch();
}