
// D�finition d'un type �num�r�

// Il est interdit pour deux types �num�r�s (donc distincs) de partager un quelconque nom d'�l�ment dans leurs listes, l'intersection doit �tre vide,
// � moins de les isoler l'un de l'autre.

int main()
{
	// 1) D�finition des types �num�r�s RVB et SPECTRE
	
	// enum RVB { ROUGE , VERT , BLEU };

	// enum SPECTRE { VIOLET , INDIGO , BLEU , VERT , JAUNE , ORANGE , ROUGE };

	// NOTE1: Le compilateur produira des erreurs car le BLEU, le VERT et le ROUGE sont red�finis dans le type SPECTRE


	// 2) Solution: Isoler les d�finitions l'une de l'autre avec la clause "class" (ou "struct" qui est �quivalente)

	enum class RVB { ROUGE, VERT, BLEU };

	enum class SPECTRE { VIOLET, INDIGO, BLEU, VERT, JAUNE, ORANGE, ROUGE };


	// 3) D�finition de variables

	RVB rvb;

	SPECTRE spectre;


	// 4) Obligation d'utiliser le nom du type (comme un nom de famille) pour acc�der � un �l�ment de leur liste

	// Syntaxe:  Type::�l�ment

	rvb = RVB::ROUGE;

	spectre = SPECTRE::ROUGE;


	// NOTE2: RVB::ROUGE est completement diff�rent de SPECTRE::ROUGE ainsi que leur valeur enti�re respective

	// ex: spectre = RVB::ROUGE;  est interdit
}