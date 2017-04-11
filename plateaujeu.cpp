# include "plateaujeu.h"



void affichage_plateau(Console*pConsole)
{
    pConsole->gotoLigCol(3,0);
     unsigned char ascii[21][31]= {
    {HAUTGAUCHE,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUTDROIT},
    {GAUCHE,VIDE,VIDE,VIDE,97,VIDE,VIDE,98,VIDE,VIDE,99,VIDE,VIDE,100,VIDE,VIDE,101,VIDE,VIDE,102,VIDE,VIDE,103,VIDE,VIDE,104,VIDE,VIDE,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,HAUTGAUCHE,HAUT,HAUT,DEMIBAS,HAUT,HAUT,DEMIBAS,HAUT,HAUT,DEMIBAS,HAUT,HAUT,DEMIBAS,HAUT,HAUT,DEMIBAS,HAUT,HAUT,DEMIBAS,HAUT,HAUT,DEMIBAS,HAUT,HAUT,HAUTDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,49,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,50,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,51,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,52,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,53,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,54,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,55,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,DEMIGAUCHE,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,CROIX,HAUT,HAUT,DEMIDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,56,GAUCHE,VIDE,VIDE,GAUCHE,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,BASGAUCHE,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,DEMIHAUT,HAUT,HAUT,BASDROIT,VIDE,VIDE,DROIT},
    {GAUCHE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,VIDE,DROIT},
    {BASGAUCHE,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,HAUT,BASDROIT}};


    pConsole->setColor(COLOR_GREEN);
    //pConsole->gotoLigCol(3,0);

    for (int i=0; i<21; i++)
    {   cout<<"        ";
        for (int j=0; j<31; j++)
        {
            cout<< ascii[i][j];
        }
        cout <<endl;
    }

}


void affichage_tableau(int **tab,Console*pConsole)
{


    /// affichage tableau
    pConsole->setColor(COLOR_WHITE);

    for (int i=0; i<LIGNE; i++)
    {pConsole->gotoLigCol(6+2*i,12);
        for (int j=0; j<COLONNE; j++)
        {
            if((tab[i][j])==0) cout << char(VIDE); /// affichage rien
            if(tab[i][j]==2) cout << char(SMILEY_BLANC); /// affichage face noir
            if(tab[i][j]==1) cout << char(SMILEY_NOIR); /// affichage face blanche
            pConsole->gotoLigCol(6+2*(i+1)-2,15+3*j);
        }
        cout <<endl;
    }
}

void poserpion(Pion pions[NBPIONS], int ligne, int colonne, int**tab, int tour, int *pionselect)
 {
     ligne=(ligne-6)/2;
     colonne=(colonne-13)/3;
     pions[*pionselect].setvisible(1); ///Le pion devient visible
     pions[*pionselect].setligne(ligne);
     pions[*pionselect].setcolonne(colonne);
     if(tour==NOIR) tab[ligne][colonne]=1;
     if(tour==BLANC) tab[ligne][colonne]=2;
     (*pionselect)++;


 }

 ///retourne 0 si pas d'adjacence, 1 si adjacence
 bool adjacence(int ligne, int colonne, int**tab, int tour)
 {
     ligne=(ligne-6)/2;
     colonne=(colonne-13)/3;

     if (tour==NOIR)
     {
         if (((tab[ligne-1][colonne-1])== 2) || ((tab[ligne-1][colonne])== 2) || ((tab[ligne-1][colonne+1])== 2) || ((tab[ligne][colonne-1])== 2) || ((tab[ligne][colonne+1])== 2) || ((tab[ligne+1][colonne-1])== 2) || ((tab[ligne+1][colonne])== 2) || ((tab[ligne+1][colonne+1])== 2))
            return 1;

         else return 0;
     }

     ///Si toutes les cases adjacentes sont vides , return 0
     /*if ((tab[ligne-1][colonne-1]==0)&&(tab[ligne-1][colonne]==0)&&(tab[ligne-1][colonne+1]==0)&&(tab[ligne][colonne-1]==0)
         &&(tab[ligne][colonne+1]==0)&&(tab[ligne+1][colonne-1]==0)&&(tab[ligne+1][colonne]==0)&&(tab[ligne+1][colonne+1]==0))
     {
         return 0;
     }
     else*/

     else
     {
         if (((tab[ligne-1][colonne-1])== 1) || ((tab[ligne-1][colonne])== 1) || ((tab[ligne-1][colonne+1])== 1) || ((tab[ligne][colonne-1])== 1) || ((tab[ligne][colonne+1])== 1) || ((tab[ligne+1][colonne-1])== 1) || ((tab[ligne+1][colonne])== 1) || ((tab[ligne+1][colonne+1])== 1))
         return 1;

         else return 0;

     }


 }





