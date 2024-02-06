#include <conio.h>	// pour le _getch()
#include <string>	// pour le type string

using namespace std;

// Définition d'une Playlist de musique

const int MAX = 10;

enum Genre { ROCK, POP, JAZZ, BLUES, CLASSIQUE, ELECTRONIQUE, RAP };  // ajouter AUCUN au début

struct Chanson
{
	string titre;
	string artiste;
	Genre genre;
	int année;
	double durée;
};

struct Playlist
{
	int cpt;
	Chanson list[MAX];
};

void main()
{
	Chanson c;
	Playlist pl = {};

	c.titre = "Time";
	c.artiste = "Pink Floyd";
	c.genre = ROCK;
	c.année = 1973;
	c.durée = 6.53;

	// à l'indice 0
	pl.list[pl.cpt] = c;
	pl.cpt++;

	// à l'indice 1
	pl.list[pl.cpt] = c;
	pl.list[pl.cpt].titre = "Money";
	pl.list[pl.cpt].durée = 6.22;

	// à l'indice 2
	pl.list[pl.cpt++] = { "Us and Them", c.artiste, c.genre, 1973, 7.49 };

	// à l'indice 3
	pl.list[pl.cpt++] = { "Dazed and Confused", "Led Zeppelin", ROCK, 1969, 6.28 };

	_getch();
}