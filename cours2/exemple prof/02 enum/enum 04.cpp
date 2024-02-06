
// Définition d'un type énuméré

// Il est interdit pour deux types énumérés (donc distincs) de partager un quelconque nom d'élément dans leurs listes, l'intersection doit être vide,
// à moins de les isoler l'un de l'autre.

int main()
{
	// 1) Définition des types énumérés RVB et SPECTRE
	
	// enum RVB { ROUGE , VERT , BLEU };

	// enum SPECTRE { VIOLET , INDIGO , BLEU , VERT , JAUNE , ORANGE , ROUGE };

	// NOTE1: Le compilateur produira des erreurs car le BLEU, le VERT et le ROUGE sont redéfinis dans le type SPECTRE


	// 2) Solution: Isoler les définitions l'une de l'autre avec la clause "class" (ou "struct" qui est équivalente)

	enum class RVB { ROUGE, VERT, BLEU };

	enum class SPECTRE { VIOLET, INDIGO, BLEU, VERT, JAUNE, ORANGE, ROUGE };


	// 3) Définition de variables

	RVB rvb;

	SPECTRE spectre;


	// 4) Obligation d'utiliser le nom du type (comme un nom de famille) pour accéder à un élément de leur liste

	// Syntaxe:  Type::élément

	rvb = RVB::ROUGE;

	spectre = SPECTRE::ROUGE;


	// NOTE2: RVB::ROUGE est completement différent de SPECTRE::ROUGE ainsi que leur valeur entière respective

	// ex: spectre = RVB::ROUGE;  est interdit
}