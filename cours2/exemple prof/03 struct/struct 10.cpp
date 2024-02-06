#include <conio.h>	// pour le _getch()
#include <string>	// pour le type string

using namespace std;

// D�finition d'une Playlist de musique

const int MAX = 10;

enum Genre { ROCK, POP, JAZZ, BLUES, CLASSIQUE, ELECTRONIQUE, RAP };  // ajouter AUCUN au d�but

struct Chanson
{
	string titre;
	string artiste;
	Genre genre;
	int ann�e;
	double dur�e;
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
	c.ann�e = 1973;
	c.dur�e = 6.53;

	// � l'indice 0
	pl.list[pl.cpt] = c;
	pl.cpt++;

	// � l'indice 1
	pl.list[pl.cpt] = c;
	pl.list[pl.cpt].titre = "Money";
	pl.list[pl.cpt].dur�e = 6.22;

	// � l'indice 2
	pl.list[pl.cpt++] = { "Us and Them", c.artiste, c.genre, 1973, 7.49 };

	// � l'indice 3
	pl.list[pl.cpt++] = { "Dazed and Confused", "Led Zeppelin", ROCK, 1969, 6.28 };

	_getch();
}