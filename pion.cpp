#include "pion.h"


Pion::Pion()
{
    m_couleur = 0;
    m_ligne = 0;
    m_colonne = 0;
    m_visible = 0;
}
Pion::~Pion() {}

///A ENLEVER
/*
void Pion::afficher__tabdepions(Console *pConsole, int l, int c)
{
	// Positionnement de l'affichage
	pConsole->gotoLigCol(l, c);

	// Affichage du pion
	pConsole->setColor(COLOR_WHITE);
	unsigned char pionNoir= 0;
    unsigned char pionBlanc = 1;

	if(getcouleur() == NOIR)


		std::cout << pionNoir;
	else
		std::cout << pionBlanc;


}
*/
/*
void affichage_pions(pConsole, pions, tour,joueur1,joueur2)
{
    if(tour == NOIR)
		std::cout << joueur1 << ", c'est a votre tour de jouer.";
    else
		std::cout << joueur2 << ", c'est a votre tour de jouer.";

    pConsole->gotoLigCol(3,0);

	// Affichage des pions
	for(unsigned int i = 0; i < NBPIONS; i++)
	{
		if(pions[i].getvisible()) // Afficher seulement si le pion est sur le plateau
			pions[i].afficher(pConsole, 8 + pions[i].getligne() * 2, 13 + pions[i].getcolonne() * 3);
	}

}
*/
