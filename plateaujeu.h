#ifndef PLATEAUJEU_H_INCLUDED
#define PLATEAUJEU_H_INCLUDED

#define NBPIONS 64

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "console.h"
#include "pion.h"

#define LIGNE 8
#define COLONNE 8


#define HAUT 205
#define BAS 205
#define GAUCHE 186
#define DROIT 186
#define HAUTGAUCHE 201
#define HAUTDROIT 187
#define BASGAUCHE 200
#define BASDROIT 188
#define CROIX 206
#define DEMIBAS 203
#define DEMIHAUT 202
#define DEMIGAUCHE 204
#define DEMIDROIT 185

#define VIDE 0
#define SMILEY_NOIR 2
#define SMILEY_BLANC 1


using namespace std;

void affichage_plateau(Console*pConsole);
void affichage_tableau(int **tab,Console*pConsole);

void poserpion(Pion pions[NBPIONS], int ligne, int colonne, int**tab, int tour, int* pionselect);
bool adjacence(int ligne, int colonne, int**tab, int tour);


class Plateau
{
    private:

    public:

    Plateau();
    ~Plateau();


};

//void affichage(pConsole, pions, tour,joueur1,joueur2);


#endif // PLATEAUJEU_H_INCLUDED
