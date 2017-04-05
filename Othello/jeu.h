#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <stdio.h>
#include <fstream>
#include "Plateau.h"
#include "console.h"


#define HAUT 205
#define BAS 205
#define GAUCHE 186
#define DROIT 186
#define HAUTGAUCHE 201
#define HAUTDROIT 187
#define BASGAUCHE 200
#define BASDROIT 188
#define VIDE 0
#define CROIX 206
#define DEMIBAS 203
#define DEMIHAUT 202
#define DEMIGAUCHE 204
#define DEMIDROIT 185

#define TOUCHEHAUT  56
#define TOUCHEBAS  50
#define TOUCHEGAUCHE  52
#define TOUCHEDROITE  54


void menu();
void sauvegarder(int**tab);
void recup_sauvegarde(int**tab);
void initialiser_plateau(int**tab);
void affichage(int**tab,Console*pConsole);
void gestion_curseur(Console*pConsole,int &ligne, int &colonne);

#endif // JEU_H_INCLUDED
