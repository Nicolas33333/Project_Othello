#include "jeu.h"
#include "Plateau.h"

void menu()
 {
    system("cls");
	Console* pConsole = NULL;
	/// Alloue la mémoire du pointeur
	pConsole = Console::getInstance();

     cout << "Jeu Othello"<<endl;


     /// création du plateau
     int** tab= new (int*[LIGNE]);
     for (int i=0; i<LIGNE; i++)
     {
         tab[i]=new int[COLONNE];
     }

     ///initialisation du plateau au début du jeu
    initialiser_plateau(tab);


    /*char caractere;
    caractere = getch();
    if (caractere == 'P' || caractere == 'p') {system("PAUSE");} ///Faire pause
    if (caractere == 'R' || caractere == 'r')*/ recup_sauvegarde(tab);

        affichage(tab, pConsole);


        sauvegarder(tab); /// sauvegarder la partie.

        int ligne=8;
        int colonne=13;
        //int*pos=new int[ligne,colonne];

    while(1)
    {

        gestion_curseur(pConsole,ligne,colonne);
    }

    ///Liberer place mémoire tab
    for (int i=0; i < LIGNE; i++)
    {
        delete[] tab[i];
    }
    delete[] tab ;
 }


 void sauvegarder(int**tab)
 {

    ofstream fic("sauvegarde.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

    if(fic)  /// si l'ouverture du fichier est réussi
        {
            for (int i=0;i < LIGNE; i++)
            {
                for (int j=0; j<COLONNE; j++)
                {
                    fic << tab[i][j]<< " ";
                }
                 fic << endl;
            }

            fic.close();  /// on ferme le fichier
        }
        else cout << "Problème d'ouverture fichier sauvegrade.txt" << endl;
}



 void recup_sauvegarde(int**tab)
 {
     ifstream fic("sauvegarde.txt", ios::in);  /// on ouvre le fichier en lecture

    if(!fic) ///si ouverture non réussie
    {
        std::cout << "Problème ouverture fichier sauvegarde.txt";
    }
    else
    {
        for(int i=0; i<LIGNE; i++)
        {
            for (int j=0; j< COLONNE; j++)
            {
                 fic >> tab[i][j];
            }
        }
    }



 }


void gestion_curseur(Console *pConsole, int &ligne, int &colonne )
 {
     ///on récupère le caractère tappé
    char caractere = getch();

    ///on modifie l'endroit du curseur avec les touches 2,4,6,8 + blindage
    if ((caractere == TOUCHEHAUT)&&(ligne>7)) { pConsole->gotoLigCol((ligne-2),colonne), (ligne)=(ligne-2 ); }
    if ((caractere == TOUCHEBAS)&&(ligne<20)) { pConsole->gotoLigCol((ligne+2),colonne), (ligne)=(ligne+2) ; }
    if ((caractere == TOUCHEGAUCHE)&&(colonne >13)) { pConsole->gotoLigCol(ligne,(colonne-3)), (colonne)=(colonne-3) ; }
    if ((caractere == TOUCHEDROITE)&&(colonne< 33)) { pConsole->gotoLigCol(ligne,(colonne+3)), (colonne) =(colonne+3) ; }


 }


void initialiser_plateau(int **tab)
{
     for (int i=0; i< LIGNE; i++)
     {
         for (int j=0; j< COLONNE; j++)
          {
              tab[i][j]=0;
          }
     }
}

void affichage(int **tab,Console*pConsole)
{


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
    pConsole->gotoLigCol(3,0);
    for (int i=0; i<21; i++)
    {   cout<<"        ";
        for (int j=0; j<31; j++)
        {
            cout<< ascii[i][j];
        }
        cout <<endl;
    }

   /// affichage contenu du tableau
    pConsole->setColor(COLOR_WHITE);
    for (int i=0; i<LIGNE; i++)
    {//pConsole->gotoLigCol(6+2*i,12);
        for (int j=0; j<COLONNE; j++)
        {
            cout<< tab[i][j];
            pConsole->gotoLigCol(6+2*i,12+3*j);
        }
        cout <<endl;
    }

}
