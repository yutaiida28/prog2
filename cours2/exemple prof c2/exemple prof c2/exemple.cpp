#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
/*
	//definition alias créer un nouveaux nom avec 'using
	//syntaxe1 using nouveau_nom = type_existant;
	//syntaxe2 using nouveau_nom = type_existant[taille];

	//1)definition de type 
	using Millimètre = double;
	using kilometre = unsigned long;
	using km = kilometre;

	using CeNomEstBoucoupTropLong = string;
	using NomCout = CeNomEstBoucoupTropLong;

	//2)definition de variable avec cesnouveux nom de type
	Millimètre largeur = 11.25, profondeur = 8.5, hauteur = 0.88;
*/
/*
	//type enumerer

	//1) définition du type énuméré "direction" qui est une liste de 5 valeurs possible
	enum Direction {N,S,E,O,INCONNU}; // on commance a conter a 0 puis ++ pour chaque valeur 
	//si notre bousole est numerique on peut donner un definition a chaquevaleur ex: enum Direction {N = 0,S = 180,E = 90,O = 270,INCONNU};
	//2) définition de la variable cap avec ce nouveau type
	Direction cap;
	//3) Laffectation
	cap = INCONNu;	//le compilateur verifife dans la liste s'il existe

	//4) avec l'instruction de désision if
	if (cap == N)
		cap = S;	// virement de bord ne pas oublier que on peut seulment metre des valleur de de la liste donc {N,S,E,O,INCONNU}

*/
	//structure
	/*
	les coordoner suivante sont utile seulment quand il sont ensemble donc il faut les encapsuler(x,y,z)avec structure
	int x;
	int y;
	int z;
	
	//donc on fait 
	struct Position
	{
		int x;
		int y;
		int z;
		// ne pas oublier que s'il ny a rien a a lintérieur sa peux briser donc mettre {} pour mettre rien
	};
	//dont lorsque on fait alias on fait un gros contenant avec trois partie deplus sont inseparable
	Position pos; 
	// si on met: Position pos, posv2; on créer 2 fois le meme contenant different pis on peut copier pos su posv2 : posv2 = pos
	// si multiple position on peut faire un tableau EX: Position pos[10] donc il il ya 10 position 
	// donc pos = un tableu pos[0] = une position (la premiere)
	*/




	

	

	_getch();
}