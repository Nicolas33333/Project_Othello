#include "jeu.h"
#include "plateaujeu.h"



void jeu(Console*pConsole)
 {
    system("cls");
    bool quit =  false;
     /// création du tableau qui va contenir les pions du jeu
     int** tab= new (int*[LIGNE]);
     for (int i=0; i<LIGNE; i++)
     {
         tab[i]=new int[COLONNE];
     }

     ///Initialisation d'un tab de pions, les 32 premiers sont noirs, les 32 autres blancs.
    Pion pions[NBPIONS];

	for(unsigned int i = 0; i < NBPIONS; i++)
	{
		if(i < 32)
			pions[i].setcouleur(0);/// couleur noire
		else
			pions[i].setcouleur(1); ///couleur blanche

	}


     ///initialisation du tableau au début du jeu -> tout à 0
    initialiser_tableau(tab, pions);

    //recup_sauvegarde(tab);


     ///Affichage du plateau vert
    affichage_plateau(pConsole);
    affichage_tableau(tab,pConsole);

    /// pour le curseur coin haut gauche du tab
    int ligne=6;
    int colonne=13;
    ///pour recuperer la val de la fn curseur si 1-> alors l'utilisateur à tapper Entrer
    bool c=0;
    int pionblancselect=32;
    int pionnoirsselect=0;

    int tour= NOIR; ///Les noirs commencent à jouer

    while(!quit)
    {

        c=gestion_curseur(pConsole,ligne,colonne, tab);
        if(c==0) c=gestion_curseur(pConsole,ligne,colonne,tab);
        else {///BOUCLE DE JEU

            ///Affichage :quel pions doit jouer.
            pConsole->setColor(COLOR_WHITE);
            pConsole->gotoLigCol(30,30);
            if(tour==NOIR) {  cout << "\nC'est aux pions Noirs de jouer "<<endl; }
            else {  cout << "\nC'est aux pions Blancs de jouer"<<endl; }
                ///fonction qui pose un pion de la bonne couleur et qui vérifie l'encadrement.


            /// Si la case est vide + que le pion encadre un/plusieurs pions adverse +adjacence
            if ( (tab[(ligne-6)/2][(colonne-13)/3]==0)/*&&(adjacence(ligne,colonne,tab))*/ )
            {
                 if(tour==NOIR) poserpion(pions,ligne, colonne,tab,tour,&pionnoirsselect); ///on pose un pion de la bonne couleur
                else poserpion(pions,ligne, colonne,tab,tour,&pionblancselect);
                /*cout<< "blanc"<<pionblancselect;
                cout << " Noir"<<pionnoirsselect;*/

                 /// On change de joueur
                if(tour == NOIR) tour = BLANC;
                else tour = NOIR;
            }
            else pConsole->gotoLigCol(30,30), cout << "Choisissez une autre case";

            ///Fin de jeu
            if ((pionblancselect==63)||(pionnoirsselect==31)) cout<<"fin de jeu, tous les pions sont posés"<<endl;
            ///+ test cas où joueur bloqué -> pas d'encadrement possible


                ///Affichage du tableau.
             affichage_tableau(tab,pConsole);






        }


    }



    ///Liberer place mémoire tab
    for (int i=0; i < LIGNE; i++)
    {
        delete[] tab[i];
    }
    delete[] tab ;
 }




bool gestion_curseur(Console *pConsole, int &ligne, int &colonne, int**tab )
 {
     ///on récupère le caractère tappé
    char caractere = 0;
    caractere= getch();

    if (caractere=='s') ///Sauvegarde de la partie
        {
            pConsole->gotoLigCol(30,20);
            cout << "Partie sauvegadee"<<endl;
            sauvegarder(tab); /// sauvegarder la partie.
        }


    ///on modifie l'endroit du curseur avec les touches 2,4,6,8 + blindage
    if ((caractere == TOUCHEHAUT)&&(ligne>7)) { pConsole->gotoLigCol((ligne-2),colonne), (ligne)=(ligne-2 ); }
    if ((caractere == TOUCHEBAS)&&(ligne<20)) { pConsole->gotoLigCol((ligne+2),colonne), (ligne)=(ligne+2); }
    if ((caractere == TOUCHEGAUCHE)&&(colonne >13)) { pConsole->gotoLigCol(ligne,(colonne-3)), (colonne)=(colonne-3) ; }
    if ((caractere == TOUCHEDROITE)&&(colonne< 33)) { pConsole->gotoLigCol(ligne,(colonne+3)), (colonne) =(colonne+3) ; }
    if (caractere == ENTRER) {return 1;}
    else return 0;
 }


void initialiser_tableau(int **tab, Pion pions[NBPIONS])
{
     for (int i=0; i< LIGNE; i++)
     {
         for (int j=0; j< COLONNE; j++)
          {
              tab[i][j]=0;
          }
     }


  /*  ///mise en place pion blanc
    tab[3][3]=2, pions[32].setvisible(1),  pions[32].setligne(3), pions[32].setcolonne(3);
    tab[4][4]=2, pions[33].setvisible(1),  pions[33].setligne(4), pions[33].setcolonne(4);

    ///mise en place pion noir
    tab[4][3]=1, pions[1].setvisible(1), pions[1].setligne(4), pions[1].setcolonne(3);
    tab[3][4]=1, pions[2].setvisible(1), pions[1].setligne(3), pions[1].setcolonne(4);*/

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
        else cout << "Problème d'ouverture fichier , return 0; sauvegrade.txt" << endl;
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
