#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "plateaujeu.h"
#include "console.h"

#define TOUCHEHAUT  56
#define TOUCHEBAS  50
#define TOUCHEGAUCHE  52
#define TOUCHEDROITE  54
#define ENTRER 13


void menu(Console*pConsole);
void debut(Console*pConsole);
void jeu(Console*pConsole);
void sauvegarder(int**tab);
void recup_sauvegarde(int**tab);
void initialiser_tableau(int**tab,Pion pions[NBPIONS]);
void actualisertab(int **tab, Pion pions[NBPIONS],int ligne, int colonne);
bool gestion_curseur(Console*pConsole,int &ligne, int &colonne, int**tab);
void poserpions(Pion pions[NBPIONS], int ligne, int colonne, int**tab, int tour);

#endif // JEU_H_INCLUDED
